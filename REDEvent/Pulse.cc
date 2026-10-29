#include <iostream>
//#include <iomanip> //for setw()

#include "REDEvent/Pulse.hh"
#include "REDEvent/Cluster.hh"

using namespace RED;

void RED::Pulse::SetCluster(RED::Cluster* cluster)
{
  fRefCluster = static_cast<TObject*>(cluster);
}

RED::Cluster* RED::Pulse::GetCluster()
{
  TObject* tmp = fRefCluster.GetObject();
  return static_cast<RED::Cluster*>(tmp);
}

void RED::Pulse::RemoveCluster()
{
  fRefCluster.Clear("C");
}


Pulse::Pulse() :
  fChannel(0), fType(0), fBaseline(0), fBaselineError(0),
  fNoise(0), fTime(0), fTimeError(0), fTau(0), fFirstSample(0),
  fLastSample(0), fWidth10(0), fWidth50(0), fWidth90(0),
  fRisetime(0), fFalltime(0), fDecaytime(0), fPeakTime(0),
  fAmplitude(0), fArea(0), fAreaEff(0), fAreaDiff(0),
  fChiSquare(0), fSaturated(0), fOverlayed(0), fPartial(0)
{
  for(int par=0; par<8; par++)
    fFitParameters[par] = 0;
  //Pulse::Clear();
}

Pulse::Pulse(const Pulse& that)
{
  fChannel = that.fChannel;
  fType = that.fType;
  fBaseline = that.fBaseline;
  fBaselineError = that.fBaselineError;
  fNoise = that.fNoise;
  fTime = that.fTime;
  fTimeError = that.fTimeError;
  fFirstSample = that.fFirstSample;
  fLastSample = that.fLastSample;
  fWidth90 = that.fWidth90;
  fWidth50 = that.fWidth50;
  fWidth10 = that.fWidth10;
  fDecaytime = that.fDecaytime;
  fRisetime = that.fRisetime;
  fFalltime = that.fFalltime;
  fPeakTime = that.fPeakTime;
  fAmplitude = that.fAmplitude;
  fArea = that.fArea;
  fAreaEff = that.fAreaEff;
  fAreaDiff = that.fAreaDiff;
  fChiSquare = that.fChiSquare;
  fSaturated = that.fSaturated;
  fOverlayed = that.fOverlayed;
  fPartial = that.fPartial;

  for (int par=0; par<8; par++)
    fFitParameters[par] = that.fFitParameters[par];

}

Pulse::~Pulse()
{
  ;
}

Pulse& Pulse::operator=( const Pulse& that)
{
  if (this == &that)
    return *this;
  else {
    fChannel = that.fChannel;
    fType = that.fType;
    fBaseline = that.fBaseline;
    fBaselineError = that.fBaselineError;
    fNoise = that.fNoise;
    fTime = that.fTime;
    fTimeError = that.fTimeError;
    fFirstSample = that.fFirstSample;
    fLastSample = that.fLastSample;
    fWidth90 = that.fWidth90;
    fWidth50 = that.fWidth50;
    fWidth10 = that.fWidth10;
    fDecaytime = that.fDecaytime;
    fRisetime = that.fRisetime;
    fFalltime = that.fFalltime;
    fPeakTime = that.fPeakTime;
    fAmplitude = that.fAmplitude;
    fArea = that.fArea;
    fAreaEff = that.fAreaEff;
    fAreaDiff = that.fAreaDiff;
    fChiSquare = that.fChiSquare;
    fSaturated = that.fSaturated;
    fOverlayed = that.fOverlayed;
    fPartial = that.fPartial;

    for (int par=0; par<8; par++)
      fFitParameters[par] = that.fFitParameters[par];

    return *this;
  }
}

