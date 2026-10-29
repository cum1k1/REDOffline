#include <iostream>
#include <vector>
#include <TFile.h>

#include "REDEvent/Event.hh"
#include "REDFile/File.hh"

using std::cout;
using std::endl;
using namespace RED;

File::_Run::_Run(): fRunNumber(0), fNumEvents(0), fDAQ_ID(0), \
  fRunType(0), fLabels(0), fLabelsJoined(0), \
  fStart(0), fStop(0), fAcquisition(0), \
  fActualNumOfChannels(0), fMaxNumOfChannels(0), \
  fTriggerMode(0), fFirstRecord(0), fDescription(0)
{ ; }

File::_Run::~_Run()
{
  if (fDAQ_ID != 0) {
    delete fDAQ_ID;
    fDAQ_ID = 0;
  }

  if (fRunType != 0) {
    delete fRunType;
    fRunType = 0;
  }

  if (fDescription != 0) {
    delete fDescription;
    fDescription = 0;
  }

  if (fLabels != 0) {
    fLabels->clear();
    delete fLabels;
    fLabels = 0;
  }

  if (fLabelsJoined != 0) {
    delete fLabelsJoined;
    fLabelsJoined = 0;
  }
}

File::_Pulse::_Pulse(): fChannel(0), fType(0), fBaseline(0), \
  fBaselineError(0), fNoise(0), fTime(0), \
  fTimeError(0), fTau(0), fFirstSample(0), \
  fLastSample(0), fWidth10(0), fWidth50(0), \
  fWidth90(0), fRisetime(0), fFalltime(0),\
  fDecaytime(0), fAmplitude(0), fPeakTime(0), \
  fArea(0), fAreaEff(0), fAreaDiff(0), fChiSquare(0),\
  fSaturated(0), fOverlayed(0), fPartial(0)
{
  //for (int i = 0; i < 8; i++ )
  //  fFitParameters[i] = 0;
}

File::_Event::_Event(): fRunNumber(0), fEventNumber(0), fTriggerCount(0), \
  fTriggerTime_fSec(0), fTriggerTime_fNanoSec(0), \
  fTriggerSource(0), fIsMonteCarloEvent(false), \
  fTaggedAsMuon(false), fTaggedAsNoise(false), \
  fNumChannels(0), fNumPulses(0), fNumClusters(0), \
  fHasSaturatedChannel(false), \
  fSkippedByClustering(false), \
  fChannel(0), fIsCompressed(0), fIsModified(0), \
  fNumSamples(0), fPeriod(0), fDelay(0), fGain(0), \
  fOffset(0), fPlaceOfTrigger(0), fBitWidth(0), \
  fSignalMin(0), fSignalMax(0), fSignalBase(0), \
  fSignalNoise(0), fSignalSaturated(0), fData(0)
{ ; }

File::_Event::~_Event()
{
  if (fData != 0) {
    delete fData;
    fData = 0;
  }
}

File::_Cluster::_Cluster(): fType(0), fTime(0), fWidth(0), fSaturated(0), \
  fPeakChannel(0), fAmplitude(0), fArea(0), \
  fAreaEff(0), fAreaDiff(0), fNumSPE(0), \
  fNumPMTTop(0), fNumPMTBottom(0), fX(0), fY(0), \
  fZ(0), fDriftTime(0), fRawEnergy(0), \
  fRawEnergyError(0), fCorrectedEnergy(0), \
  fCorrectedEnergyError(0), fPulsesArray(0)
{ ; }

File::_Cluster::~_Cluster()
{
  if (fPulsesArray != 0) {
    delete fPulsesArray;
    fPulsesArray = 0;
  }
}
#define DEBUG(V,A) if (1) { A }


//////////////////////////////////////////////////////////////////////////
//                                                                      //
//////////////////////////////////////////////////////////////////////////


File::File(): fFile(0),fRunTree(0), fEventTree(0), fEvent(0), fRun(0), \
  fRecordCounter(0), fMaxNumOfChannels(0), fMaxNumOfPulses(0)
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  fUseLegacyMode = false;
}
File::~File()
{

  if (fFile) delete fFile;
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

/*File& File::operator=(const File& that)
{
  if (this == &that) return *this;
  SetFilename(that.GetFilename());
  fFile = that.fFile;
  fRunTree = that.fRunTree;
  fEventTree = that.fEventTree;
  fEvent = that.fEvent;
  fRun = that.fRun;
  fRecordCounter = that.fRecordCounter;
  fNumPulses = that.fNumPulses;

  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return *this;
}*/

bool File::operator==(const File& that) const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  if(GetFilename().compare(that.GetFilename()) == 0 && \
      fRunTree == that.fRunTree && \
      fEventTree == that.fEventTree && \
      fEvent == that.fEvent && \
      fRun == that.fRun && \
      fRecordCounter == that.fRecordCounter && \
      fMaxNumOfChannels == that.fMaxNumOfChannels && \
      fMaxNumOfPulses == that.fMaxNumOfPulses && \
      fMaxNumOfClusters == that.fMaxNumOfClusters)
    return true;
  else
    return false;
}
void File::Print( Option_t* option) const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}
void File::Clear( Option_t* option)
{
  if (fRunTree != 0) {
    delete fRunTree;
    fRunTree = 0;
  }

  if (fEventTree != 0) {
    delete fEventTree;
    fEventTree = 0;
  }

  if (fEvent != 0) {
    delete fEvent;
    fEvent = 0;
  }

  if (fRun != 0) {
    delete fRun;
    fRun = 0;
  }

  if (fFile != 0) {
    delete fFile;
    fFile = 0;
  }

  fRecordCounter = 0;
  fMaxNumOfChannels = 0;
  fMaxNumOfPulses = 0;
  fMaxNumOfClusters = 0;

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

bool File::IsOpen() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return  (fFile!=0) ? true : false;
}
bool File::IsWritable() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return false;
}

bool File::Open()
{

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  return false;
}
bool File::ReOpen()
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return false;
}
bool File::Close()
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  if (IsOpen()) {
    fFile->Close();
    delete fFile;
    fFile = 0;
    return true;
  } else return false;
}
bool File::ReadEvent(Event *event, int irecord)
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  if (IsOpen() && fEventTree != 0 && fRunTree != 0) {
    event->Clear();

    if (!fUseLegacyMode)
      fEventTree->SetBranchAddress(GetEventBranchName().c_str(), &event);

    fEventTree->GetEntry(irecord);

    if (fRecordCounter!=irecord )
      fRecordCounter = irecord;

    if (fUseLegacyMode) {
      for(int j = 0; j < fEvent->fNumWaveforms; j++) {
        Waveform *wf = event->GetNewWaveform();
        ReadWaveform(wf, j);
      }

      for (int k = 0; k < fEvent->fNumPulses; k++) {
        Pulse *pulse = event->GetNewPulse();
        ReadPulse(pulse, k);
      }

      for (int l = 0; l < fEvent->fNumClusters; l++) {
        Cluster *cluster = event->GetNewCluster();
        ReadCluster(cluster, l, event);
      }

      event->fRunNumber = fEvent->fRunNumber;
      event->fEventNumber = fEvent->fEventNumber;
      event->fNumChannels = fEvent->fNumChannels;
      event->fTriggerCount = fEvent->fTriggerCount;
      event->fTriggerTime.SetSec(fEvent->fTriggerTime_fSec);
      event->fTriggerTime.SetNanoSec(fEvent->fTriggerTime_fNanoSec);
      event->fTriggerSource = fEvent->fTriggerSource;
      event->fIsMonteCarloEvent = fEvent->fIsMonteCarloEvent;
      event->fTaggedAsMuon = fEvent->fTaggedAsMuon;
      event->fTaggedAsNoise = fEvent->fTaggedAsNoise;
      event->fHasSaturatedChannel = fEvent->fHasSaturatedChannel;
      event->fSkippedByClustering = fEvent->fSkippedByClustering;
    }

    if (!event->GetRunInfo() ||
        event->GetRunInfo()->fRunNumber != event->fRunNumber) {
      const RunInfo &info = GetRunInfo(event->fRunNumber);
      event->ResetRunInfo();
      event->SetRunInfo(info);
      event->GetRunInfo()->fFirstRecord = info.fFirstRecord;
    }

    return true;
  } else
    return false;
}
bool File::ReadNextEvent(Event *event)
{
// DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  if (IsOpen() && fEventTree!=0 && fRunTree!=0) {
    ReadEvent(event, fRecordCounter+1);
    return true;
  } else
    return false;
}
Event* File::ReadEvent(int irecord)
{
  fRecordCounter = irecord;
  Event *event = new Event();

  if (IsOpen())
    ReadEvent(event,irecord);

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return event;
}

