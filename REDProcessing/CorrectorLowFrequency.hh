#ifndef RED_CorrectorLowFrequency_hh
#define RED_CorrectorLowFrequency_hh

#include <vector>
#include <cmath>
#include <TString.h>

#include "REDProcessing/ProcessingModule.hh"

namespace RED
{
  class PulseFinder;

  class CorrectorLowFrequency : public ProcessingModule
  {
  public:
    CorrectorLowFrequency();
    ~CorrectorLowFrequency();

    EventStatus ProcessEvent(Event *event);

    void SetBaselineStartTime(double val) { fBaselineStartTime = val; }
    double GetBaselineStartTime() const { return fBaselineStartTime; }
    void SetBaselineEndTime(double val) { fBaselineEndTime = val; }
    double GetBaselineEndTime() const { return fBaselineEndTime; }
    void SetBaselineSearchInterval(double aStartTime, double aEndTime)
      { fBaselineStartTime = aStartTime; fBaselineEndTime = aEndTime; }

    void SetChunkDuration(double val) { fChunkDuration = val; }
    double GetChunkDuration() const { return fChunkDuration; }
    void SetCutFrequency(double val) { fCutFrequency = val; }
    double GetCutFrequency() const { return fCutFrequency; }
    void SetPrePulseMargin(double val) { fPrePulseMargin = val; }
    double GetPrePulseMargin() const { return fPrePulseMargin; }
    void SetPostPulseMargin(double val) { fPostPulseMargin = val; }
    double GetPostPulseMargin() const { return fPostPulseMargin; }

    void SetThresholdSignal(int ichannel, double thr);
    void SetThresholdSignal(int nchannels, const double *thr);
    double GetThresholdSignal(int ichannel) const;
    void SetThresholdNoise(int ichannel, double thr);
    void SetThresholdNoise(int nchannels, const double *thr);
    double GetThresholdNoise(int ichannel) const;

    void SetPulseFinderName(const char *name) { fFinderName = name; fFinder = FindPulseFinder(); }
    void SetPulseFinderName(const std::string &name) { fFinderName = name; fFinder = FindPulseFinder(); }
    void SetPulseFinderName(const TString &name) { fFinderName = name; fFinder = FindPulseFinder(); }
    const char* GetPulseFinderName() const { return fFinderName.Data(); }

  private:
    double fBaselineStartTime; // Baseline calculation window start time, 0 means inherit from PulseFinder
    double fBaselineEndTime;   // Baseline calculation window end time, 0 means inherit from PulseFinder
    double fChunkDuration;     // Split waveform into chunks of this size, also matches knot step
    double fCutFrequency;      // Parameter that controls smoothing strength for moving average
    double fPrePulseMargin;    // Drop extra samples before pulse
    double fPostPulseMargin;   // Drop extra samples after pulse
    std::vector<double> fThresholdSignal; // Absolute pulse detection threshold, related to pileup amplitude
    std::vector<double> fThresholdNoise;  // Relative pulse detection threshold, related to noise amplitude
    TString fFinderName;   // Object name of PulseFinder
    PulseFinder *fFinder;  //! pointer to active PulseFinder

    PulseFinder* FindPulseFinder();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(CorrectorLowFrequency)
    ClassDef(CorrectorLowFrequency,1)
  };

  inline void CorrectorLowFrequency::SetThresholdSignal(int nchannels, const double *threshold)
  {
    if (nchannels > static_cast<int>(fThresholdSignal.size()))
      fThresholdSignal.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fThresholdSignal[i] = threshold[i];
  }

  inline void CorrectorLowFrequency::SetThresholdSignal(int ichannel, double threshold)
  {
    if (ichannel >= static_cast<int>(fThresholdSignal.size())) {
      const double &val = (fThresholdSignal.empty() ? 0.1 : fThresholdSignal.back());
      fThresholdSignal.resize(ichannel+1, val);
    }
    fThresholdSignal[ichannel] = threshold;
  }

  inline double CorrectorLowFrequency::GetThresholdSignal(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fThresholdSignal.size()))
      return fThresholdSignal[ichannel];
    return NAN;
  }

  inline void CorrectorLowFrequency::SetThresholdNoise(int nchannels, const double *threshold)
  {
    if (nchannels > static_cast<int>(fThresholdNoise.size()))
      fThresholdNoise.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fThresholdNoise[i] = threshold[i];
  }

  inline void CorrectorLowFrequency::SetThresholdNoise(int ichannel, double threshold)
  {
    if (ichannel >= static_cast<int>(fThresholdNoise.size())) {
      const double &val = (fThresholdNoise.empty() ? 0. : fThresholdNoise.back());
      fThresholdNoise.resize(ichannel+1, val);
    }
    fThresholdNoise[ichannel] = threshold;
  }

  inline double CorrectorLowFrequency::GetThresholdNoise(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fThresholdNoise.size()))
      return fThresholdNoise[ichannel];
    return NAN;
  }

} // namespace

#endif /* RED_CorrectorLowFrequency_hh */