bool Pulse::operator==(const Pulse& ev) const
{

  if (fChannel == ev.fChannel &&
      fType == ev.fType &&
      fBaseline == ev.fBaseline &&
      fBaselineError == ev.fBaselineError &&
      fNoise == ev.fNoise &&
      fTime == ev.fTime &&
      fTimeError == ev.fTimeError &&
      fTau == ev.fTau &&
      fFirstSample == ev.fFirstSample &&
      fLastSample == ev.fLastSample &&
      fWidth10 == ev.fWidth10 &&
      fWidth50 == ev.fWidth50 &&
      fWidth90 == ev.fWidth90 &&
      fDecaytime == ev.fDecaytime &&
      fRisetime == ev.fRisetime &&
      fFalltime == ev.fFalltime &&
      fPeakTime == ev.fPeakTime &&
      fAmplitude == ev.fAmplitude &&
      fArea == ev.fArea &&
      fAreaEff == ev.fAreaEff &&
      fAreaDiff == ev.fAreaDiff &&
      fChiSquare == ev.fChiSquare &&
      fSaturated == ev.fSaturated &&
      fOverlayed == ev.fOverlayed &&
      fPartial == ev.fPartial)
    return true;
  else
    return false;
}
void Pulse::Print( Option_t* opt) const
{
  std::ostream &os = std::cout;
  const Pulse &pls = *this;
  const char *prefix = "  ", *postfix = ",\n";
  os << "{\n"
     << prefix << ".fChannel = " << pls.fChannel << postfix
     << prefix << ".fType = " << pls.fType << postfix
     << prefix << ".fBaseline = " << pls.fBaseline << postfix
     << prefix << ".fBaselineError = " << pls.fBaselineError << postfix
     << prefix << ".fNoise = " << pls.fNoise << postfix
     << prefix << ".fTime = " << pls.fTime << postfix
     << prefix << ".fTimeError = " << pls.fTimeError << postfix
     << prefix << ".fTau = " << pls.fTau << postfix
     << prefix << ".fFirstSample = " << pls.fFirstSample << postfix
     << prefix << ".fLastSample = " << pls.fLastSample << postfix
     << prefix << ".fWidth10 = " << pls.fWidth10 << postfix
     << prefix << ".fWidth50 = " << pls.fWidth50 << postfix
     << prefix << ".fWidth90 = " << pls.fWidth90 << postfix
     << prefix << ".fRisetime = " << pls.fRisetime << postfix
     << prefix << ".fFalltime = " << pls.fFalltime << postfix
     << prefix << ".fDecaytime = " << pls.fDecaytime << postfix
     << prefix << ".fPeakTime = " << pls.fPeakTime << postfix
     << prefix << ".fAmplitude = " << pls.fAmplitude << postfix
     << prefix << ".fArea = " << pls.fArea << postfix
     << prefix << ".fAreaEff = " << pls.fAreaEff << postfix
     << prefix << ".fAreaDiff = " << pls.fAreaDiff << postfix
     << prefix << ".fChiSquare  = " << pls.fChiSquare << postfix
     << prefix << ".fFitParameters[8] = { ";
  for (int i=0; i<8; i++) os << pls.fFitParameters[i] <<", ";
  os << "}" << postfix
     << prefix << ".fSaturated = " << pls.fSaturated << postfix
     << prefix << ".fOverlayed = " << pls.fOverlayed << postfix
     << prefix << ".fPartial = " << pls.fPartial << postfix
     << "}" << std::endl;
}


void Pulse::Clear( Option_t* option)
{
  fType = 0;
  fBaseline = 0;
  fBaselineError = 0;
  fNoise = 0;
  fTime = 0;
  fTimeError = 0;
  fTau = 0;
  fFirstSample = 0;
  fLastSample = 0;
  fWidth10 = 0;
  fWidth50 = 0;
  fWidth90 = 0;
  fRisetime = 0;
  fFalltime = 0;
  fDecaytime = 0;
  fAmplitude = 0;
  fPeakTime = 0;
  fArea = 0;
  fAreaDiff = 0;
  fAreaEff = 0;
  fChiSquare = 0;
  fSaturated = 0;
  fOverlayed = 0;
  fPartial = 0;

  for(int par=0; par<8; par++)
    fFitParameters[par] = 0;

}
