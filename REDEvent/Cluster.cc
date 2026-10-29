#include <iostream>
//#include <iomanip> //for setw

#include "REDEvent/Cluster.hh"

using namespace RED;

Cluster::Cluster():
  fType(0), fTime(0), fWidth(0), fSaturated(0),
  fPeakChannel(0), fAmplitude(0), fArea(0),
  fAreaEff(0), fAreaDiff(0), fNumSPE(0),
  fNumPMTTop(0), fNumPMTBottom(0), fX(0), fY(0),
  fZ(0), fDriftTime(0), fRawEnergy(0),
  fRawEnergyError(0), fCorrectedEnergy(0),
  fCorrectedEnergyError(0)
{
  ;
  //Cluster::Clear();
}

Cluster::Cluster(const Cluster& m_cluster)
{
  fType = m_cluster.fType;
  fTime = m_cluster.fTime;
  fWidth = m_cluster.fWidth;
  fSaturated = m_cluster.fSaturated;
  fPeakChannel = m_cluster.fPeakChannel;
  fAmplitude = m_cluster.fAmplitude;
  fArea = m_cluster.fArea;
  fAreaEff = m_cluster.fAreaEff;
  fAreaDiff = m_cluster.fAreaDiff;
  fNumSPE = m_cluster.fNumSPE;
  fNumPMTTop = m_cluster.fNumPMTTop;
  fNumPMTBottom = m_cluster.fNumPMTBottom;
  fX = m_cluster.fX;
  fY = m_cluster.fY;
  fZ = m_cluster.fZ;
  fDriftTime = m_cluster.fDriftTime;
  fRawEnergy = m_cluster.fRawEnergy;
  fRawEnergyError = m_cluster.fRawEnergyError;
  fCorrectedEnergy = m_cluster.fCorrectedEnergy;
  fCorrectedEnergyError = m_cluster.fCorrectedEnergyError;

  fRefPulses = m_cluster.fRefPulses;

}

Cluster::~Cluster()
{
  ;
}

Cluster& Cluster::operator=( const Cluster& m_cluster)
{
  if (this == &m_cluster)
    return *this;
  else {
    fType = m_cluster.fType;
    fTime = m_cluster.fTime;
    fWidth = m_cluster.fWidth;
    fSaturated = m_cluster.fSaturated;
    fPeakChannel = m_cluster.fPeakChannel;
    fAmplitude = m_cluster.fAmplitude;
    fArea = m_cluster.fArea;
    fAreaEff = m_cluster.fAreaEff;
    fAreaDiff = m_cluster.fAreaDiff;
    fNumSPE = m_cluster.fNumSPE;
    fNumPMTTop = m_cluster.fNumPMTTop;
    fNumPMTBottom = m_cluster.fNumPMTBottom;
    fX = m_cluster.fX;
    fY = m_cluster.fY;
    fZ = m_cluster.fZ;
    fDriftTime = m_cluster.fDriftTime;
    fRawEnergy = m_cluster.fRawEnergy;
    fRawEnergyError = m_cluster.fRawEnergyError;
    fCorrectedEnergy = m_cluster.fCorrectedEnergy;
    fCorrectedEnergyError = m_cluster.fCorrectedEnergyError;

    fRefPulses = m_cluster.fRefPulses;   // operator=() is overloaded in TRefArray().

    return *this;
  }
}

bool Cluster::operator==(const Cluster& m_cluster) const
{
  if (fType == m_cluster.fType &&
      fTime == m_cluster.fTime  &&
      fWidth == m_cluster.fWidth &&
      fSaturated == m_cluster.fSaturated &&
      fPeakChannel == m_cluster.fPeakChannel &&
      fAmplitude == m_cluster.fAmplitude &&
      fArea == m_cluster.fArea &&
      fAreaEff == m_cluster.fAreaEff &&
      fAreaDiff == m_cluster.fAreaDiff &&
      fNumSPE == m_cluster.fNumSPE &&
      fNumPMTTop == m_cluster.fNumPMTTop &&
      fNumPMTBottom == m_cluster.fNumPMTBottom &&
      fX == m_cluster.fX &&
      fY == m_cluster.fY &&
      fZ == m_cluster.fZ &&
      fDriftTime == m_cluster.fDriftTime &&
      fRawEnergy == m_cluster.fRawEnergy &&
      fRawEnergyError == m_cluster.fRawEnergyError &&
      fCorrectedEnergy == m_cluster.fCorrectedEnergy &&
      fCorrectedEnergyError == m_cluster.fCorrectedEnergyError)
    return true;
  else
    return false;
}

void Cluster::Print( Option_t* option) const
{
  std::ostream &os = std::cout;
  const Cluster &cl = *this;
  const char *prefix = "  ", *postfix = ",\n";
  os << "{\n"
     << prefix << ".fType = " << cl.fType << postfix
     << prefix << ".fTime = " << cl.fTime << postfix
     << prefix << ".fWidth = " << cl.fWidth << postfix
     << prefix << ".fSaturated = " << cl.fSaturated << postfix
     << prefix << ".fPeakChannel = " << cl.fPeakChannel << postfix
     << prefix << ".fAmplitude = " << cl.fAmplitude << postfix
     << prefix << ".fArea = " << cl.fArea << postfix
     << prefix << ".fAreaEff = " << cl.fAreaEff << postfix
     << prefix << ".fAreaDiff = " << cl.fAreaDiff << postfix
     << prefix << ".fNumSPE = " << cl.fNumSPE << postfix
     << prefix << ".fNumPMTTop = " << cl.fNumPMTTop << postfix
     << prefix << ".fNumPMTBottom = " << cl.fNumPMTBottom << postfix
     << prefix << ".fX = " << cl.fX << postfix
     << prefix << ".fY = " << cl.fY << postfix
     << prefix << ".fZ = " << cl.fZ << postfix
     << prefix << ".fDriftTime = " << cl.fDriftTime << postfix
     << prefix << ".fRawEnergy = " << cl.fRawEnergy << postfix
     << prefix << ".fRawEnergyError = " << cl.fRawEnergyError << postfix
     << prefix << ".fCorrectedEnergy = " << cl.fCorrectedEnergy << postfix
     << prefix << ".fCorrectedEnergyError = " << cl.fCorrectedEnergyError << postfix
     << "}" << std::endl;
}

void Cluster::Clear( Option_t* option)
{
  fType = 0;
  fTime = 0;
  fWidth = 0;
  fSaturated = 0;
  fPeakChannel = 0;
  fAmplitude = 0;
  fArea = 0;
  fAreaEff = 0;
  fAreaDiff = 0;
  fNumSPE = 0;
  fNumPMTTop = 0;
  fNumPMTBottom = 0;
  fX = 0;
  fY = 0;
  fZ = 0;
  fDriftTime = 0;
  fRawEnergy = 0;
  fRawEnergyError = 0;
  fCorrectedEnergy = 0;
  fCorrectedEnergyError = 0;

  fRefPulses.Clear("C");

}
