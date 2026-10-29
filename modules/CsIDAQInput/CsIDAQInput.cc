#include <iostream>
#include <TFile.h>
#include <TTree.h>

#include "REDEvent/Event.hh"
#include "REDEvent/Waveform.hh"
#include "REDEvent/RunInfo.hh"
#include "TTemplWaveform.hh"

#include "CsIDAQInput.hh"


using std::cout;
using std::clog;
using std::endl;
using std::string;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( CsIDAQInput )
ClassImp( CsIDAQInput )


struct RED::CsIDAQInput::EventData
{
  TTemplWaveform<Char_t> *fWaveformCH0;
  TTemplWaveform<Char_t> *fWaveformCH1;
  UChar_t fYear;
  UChar_t fMonth;
  UChar_t fDay;
  UChar_t fHours;
  UChar_t fMinutes;
  UChar_t fSeconds;
  UChar_t fHundredthOfSeconds;

  EventData(): fWaveformCH0(0), fWaveformCH1(0) { ; }
  TTimeStamp TimeStamp() const;
};

struct RED::CsIDAQInput::RunSettings
{
  UChar_t   fCoupling_CH0;              // AC=0, DC=1
  Double_t  fProbeAttenuation_CH0;
  Double_t  fVerticalRange_CH0;         // volts
  Double_t  fVerticalOffset_CH0;        // volts
  UChar_t   fCoupling_CH1;              // AC=0, DC=1
  Double_t  fProbeAttenuation_CH1;
  Double_t  fVerticalRange_CH1;         // volts
  Double_t  fVerticalOffset_CH1;        // volts
  Double_t  fMinimumSampleRate;         // samples/second
  Double_t  fMinimumRecordLength;       // samples
  Double_t  fTriggerReferencePosition;  // in percent of waveform length
  UChar_t   fCoupling_trigger;          // AC=0, DC=1
  UChar_t   fTrigger_slope;             // falling=0, rising =1
  UChar_t   fTrigger_source;            // CH0, CH1, Ext = 3 - not a clear description
  Double_t  fTrigger_level;             // volts
  Double_t  fHysteresis;                // volts
  Double_t  fHoldoff;                   // seconds
  Double_t  fTrigger_delay;             // seconds
  UChar_t   fTrigger_type;              // edge = 0, hyst = 1
  Double_t  fEntry19;                   // reserved
  Double_t  fEntry20;                   // reserved
  Double_t  fEntry21;                   // reserved
  Double_t  fTimestamp_start;           // FIXME see note CsI_Note_01
  Double_t  fTimestamp_end;             // FIXME see note CsI_Note_01
  Double_t  fEntry24;                   // reserved
  Double_t  fEntry25;                   // reserved

  // Grayson comment:
  //    "Time is LabView not Unix, i.e. whole seconds after the Epoch 01/01/1904 00:00:00.00 UTC"
};

TTimeStamp RED::CsIDAQInput::EventData::TimeStamp() const
{
  int year    = static_cast<int>(fYear) + 2000;
  int month   = static_cast<int>(fMonth);
  int day     = static_cast<int>(fDay);
  int hour    = static_cast<int>(fHours);
  int minute  = static_cast<int>(fMinutes);
  int second  = static_cast<int>(fSeconds);
  int nsecond = static_cast<int>(fHundredthOfSeconds)*10000000;

  return TTimeStamp(year, month, day, hour, minute, second, nsecond, kFALSE, 0);
}

CsIDAQInput::CsIDAQInput():
  fFile(0), fEventTree(0), fEventData(0),
  fRunSettingsTree(0), fRunSettings(0)
{
  cout << __PRETTY_FUNCTION__ << endl;
  fCurrSegment = 0;
  fRunHint.type   = "";
  fRunHint.number = 0;
  fRunHint.date   = 0;
  fRunHint.time   = 0;
  fEventData = new EventData();
  fRunSettings = new RunSettings();
}
CsIDAQInput::~CsIDAQInput()
{
  cout << __PRETTY_FUNCTION__ << endl;
  // just for the case
  CloseSegment();
  delete fRunSettings;
  delete fEventData;
}

