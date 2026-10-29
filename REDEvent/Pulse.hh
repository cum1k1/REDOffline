#ifndef RED_Pulse_hh
#define RED_Pulse_hh

#ifndef ROOT_TObject
# include "TObject.h"
#endif
#ifndef ROOT_TRefArray
# include "TRefArray.h"
#endif
#ifndef ROOT_TRef
# include "TRef.h"
#endif

namespace RED
{

  class Cluster;

  class Pulse : public TObject
  {
  public:
    Int_t       fChannel;              // channel number
    Int_t       fType;
    Double_t    fBaseline;             // baseline
    Double_t    fBaselineError;        // baseline uncertainty
    Double_t    fNoise;
    Double_t    fTime;                 // time of the begining in nanoseconds
    Double_t    fTimeError;            // time uncertainty
    Double_t    fTau;
    Int_t       fFirstSample;          // the first sample of a pulse
    Int_t       fLastSample;           // the last sample of a pulse
    Double_t    fWidth10;
    Double_t    fWidth50;
    Double_t    fWidth90;
    Double_t    fRisetime;             // Leading edge risetime
    Double_t    fFalltime;
    Double_t    fDecaytime;
    Double_t    fPeakTime;             // Time of maximum amplitude
    Double_t    fAmplitude;            // Maximum amplitude
    Double_t    fArea;
    Double_t    fAreaEff;
    Double_t    fAreaDiff;
    Double_t    fChiSquare;            // chi^2 from fit
    Double_t    fFitParameters[8];
    Int_t       fSaturated;
    Bool_t      fOverlayed;
    Bool_t      fPartial;

    // Get/Set associated charge cluster
    //void InsertCluster( Cluster* aValue );
    //Cluster*  GetClusterAt( size_t index );
    //const Cluster*  GetClusterAt( size_t index ) const;
    //size_t GetNumClusters() const;
    //
    void SetCluster(RED::Cluster* cluster);
    RED::Cluster* GetCluster();
    void RemoveCluster();

  public:
    Pulse();
    Pulse(const Pulse&);
    ~Pulse();
    virtual void Clear( Option_t* opt = "" );
    //virtual void RecursiveRemove(TObject* obj);   //Auto remove objects from Pulses
    virtual void Print( Option_t* opt = "" ) const;
    Pulse& operator=( const Pulse& );
    bool operator==(const Pulse& sig) const;

  protected:
    //TRefArray      fRefClusters; // clusters this signal went into.
    TRef           fRefCluster;  // at the moment we allow only a single 'parent' cluster

    ClassDef( Pulse, 1 )
  };

} // namespace

#endif /* RED_Pulse_hh */