bool File::ReadEvent(Event* event, int irun, int irecord)
{
  bool IsRead = false;
  bool Found  = false;

  if ( IsOpen() && fRunTree!=0 && fEventTree!=0) {

    int iTreeEntry = 0;


    for(int i=0; i<fEventTree->GetEntries(); i++) {
      fEventTree->GetEntry(i);
      if(fEvent->fRunNumber == irun) {
        iTreeEntry = i;
        Found = true;
        break;
      } else
        Found = false;
    }

    int iRunEntry = 0;

    for (int i=0; i<GetNumEvents(); i++) {
      fRunTree->GetEntry(i);
      if (fRunInfo.fRunNumber == irun) {
        iRunEntry = i;
        Found = true;
        break;
      } else
        Found = false;
    }

    if (Found) {
      fRunTree->GetEntry(iRunEntry);

      if((fRunInfo.fNumEvents)-1 >= irecord) {
        ReadEvent(event, iTreeEntry+irecord-1);
        IsRead = true;
      } else
        IsRead = false;
    } else
      IsRead = false;
  } else
    IsRead = false;

  return IsRead;
}

int File::GetNumEvents() const
{

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  return (fRunTree != 0) ? fRunInfo.fNumEvents : -1;
}
int File::GetMaxNumChannels() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return (IsOpen()) ? fRun->fMaxNumOfChannels : -1;
}

Long64_t File::GetFileSize() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return (IsOpen()) ? fFile->GetSize() : -1;
}

const RunInfo& File::GetRunInfo() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return fRunInfo;
}
const RunInfo& File::GetRunInfo(int run_id) const
{
  if (IsOpen() && fRunTree!=0) {
    std::map<Int_t,RED::RunInfo>::const_iterator it = fRunMap.find(run_id);
    if (it != fRunMap.end())
      fRunInfo = (it->second);

  }
  return fRunInfo;
}
const ProcessingInfo& File::GetProcessingInfo(int level) const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return fProcInfo;
}


void File::ReadRunInfo(int entry)
{
  if (IsOpen() && fRunTree!=0) {

    if (!fUseLegacyMode) {
      RunInfo *info = &fRunInfo;
      fRunTree->SetBranchAddress(GetRunBranchName().c_str(), &info);
    }

    fRunTree->GetEntry(entry);

    if (fUseLegacyMode) {
      fRunInfo.fRunNumber = fRun->fRunNumber;
      fRunInfo.fDAQ_ID = *(fRun->fDAQ_ID);
      fRunInfo.fRunType = *(fRun->fRunType);
      //  for(int i=0;i<16;i++) strcpy(fRunInfo.fLabels[i],fRun->fLabels[i]);
      fRunInfo.fLabels = *(fRun->fLabels);
      fRunInfo.fStart = fRun->fStart;
      fRunInfo.fStop = fRun->fStop;
      fRunInfo.fAcquisition = fRun->fAcquisition;
      fRunInfo.fNumChannels = fRun->fActualNumOfChannels;
      fRunInfo.fTriggerMode = fRun->fTriggerMode;
      fRunInfo.fDescription = *(fRun->fDescription);
      fRunInfo.fFirstRecord = fRun->fFirstRecord;
      fRunInfo.fNumEvents = fRun->fNumEvents;
    }
  }
}


void File::ReadWaveform(Waveform *Waveform, int ChannelNumber)
{
  Waveform->fChannel = (fEvent->fChannel[ChannelNumber]);
  Waveform->fIsCompressed = fEvent->fIsCompressed[ChannelNumber];
  Waveform->fNumSamples = (fEvent->fNumSamples[ChannelNumber]);
  Waveform->fIsModified = (fEvent->fIsModified[ChannelNumber]);

  // sampling parameters
  Waveform->fPeriod = fEvent->fPeriod[ChannelNumber];
  Waveform->fDelay = fEvent->fDelay[ChannelNumber];
  Waveform->fGain = fEvent->fGain[ChannelNumber];
  Waveform->fOffset = fEvent->fOffset[ChannelNumber];
  Waveform->fPlaceOfTrigger =  fEvent->fPlaceOfTrigger[ChannelNumber];
  Waveform->fBitWidth = fEvent->fBitWidth[ChannelNumber];

  // signal parameters
  Waveform->fSignalMin = (Int_t)(fEvent->fSignalMin[ChannelNumber]);
  Waveform->fSignalMax = fEvent->fSignalMax[ChannelNumber];
  Waveform->fSignalBase = fEvent->fSignalBase[ChannelNumber];
  Waveform->fSignalNoise = fEvent->fSignalNoise[ChannelNumber];
  Waveform->fSignalSaturated =  fEvent->fSignalSaturated[ChannelNumber];

  Waveform->fData.resize(Waveform->fNumSamples);
  for(int i=0; i<Waveform->fNumSamples; i++)
    Waveform->fData[i] = fEvent->fData->at(ChannelNumber)[i];

}

void File::ReadPulse(Pulse *pulse, int PulseNumber)
{
  pulse->fChannel = fPulses->fChannel[PulseNumber];
  pulse->fType = fPulses->fType[PulseNumber];
  pulse->fBaseline = fPulses->fBaseline[PulseNumber];
  pulse->fBaselineError = fPulses->fBaselineError[PulseNumber];
  pulse->fNoise = fPulses->fNoise[PulseNumber];
  pulse->fTime = fPulses->fTime[PulseNumber];
  pulse->fTimeError = fPulses->fTimeError[PulseNumber];
  pulse->fTau = fPulses->fTau[PulseNumber];
  pulse->fFirstSample = fPulses->fFirstSample[PulseNumber];
  pulse->fLastSample = fPulses->fLastSample[PulseNumber];
  pulse->fWidth10 = fPulses->fWidth10[PulseNumber];
  pulse->fWidth50 = fPulses->fWidth50[PulseNumber];
  pulse->fWidth90 = fPulses->fWidth90[PulseNumber];
  pulse->fRisetime = fPulses->fRisetime[PulseNumber];
  pulse->fFalltime = fPulses->fFalltime[PulseNumber];
  pulse->fDecaytime = fPulses->fDecaytime[PulseNumber];
  pulse->fPeakTime = fPulses->fPeakTime[PulseNumber];
  pulse->fAmplitude = fPulses->fAmplitude[PulseNumber];
  pulse->fArea = fPulses->fArea[PulseNumber];
  pulse->fAreaEff = fPulses->fAreaEff[PulseNumber];
  pulse->fAreaDiff = fPulses->fAreaDiff[PulseNumber];
  pulse->fChiSquare = fPulses->fChiSquare[PulseNumber];
  pulse->fSaturated = fPulses->fSaturated[PulseNumber];
  pulse->fOverlayed = fPulses->fOverlayed[PulseNumber];
  pulse->fPartial = fPulses->fPartial[PulseNumber];
}

