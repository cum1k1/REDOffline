#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"

#include "REDEvent/Event.hh"
#include "REDEvent/Waveform.hh"
#include "REDEvent/RunInfo.hh"

#include "DataFile.hh"
#include "data_file_types.hh"

using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::cin;
using namespace RED;

struct RED::DAQTrees {
  TTree *fEventTree;
  TTree *fRunTree;
  TTree *fPulseTree;
  TTree *fEventChannelTree;
  TTree *fRunChannelTree;
  TTree *fRunControlTree;
};

struct RED::EventData {
  event_header_v1    event;
  event_channel_v1   event_channel;
  waveform_v1        waveform;
};

struct RED::RunData {
  run_header_v1      run;
  std::vector<channel_header_v1> run_channel;
  run_control_v1     run_control;
};




DataFile::DataFile(): fFile(0), fNumSamples(1024)
{
  fInputTree = new DAQTrees;
  fData = new EventData;
  fRun = new RunData;
  fRunInfo = new RunInfo;

  //RunInfo->fLabels = 0;

}

/*DataFile::DataFile( const DataFile &m_datafile )
{
    fFile = ?

    fInputTree = new DAQTrees;
    *fInputTree = *m_datafile.fInputTree;

    fData = new EventData;
    *fData = *m_datafile.fData;

    fRun = new RunData;
    *fRun = *m_datafile.fRun;

    fRunInfo = new RunInfo;
    *fRunInfo = *m_datafile.fRunInfo;
}


DataFile& DataFile::operator=( const DataFile &m_datafile )
{
    if(this == &m_datafile) return *this;

    fFile = ?

    *fInputTree = *m_datafile.fInputTree;

    *fData = *m_datafile.fData;

    *fRun = *m_datafile.fRun;

    *fRunInfo = *m_datafile.fRunInfo;

    return *this;
}*/

bool DataFile::IsOpen()
{
  if (fFile != 0 && fFile->IsOpen()) return true;
  else return false;
}

void DataFile::NewFileOpen(string Name)
{
  Close();

  fFile = new TFile(Name.c_str());
}

void DataFile::NewFileOpen( const char *FileName)
{
  Close();

  fFile = new TFile(FileName);
}

bool DataFile::Open(const char *FileName)
{
  std::string Name = &*FileName;

  return Open(Name);
}

bool DataFile::Open(const string& FileName)
{
  NewFileOpen(FileName);

  if (fFile->IsZombie()) {
    cout<<"Error opening file \n";
    return false;
  } else {

    fInputTree->fEventTree=(TTree*)fFile->Get("event");
    fInputTree->fRunTree=(TTree *)(fFile->Get("run"));
    fInputTree->fPulseTree=(TTree *)(fFile->Get("event_pulse"));
    fInputTree->fEventChannelTree=(TTree *)(fFile->Get("event_channel"));
    fInputTree->fRunChannelTree=(TTree *)(fFile->Get("run_channel"));
    fInputTree->fRunControlTree=(TTree *)(fFile->Get("run_control"));

    if (!fInputTree->fEventTree || !fInputTree->fRunTree || !fInputTree->fEventChannelTree\
        || !fInputTree->fRunChannelTree) {
      cout<<"\nFile  is bad. Exiting.\n";
      return false;
    }

    fInputTree->fRunTree -> SetBranchAddress("run_br",&fRun->run);
    channel_header_v1 run_channel;
    fInputTree->fRunChannelTree -> SetBranchAddress("run_channel_br",&run_channel);
    fInputTree->fRunControlTree -> SetBranchAddress("run_control_br",&fRun->run_control);
    fInputTree->fRunTree->GetEntry(0);
    if (static_cast<int>(fRunInfo->fLabels.size()) < fRun->run.nchannels) fRunInfo->fLabels.resize(fRun->run.nchannels);
    if (static_cast<int>(fRun->run_channel.size()) < fRun->run.nchannels) fRun->run_channel.resize(fRun->run.nchannels);
    ReadRunInfo();
    for (int i = 0; i < fInputTree->fRunChannelTree->GetEntries(); i++) {
      fInputTree->fRunChannelTree->GetEntry(i);
      fRun->run_channel[run_channel.ichannel] = run_channel;
      fRunInfo->fLabels[run_channel.ichannel] = run_channel.label;
      if (fNumSamples < run_channel.nsamples) fNumSamples = run_channel.nsamples;
    }
    fInputTree->fRunChannelTree->SetBranchAddress("run_channel_br",nullptr);

    fInputTree->fEventTree -> SetBranchAddress("event_br",&fData->event);
    fInputTree->fEventChannelTree -> SetBranchAddress("event_channel_br",&fData->event_channel );
    fInputTree->fEventChannelTree -> SetBranchAddress("event_channel_wf",&fData->waveform);
    fData->waveform.data = new uint32_t[fNumSamples];
    fInputTree->fEventChannelTree -> SetBranchAddress("event_channel_data",fData->waveform.data);

//      fInputTree.tPulse -> SetBranchAddress("event_pulse_br",&pulse);

    return true;
  }
}

