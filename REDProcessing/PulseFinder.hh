#ifndef RED_PulseFinder_hh
#define RED_PulseFinder_hh

#include "REDProcessing/ProcessingModule.hh"
#include <cmath>

namespace RED
{

  class Event;
  class Pulse;
  class Waveform;

  struct BaselineParameters {
    double fBaseline;        // Baseline level
    double fBaselineError;   // BaselineError
    double fBaselineFitAmp;  // Amplitude of the baseline fit
    double fBaselineFitLow;  // Lower edge of the baseline fit range
    double fBaselineFitUp;   // Upper edge of the baseline fit range
    double fNoise;           // Noise level
    double fSignalMin;       // Minimal voltage value on the waveform
    double fSignalMax;       // Maximal voltage value on the waveform

    BaselineParameters(): fBaseline(0), fBaselineError(0),
      fBaselineFitAmp(0), fBaselineFitLow(0), fBaselineFitUp(0),
      fNoise(0), fSignalMin(0), fSignalMax(0)
    { ; }

    ~BaselineParameters()
    { ; }

    BaselineParameters(const BaselineParameters& that)
    {
      fBaseline = that.fBaseline;
      fBaselineError = that.fBaselineError;
      fBaselineFitAmp = that.fBaselineFitAmp;
      fBaselineFitLow = that.fBaselineFitLow;
      fBaselineFitUp = that.fBaselineFitUp;
      fNoise = that.fNoise;
      fSignalMin = that.fSignalMin;
      fSignalMax = that.fSignalMax;
    }

    BaselineParameters& operator=(const BaselineParameters& that)
    {
      if (this == &that) {
        return *this;
      } else {
        fBaseline = that.fBaseline;
        fBaselineError = that.fBaselineError;
        fBaselineFitAmp = that.fBaselineFitAmp;
        fBaselineFitLow = that.fBaselineFitLow;
        fBaselineFitUp = that.fBaselineFitUp;
        fNoise = that.fNoise;
        fSignalMin = that.fSignalMin;
        fSignalMax = that.fSignalMax;
        return *this;
      }
    }

    void Clear()
    {
      fBaseline = 0;
      fBaselineError = 0;
      fBaselineFitAmp = 0;
      fBaselineFitLow = 0;
      fBaselineFitUp = 0;
      fNoise = 0;
      fSignalMin = 0;
      fSignalMax = 0;
    }
  };

  class PulseFinder : public ProcessingModule
  {
  public:

    struct PulseRange {
      int StartSample;
      int EndSample;
      PulseRange() { Clear(); }
      void Clear() { StartSample = -1; EndSample = -1; }
    };

    PulseFinder();
    ~PulseFinder();

    EventStatus ProcessEvent(Event*);  // The main Processing function
    bool CanChangeEvents() { return true; }

    // Common channel parameters
    void SetFitVariation(double variation) { fFitVariation = variation; }
    void SetFitVariationMultiplier(double multiplier) { fFitVariationMultiplier = multiplier; }
    void SetProcedureChoiceRelation(double relation) { fProcedureChoiceRelation = relation; }
    void SetPulsePreSamples (int interval = 0) { fPulsePreSamples = ((interval >= 0)?interval:0); }
    void SetPulsePostSamples (int interval = 0) { fPulsePostSamples = ((interval >= 0)?interval:0); }
    void SetPulseMinDuration (int interval = 0) { fPulseMinDuration = ((interval >= 0)?interval:0); }
    void SetPulseMinInterval (int interval = 0) { fPulseMinInterval = ((interval >= 0)?interval:0); }
    void SetUseAbsoluteThreshold(bool val) { fUseAbsoluteThreshold = val; }
    void SetUseThresholdInPulse(bool val) { fUseThresholdInPulse = val; }

    // Individual channel parameters
    void SetPulseDetectThreshold(int ichannel, double factor);
    void SetPulseDetectThreshold(int nchannels, const double *factor);
    void SetPulseGateThreshold(int ichannel, double factor);
    void SetPulseGateThreshold(int nchannels, const double *factor);
    void SetBaselineExpected(int ichannel, double baseline);
    void SetBaselineExpected(int nchannel, const double *baseline);
    void SetBaselineDeviation(int ichannel, double deviation);
    void SetBaselineDeviation(int nchannels, const double *deviation);
    void SetBaselineStartTime(int ichannel, double time);
    void SetBaselineStartTime(int nchannels, const double *time);
    void SetBaselineEndTime(int ichannel, double time);
    void SetBaselineEndTime(int nchannels, const double *time);
    void SetBaselineTimeInterval(int nchannels, const double *StartTime, const double *EndTime);