void File::ReadCluster(Cluster *cluster, int ClusterNumber, Event* event)
{
  cluster->fType = fClusters->fType[ClusterNumber];
  cluster->fTime = fClusters->fTime[ClusterNumber];
  cluster->fWidth = fClusters->fWidth[ClusterNumber];
  cluster->fSaturated = fClusters->fSaturated[ClusterNumber];
  cluster->fPeakChannel = fClusters->fPeakChannel[ClusterNumber];
  cluster->fAmplitude = fClusters->fAmplitude[ClusterNumber];
  cluster->fArea = fClusters->fArea[ClusterNumber];
  cluster->fAreaEff = fClusters->fAreaEff[ClusterNumber];
  cluster->fAreaDiff = fClusters->fAreaDiff[ClusterNumber];
  cluster->fNumSPE = fClusters->fNumSPE[ClusterNumber];
  cluster->fNumPMTTop = fClusters->fNumPMTTop[ClusterNumber];
  cluster->fNumPMTBottom = fClusters->fNumPMTBottom[ClusterNumber];

  cluster->fX = fClusters->fX[ClusterNumber];
  cluster->fY = fClusters->fY[ClusterNumber];
  cluster->fZ = fClusters->fZ[ClusterNumber];
  cluster->fDriftTime = fClusters->fDriftTime[ClusterNumber];

  cluster->fRawEnergy = fClusters->fRawEnergy[ClusterNumber];
  cluster->fRawEnergyError = fClusters->fRawEnergyError[ClusterNumber];
  cluster->fCorrectedEnergy = fClusters->fCorrectedEnergy[ClusterNumber];
  cluster->fCorrectedEnergyError = fClusters->fCorrectedEnergyError[ClusterNumber];

//  fClusters->fPulsesArray->clear();

  RED::Pulse* pulse = 0;
  for (unsigned int i = 0; i < fClusters->fPulsesArray->at(ClusterNumber).size(); i++) {
    pulse = event->GetPulse((*fClusters->fPulsesArray)[ClusterNumber][i]);
    cluster->AddPulse(pulse);
    pulse->SetCluster(cluster);
  }
}
void File::FillRunMap()
{
  if (fRunTree) {
    for (int i=0; i<fRunTree->GetEntries(); i++) {
      ReadRunInfo(i);
      fRunMap[fRunInfo.fRunNumber] = fRunInfo;
      if (!fUseLegacyMode) {
        fRunMap[fRunInfo.fRunNumber].fFirstRecord = fRunInfo.fFirstRecord;
        fRunMap[fRunInfo.fRunNumber].SetUniqueID(fRunInfo.GetUniqueID());
        fRunInfo.SetUniqueID(0);
      }
    }
  }
}

void File::ClearRunMap()
{
  if (!fRunMap.empty())
    fRunMap.clear();
}

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//////////////////////////////////////////////////////////////////////////


InputFile::InputFile() : File()
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}
InputFile::InputFile(const char *filename) : File()
{
  SetFilename(std::string(filename));

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}
InputFile::InputFile(const std::string &filename) : File()
{
  SetFilename(filename);
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}
/*InputFile::InputFile(const InputFile &that)
{

  SetFilename(that.GetFilename());
  fFile = that.fFile;
  fRunTree = that.fRunTree;
  fEventTree = that.fEventTree;
  fEvent = that.fEvent;
  fRun = that.fRun;
  fRecordCounter = that.fRecordCounter;
  fNumPulses = that.fNumPulses;

  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}
*/

InputFile::~InputFile()
{
  Close();
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

bool InputFile::Open()
{

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  if (!IsOpen()) {

    fFile = new TFile((GetFilename()).c_str(),"READ");

    if (fFile->IsZombie()) return false;

    fRunTree = (TTree*)fFile->Get(GetRunTreeName().c_str());
    fEventTree = (TTree*)fFile->Get(GetEventTreeName().c_str());

    fRun = new _Run();
    fEvent = new _Event();
    fPulses = new _Pulse();
    fClusters = new _Cluster();

    SetWaveformArraySize(0);
    SetPulseArraySize(0);
    SetClusterArraySize(0);

    fMaxNumOfPulses = 0;
    fMaxNumOfChannels = 0;
    fMaxNumOfClusters = 0;

    bool fEventMatch = false; // event branches ok
    bool fRunMatch = false;   // run branches ok

    if (fEventTree) {
      if (fEventTree->GetNbranches() > 1)
        fUseLegacyMode = true;

      if (fUseLegacyMode) {
        fEventTree->SetBranchAddress("fRunNumber", &fEvent->fRunNumber);
        fEventTree->SetBranchAddress("fEventNumber", &fEvent->fEventNumber);
        fEventTree->SetBranchAddress("fNumChannels", &fEvent->fNumChannels);
        fEventTree->SetBranchAddress("fNumPulses", &fEvent->fNumPulses);
        fEventTree->SetBranchAddress("fNumClusters", &fEvent->fNumClusters);
      }
    }

    if (!fUseLegacyMode) {
      Event *event = nullptr;
      if (fEventTree->SetBranchAddress(GetEventBranchName().c_str(), &event) == 0)
        fEventMatch = true;
      else
        fEventMatch = false;
    } else {
      for (int entry = 0; entry < fEventTree->GetEntries(); entry++) {
        fEventTree->GetEntry(entry);
        if (fMaxNumOfPulses < fEvent->fNumPulses) fMaxNumOfPulses = fEvent->fNumPulses;
        if (fMaxNumOfChannels < fEvent->fNumChannels) fMaxNumOfChannels = fEvent->fNumChannels;
        if (fMaxNumOfClusters < fEvent->fNumClusters) fMaxNumOfClusters = fEvent->fNumClusters;
      }
      std::cout<<"Finish counts\n";
      SetPulseArraySize(fMaxNumOfPulses);
      SetPulseBranchAddress();

      SetWaveformArraySize(fMaxNumOfChannels);
      SetWaveformBranchAddress();

      SetClusterArraySize(fMaxNumOfClusters);
      SetClusterBranchAddress();
    }

    if (fRunTree) {
      if (!fUseLegacyMode) {
        RunInfo* info = nullptr;
        if (fRunTree->SetBranchAddress(GetRunBranchName().c_str(), &info) == 0)
          fRunMatch = true;
        else
          fRunMatch = false;
      } else {
        fRunTree->SetBranchAddress("fRunInfo_fRunNumber", &fRun->fRunNumber);
        fRunTree->SetBranchAddress("fRunInfo_fNumEvents", &fRun->fNumEvents);
        fRunTree->SetBranchAddress("fRunInfo_fRunType", &(fRun->fRunType));
        fRunTree->SetBranchAddress("fRunInfo_fDAQ_ID", &fRun->fDAQ_ID);
        fRunTree->SetBranchAddress("fRunInfo_fActualNumOfChannels", &fRun->fActualNumOfChannels);
        fRunTree->SetBranchAddress("fRunInfo_fMaxNumOfChannels", &fRun->fMaxNumOfChannels);
        fRunTree->SetBranchAddress("fRunInfo_fLabels", &fRun->fLabels);
        fRunTree->SetBranchAddress("fRunInfo_fLabelsJoined", &fRun->fLabelsJoined);
        fRunTree->SetBranchAddress("fRunInfo_fStart", &fRun->fStart);
        fRunTree->SetBranchAddress("fRunInfo_fStop", &fRun->fStop);
        fRunTree->SetBranchAddress("fRunInfo_fAcquisition", &fRun->fAcquisition);
        fRunTree->SetBranchAddress("fRunInfo_fTriggerMode", &fRun->fTriggerMode);
        fRunTree->SetBranchAddress("fRunInfo_fDescription", &fRun->fDescription);

        fRunMatch = true;
      }
    } else
      fRunMatch = false;

    File::FillRunMap();
    if (fRunMatch)
      ReadRunInfo();

    if(fEventTree) {
      if (!fUseLegacyMode) {
        ; // address is set already
      } else {
        fEventTree->SetBranchAddress("fRunNumber", &fEvent->fRunNumber);
        fEventTree->SetBranchAddress("fEventNumber", &fEvent->fEventNumber);
        fEventTree->SetBranchAddress("fNumChannels", &fEvent->fNumChannels);
        fEventTree->SetBranchAddress("fNumWaveforms", &fEvent->fNumWaveforms);
        fEventTree->SetBranchAddress("fNumPulses", &fEvent->fNumPulses);
        fEventTree->SetBranchAddress("fNumClusters", &fEvent->fNumClusters);
        fEventTree->SetBranchAddress("fTriggerCount", &fEvent->fTriggerCount);
        fEventTree->SetBranchAddress("fTriggerTime_fSec", &fEvent->fTriggerTime_fSec);
        fEventTree->SetBranchAddress("fTriggerTime_fNanoSec", &fEvent->fTriggerTime_fNanoSec);
        fEventTree->SetBranchAddress("fTriggerSource", &fEvent->fTriggerSource);
        fEventTree->SetBranchAddress("fIsMonteCarloEvent", &fEvent->fIsMonteCarloEvent);
        fEventTree->SetBranchAddress("fTaggedAsMuon", &fEvent->fTaggedAsMuon);
        fEventTree->SetBranchAddress("fTaggedAsNoise", &fEvent->fTaggedAsNoise);
        fEventTree->SetBranchAddress("fHasSaturatedChannel", &fEvent->fHasSaturatedChannel);
        fEventTree->SetBranchAddress("fSkippedByClustering", &fEvent->fSkippedByClustering);

        fEventTree->SetBranchAddress("fWaveforms_fData",&(fEvent->fData));
        fEventTree->SetBranchAddress("fClusters_fPulsesArray",&fClusters->fPulsesArray);

        //      SetPulseBranchAddress();

        fEventMatch = true;
      }
    } else
      fEventMatch = false;

    if (fEventMatch && fRunMatch)
      return true;
    else
      return false;
  } else
    return false;


}
bool InputFile::ReOpen()
{
  Close();

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  return Open();
}
bool InputFile::Close()
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  if (IsOpen()) {

    if (fRun != 0) {
      delete fRun;
      fRun = 0;
    }


    if (fEvent != 0) {
      delete fEvent;
      fEvent = 0;
    }

    SetPulseArraySize(0);

    if (fPulses != 0) {
      delete fPulses;
      fPulses = 0;
    }

    if (fRunTree != 0) {
      delete fRunTree;
      fRunTree = 0;
    }

    if (fEventTree != 0) {
      delete fEventTree;
      fEventTree = 0;
    }

    fFile->Close();

    if (fFile != 0) {
      delete fFile;
      fFile = 0;
    }

    ClearRunMap();

    return true;
  } else
    return false;

}

