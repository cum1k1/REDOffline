#include <iostream>
#include <vector>
#include <cstdio>

#include "TFile.h"
#include "TTree.h"

#include "daqman/ChannelData.hh"
#include "daqman/EventData.hh"

#include "DAQMANInput.hh"
#include "REDEvent/Event.hh"
#include "REDEvent/Waveform.hh"

using std::cout;
using std::endl;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( DAQMANInput )
ClassImp( DAQMANInput )


DAQMANInput::DAQMANInput()
  :mode(0), level(0.0), option(), fEntry(-1), fFile(0), fEventTree(0),
  fEvent(0)
{
  cout << __PRETTY_FUNCTION__ << endl;

  fCurrSegment = -1;
  SetVerbose(0);
  fStatus = kCreated;
}
DAQMANInput::~DAQMANInput()
{
  cout << __PRETTY_FUNCTION__ << endl;
  CloseSegment();
}

int DAQMANInput::Initialize()
{
  cout << __PRETTY_FUNCTION__ << endl;

  if (fStatus == kCreated)
    fStatus = kInit;

  fCurrSegment = 0;
  return 0;
}
ProcessingModule::EventStatus DAQMANInput::BeginOfRun(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fCurrSegment >= fSegments.size()) {
    fStatus = kEndAll;
    return kError;
  }

  if (!OpenSegment()) {
    fStatus = kErrorSegment;
    return kError;
  }

  int first_run_record = fRunInfo.fNumEvents;
  FillRunInfo();
  fRunInfo.fFirstRecord = first_run_record;
  event->SetRunInfo(fRunInfo);
  fEventNumber = 0;

  fStatus = kGood;

  return kOk;
}
ProcessingModule::EventStatus DAQMANInput::BeginOfRunSegment(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  int old_num_events = fRunInfo.fNumEvents + fRunInfo.fFirstRecord;
  if (fCurrSegment>=fSegments.size()) {
    fStatus = kEndAll;
    return kError;
  }

  fStatus = kGood;
  if (!OpenSegment()) {
    fRunInfo.fNumEvents += old_num_events;
  }

  fEntry = -1;
  return kOk;
}

ProcessingModule::EventStatus DAQMANInput::ProcessEvent(Event *event)
{
  if (fVerbose >= 1) {
    cout << __PRETTY_FUNCTION__ <<"\n"
        <<"  run_number="<< event->fRunNumber <<" event_number="<< event->fEventNumber << endl;
  }

//  if (fEntry > 100) {
//    fStatus = kEndSegment;
//  return kOk;
//}

  if (fVerbose>1) {
    event->Print();
  }

  if (fStatus!=kGood && fStatus != kErrorSegment)
    return kError;

  if (++fEntry >= fEventTree->GetEntries()) {
    fStatus = kEndSegment;
    return kError;
  }

  if (fEventTree->GetEntry(fEntry) <= 0) {
    std::clog << "Failed to read event #" << fEntry << endl;
    return kError;
  }
  event->Clear();
  event->fRunInfo = &fRunInfo;
  event->fRunNumber = fRunInfo.fRunNumber;
  event->fEventNumber = fEvent->event_id;
  event->fNumChannels = fEvent->channels.size();
  event->fTriggerTime.SetSec(fEvent->timestamp);
  event->fIsMonteCarloEvent = false;
  event->fTaggedAsMuon = false;
  event->fTaggedAsNoise = false;
  event->fHasSaturatedChannel = false;
  event->fSkippedByClustering = false;

  ChannelData *cdata = 0;

  for (int ch = 0; ch < event->fNumChannels; ch++) {  // channel cycle
    Waveform *wave = event->GetNewWaveform();

  cdata = &fEvent->channels[ch];

    if (wave->fData.size() < cdata->waveform.size())
      wave->fData.resize(cdata->waveform.size());

    for (size_t sample = 0; sample < wave->fData.size(); sample++)
      wave->fData[sample] = cdata->waveform[sample];

    wave->fChannel = cdata->channel_num;
    wave->fPeriod = 1./cdata->sample_rate;
    wave->fDelay = -(cdata->trigger_index*wave->fPeriod);
    wave->fNumSamples = wave->fData.size();
    wave->fBitWidth = 12;
    wave->fGain = 2./(1<<wave->fBitWidth)*1e-3;  // FIXME  2 mv and 12 bit
    wave->fOffset = -wave->fGain*4096; //FIXME to garantee all the signal below zero
    wave->fPlaceOfTrigger = cdata->trigger_index;
    wave->fSignalSaturated = cdata->saturated;
    wave->fSignalMax = cdata->maximum;
    wave->fSignalMin = cdata->minimum;
  }

  return kOk;
}

ProcessingModule::EventStatus DAQMANInput::EndOfRunSegment(Event *)
{
  cout << __PRETTY_FUNCTION__ << endl;


  CloseSegment();
  fCurrSegment++;

  if (fCurrSegment < fSegments.size()) {
    unsigned int PrevSegmentNumber = 0;
    unsigned int CurrSegmentNumber = 0;
    sscanf(fSegments[fCurrSegment-1].c_str(), "file:Run%u.root", &PrevSegmentNumber);
    sscanf(fSegments[fCurrSegment].c_str(), "file:Run%u.root", &CurrSegmentNumber);

    if (PrevSegmentNumber != CurrSegmentNumber)
      fStatus = kEndRun;
    else
      fStatus = kEndSegment;

  } else {
    fStatus = kEndAll;
  }

  return kOk;
}
ProcessingModule::EventStatus DAQMANInput::EndOfRun(Event *)
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fStatus != kEndAll)
    fStatus = kEndRun;
  return kOk;
}
int DAQMANInput::ShutDown()
{
  fStatus = kEndAll;                    // FIXME
  cout << __PRETTY_FUNCTION__ << endl;
  return 0;
}

bool DAQMANInput::OpenSegment()
{
  if (fFile != 0) return true;

  InputModule::OpenSegment();
  fFile = TFile::Open(fSegments[fCurrSegment].c_str());
  if (fFile==0 || !fFile->IsOpen() || fFile->IsZombie()) {
    std::clog << "Can't open file '" << fSegments[fCurrSegment] << "'" << endl;
    return false;
  }

  fEventTree = static_cast<TTree*>(fFile->Get("Events"));
  if (fEventTree == NULL) {
    std::clog << "Can't find proper tree in '" << fSegments[fCurrSegment] << "'" << endl;
    return false;
  }
  int status = 0;

  status = fEventTree->SetBranchAddress("event", &fEvent);
  if (status != 0) {
     std::clog << "Can't find branch in '" << fSegments[fCurrSegment] << "'" << endl;
     return false;
  }
  return true;
}

bool DAQMANInput::CloseSegment()
{
  InputModule::CloseSegment();

  if (fFile) {
    delete fFile;
    fFile = 0;
  }
  return true;
}

void DAQMANInput::FillRunInfo()
{
  fEventTree->GetEntry(1);

  fRunInfo.Clear();
  fRunInfo.fRunNumber = fEvent->run_id;
  fRunInfo.fStart.SetSec(fEvent->timestamp);
  fRunInfo.fStop.SetSec(fEvent->timestamp);
  fRunInfo.fAcquisition = fRunInfo.fStop - fRunInfo.fStart;
  fRunInfo.fNumEvents = fEventTree->GetEntries();
  fRunInfo.fNumChannels = fEvent->channels.size();

  for (size_t i = 0; i < fEvent->channels.size(); i++) {
    fRunInfo.fLabels.push_back(fEvent->channels[i].label);

  }
}
