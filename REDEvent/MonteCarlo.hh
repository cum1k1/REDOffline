#ifndef RED_MonteCarlo_hh
#define RED_MonteCarlo_hh

#ifndef ROOT_TObject
# include "TObject.h"
#endif

namespace RED
{

  class MonteCarlo : public TObject
  {

  public:
    Int_t       fGeant4EventNumber;                  // GEANT4 event number.
    Int_t       fGeant4SubEventNumber;               // GEANT4 Sub-event number, in the case of a decay chain or metastable states.
    Double_t    fPrimaryEventX;                      // Primary event x position in millimeters.
    Double_t    fPrimaryEventY;                      // Primary event y position in millimeters.
    Double_t    fPrimaryEventZ;                      // Primary event z position in millimeters.
    //Double_t    fBetaDecayQValue;                    // Beta decay Q value.
    Int_t       fEventType;                          //
    Double_t    fTotalEnergyInShield;                //Total energy deposited in the lead.
    Double_t    fTotalEnergyInCryostat;              // Total energy deposited in the inner cryostat.
    Double_t    fTotalEnergyInLiquidXe;              // Total energy deposited in the liquid xenon.
    Double_t    fTotalScintillationEnergyInLiquidXe; // Total ionization energy deposited in
    Double_t    fTotalIonizationEnergyInLiquidXe;    /* Total ionization energy deposited in the
                                                        liquid xenon, accounting for quenching. */
    Int_t       fTotalScintillationPhotons;          // Total number of scintillation photons generated.
    Int_t       fTotalScintillationHitsTop;          // Total number of scintillation photons seen by top PMTs.
    Int_t       fTotalScintillationHitsBottom;       // Total number of scintillation photons seen by bottom PMTs.
    Int_t       fTotalIonizationElectrons;           // Total number of ionization electrons generated.
    Int_t       fTotalElectroluminescencePhotons;    // Total number of electroluminescence photons generated.
    Int_t       fTotalElectroluminescenceHitsTop;    // Total number of electroluminescence photons seen by top PMTs.
    Int_t       fTotalElectroluminescenceHitsBottom; // Total number of electroluminescence photons seen by bottom PMTs.
    //TClonesArray*   fParticleInformation;     //->Array of Primary and secondary generated particles
    //TClonesArray*   fPMTHits;                 //->Array of Monte Carlo APD photon counting

  public:
    //MonteCarlo();
    //~MonteCarlo();

    ClassDef(MonteCarlo,1)
  };

//---- inlines -----------------------------------------------------------------

} // namespace

#endif /* REDMonteCarlo_hh */