bool InputFile::IsWritable() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return false;
}

bool InputFile::IsOpen() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  return (File::IsOpen() && fRunTree != 0 && fEventTree != 0) ? true : false;
//   return File::IsOpen();
}


/*void File::GetRunInfo(Event *event)
{
  event->fRunInfo = ;
}*/

void InputFile::SetFilename(const std::string& filename)
{
  if (IsOpen())
    Close();
  File::SetFilename(filename);
}

int InputFile::GetNumEntries() const
{
  if (IsOpen()) return fEventTree->GetEntries();
  else return 0;
}

int InputFile::GetRunNumber() const
{
  if (IsOpen()) return GetRunInfo().fRunNumber;
  else return 0;
}

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//////////////////////////////////////////////////////////////////////////

OutputFile::OutputFile() : File()
{
  fRunTree = 0;
  fEventTree = 0;
  fRunInfoCached = new RunInfo();

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

OutputFile::OutputFile(const char *filename) : File()
{
  fRunTree = 0;
  fEventTree = 0;
  fRunInfoCached = new RunInfo();
  File::SetFilename(std::string(filename));
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

}

OutputFile::OutputFile(const std::string &filename) : File()
{
  fRunTree = 0;
  fEventTree = 0;
  File::SetFilename(filename);
  fRunInfoCached = new RunInfo();
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

/*OutputFile::OutputFile(const OutputFile &that)
{
  SetFilename(that.GetFilename());
  fFile = that.fFile;
  fRunTree = that.fRunTree;
  fEventTree = that.fEventTree;
  fEvent = that.fEvent;
  fRun = that.fRun;
  fRecordCounter = that.fRecordCounter;
  fNumPulses = that.fNumPulses;
  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}*/



OutputFile::~OutputFile()
{
  delete fRunInfoCached;
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

void OutputFile::SetFilename(const std::string &filename)
{
  if (IsOpen()) Close();

  File::SetFilename(filename);

//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

bool OutputFile::Open()
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  if (!IsOpen()) {
    fFile = new TFile((GetFilename()).c_str(),"RECREATE");

    if (fFile->IsZombie()) return false;

    fEvent = new _Event();
    fPulses = new _Pulse();

    fRun = new _Run();
    fRun->fDAQ_ID = new std::string();
    fRun->fRunType = new std::string();
    fRun->fDescription = new std::string();
    fRun->fLabels = new std::vector<std::string>();
    fRun->fLabelsJoined = new std::string();

    fEvent->fData = new std::vector<std::vector<float> >();

    fClusters = new _Cluster();
    fClusters->fPulsesArray = new std::vector<std::vector<int> >();

    SetPulseArraySize(0);
    SetWaveformArraySize(0);
    SetClusterArraySize(0);

    fMaxNumOfChannels = 0;
    fMaxNumOfPulses = 0;
    fMaxNumOfClusters = 0;

    InitRunTree();
    InitEventTree();

    fFile->ls();
    return true;
  } else
    return false;

}

bool OutputFile::ReOpen()
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  if(IsOpen() && fFile->IsOpen()) {
    Close();
    Open();
    return true;
  } else
    return false;


}

bool OutputFile::Close()
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ <<" "<< fFile <<" "<< fEventTree <<" "<< fRunTree << endl;);

  if(File::IsOpen()) {
    fFile->cd();
    if (fEventTree != 0) fEventTree->Write();

    if (fRunTree != 0) fRunTree->Write();

    if (fEventTree != 0) {
      delete fEventTree;
      fEventTree = 0;
    }

    if (fRunTree != 0) {
      delete fRunTree;
      fRunTree = 0;
    }

    if (fEvent != 0) {
      delete fEvent;
      fEvent = 0;
    }

    if (fRun != 0) {
      delete fRun;
      fRun = 0;
    }

    SetPulseArraySize(0);

    if (fPulses != 0) {
      delete fPulses;
      fPulses = 0;
    }

    fFile->Write();
    fFile->ls();
    fFile->Close();

    if (fFile != 0) {
      delete fFile;
      fFile = 0;
    }

    return true;
  } else
    return false;
}