    // Pulse Finder Parameters
    double GetFitvariation() const { return fFitVariation; }
    double GetFitVariationMultiplier() const { return fFitVariationMultiplier; }
    double GetProcedureChoiceRelation() const { return fProcedureChoiceRelation; }
    int GetPulsePreSamples () const { return fPulsePreSamples; }
    int GetPulsePostSamples () const { return fPulsePostSamples; }
    int GetPulseMinDuration () const { return fPulseMinDuration; }
    int GetPulseMinInterval () const { return fPulseMinInterval; }
    bool GetUseAbsoluteThreshold() const { return fUseAbsoluteThreshold; }
    bool GetUseThresholdInPulse() const { return fUseThresholdInPulse; }
    double GetPulseDetectThreshold(int ichannel) const;
    double GetPulseGateThreshold(int ichannel) const;
    double GetBaselineExpected(int ichannel) const;
    double GetBaselineDeviation(int ichannel) const;
    double GetBaselineStartTime(int ichannel) const;
    double GetBaselineEndTime(int ichannel) const;

    void CheckChannelParameters(int MaxNumChannels);
    // Determine baseline parameters
    RED::BaselineParameters GetBaselineParameters(const Waveform* wf,
      double BaselineExpected = 0., double BaselineDeviation = 0.3,
      double StartTime = 0., double EndTime = 0.);
    double GetBaselineParametersFast(const Waveform *wf) const;
    double GetBaselineParametersFast(const Waveform *wf, double StartTime, double EndTime) const;
    double GetBaselineParametersFast(const Waveform *wf, double StartTime, double EndTime,
      double Expected, double Deviation) const;

  private:
    int    fChannel;                    //!
    BaselineParameters fBaselineParams; //! cache Parameters of baseline

    std::vector<PulseRange> fRanges; //! Contains pairs begin/end for pulses as they are found


    double       fFitVariation;            // Parameter of fit range
    double       fFitVariationMultiplier;  // Multiplier of fFitVariation for High Sensetivity
    double       fProcedureChoiceRelation; // Ratio of heigh of max. peak on Amplitude hist. to Number of samples in a waveform
    unsigned int fPulsePreSamples;         // Add this number of samples at the start of the pulse
    unsigned int fPulsePostSamples;        // Add this number of samples at the end of the pulse
    unsigned int fPulseMinDuration;        // Extend pulse for at least this minimal duration
    unsigned int fPulseMinInterval;        // Combine pulses if distance between two is shorter than this
    bool         fUseAbsoluteThreshold;    // use threshold as absolute value or scale factor for noise level
    bool         fUseThresholdInPulse;     // use threshold to skip noise samples from pulse measurement

    std::vector<double> fPulseDetectThreshold;// Pulse detection threshold
    std::vector<double> fPulseGateThreshold;  // Pulse boundaries threshold
    std::vector<double> fBaselineExpected;    // Expected Baseline value
    std::vector<double> fBaselineDeviation;   // Deviation from expected Baseline value
    std::vector<double> fBaselineStartTime;   // Start of baseline search time interval
    std::vector<double> fBaselineEndTime;     // End of baseline search time interval

    void LocatePulses(const Waveform* wf, const double threshold);

    void FillPulseParameters(Pulse* pulse, const int StartSample, const int EndSample,  //Filling the Pulse structure
                             const Waveform* wf, const double threshold);
    void Clear();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(PulseFinder)
    ClassDef(PulseFinder,1)
  };

  inline void PulseFinder::SetPulseDetectThreshold(int ichannel, double threshold)
  {
    if (ichannel >= static_cast<int>(fPulseDetectThreshold.size())) {
      const double &dfl = fUseAbsoluteThreshold ? 0.1 : 5.;
      const double &val = (fPulseDetectThreshold.empty() ? dfl : fPulseDetectThreshold.back());
      fPulseDetectThreshold.resize(ichannel+1, val);
    }
    fPulseDetectThreshold[ichannel] = threshold;
  }

  inline void PulseFinder::SetPulseDetectThreshold(int nchannels, const double *threshold)
  {
    if (nchannels > static_cast<int>(fPulseDetectThreshold.size()))
      fPulseDetectThreshold.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fPulseDetectThreshold[i] = threshold[i];
  }