int CsIDAQInput::Initialize()
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fStatus==kCreated) fStatus = kInit;
  fCurrSegment = 0;
  return 0;
}

ProcessingModule::EventStatus CsIDAQInput::BeginOfRun(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fCurrSegment>=fSegments.size()) {
    fStatus = kEndAll;
    return kError;
  }
  if(fCurrSegment==0)
    // Only for the very first call, later it's done in EndOfRunSegment
    ParseFileName();
  fStatus = kGood;
  if (!OpenSegment()) {
    fStatus = kErrorSegment;
    return kError;
  }

  // Make RunInfo.
  // new run, so full copy and corrections
  FillRunInfo();
  event->SetRunInfo(fRunInfo);
  fEventNumber = 0;

  return kOk;
}

ProcessingModule::EventStatus CsIDAQInput::BeginOfRunSegment(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  int old_num_events = fRunInfo.fNumEvents;
  // try to open file
  if (fCurrSegment>=fSegments.size()) {
    fStatus = kEndAll;
    return kError;
  }
  fStatus = kGood;
  if (!OpenSegment()) {
    fStatus = kErrorSegment;
    return kError;
  }

  // update some info in RunInfo
  event->SetRunInfo(fRunInfo);
  if (fRunHint.same_run) {
    fRunInfo.fNumEvents += old_num_events;
  }
  // see also EndOfRunSegment()
  fEntry = -1;

  //fRunInfo.Print();
  return kOk;
}

ProcessingModule::EventStatus CsIDAQInput::ProcessEvent(Event *event)
{
  //cout << __PRETTY_FUNCTION__ <<" "<< fStatus << endl;
  if (fStatus!=kGood && fStatus!=kErrorEvent) return kError;

  if (++fEntry >= fEventTree->GetEntries()) {
    fStatus = kEndSegment;
    return kError;
  }
  if (fEventTree->GetEntry(fEntry)<=0) {
    // read failed
    clog << "Failed to read event #" << fEntry << endl;
    fStatus = kErrorEvent;
    return kError;
  }

  event->Clear();
  event->fRunInfo = &fRunInfo;
  event->fRunNumber = fRunInfo.fRunNumber;
  event->fEventNumber = fEventNumber++;
  event->fNumChannels = 2;
  event->fTriggerCount = 0;
  event->fTriggerTime = fEventData->TimeStamp();
  event->fTriggerSource = 0;
  event->fIsMonteCarloEvent = false;
  event->fTaggedAsMuon = false;
  event->fTaggedAsNoise = false;
  event->fHasSaturatedChannel = false;
  event->fSkippedByClustering = false;

  {
    Waveform* wave = event->GetNewWaveform();
    std::vector<Char_t> *tmp;
    tmp = &(fEventData->fWaveformCH0->GetVectorData());
    if(wave->fData.size() < tmp->size())
      wave->fData.resize(tmp->size());

    for (unsigned int i=0; i<tmp->size();i++)
      wave->fData[i] = static_cast<int>((*tmp)[i]);

    wave->fChannel = 0;                           //FIXME
    wave->fIsCompressed = false;
    wave->fIsModified = 0;
    wave->fNumSamples = wave->fData.size();
    wave->fOffset = fEventData->fWaveformCH0->GetTOffset();
    wave->fPeriod = 1e-9/fEventData->fWaveformCH0->GetSamplingFreq();    // to use seconds
    wave->fBitWidth = 8;                         // NI PCI-5153, 8 bit (CsI_Note_01.pdf)
    wave->fSignalMin = 0;
    wave->fSignalMax = 0;
    wave->fSignalBase = 0;
    wave->fSignalNoise = 0;
    wave->fSignalSaturated = false;

    // default is for old files without run settings tree
    if (fRunSettings->fVerticalRange_CH0!=0.)
      wave->fGain = fRunSettings->fVerticalRange_CH0/((1<<wave->fBitWidth)-1);
    else
      wave->fGain = 0.2/((1<<wave->fBitWidth)-1);
    if (fRunSettings->fTriggerReferencePosition!=0.)
      wave->fDelay = -wave->fPeriod*wave->fNumSamples*fRunSettings->fTriggerReferencePosition*0.01;
    else
      wave->fDelay = -55e-6;
    wave->fPlaceOfTrigger = -wave->fDelay/wave->fPeriod;

    wave = event->GetNewWaveform();
    tmp = &fEventData->fWaveformCH1->GetVectorData();
    if(wave->fData.size() < tmp->size())
      wave->fData.resize(tmp->size());

    for (size_t i=0; i<tmp->size();i++)
      wave->fData[i] = static_cast<int>((*tmp)[i]);

    wave->fChannel = 1;                           //FIXME
    wave->fIsCompressed = false;
    wave->fIsModified = 0;
    wave->fNumSamples = wave->fData.size();
    wave->fOffset = fEventData->fWaveformCH1->GetTOffset();
    wave->fPeriod = 1e-9/fEventData->fWaveformCH1->GetSamplingFreq();    // to use seconds
    wave->fBitWidth = 8;                         // NI PCI-5153, 8 bit (CsI_Note_01.pdf)
    wave->fSignalMin = 0;
    wave->fSignalMax = 0;
    wave->fSignalBase = 0;
    wave->fSignalNoise = 0;
    wave->fSignalSaturated = false;

    // default is for old files without run settings tree
    if (fRunSettings->fVerticalRange_CH1!=0.)
      wave->fGain = fRunSettings->fVerticalRange_CH1/((1<<wave->fBitWidth)-1);
    else
      wave->fGain = 0.2/((1<<wave->fBitWidth)-1);
    if (fRunSettings->fTriggerReferencePosition!=0.)
      wave->fDelay = -wave->fPeriod*wave->fNumSamples*fRunSettings->fTriggerReferencePosition*0.01;
    else
      wave->fDelay = -55e-6;
    wave->fPlaceOfTrigger = -wave->fDelay/wave->fPeriod;
  }
  //event->SetRunInfo(fRunInfo);

  //event->Print();
  return kOk;
}