bool OutputFile::WriteEvent(const Event *event)
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
  if (IsOpen()) {

    if (fEvent != 0 && fEvent->fData != 0)
      fEvent->fData->clear();

    if (fClusters != 0 && fClusters->fPulsesArray != 0)
      fClusters->fPulsesArray->clear();

    if (!fUseLegacyMode) {
      fEventTree->SetBranchAddress(GetEventBranchName().c_str(), &event);
    } else {
      fEvent->fRunNumber = event->GetRunInfo()->fRunNumber;
      fEvent->fEventNumber = event->fEventNumber;
      fEvent->fTriggerCount = event->fTriggerCount;
      fEvent->fTriggerTime_fSec = event->fTriggerTime.GetSec();
      fEvent->fTriggerTime_fNanoSec = event->fTriggerTime.GetNanoSec();
      fEvent->fTriggerSource = event->fTriggerSource;
      fEvent->fIsMonteCarloEvent = event->fIsMonteCarloEvent;
      fEvent->fTaggedAsMuon = event->fTaggedAsMuon;
      fEvent->fTaggedAsNoise = event->fTaggedAsNoise;
      fEvent->fHasSaturatedChannel = event->fHasSaturatedChannel;
      fEvent->fSkippedByClustering = event->fSkippedByClustering;
      fEvent->fNumChannels = event->fNumChannels;
      fEvent->fNumWaveforms = event->GetNumWaveforms();


      if (fEvent->fNumWaveforms > fMaxNumOfChannels) {
        fMaxNumOfChannels = fEvent->fNumWaveforms;
        SetWaveformArraySize(fMaxNumOfChannels);
        SetWaveformBranchAddress();
      }

      fEvent->fData->resize(event->GetNumWaveforms());

      const Waveform *wf = 0;
      if(event->GetNumWaveforms()>0) {
        for (int i = 0; i < event->GetNumWaveforms(); i++) {

          wf = (event->GetWaveform(i));
          fEvent->fChannel[i] = wf->fChannel;
          fEvent->fIsCompressed[i] = wf->fIsCompressed;
          fEvent->fIsModified[i] = wf->fIsModified;
          fEvent->fNumSamples[i] = wf->fNumSamples;
          for (unsigned int j = 0; j < wf->fData.size(); j++)
            (*fEvent->fData)[i].push_back(wf->fData[j]);
          fEvent->fPeriod[i] = wf->fPeriod;
          fEvent->fDelay[i] = wf->fDelay;
          fEvent->fGain[i] = wf->fGain;
          fEvent->fOffset[i] = wf->fOffset;
          fEvent->fPlaceOfTrigger[i] = wf->fPlaceOfTrigger;
          fEvent->fBitWidth[i] = wf->fBitWidth;
          fEvent->fSignalMin[i] = wf->fSignalMin;
          fEvent->fSignalMax[i] = wf->fSignalMax;
          fEvent->fSignalBase[i] = wf->fSignalBase;
          fEvent->fSignalNoise[i] = wf->fSignalNoise;
          fEvent->fSignalSaturated[i] = wf->fSignalSaturated;

        }
      }

      fEvent->fNumPulses = event->GetNumPulses();

      if (fMaxNumOfPulses < fEvent->fNumPulses) {
        fMaxNumOfPulses = fEvent->fNumPulses;
        SetPulseArraySize(fMaxNumOfPulses);
        SetPulseBranchAddress();
      }

      for(int j = 0; j < event->GetNumPulses(); j++) {

        const Pulse* pulse = event->GetPulse(j);
        fPulses->fChannel[j] = pulse->fChannel;
        fPulses->fType[j] = pulse->fType;
        fPulses->fBaseline[j] = pulse->fBaseline;
        fPulses->fBaselineError[j] = pulse->fBaselineError;
        fPulses->fNoise[j] = pulse->fNoise;
        fPulses->fTime[j] = pulse->fTime;
        fPulses->fTimeError[j] = pulse->fTimeError;
        fPulses->fTau[j] = pulse->fTau;
        fPulses->fFirstSample[j] = pulse->fFirstSample;
        fPulses->fLastSample[j] = pulse->fLastSample;
        fPulses->fWidth10[j] = pulse->fWidth10;
        fPulses->fWidth50[j] = pulse->fWidth50;
        fPulses->fWidth90[j] = pulse->fWidth90;
        fPulses->fRisetime[j] = pulse->fRisetime;
        fPulses->fFalltime[j] = pulse->fFalltime;
        fPulses->fDecaytime[j] = pulse->fDecaytime;
        fPulses->fPeakTime[j] = pulse->fPeakTime;
        fPulses->fAmplitude[j] = pulse->fAmplitude;
        fPulses->fArea[j] = pulse->fArea;
        fPulses->fAreaEff[j] = pulse->fAreaEff;
        fPulses->fAreaDiff[j] = pulse->fAreaDiff;
        fPulses->fChiSquare[j] = pulse->fChiSquare;
        fPulses->fSaturated[j] = pulse->fSaturated;
        fPulses->fOverlayed[j] = pulse->fOverlayed;
        fPulses->fPartial[j] = pulse->fPartial;
      }

      fEvent->fNumClusters = event->GetNumClusters();

      if (fMaxNumOfClusters < fEvent->fNumClusters) {
        fMaxNumOfClusters = fEvent->fNumClusters;
        SetClusterArraySize(fMaxNumOfClusters);
        SetClusterBranchAddress();
      }

      int UsedPulses[fEvent->fNumPulses];
      for (int i = 0; i < event->GetNumPulses(); i++)
        UsedPulses[i] = 0;

      fClusters->fPulsesArray->resize(fEvent->fNumClusters);

      for (int k = 0; k < event->GetNumClusters(); k++) {
        const Cluster* cluster = event->GetCluster(k);
        fClusters->fType[k] = cluster->fType;
        fClusters->fTime[k] = cluster->fTime;
        fClusters->fWidth[k] = cluster->fWidth;
        fClusters->fSaturated[k] = cluster->fSaturated;
        fClusters->fPeakChannel[k] = cluster->fPeakChannel;
        fClusters->fAmplitude[k] = cluster->fAmplitude;
        fClusters->fArea[k] = cluster->fArea;
        fClusters->fAreaEff[k] = cluster->fAreaEff;
        fClusters->fAreaDiff[k] = cluster->fAreaDiff;
        fClusters->fNumSPE[k] = cluster->fNumSPE;
        fClusters->fNumPMTTop[k] = cluster->fNumPMTTop;
        fClusters->fNumPMTBottom[k] = cluster->fNumPMTBottom;

        fClusters->fX[k] = cluster->fX;
        fClusters->fY[k] = cluster->fY;
        fClusters->fZ[k] = cluster->fZ;
        fClusters->fDriftTime[k] = cluster->fDriftTime;

        fClusters->fRawEnergy[k] = cluster->fRawEnergy;
        fClusters->fRawEnergyError[k] = cluster->fRawEnergyError;
        fClusters->fCorrectedEnergy[k] = cluster->fCorrectedEnergy;
        fClusters->fCorrectedEnergyError[k] = cluster->fCorrectedEnergyError;


        for (int i = 0; i < cluster->GetNumPulses(); i++) {
          const Pulse* ClusterPulse = cluster->GetPulse(i);
          for (int j = 0; j < event->GetNumPulses(); j++) {
            if (UsedPulses[j] == 0) {
              const Pulse* EventPulse = event->GetPulse(j);
              if (*EventPulse == *ClusterPulse) {
                (*fClusters->fPulsesArray)[k].push_back(j);
                UsedPulses[j] = 1;
                break;
              }
            }
          }
        }
      }
    }

    fEventTree->Fill();

    return true;
  } else
    return false;

}
void OutputFile::AddRunInfo(const RunInfo* RunInfo)
{
  if (RunInfo->fNumChannels > fMaxNumOfChannels)
    fMaxNumOfChannels = RunInfo->fNumChannels;

  if (!fUseLegacyMode) {
    fRunTree->SetBranchAddress(GetRunBranchName().c_str(), &RunInfo);
  } else {
    fRun->fLabels->clear();
    fRun->fLabelsJoined->clear();

    fRun->fRunNumber = RunInfo->fRunNumber;
    fRun->fNumEvents = RunInfo->fNumEvents;
    *(fRun->fRunType) = RunInfo->fRunType;
    *(fRun->fDAQ_ID) = RunInfo->fDAQ_ID;
    fRun->fActualNumOfChannels = RunInfo->fNumChannels;
    fRun->fMaxNumOfChannels = fMaxNumOfChannels;
    fRun->fStart = RunInfo->fStart;
    fRun->fStop = RunInfo->fStop;
    fRun->fAcquisition = RunInfo->fAcquisition;
    fRun->fTriggerMode = RunInfo->fTriggerMode;
    fRun->fFirstRecord = RunInfo->fFirstRecord; // FIXME
    *(fRun->fDescription) = (RunInfo->fDescription);

    for (unsigned int label = 0; label < RunInfo->fLabels.size(); label++)
      fRun->fLabels->push_back(RunInfo->fLabels[label]);

    for(unsigned int i = 0; i < RunInfo->fLabels.size(); i++) {
      *(fRun->fLabelsJoined) += RunInfo->fLabels[i];
      *(fRun->fLabelsJoined) += "; ";
    }
  }

  fRunTree->Fill();
  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}

bool OutputFile::IsOpen() const
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);

  return (File::IsOpen() && fEventTree != 0) ? true : false;
}


void OutputFile::SetProcessingInfo(const ProcessingInfo&)
{
//  DEBUG(0,cout << __PRETTY_FUNCTION__ << endl;);
}