  inline double PulseFinder::GetPulseDetectThreshold(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fPulseDetectThreshold.size()))
      return fPulseDetectThreshold[ichannel];
    return NAN;
  }

  inline void PulseFinder::SetPulseGateThreshold(int ichannel, double threshold)
  {
    if (ichannel >= static_cast<int>(fPulseGateThreshold.size())) {
      const double &dfl = fUseAbsoluteThreshold ? 0.05 : 3.;
      const double &val = (fPulseGateThreshold.empty() ? dfl : fPulseGateThreshold.back());
      fPulseGateThreshold.resize(ichannel+1, val);
    }
    fPulseGateThreshold[ichannel] = threshold;
  }

  inline void PulseFinder::SetPulseGateThreshold(int nchannels, const double *threshold)
  {
    if (nchannels > static_cast<int>(fPulseGateThreshold.size()))
      fPulseGateThreshold.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fPulseGateThreshold[i] = threshold[i];
  }

  inline double PulseFinder::GetPulseGateThreshold(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fPulseGateThreshold.size()))
      return fPulseGateThreshold[ichannel];
    return NAN;
  }

  inline void PulseFinder::SetBaselineExpected(int ichannel, double baseline)
  {
    if (ichannel >= static_cast<int>(fBaselineExpected.size())) {
      const double &val = (fBaselineExpected.empty() ? 0. : fBaselineExpected.back());
      fBaselineExpected.resize(ichannel+1, val);
    }
    fBaselineExpected[ichannel] = baseline;
  }

  inline void PulseFinder::SetBaselineExpected(int nchannels, const double *baseline)
  {
    if (nchannels > static_cast<int>(fBaselineExpected.size()))
      fBaselineExpected.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fBaselineExpected[i] = baseline[i];
  }

  inline double PulseFinder::GetBaselineExpected(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fBaselineExpected.size()))
      return fBaselineExpected[ichannel];
    return NAN;
  }

  inline void PulseFinder::SetBaselineDeviation(int ichannel, double deviation)
  {
    if (ichannel >= static_cast<int>(fBaselineDeviation.size())) {
      const double &val = (fBaselineDeviation.empty() ? 0.3 : fBaselineDeviation.back());
      fBaselineDeviation.resize(ichannel+1, val);
    }
    fBaselineDeviation[ichannel] = deviation;
  }

  inline void PulseFinder::SetBaselineDeviation(int nchannels, const double *deviation)
  {
    if (nchannels > static_cast<int>(fBaselineDeviation.size()))
      fBaselineDeviation.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fBaselineDeviation[i] = deviation[i];
  }

  inline double PulseFinder::GetBaselineDeviation(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fBaselineDeviation.size()))
      return fBaselineDeviation[ichannel];
    return NAN;
  }

  inline void PulseFinder::SetBaselineStartTime(int ichannel, double StartTime)
  {
    if (ichannel >= static_cast<int>(fBaselineStartTime.size())) {
      const double &val = (fBaselineStartTime.empty() ? 0. : fBaselineStartTime.back());
      fBaselineStartTime.resize(ichannel+1, val);
    }
    fBaselineStartTime[ichannel] = StartTime;
  }

  inline void PulseFinder::SetBaselineStartTime(int nchannels, const double *StartTime)
  {
    if (nchannels > static_cast<int>(fBaselineStartTime.size()))
      fBaselineStartTime.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fBaselineStartTime[i] = StartTime[i];
  }

  inline double PulseFinder::GetBaselineStartTime(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fBaselineStartTime.size()))
      return fBaselineStartTime[ichannel];
    return NAN;
  }

  inline void PulseFinder::SetBaselineEndTime(int ichannel, double EndTime)
  {
    if (ichannel >= static_cast<int>(fBaselineEndTime.size())) {
      const double &val = (fBaselineEndTime.empty() ? 0. : fBaselineEndTime.back());
      fBaselineEndTime.resize(ichannel+1, val);
    }
    fBaselineEndTime[ichannel] = EndTime;
  }

  inline void PulseFinder::SetBaselineEndTime(int nchannels, const double *EndTime)
  {
    if (nchannels > static_cast<int>(fBaselineEndTime.size()))
      fBaselineEndTime.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fBaselineEndTime[i] = EndTime[i];
  }

  inline double PulseFinder::GetBaselineEndTime(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fBaselineEndTime.size()))
      return fBaselineEndTime[ichannel];
    return NAN;
  }

  inline void PulseFinder::SetBaselineTimeInterval(int nchannels, const double *StartTime, const double *EndTime)
  {
    SetBaselineStartTime(nchannels, StartTime);
    SetBaselineEndTime(nchannels, EndTime);
  }

} // namespace

#endif /* RED_PulseFinder_hh */
