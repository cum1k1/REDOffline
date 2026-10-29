#ifndef RED_Cluster_hh
#define RED_Cluster_hh

#ifndef ROOT_TObject
# include "TObject.h"
#endif

#ifndef ROOT_TRefArray
# include "TRefArray.h"
#endif

#include "REDEvent/Pulse.hh"

namespace RED
{

  class Cluster : public TObject
  {
  public:
    Int_t       fType;
    Double_t    fTime;           // Collection time of the cluster, in nanoseconds
    Double_t    fWidth;          //
    Int_t       fSaturated;      //
    Int_t       fPeakChannel;    //
    Double_t    fAmplitude;      //
    Double_t    fArea;           //
    Double_t    fAreaEff;        //
    Double_t    fAreaDiff;       //
    Int_t       fNumSPE;         //
    Int_t       fNumPMTTop;      //
    Int_t       fNumPMTBottom;   //
    //
    Double_t    fX;              // x position of the cluster, in millimeters.
    Double_t    fY;              // y position of the cluster, in millimeters.
    Double_t    fZ;              // z position of the cluster, in millimeters.
    Double_t    fDriftTime;      // Drift time of the cluster, in nanoseconds.
    //
    Double_t    fRawEnergy;             // Raw cluster energy in keV.
    Double_t    fRawEnergyError;        //
    Double_t    fCorrectedEnergy;
    Double_t    fCorrectedEnergyError;  //

  public:
    Cluster();
    Cluster(const Cluster&);
    ~Cluster();
    virtual void Clear( Option_t* opt = "" );
    //virtual void RecursiveRemove(TObject* obj);   //Auto remove objects from Pulses
    virtual void Print( Option_t* opt = "" ) const;
    Cluster& operator=( const Cluster& );
    bool operator==(const Cluster& sig) const;

    void AddPulse(Pulse* pulse);
    void RemovePulse(int idx);
    const Pulse* GetPulse(int idx) const;
    Pulse* GetPulse(int idx);
    //int GetPulseNumber(int idx);    //FIXME
    int GetNumPulses() const;
    void ClearPulsesArray();

  protected:
    //TRef        fRefScintCluster; //
    TRefArray   fRefPulses;       // array of pulses that went into the cluster

    ClassDef( Cluster, 1 )
  };

//---- inlines -----------------------------------------------------------------

  inline void Cluster::AddPulse(Pulse* pulse)
  {
    TObject* tmp = static_cast<TObject*>(pulse);
    fRefPulses.Add(tmp);
  }

  inline void Cluster::RemovePulse(int idx)
  {
    if (idx >= 0)
      fRefPulses.RemoveAt(idx);
  }

  inline const Pulse* Cluster::GetPulse(int idx) const
  {
    TObject *tmp = fRefPulses.At(idx);
    if (tmp != 0) return static_cast<Pulse*>(tmp);
    else return 0;
  }

  inline Pulse* Cluster::GetPulse(int idx)
  {
    TObject *tmp = fRefPulses.At(idx);
    if (tmp != 0) return static_cast<Pulse*>(tmp);
    else return 0;
  }

  inline int Cluster::GetNumPulses() const
  {
    return fRefPulses.GetEntriesFast();
  }

  inline void Cluster::ClearPulsesArray()
  {
    fRefPulses.Clear("C");
  }

} // namespace

#endif /* RED_Cluster_hh */