void OutputFile::InitRunTree()
{
  fFile->cd(); // FIXME
  fRunTree = new TTree(File::GetRunTreeName().c_str(),File::GetRunTreeDescription().c_str());

  if (!fUseLegacyMode) {
    RunInfo *info = nullptr;
    fRunTree->Branch(GetRunBranchName().c_str(),&info);
  } else {
    fRunTree->Branch("fRunInfo_fRunNumber", &fRun->fRunNumber, "fRunInfo_fRunNumber/I");
    fRunTree->Branch("fRunInfo_fNumEvents", &fRun->fNumEvents,"fRunInfo_fNumEvents/I");
    fRunTree->Branch("fRunInfo_fRunType", &fRun->fRunType);
    fRunTree->Branch("fRunInfo_fDAQ_ID", &fRun->fDAQ_ID);
    fRunTree->Branch("fRunInfo_fActualNumOfChannels", &fRun->fActualNumOfChannels);
    fRunTree->Branch("fRunInfo_fMaxNumOfChannels", &fRun->fMaxNumOfChannels);
    fRunTree->Branch("fRunInfo_fLabels", &fRun->fLabels);
    fRunTree->Branch("fRunInfo_fLabelsJoined", &fRun->fLabelsJoined);
    fRunTree->Branch("fRunInfo_fStart",&(fRun->fStart),"fRunInfo_fStart/i");
    fRunTree->Branch("fRunInfo_fStop",&fRun->fStop,"fRunInfo_fStop/i");
    fRunTree->Branch("fRunInfo_fAcquisition", &fRun->fAcquisition,"fRunInfo_fAcquisition/i");
    fRunTree->Branch("fRunInfo_fTriggerMode", &fRun->fTriggerMode,"fRunInfo_fTriggerMode/I");
    fRunTree->Branch("fRunInfo_fFirstRecord", &fRun->fFirstRecord, "fRunInfo_fFirstRecord/I");
    fRunTree->Branch("fRunInfo_fDescription", &fRun->fDescription);
  }
  fRunTree->BranchRef();
}


//___________________Added_Methods____________________
//


void OutputFile::InitEventTree()
{

  RunInfo RunInfo = File::GetRunInfo();

  fFile->cd(); // FIXME

  fEventTree = new TTree(File::GetEventTreeName().c_str(),File::GetEventTreeDescription().c_str());

  if (!fUseLegacyMode) {
    Event *event = nullptr;
    fEventTree->Branch(GetEventBranchName().c_str(), &event);
  } else {
    fEventTree->Branch("fRunNumber", &fEvent->fRunNumber, "fRunNumber/I");
    fEventTree->Branch("fEventNumber", &fEvent->fEventNumber, "fEventNumber/I");
    fEventTree->Branch("fNumChannels",&fEvent->fNumChannels,"fNumChannels/I");
    fEventTree->Branch("fTriggerCount", &fEvent->fTriggerCount, "fTriggerCount/I");
    fEventTree->Branch("fTriggerTime_fSec", &fEvent->fTriggerTime_fSec, "fTriggerTime_fSec/i");
    fEventTree->Branch("fTriggerTime_fNanoSec", &fEvent->fTriggerTime_fNanoSec, "fTriggerTime_fNanoSec/i");
    fEventTree->Branch("fTriggerSource", &fEvent->fTriggerSource, "fTriggerSource/i");
    fEventTree->Branch("fIsMonteCarloEvent", &fEvent->fIsMonteCarloEvent, "fIsMonteCarloEvent/O");
    fEventTree->Branch("fTaggedAsMuon", &fEvent->fTaggedAsMuon, "fTaggedAsMuon/O");
    fEventTree->Branch("fTaggedAsNoise", &fEvent->fTaggedAsNoise, "fTaggedAsNoise/O");
    fEventTree->Branch("fHasSaturatedChannel", &fEvent->fHasSaturatedChannel, "fHasSaturatedChannel/O");
    fEventTree->Branch("fSkippedByClustering", &fEvent->fSkippedByClustering, "fSkippedByClustering/O");

    fEventTree->Branch("fNumWaveforms", &fEvent->fNumWaveforms, "fNumWaveforms/I");
    fEventTree->Branch("fWaveforms_fChannel",fEvent->fChannel,"fWaveforms_fChannel[fNumWaveforms]/I");
    fEventTree->Branch("fWaveforms_fIsCompressed",fEvent->fIsCompressed,"fWaveforms_fIsCompressed[fNumWaveforms]/O");
    fEventTree->Branch("fWaveforms_fIsModified",fEvent->fIsModified,"fWaveforms_fIsModified[fNumWaveforms]/I");
    fEventTree->Branch("fWaveforms_fNumSamples",fEvent->fNumSamples,"fWaveforms_fNumSamples[fNumWaveforms]/I");
    fEventTree->Branch("fWaveforms_fPeriod",fEvent->fPeriod,"fWaveforms_fPeriod[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fDelay",fEvent->fDelay,"fWaveforms_fDelay[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fGain",fEvent->fGain,"fWaveforms_fGain[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fOffset",fEvent->fOffset,"fWaveforms_fOffset[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fTriggerPlace",fEvent->fPlaceOfTrigger,"fWaveforms_fTriggerPlace[fNumWaveforms]/I");
    fEventTree->Branch("fWaveforms_fBitWidth",fEvent->fBitWidth,"fWaveforms_fBitWidth[fNumWaveforms]/I");
    fEventTree->Branch("fWaveforms_fSignalMin",fEvent->fSignalMin,"fWaveforms_fSignalMin[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fSignalMax",fEvent->fSignalMax,"fWaveforms_fSignalMax[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fSignalBase",fEvent->fSignalBase,"fWaveforms_fSignalBase[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fSignalNoise",fEvent->fSignalNoise,"fWaveforms_fSignalNoise[fNumWaveforms]/D");
    fEventTree->Branch("fWaveforms_fSignalSaturated",fEvent->fSignalSaturated,"fWaveforms_fSignalSaturated[fNumWaveforms]/O");
    fEventTree->Branch("fWaveforms_fData",&fEvent->fData);

    fEventTree->Branch("fNumPulses",&fEvent->fNumPulses,"fNumPulses/I");
    fEventTree->Branch("fPulses_fChannel",fPulses->fChannel,"fPulses_fChannel[fNumPulses]/I");
    fEventTree->Branch("fPulses_fType",fPulses->fType,"fPulses_fType[fNumPulses]/I");
    fEventTree->Branch("fPulses_fBaseline",fPulses->fBaseline,"fPulses_fBaseline[fNumPulses]/D");
    fEventTree->Branch("fPulses_fBaselineError",fPulses->fBaselineError,"fPulses_fBaselineError[fNumPulses]/D");
    fEventTree->Branch("fPulses_fNoise",fPulses->fNoise,"fPulses_fNoise[fNumPulses]/D");
    fEventTree->Branch("fPulses_fTime",fPulses->fTime,"fPulses_fTime[fNumPulses]/D");
    fEventTree->Branch("fPulses_fTimeError",fPulses->fTimeError,"fPulses_fTimeError[fNumPulses]/D");
    fEventTree->Branch("fPulses_fTau",fPulses->fTau,"fPulses_fTau[fNumPulses]/D");
    fEventTree->Branch("fPulses_fFirstSample",fPulses->fFirstSample,"fPulses_fFirstSample[fNumPulses]/I");
    fEventTree->Branch("fPulses_fLastSample",fPulses->fLastSample,"fPulses_fLastSample[fNumPulses]/I");
    fEventTree->Branch("fPulses_fWidth10",fPulses->fWidth10,"fPulses_fWidth10[fNumPulses]/D");
    fEventTree->Branch("fPulses_fWidth50",fPulses->fWidth50,"fPulses_fWidth50[fNumPulses]/D");
    fEventTree->Branch("fPulses_fWidth90",fPulses->fWidth90,"fPulses_fWidth90[fNumPulses]/D");
    fEventTree->Branch("fPulses_fRisetime",fPulses->fRisetime,"fPulses_fRisetime[fNumPulses]/D");
    fEventTree->Branch("fPulses_fFalltime",fPulses->fFalltime,"fPulses_fFalltime[fNumPulses]/D");
    fEventTree->Branch("fPulses_fDecaytime",fPulses->fDecaytime,"fPulses_fDecaytime[fNumPulses]/D");
    fEventTree->Branch("fPulses_fPeakTime",fPulses->fPeakTime,"fPulses_fPeakTime[fNumPulses]/D");
    fEventTree->Branch("fPulses_fAmplitude",fPulses->fAmplitude,"fPulses_fAmplitude[fNumPulses]/D");
    fEventTree->Branch("fPulses_fArea",fPulses->fArea,"fPulses_fArea[fNumPulses]/D");
    fEventTree->Branch("fPulses_fAreaEff",fPulses->fAreaEff,"fPulses_fAreaEff[fNumPulses]/D");
    fEventTree->Branch("fPulses_fAreaDiff",fPulses->fAreaDiff,"fPulses_fAreaDiff[fNumPulses]/D");
    fEventTree->Branch("fPulses_fChiSquare",fPulses->fChiSquare,"fPulses_fChiSquare[fNumPulses]/D");
    fEventTree->Branch("fPulses_fSaturated",fPulses->fSaturated,"fPulses_fSaturated[fNumPulses]/I");
    fEventTree->Branch("fPulses_fOverlayed",fPulses->fOverlayed,"fPulses_fOverlayed[fNumPulses]/O");
    fEventTree->Branch("fPulses_fPartial",fPulses->fPartial,"fPulses_fPartial[fNumPulses]/O");

    fEventTree->Branch("fNumClusters", &fEvent->fNumClusters, "fNumClusters/I");
    fEventTree->Branch("fClusters_fType", fClusters->fType, "fClusters_fType[fNumClusters]/I");
    fEventTree->Branch("fClusters_fTime", fClusters->fTime, "fClusters_fTime[fNumClusters]/D");
    fEventTree->Branch("fClusters_fWidth", fClusters->fWidth, "fClusters_fWidth[fNumClusters]/D");
    fEventTree->Branch("fClusters_fSaturated", fClusters->fSaturated, "fClusters_fSaturated[fNumClusters]/I");
    fEventTree->Branch("fClusters_fPeakChannel", fClusters->fPeakChannel, "fClusters_fPeakChannel[fNumClusters]/I");
    fEventTree->Branch("fClusters_fAmplitude", fClusters->fAmplitude, "fClusters_fAmplitude[fNumClusters]/D");
    fEventTree->Branch("fClusters_fArea", fClusters->fArea, "fClusters_fArea[fNumClusters]/D");
    fEventTree->Branch("fClusters_fAreaEff", fClusters->fAreaEff, "fClusters_fAreaEff[fNumClusters]/D");
    fEventTree->Branch("fClusters_fAreaDiff", fClusters->fAreaDiff, "fClusters_fAreaDiff[fNumClusters]/D");
    fEventTree->Branch("fClusters_fNumSPE", fClusters->fNumSPE, "fClusters_fNumSPE[fNumClusters]/I");
    fEventTree->Branch("fClusters_fNumPMTTop", fClusters->fNumPMTTop, "fClusters_fNumPMTTop[fNumClusters]/I");
    fEventTree->Branch("fClusters_fNumPMTBottom", fClusters->fNumPMTBottom, "fClusters_fNumPMTBottom[fNumClusters]/I");
    fEventTree->Branch("fClusters_fX", fClusters->fX, "fClusters_fX[fNumClusters]/D");
    fEventTree->Branch("fClusters_fY", fClusters->fY, "fClusters_fY[fNumClusters]/D");
    fEventTree->Branch("fClusters_fZ", fClusters->fZ, "fClusters_fZ[fNumClusters]/D");
    fEventTree->Branch("fClusters_fDriftTime", fClusters->fDriftTime, "fClusters_fDriftTime[fNumClusters]/D");
    fEventTree->Branch("fClusters_fRawEnergy", fClusters->fRawEnergy, "fClusters_fRawEnergy[fNumClusters]/D");
    fEventTree->Branch("fClusters_fRawEnergyError", fClusters->fRawEnergyError, "fClusters_fRawEnergyError[fNumClusters]/D");
    fEventTree->Branch("fClusters_fCorrectedEnergy", fClusters->fCorrectedEnergy, "fClusters_fCorrectedEnergy[fNumClusters]/D");
    fEventTree->Branch("fClusters_fCorrectedEnergyError", fClusters->fCorrectedEnergyError, "fClusters_fCorrectedEnergyError[fNumClusters]/D");
    fEventTree->Branch("fClusters_fPulsesArray", &fClusters->fPulsesArray);

    SetWaveformBranchAddress();
    SetPulseBranchAddress();
    SetClusterBranchAddress();
  }
  fEventTree->BranchRef();
}

