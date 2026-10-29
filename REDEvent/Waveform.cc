#include <iostream>
//#include <iomanip> // for setw()

#include "REDEvent/Waveform.hh"

using namespace RED;

Waveform::Waveform() :
  fChannel(0), fIsCompressed(false), fIsModified(0),
  fNumSamples(0), fPeriod(0), fDelay(0), fGain(0),
  fOffset(0), fPlaceOfTrigger(0), fBitWidth(0),
  fSignalMin(0), fSignalMax(0), fSignalBase(0),
  fSignalNoise(0), fSignalSaturated(false),
  fBaselineFitAmp(0), fBaselineFitLow(0), fBaselineFitUp(0)
{
  ;
  //Waveform::Clear();
}

Waveform::Waveform( const Waveform& m_waveform)
{
  fChannel = m_waveform.fChannel;
  fIsCompressed = m_waveform.fIsCompressed;
  fIsModified = m_waveform.fIsModified;
  fNumSamples = m_waveform.fNumSamples;
  fData = m_waveform.fData;
  fPeriod = m_waveform.fPeriod;
  fDelay = m_waveform.fDelay;
  fGain = m_waveform.fGain;
  fOffset = m_waveform.fOffset;
  fPlaceOfTrigger = m_waveform.fPlaceOfTrigger;
  fBitWidth = m_waveform.fBitWidth;
  fSignalMin = m_waveform.fSignalMin;
  fSignalMax = m_waveform.fSignalMax;
  fSignalBase = m_waveform.fSignalBase;
  fSignalNoise = m_waveform.fSignalNoise;
  fBaselineFitAmp = m_waveform.fBaselineFitAmp;
  fBaselineFitLow = m_waveform.fBaselineFitLow;
  fBaselineFitUp  = m_waveform.fBaselineFitUp;
}

Waveform& Waveform::operator=( const Waveform &m_waveform)
{
  if (this == &m_waveform)
    return *this;
  else {
    fChannel = m_waveform.fChannel;
    fIsCompressed = m_waveform.fIsCompressed;
    fIsModified = m_waveform.fIsModified;
    fNumSamples = m_waveform.fNumSamples;
    fData = m_waveform.fData;
    fPeriod = m_waveform.fPeriod;
    fDelay = m_waveform.fDelay;
    fGain = m_waveform.fGain;
    fOffset = m_waveform.fOffset;
    fPlaceOfTrigger = m_waveform.fPlaceOfTrigger;
    fBitWidth = m_waveform.fBitWidth;
    fSignalMin = m_waveform.fSignalMin;
    fSignalMax = m_waveform.fSignalMax;
    fSignalBase = m_waveform.fSignalBase;
    fSignalNoise = m_waveform.fSignalNoise;
    fBaselineFitAmp = m_waveform.fBaselineFitAmp;
    fBaselineFitLow = m_waveform.fBaselineFitLow;
    fBaselineFitUp  = m_waveform.fBaselineFitUp;

    return *this;
  }
}

Waveform::~Waveform()
{
  ;
}

void Waveform::Print( Option_t* Option) const
{
  std::ostream &os = std::cout;
  const Waveform &wf = *this;
  const char *prefix = "  ", *postfix = ",\n";
  os << "{\n"
     << prefix << ".fChannel = " << wf.fChannel << postfix
     << prefix << ".fIsCompressed = " << wf.fIsCompressed << postfix
     << prefix << ".fIsModified = " << wf.fIsModified << postfix
     << prefix << ".fNumSamples = " << wf.fNumSamples << postfix
     << prefix << ".fData[" << wf.fData.size() << "] = " << &wf.fData[0] << postfix
     << prefix << ".fPeriod = " << wf.fPeriod << postfix
     << prefix << ".fDelay = " << wf.fDelay << postfix
     << prefix << ".fGain = " << wf.fGain << postfix
     << prefix << ".fOffset = " << wf.fOffset << postfix
     << prefix << ".fPlaceOfTrigger = " << wf.fPlaceOfTrigger << postfix
     << prefix << ".fBitWidth = " << wf.fBitWidth << postfix
     << prefix << ".fSignalMin = " << wf.fSignalMin << postfix
     << prefix << ".fSignalMax = " << wf.fSignalMax << postfix
     << prefix << ".fSignalBase = " << wf.fSignalBase << postfix
     << prefix << ".fSignalNoise = " << wf.fSignalNoise << postfix
     << prefix << ".fSignalSaturated = " << wf.fSignalSaturated << postfix
     << prefix << ".fNameOfWaveform = '" << wf.fNameOfWaveform << "'" << postfix
     << prefix << ".fBaselineFitAmp = " << wf.fBaselineFitAmp << postfix
     << prefix << ".fBaselineFitLow = " << wf.fBaselineFitLow << postfix
     << prefix << ".fBaselineFitUp = " << wf.fBaselineFitUp << postfix
     << "}" << std::endl;
}