int DataFile::GetNumEvents()
{
  if (IsOpen())
    return fRunInfo->fNumEvents;
  else
    return 0;
}

int DataFile::GetNumEntries()
{
  if (IsOpen())
    return fRun->run.nentries;
  else
    return 0;
}


bool DataFile::ReadWaveform(Waveform *Waveform)
{
  Waveform->fChannel = fData->event_channel.ichannel;
  Waveform->fIsCompressed = fData->waveform.packing;
  Waveform->fNumSamples = fData->waveform.nsamples;
  Waveform->fIsModified = fData->waveform.modified;

  // sampling parameters
  Waveform->fPeriod = fRun->run_channel[Waveform->fChannel].period;
  Waveform->fDelay = fRun->run_channel[Waveform->fChannel].delay;
  Waveform->fGain = fRun->run_channel[Waveform->fChannel].gain;
  Waveform->fOffset = fRun->run_channel[Waveform->fChannel].offset;
  Waveform->fPlaceOfTrigger = fRun->run_channel[Waveform->fChannel].trigger;
  Waveform->fBitWidth = fRun->run_channel[Waveform->fChannel].nbits;

  // signal parameters
  Waveform->fSignalMin = fData->event_channel.line_min;
  Waveform->fSignalMax = fData->event_channel.line_max;
  Waveform->fSignalBase = fData->event_channel.line_base;
  Waveform->fSignalNoise = fData->event_channel.line_noise;

//
  Waveform->fData.resize(Waveform->fNumSamples);
  for(int i=0; i<Waveform->fNumSamples; i++)
    Waveform->fData[i] = fData->waveform.data[i];

  return true;
}


bool DataFile::ReadRunInfo()
{
  fRunInfo->fRunNumber = fRun->run.irun;
  char daq_id[50];
  sprintf(daq_id,"%i",fRun->run.daq_id);
  fRunInfo-> fDAQ_ID = daq_id;
//      fRunType= RunInfo._run.;
//
  fRunInfo->fStart = (fRun->run.start_gsec)*(1e+9) + fRun->run.start_sec+(fRun->run.start_nsec)*(1e-9);
  fRunInfo->fStop = (fRun->run.stop_gsec)*(1e+9) + fRun->run.stop_sec+(fRun->run.stop_nsec)*(1e-9);
  fRunInfo->fAcquisition = (fRun->run.act_gsec)*(1e+9) + fRun->run.act_sec+(fRun->run.act_nsec)*(1e-9);
  fRunInfo->fNumChannels = fRun->run.nchannels;
//      fTriggerMode=RunInfo._run.nevents;
  fRunInfo->fDescription = fRun->run.descr;
  fRunInfo->fNumEvents = fRun->run.nevents;
  return true;
}

bool DataFile::ReadRunInfo(Event* m_event)
{
  m_event->SetRunInfo(fRunInfo);
  return true;
}

int DataFile::GetRunNumber() const
{
  if (fFile->IsOpen() && fRunInfo != 0)
    return fRunInfo->fRunNumber;
  else
    return -1;
}

//ProcessingModule::EventStatus
//
bool DataFile::ReadEvent(Event *event, int nevent)
{

  event->Clear();

  int ret = fInputTree->fEventTree->GetEntry(nevent);
  if (ret<=0) return false;
  //fInputTree->fPulseTree->GetEntry(nevent);

  for(int j = 0; j < fData->event.nchannels; j++) {
    fInputTree->fEventChannelTree->GetEntry(fData->event.ch_ientry+j);
    Waveform *wf = event->GetNewWaveform();
    ReadWaveform(wf);
    //wf->Clear();
  }

  event->SetRunInfo(fRunInfo);
  event->fRunNumber = fRun->run.irun;
  event->fNumChannels = fData->event.nchannels;
  event->fEventNumber = fData->event.ievent;
  event->fTriggerCount = fData->event.trigger_count;
  event->fTriggerTime.SetSec(fData->event.time_gsec*1000000000+fData->event.time_sec);
  event->fTriggerTime.SetNanoSec(fData->event.time_nsec);
  event->fTriggerSource = fData->event.trigger_count;
  event->fIsMonteCarloEvent = false;

  //event->fRun->fRunNumber=0;
  return true;
}

void DataFile::Close()
{
  if(IsOpen()) {
    fFile->Close();
    delete fFile;
    fFile = 0;
  }
}

DataFile::~DataFile()
{
  Close();

  delete fRun;
  //delete fRunInfo;
  delete fInputTree;
  delete fData;

  fInputTree = 0;
  fData = 0;
  fRun = 0;
}

void DataFile::ResizeWaveform(unsigned int *waveform, int nsamples)
{
  if (waveform) {
    delete [] waveform;
    waveform = 0;
  }
  fNumSamples = nsamples;
  waveform = new unsigned int[fNumSamples];
  fInputTree->fEventChannelTree->SetBranchAddress("event_channel_data",waveform);
}