void File::SetWaveformArraySize(int size)
{

  fEvent->fChannel =  SetArraySize(fEvent->fChannel, size);
  fEvent->fIsCompressed =  SetArraySize(fEvent->fIsCompressed, size);
  fEvent->fIsModified =  SetArraySize(fEvent->fIsModified, size);
  fEvent->fNumSamples =  SetArraySize(fEvent->fNumSamples, size);
  fEvent->fPeriod =  SetArraySize(fEvent->fPeriod, size);
  fEvent->fDelay =  SetArraySize(fEvent->fDelay, size);
  fEvent->fGain =  SetArraySize(fEvent->fGain, size);
  fEvent->fOffset =  SetArraySize(fEvent->fOffset, size);
  fEvent->fPlaceOfTrigger =  SetArraySize(fEvent->fPlaceOfTrigger, size);
  fEvent->fBitWidth =  SetArraySize(fEvent->fBitWidth, size);
  fEvent->fSignalMin =  SetArraySize(fEvent->fSignalMin, size);
  fEvent->fSignalMax =  SetArraySize(fEvent->fSignalMax, size);
  fEvent->fSignalBase =  SetArraySize(fEvent->fSignalBase, size);
  fEvent->fSignalNoise =  SetArraySize(fEvent->fSignalNoise, size);
  fEvent->fSignalSaturated =  SetArraySize(fEvent->fSignalSaturated, size);
}

void File::SetPulseArraySize(int size)
{
  fPulses->fChannel = SetArraySize(fPulses->fChannel, size);
  fPulses->fType = SetArraySize(fPulses->fType, size);
  fPulses->fBaseline = SetArraySize(fPulses->fBaseline, size);
  fPulses->fBaselineError = SetArraySize(fPulses->fBaselineError, size);
  fPulses->fNoise = SetArraySize(fPulses->fNoise, size);
  fPulses->fTime = SetArraySize(fPulses->fTime, size);
  fPulses->fTimeError = SetArraySize(fPulses->fTimeError, size);
  fPulses->fTau = SetArraySize(fPulses->fTau, size);
  fPulses->fFirstSample = SetArraySize(fPulses->fFirstSample, size);
  fPulses->fLastSample = SetArraySize(fPulses->fLastSample, size);
  fPulses->fWidth10 = SetArraySize(fPulses->fWidth10, size);
  fPulses->fWidth50 = SetArraySize(fPulses->fWidth50, size);
  fPulses->fWidth90 = SetArraySize(fPulses->fWidth90, size);
  fPulses->fRisetime = SetArraySize(fPulses->fRisetime, size);
  fPulses->fFalltime = SetArraySize(fPulses->fFalltime, size);
  fPulses->fDecaytime = SetArraySize(fPulses->fDecaytime, size);
  fPulses->fAmplitude = SetArraySize(fPulses->fAmplitude, size);
  fPulses->fPeakTime = SetArraySize(fPulses->fPeakTime, size);
  fPulses->fArea = SetArraySize(fPulses->fArea, size);
  fPulses->fAreaEff = SetArraySize(fPulses->fAreaEff, size);
  fPulses->fAreaDiff = SetArraySize(fPulses->fAreaDiff, size);
  fPulses->fChiSquare = SetArraySize(fPulses->fChiSquare, size);
  fPulses->fSaturated = SetArraySize(fPulses->fSaturated, size);
  fPulses->fOverlayed = SetArraySize(fPulses->fOverlayed, size);
  fPulses->fPartial = SetArraySize(fPulses->fPartial, size);

}

