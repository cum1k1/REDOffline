#ifndef RED_Waveform_hh
#define RED_Waveform_hh

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// RED::Waveform                                                        //
//                                                                      //
// Encapsulation class to store actual waveforms of signals             //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TObject
# include "TObject.h"
#endif

#include <vector>

namespace RED
{

  //template<typename _Tp>
  //class REDTemplWaveform : public TObject
  class Waveform : public TObject
  {
  public:
    Int_t       fChannel;           // channel number
    Bool_t      fIsCompressed;      // is waveform compressed or not
    Int_t       fIsModified;        // how many times waveform was modified
    Int_t       fNumSamples;
    //typedef std::vector<_Tp> VecType;
    std::vector<float> fData;       // Waveform data
    // sampling parameters
    Double_t    fPeriod;            // Sampling frequency
    Double_t    fDelay;             // Time offset
    Double_t    fGain;              //
    Double_t    fOffset;            //
    Int_t       fPlaceOfTrigger;
    Int_t       fBitWidth;
    // signal parameters
    Double_t    fSignalMin;
    Double_t    fSignalMax;
    Double_t    fSignalBase;
    Double_t    fSignalNoise;
    Bool_t      fSignalSaturated;
    // parameters of the fit evaluating the baseline
    Double_t    fBaselineFitAmp;    //! amplitude
    Double_t    fBaselineFitLow;    //! lower edge
    Double_t    fBaselineFitUp;     //! upper edge
    //
    std::string fNameOfWaveform;    //! Name of Waveform, don't save

    Waveform();
    Waveform( const Waveform& );
    ~Waveform();

    Waveform& operator=( const Waveform& );
    //bool operator==( const Waveform& ) const;
    void Print( Option_t* Option = "") const;
    //void Clear( Option_t* Option = "");

//  void DrawWaveform( const Waveform& ) const;
    inline double TimeToUser(double it) const { return fDelay+fPeriod*it; }
    inline double TimeFromUser(double t) const { return (t-fDelay)/fPeriod; }
    inline double AmplToUser(double iv) const { return fOffset+fGain*iv; }
    inline double AmplFromUser(double v) const { return (v-fOffset)/fGain; }

    ClassDef( Waveform, 1 )
  };

//---- inlines -----------------------------------------------------------------

} // namespace

#endif /* Waveform_hh */