ProcessingModule::EventStatus CsIDAQInput::EndOfRunSegment(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  // add things to fRunInfo
  fRunInfo.fStop = fEventData->TimeStamp();
  fRunInfo.fAcquisition = fRunInfo.fStop - fRunInfo.fStart;

  CloseSegment();

  // what's next
  fCurrSegment++;
  if (fCurrSegment<fSegments.size()) {
    ParseFileName();
    if (fRunHint.same_run)
      fStatus = kEndSegment;
    else
      fStatus = kEndRun;
  } else {
    fStatus = kEndAll;
  }
  return kOk;
}

void CsIDAQInput::ParseFileName()
{
  // url: [file:]<path/file>
  // name: ^(\d{6})/(\d{6}).root$
  // 1=date, 2=time
  const string& uri = fSegments[fCurrSegment];
  string::size_type i,j,k;
  fRunHint.same_run = true;

  // FIXME move to a dedicated function
  string scheme;
  i = uri.find(':');
  if (i!=string::npos) scheme.assign(uri,0,i);
  else scheme = "file", i = -1;
  j = uri.rfind("#");
  if (j!=string::npos) ;//fragment
  j = uri.rfind("?",j);
  if (j!=string::npos) ;//query

  string name;
  //k = uri.rfind('/',j);
  //if (k==string::npos) k = i;
  name.assign(uri,i+1,j);

  string ext, time;
  j = name.rfind('.');
  if (j!=string::npos) ext.assign(name,j+1,string::npos);
  if (ext=="root" && j>0) {
    k = name.rfind('/',j-1);
    if (k!=string::npos) {
      if (k+1<j) time.assign(name,k+1,j-k-1);
      j = k;
    }
  }
  fRunHint.time = (time.find_first_not_of("0123456789")==string::npos)?strtol(time.c_str(),0,10):0;
  // in theory we could also check that delta_time is 30 seconds, but who cares
  name.erase(j,string::npos);

  string date;
  j = name.rfind('/');
  if (j!=string::npos) date.assign(name,j+1,string::npos);
  fRunHint.date = (date.find_first_not_of("0123456789")==string::npos)?strtol(date.c_str(),0,10):0;
  fRunHint.same_run = (fRunHint.date!=0 && fRunHint.time!=0 && fCurrSegment>0);

  //cout << "fRunHint { " << fRunHint.number <<" '"<< fRunHint.type <<"' "<< fRunHint.date <<" "<< fRunHint.time <<" "<< (fRunHint.same_run?1:0) <<" "<< (fRunHint.format_ok?1:0) <<" }"<< endl;
  return;
}

