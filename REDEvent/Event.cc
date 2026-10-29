#include <iostream>
#include <iomanip>

#include "REDEvent/Event.hh"
#include "REDEvent/Waveform.hh"
#include "REDEvent/RunInfo.hh"

using namespace RED;

const int DEFAULT_NUM_WAVEFORMS = 40;
const int DEFAULT_NUM_PULSES    = 100;
const int DEFAULT_NUM_CLUSTERS  = 100;

Event::Event() :
  fRunInfo(0), fProcInfo(0), fWaveforms(0), fPulses(0), fClusters(0)
{
  fRunNumber = 0;
  fEventNumber = 0;
  fNumChannels = 0;
  fTriggerCount = 0;
  fTriggerTime.SetSec(0);
  fTriggerTime.SetNanoSec(0);
  fIsMonteCarloEvent = false;
  fTaggedAsMuon = false;
  fTaggedAsNoise = false;
  fHasSaturatedChannel = false;
  fSkippedByClustering = false;
  //Event::Clear();

  fWaveforms = new TClonesArray(Waveform::Class(),DEFAULT_NUM_WAVEFORMS);
  fPulses = new TClonesArray(Pulse::Class(),DEFAULT_NUM_PULSES);
  fClusters = new TClonesArray(Cluster::Class(),DEFAULT_NUM_CLUSTERS);

  std::cout << __PRETTY_FUNCTION__ <<" "<< this << std::endl;
}

Event::Event(const Event& that)
{
  fRunNumber = that.fRunNumber;
  fEventNumber = that.fEventNumber;
  fTriggerCount = that.fTriggerCount;
  fTriggerTime = that.fTriggerTime;
  fIsMonteCarloEvent = that.fIsMonteCarloEvent;
  fTaggedAsMuon = that.fTaggedAsMuon;
  fTaggedAsNoise = that.fTaggedAsNoise;
  fHasSaturatedChannel = that.fHasSaturatedChannel;
  fSkippedByClustering = that.fSkippedByClustering;

  fProcInfo = that.fProcInfo;
  fWaveforms = that.fWaveforms;
  fPulses = that.fPulses;
  fClusters = that.fClusters;

  std::cout << __PRETTY_FUNCTION__ <<" "<< this << std::endl;
}

Event::~Event()
{
  std::cout << __PRETTY_FUNCTION__ <<" "<< this << std::endl;

  delete fWaveforms;
  delete fPulses;
  delete fClusters;
}

Event& Event::operator=( const Event& that)
{
  if (this == &that)
    return *this;
  else {
    fRunNumber = that.fRunNumber;
    fEventNumber = that.fEventNumber;
    fNumChannels = that.fNumChannels;
    fTriggerCount = that.fTriggerCount;
    fTriggerTime = that.fTriggerTime;
    fIsMonteCarloEvent = that.fIsMonteCarloEvent;
    fTaggedAsMuon = that.fTaggedAsMuon;
    fTaggedAsNoise = that.fTaggedAsNoise;
    fHasSaturatedChannel = that.fHasSaturatedChannel;
    fSkippedByClustering = that.fSkippedByClustering;

    fProcInfo = that.fProcInfo;
    fWaveforms = that.fWaveforms;
    fPulses = that.fPulses;
    fClusters = that.fClusters;

    return *this;
  }
}

bool Event::operator==(const Event& ev) const
{
  if ( fRunNumber == ev.fRunNumber &&
       fEventNumber == ev.fEventNumber &&
       fNumChannels == ev.fNumChannels &&
       fTriggerCount == ev.fTriggerCount &&
       fTriggerTime.GetSec() == ev.fTriggerTime.GetSec() &&
       fTriggerTime.GetNanoSec() == ev.fTriggerTime.GetNanoSec() &&
       fIsMonteCarloEvent == ev.fIsMonteCarloEvent &&
       fTaggedAsMuon == ev.fTaggedAsMuon &&
       fTaggedAsNoise == ev.fTaggedAsNoise &&
       fHasSaturatedChannel == ev.fHasSaturatedChannel &&
       fSkippedByClustering == ev.fSkippedByClustering &&
       fProcInfo == ev.fProcInfo &&
       fWaveforms == ev.fWaveforms &&
       fPulses == ev.fPulses &&
       fClusters == ev.fClusters)

    return true;
  else
    return false;

}

void Event::Print( Option_t* option) const
{
  std::ostream &os = std::cout;
  const Event &ev = *this;
  const char *prefix = "  ", *postfix = ",\n";
  os << "{\n"
     << prefix << ".fRunInfo = " << ev.fRunInfo.GetObject() << postfix
     << prefix << ".fRunNumber = " << ev.fRunNumber << postfix
     << prefix << ".fNumChannels = " << ev.fNumChannels << postfix
     << prefix << ".fEventNumber = " << ev.fEventNumber << postfix
     << prefix << ".fTriggerCount = " << ev.fTriggerCount << postfix
     << prefix << ".fTriggerTime = '" << ev.fTriggerTime.AsString("c") <<"'"<< postfix
     << prefix << ".fTriggerSource = " << ev.fTriggerSource << postfix
     << prefix << ".fIsMonteCarloEvent = " << ev.fIsMonteCarloEvent << postfix
     << prefix << ".fTaggedAsMuon = " << ev.fTaggedAsMuon << postfix
     << prefix << ".fTaggedAsNoise = " << ev.fTaggedAsNoise << postfix
     << prefix << ".fHasSaturatedChannel = " << ev.fHasSaturatedChannel << postfix
     << prefix << ".fSkippedByClustering = " << ev.fSkippedByClustering << postfix
     << prefix << ".fProcInfo = " << ev.fProcInfo << postfix
     //<< prefix << ".fChanMap = " << ev.fChanMap << postfix
     << prefix << ".fWaveforms[" << ev.GetNumWaveforms() << "] = " << ev.fWaveforms << postfix
     << prefix << ".fPulses[" << ev.GetNumPulses() << "] = " << ev.fPulses << postfix
     << prefix << ".fClusters[" << ev.GetNumClusters() << "] = " << ev.fClusters << postfix
     << "}" << std::endl;
}

void Event::Clear( Option_t* option)
{
  //std::cout << __PRETTY_FUNCTION__ <<" "<< this << std::endl;
  fWaveforms->Clear("C");
  fPulses->Clear("C");
  fClusters->Clear("C");
}

const RunInfo* Event::GetRunInfo() const
{
  return static_cast<const RunInfo*>(fRunInfo.GetObject());
}

RunInfo* Event::GetRunInfo()
{
  TObject *info_obj = fRunInfo.GetObject();
  RunInfo *info = nullptr;
  if (info_obj && info_obj->InheritsFrom(RED::RunInfo::Class())) {
    info = dynamic_cast<RunInfo*>(info_obj);
  } else {
    info = new RunInfo();
    fRunInfo = static_cast<TObject*>(info);
  }
  return info;
}

void Event::SetRunInfo(const RunInfo& runInfo)
{
  RunInfo *info = GetRunInfo();
  *info = runInfo;
}

void Event::SetRunInfo(const RunInfo* runInfo)
{
  RunInfo *info = GetRunInfo();
  *info = *runInfo;
}

void Event::ResetRunInfo()
{
  RunInfo* info = GetRunInfo();
  if (info && info->InheritsFrom(RED::RunInfo::Class())) {
    info->ResetBit(kIsReferenced);
    info->ResetBit(kCanDelete);
    delete info;
    info = 0;
  }
  info = new RunInfo();
  fRunInfo = static_cast<TObject*>(info);
}
