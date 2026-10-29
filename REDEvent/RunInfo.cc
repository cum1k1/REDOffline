
#include <iomanip>  //for setw
#include <iostream> //for I/O


#include "REDEvent/RunInfo.hh"

using namespace RED;

RunInfo::RunInfo():
  fRunNumber(0), fStart(0), fStop(0),
  fAcquisition(0), fNumChannels(0),
  fTriggerMode(0), fNumEvents(0),
  fFirstRecord(0)
{
  fDAQ_ID.clear();
  fRunType.clear();
  fLabels.clear();
  fDescription.clear();
  //RunInfo::Clear();
}

RunInfo::RunInfo( const RunInfo& m_info)
{
  fRunNumber = m_info.fRunNumber;
  fStart = m_info.fStart;
  fStop = m_info.fStop;
  fAcquisition = m_info.fAcquisition;
  fNumChannels = m_info.fNumChannels;
  fTriggerMode = m_info.fTriggerMode;
  fNumChannels = m_info.fNumChannels;
  fNumEvents = m_info.fNumEvents;
  fFirstRecord = m_info.fFirstRecord;

  fDAQ_ID = m_info.fDAQ_ID;
  fRunType = m_info.fRunType;
  fDescription = m_info.fDescription;
  fLabels = m_info.fLabels;
}

RunInfo::~RunInfo()
{
  ;
}

void RunInfo::Clear( Option_t* opt)
{
  fDAQ_ID.clear();
  fRunType.clear();
  fLabels.clear();
  fDescription.clear();

  fRunNumber = 0;
  fStart = 0;
  fStop = 0;
  fAcquisition = 0;
  fNumChannels = 0;
  fTriggerMode = 0;
  fNumChannels = 0;
  fNumEvents = 0;
}

void RunInfo::Print( Option_t* opt) const
{
  std::ostream &os = std::cout;
  const RunInfo &ri = *this;
  const char *prefix = "  ", *postfix = ",\n";
  os << "{\n"
     << prefix << ".fRunNumber = " << ri.fRunNumber << postfix
     << prefix << ".fDAQ_ID = '" << ri.fDAQ_ID << "'" << postfix
     << prefix << ".fRunType = '" << ri.fRunType << "'" << postfix
     << prefix << ".fLabels[" << ri.fLabels.size() << "] = { \n";
  for (unsigned int i=0; i<ri.fLabels.size(); i++)
    os << prefix <<"  '"<< ri.fLabels[i] <<"'"<< postfix;
  os << prefix << "}" << postfix
     << prefix << ".fStart = " << ri.fStart << postfix
     << prefix << ".fStop = " << ri.fStop << postfix
     << prefix << ".fAcquisition = " << ri.fAcquisition.AsDouble() << postfix
     << prefix << ".fNumChannels = " << ri.fNumChannels << postfix
     << prefix << ".fTriggerMode = " << ri.fTriggerMode << postfix
     << prefix << ".fDescription = \"" << ri.fDescription << '"' << postfix
     << prefix << ".fNumEvents = " << ri.fNumEvents << postfix
     << prefix << ".fFirstRecord = " << ri.fFirstRecord << postfix
     << "}" << std::endl;
}

bool RunInfo::operator==(const RunInfo& m_info) const
{
  if (fRunNumber == m_info.fRunNumber &&
      fStart == m_info.fStart &&
      fStop == m_info.fStop &&
      fAcquisition == m_info.fAcquisition &&
      fNumChannels ==  m_info.fNumChannels &&
      fTriggerMode == m_info.fTriggerMode  &&
      fNumChannels == m_info.fNumChannels &&
      fNumEvents == m_info.fNumEvents &&

      fDAQ_ID.compare(m_info.fDAQ_ID) == 0 &&
      fRunType.compare(m_info.fRunType) == 0 &&
      fDescription.compare(m_info.fDescription) == 0 ) // FIXME check ==

    return true;
  else
    return false;
}

RunInfo& RunInfo::operator=( const RunInfo& m_info)
{
  if (this == &m_info)
    return *this;
  else {
    fRunNumber = m_info.fRunNumber ;
    fStart = m_info.fStart;
    fStop = m_info.fStop;
    fAcquisition = m_info.fAcquisition;
    fNumChannels = m_info.fNumChannels;
    fTriggerMode = m_info.fTriggerMode;
    fNumChannels = m_info.fNumChannels;
    fNumEvents = m_info.fNumEvents;

    fDAQ_ID = m_info.fDAQ_ID;
    fRunType = m_info.fRunType;
    fDescription = m_info.fDescription;
    fLabels = m_info.fLabels;

    return *this;
  }
}