bool CsIDAQInput::OpenSegment()
{
  if (fFile!=0) return true;

  InputModule::OpenSegment();
  fFile = TFile::Open(fSegments[fCurrSegment].c_str());
  //fFile->verbose = fVerbose;
  if (fFile==0 || !fFile->IsOpen() || fFile->IsZombie()) {
    clog << "Can't open file '" << fSegments[fCurrSegment] << "'" << endl;
    return false;
  }

  //fTree = (TTree*)fFile->Get("settings");
  fEventTree = static_cast<TTree*>(fFile->Get("csiData"));
  if (!fEventTree) {
    clog << "Can't find proper tree in '" << fSegments[fCurrSegment] << "'" << endl;
    return false;
  } else {
    int status = 0;

    status += fEventTree->SetBranchAddress("waveform_ch0",&(fEventData->fWaveformCH0));
    status += fEventTree->SetBranchAddress("waveform_ch1",&(fEventData->fWaveformCH1));
    status += fEventTree->SetBranchAddress("timestamp_year",&fEventData->fYear);
    status += fEventTree->SetBranchAddress("timestamp_month",&fEventData->fMonth);
    status += fEventTree->SetBranchAddress("timestamp_day",&fEventData->fDay);
    status += fEventTree->SetBranchAddress("timestamp_hour",&fEventData->fHours);
    status += fEventTree->SetBranchAddress("timestamp_minute",&fEventData->fMinutes);
    status += fEventTree->SetBranchAddress("timestamp_minute",&fEventData->fMinutes);
    status += fEventTree->SetBranchAddress("timestamp_second",&fEventData->fSeconds);
    status += fEventTree->SetBranchAddress("timestamp_hundredthSecond",&fEventData->fHundredthOfSeconds);

    if (status!=0) {
      clog << "Can't unknown tree structure in '" << fSegments[fCurrSegment] << "'" << endl;
      return false;
    }
  }
  fRunSettingsTree = static_cast<TTree*>(fFile->Get("settings"));
  if (!fRunSettingsTree) {
    clog << "Can't find settings tree in '" << fSegments[fCurrSegment] << "'" << endl;
    // Don't use 'return false;' because some of files
    // have runSettings tree and some of them don't have.
  } else {
    int status = 0;

    status += fRunSettingsTree->SetBranchAddress("coupling_ch0",&(fRunSettings->fCoupling_CH0));
    status += fRunSettingsTree->SetBranchAddress("probeAttenuation_ch0",&(fRunSettings->fProbeAttenuation_CH0));
    status += fRunSettingsTree->SetBranchAddress("verticalRange_ch0",&(fRunSettings->fVerticalRange_CH0));
    status += fRunSettingsTree->SetBranchAddress("verticalOffset_ch0",&(fRunSettings->fVerticalOffset_CH0));
    status += fRunSettingsTree->SetBranchAddress("coupling_ch1",&(fRunSettings->fCoupling_CH1));
    status += fRunSettingsTree->SetBranchAddress("probeAttenuation_ch1",&(fRunSettings->fProbeAttenuation_CH1));
    status += fRunSettingsTree->SetBranchAddress("verticalRange_ch1",&(fRunSettings->fVerticalRange_CH1));
    status += fRunSettingsTree->SetBranchAddress("verticalOffset_ch1",&(fRunSettings->fVerticalOffset_CH1));
    status += fRunSettingsTree->SetBranchAddress("minimumSampleRate",&(fRunSettings->fMinimumSampleRate));
    status += fRunSettingsTree->SetBranchAddress("minimumRecordLength",&(fRunSettings->fMinimumRecordLength));
    status += fRunSettingsTree->SetBranchAddress("trigger_referencePosition",&(fRunSettings->fTriggerReferencePosition));
    status += fRunSettingsTree->SetBranchAddress("coupling_trigger",&(fRunSettings->fCoupling_trigger));
    status += fRunSettingsTree->SetBranchAddress("trigger_slope",&(fRunSettings->fTrigger_slope));
    status += fRunSettingsTree->SetBranchAddress("trigger_source",&(fRunSettings->fTrigger_source));
    status += fRunSettingsTree->SetBranchAddress("trigger_level",&(fRunSettings->fTrigger_level));
    status += fRunSettingsTree->SetBranchAddress("hysteresis",&(fRunSettings->fHysteresis));
    status += fRunSettingsTree->SetBranchAddress("holdoff",&(fRunSettings->fHoldoff));
    status += fRunSettingsTree->SetBranchAddress("trigger_delay",&(fRunSettings->fTrigger_delay));
    status += fRunSettingsTree->SetBranchAddress("trigger_type",&(fRunSettings->fTrigger_type));
    status += fRunSettingsTree->SetBranchAddress("entry19",&(fRunSettings->fEntry19));
    status += fRunSettingsTree->SetBranchAddress("entry20",&(fRunSettings->fEntry20));
    status += fRunSettingsTree->SetBranchAddress("entry21",&(fRunSettings->fEntry21));
    status += fRunSettingsTree->SetBranchAddress("timestamp_start",&(fRunSettings->fTimestamp_start));
    status += fRunSettingsTree->SetBranchAddress("timestamp_end",&(fRunSettings->fTimestamp_end));
    status += fRunSettingsTree->SetBranchAddress("entry24",&(fRunSettings->fEntry24));
    status += fRunSettingsTree->SetBranchAddress("entry25",&(fRunSettings->fEntry25));

    if (status) {
      clog << "Can't unknown tree structure in '" << fSegments[fCurrSegment] << "'" << endl;
      return false;
    }

  }

  return true;
}
void CsIDAQInput::FillRunInfo()
{
  int prev_run_number = fRunInfo.fRunNumber;
  fRunInfo.Clear();
  if (fRunSettings!=0) fRunSettingsTree->GetEntry(0);
  fEventTree->GetEntry(0);
  int date = fEventData->fYear*10000 + fEventData->fMonth*100 + fEventData->fDay;
  int run_number = date*100 + prev_run_number%100 + 1;
  fRunInfo.fRunNumber = (fRunHint.number>0)?fRunHint.number:run_number;
  fRunInfo.fDAQ_ID = "CsI NI PCI-5153";
  fRunInfo.fRunType = fRunHint.type;
  fRunInfo.fLabels.push_back("data");
  fRunInfo.fLabels.push_back("veto");
  fRunInfo.fStart = fEventData->TimeStamp();
  //fEventTree->GetEntry(fEventTree->GetEntries()-1); // do not hurry
  fRunInfo.fStop = fEventData->TimeStamp();
  fRunInfo.fAcquisition = fRunInfo.fStop - fRunInfo.fStart;
  fRunInfo.fNumChannels = 2;
  fRunInfo.fNumEvents = fEventTree->GetEntries();
}
bool CsIDAQInput::CloseSegment()
{
  InputModule::CloseSegment();
  if (fFile) {
    delete fFile;
    fFile = 0;
  }
  return true;
}