void File::SetClusterArraySize(int size)
{
  fClusters->fType = SetArraySize(fClusters->fType, size);
  fClusters->fTime = SetArraySize(fClusters->fTime, size);
  fClusters->fWidth = SetArraySize(fClusters->fWidth, size);
  fClusters->fSaturated = SetArraySize(fClusters->fSaturated, size);
  fClusters->fPeakChannel = SetArraySize(fClusters->fPeakChannel, size);
  fClusters->fAmplitude = SetArraySize(fClusters->fAmplitude, size);
  fClusters->fArea = SetArraySize(fClusters->fArea, size);
  fClusters->fAreaEff = SetArraySize(fClusters->fAreaEff, size);
  fClusters->fAreaDiff = SetArraySize(fClusters->fAreaDiff, size);
  fClusters->fNumSPE = SetArraySize(fClusters->fNumSPE, size);
  fClusters->fNumPMTTop = SetArraySize(fClusters->fNumPMTTop, size);
  fClusters->fNumPMTBottom = SetArraySize(fClusters->fNumPMTBottom, size);
  fClusters->fX = SetArraySize(fClusters->fX, size);
  fClusters->fY = SetArraySize(fClusters->fY, size);
  fClusters->fZ = SetArraySize(fClusters->fZ, size);
  fClusters->fDriftTime = SetArraySize(fClusters->fDriftTime, size);
  fClusters->fRawEnergy = SetArraySize(fClusters->fRawEnergy, size);
  fClusters->fRawEnergyError = SetArraySize(fClusters->fRawEnergyError, size);
  fClusters->fCorrectedEnergy = SetArraySize(fClusters->fCorrectedEnergy, size);
  fClusters->fCorrectedEnergyError = SetArraySize(fClusters->fCorrectedEnergyError, size);
}

void File::SetWaveformBranchAddress()
{
  fEventTree->SetBranchAddress("fWaveforms_fChannel",fEvent->fChannel);
  fEventTree->SetBranchAddress("fWaveforms_fIsCompressed",fEvent->fIsCompressed);
  fEventTree->SetBranchAddress("fWaveforms_fIsModified",fEvent->fIsModified);
  fEventTree->SetBranchAddress("fWaveforms_fNumSamples",fEvent->fNumSamples);
  fEventTree->SetBranchAddress("fWaveforms_fPeriod",fEvent->fPeriod);
  fEventTree->SetBranchAddress("fWaveforms_fDelay",fEvent->fDelay);
  fEventTree->SetBranchAddress("fWaveforms_fGain",fEvent->fGain);
  fEventTree->SetBranchAddress("fWaveforms_fOffset",fEvent->fOffset);
  fEventTree->SetBranchAddress("fWaveforms_fTriggerPlace",fEvent->fPlaceOfTrigger);
  fEventTree->SetBranchAddress("fWaveforms_fBitWidth",fEvent->fBitWidth);
  fEventTree->SetBranchAddress("fWaveforms_fSignalMin",fEvent->fSignalMin);
  fEventTree->SetBranchAddress("fWaveforms_fSignalMax",fEvent->fSignalMax);
  fEventTree->SetBranchAddress("fWaveforms_fSignalBase",fEvent->fSignalBase);
  fEventTree->SetBranchAddress("fWaveforms_fSignalNoise",fEvent->fSignalNoise);
  fEventTree->SetBranchAddress("fWaveforms_fSignalSaturated",fEvent->fSignalSaturated);
}

void File::SetPulseBranchAddress()
{
  fEventTree->SetBranchAddress("fPulses_fChannel", fPulses->fChannel);
  fEventTree->SetBranchAddress("fPulses_fType", fPulses->fType);
  fEventTree->SetBranchAddress("fPulses_fBaseline", fPulses->fBaseline);
  fEventTree->SetBranchAddress("fPulses_fBaselineError", fPulses->fBaselineError);
  fEventTree->SetBranchAddress("fPulses_fNoise", fPulses->fNoise);
  fEventTree->SetBranchAddress("fPulses_fTime", fPulses->fTime);
  fEventTree->SetBranchAddress("fPulses_fTimeError", fPulses->fTimeError);
  fEventTree->SetBranchAddress("fPulses_fTau", fPulses->fTau);
  fEventTree->SetBranchAddress("fPulses_fFirstSample", fPulses->fFirstSample);
  fEventTree->SetBranchAddress("fPulses_fLastSample", fPulses->fLastSample);
  fEventTree->SetBranchAddress("fPulses_fWidth10", fPulses->fWidth10);
  fEventTree->SetBranchAddress("fPulses_fWidth50", fPulses->fWidth50);
  fEventTree->SetBranchAddress("fPulses_fWidth90", fPulses->fWidth90);
  fEventTree->SetBranchAddress("fPulses_fRisetime", fPulses->fRisetime);
  fEventTree->SetBranchAddress("fPulses_fFalltime", fPulses->fFalltime);
  fEventTree->SetBranchAddress("fPulses_fDecaytime", fPulses->fDecaytime);
  fEventTree->SetBranchAddress("fPulses_fAmplitude", fPulses->fAmplitude);
  fEventTree->SetBranchAddress("fPulses_fPeakTime", fPulses->fPeakTime);
  fEventTree->SetBranchAddress("fPulses_fArea", fPulses->fArea);
  fEventTree->SetBranchAddress("fPulses_fAreaEff", fPulses->fAreaEff);
  fEventTree->SetBranchAddress("fPulses_fAreaDiff", fPulses->fAreaDiff);
  fEventTree->SetBranchAddress("fPulses_fChiSquare", fPulses->fChiSquare);
  fEventTree->SetBranchAddress("fPulses_fSaturated", fPulses->fSaturated);
  fEventTree->SetBranchAddress("fPulses_fOverlayed", fPulses->fOverlayed);
  fEventTree->SetBranchAddress("fPulses_fPartial", fPulses->fPartial);
}

void File::SetClusterBranchAddress()
{
  fEventTree->SetBranchAddress("fClusters_fType", fClusters->fType);
  fEventTree->SetBranchAddress("fClusters_fTime", fClusters->fTime);
  fEventTree->SetBranchAddress("fClusters_fWidth", fClusters->fWidth);
  fEventTree->SetBranchAddress("fClusters_fSaturated", fClusters->fSaturated);
  fEventTree->SetBranchAddress("fClusters_fPeakChannel", fClusters->fPeakChannel);
  fEventTree->SetBranchAddress("fClusters_fAmplitude", fClusters->fAmplitude);
  fEventTree->SetBranchAddress("fClusters_fArea", fClusters->fArea);
  fEventTree->SetBranchAddress("fClusters_fAreaEff", fClusters->fAreaEff);
  fEventTree->SetBranchAddress("fClusters_fAreaDiff", fClusters->fAreaDiff);
  fEventTree->SetBranchAddress("fClusters_fNumSPE", fClusters->fNumSPE);
  fEventTree->SetBranchAddress("fClusters_fNumPMTTop", fClusters->fNumPMTTop);
  fEventTree->SetBranchAddress("fClusters_fNumPMTBottom", fClusters->fNumPMTBottom);
  fEventTree->SetBranchAddress("fClusters_fX", fClusters->fX);
  fEventTree->SetBranchAddress("fClusters_fY", fClusters->fY);
  fEventTree->SetBranchAddress("fClusters_fZ", fClusters->fZ);
  fEventTree->SetBranchAddress("fClusters_fDriftTime", fClusters->fDriftTime);
  fEventTree->SetBranchAddress("fClusters_fRawEnergy", fClusters->fRawEnergy);
  fEventTree->SetBranchAddress("fClusters_fRawEnergyError", fClusters->fRawEnergyError);
  fEventTree->SetBranchAddress("fClusters_fCorrectedEnergy", fClusters->fCorrectedEnergy);
  fEventTree->SetBranchAddress("fClusters_fCorrectedEnergyError", fClusters->fCorrectedEnergyError);
}
