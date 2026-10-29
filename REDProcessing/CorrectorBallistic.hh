#ifndef RED_CorrectorBallistic_hh
#define RED_CorrectorBallistic_hh

#include <vector>
#include <cmath>
#include <TString.h>

#include "REDProcessing/ProcessingModule.hh"

namespace RED
{
  class PulseFinder;

  class CorrectorBallistic : public ProcessingModule
  {
  public:
    CorrectorBallistic();
    ~CorrectorBallistic();

    EventStatus ProcessEvent(Event *event);

    //
    void SetCorrectionTau(int ichannel, double tau);
    void SetCorrectionTau(int nchannels, const double *tau);
    void SetCorrectionThreshold(int ichannel, double threshold);
    void SetCorrectionThreshold(int nchannels, const double *threshold);
    void SetPulseFinderName(const char *name) { fFinderName = name; fFinder = FindPulseFinder(); }
    void SetPulseFinderName(const std::string &name) { fFinderName = name; fFinder = FindPulseFinder(); }
    void SetPulseFinderName(const TString &name) { fFinderName = name; fFinder = FindPulseFinder(); }

    double GetCorrectionTau(int ichannel) const;
    double GetCorrectionThreshold(int ichannel) const;
    const char* GetPulseFinderName() const { return fFinderName.Data(); }

    void SetStartTime(int time) { fStartTime = time; }
    void SetEndTime(int time) { fEndTime = time; }
    void SetBaselineSearchInterval(double start_time, double end_time)
      { fStartTime = start_time; fEndTime = end_time; }

    double GetStartTime() const { return fStartTime; }
    double GetEndTime() const { return fEndTime; }

  private:
    double fStartTime;     // Baseline calculation window start time, 0 means inherit from PulseFinder
    double fEndTime;       // Baseline calculation window end time, 0 means inherit from PulseFinder
    std::vector<double> fCorrectionThreshold; // Signal detection threshold for each channel
    std::vector<double> fCorrectionTau;       // Electronics shaping time for each channel
    TString fFinderName;   // Object name of PulseFinder
    PulseFinder *fFinder;  //! pointer to active PulseFinder

    PulseFinder* FindPulseFinder();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(CorrectorBallistic)
    ClassDef(CorrectorBallistic,1)
  };

  inline void CorrectorBallistic::SetCorrectionTau(int nchannels, const double *tau)
  {
    if (nchannels > static_cast<int>(fCorrectionTau.size()))
      fCorrectionTau.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fCorrectionTau[i] = tau[i];
  }

  inline void CorrectorBallistic::SetCorrectionTau(int ichannel, double tau)
  {
    if (ichannel >= static_cast<int>(fCorrectionTau.size())) {
      const double &val = (fCorrectionTau.empty() ? 1. : fCorrectionTau.back());
      fCorrectionTau.resize(ichannel+1, val);
    }
    fCorrectionTau[ichannel] = tau;
  }

  inline double CorrectorBallistic::GetCorrectionTau(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fCorrectionTau.size()))
      return fCorrectionTau[ichannel];
    return NAN;
  }

  inline void CorrectorBallistic::SetCorrectionThreshold(int nchannels, const double *threshold)
  {
    if (nchannels > static_cast<int>(fCorrectionThreshold.size()))
      fCorrectionThreshold.resize(nchannels);

    for (int i=0; i<nchannels; i++)
      fCorrectionThreshold[i] = threshold[i];
  }

  inline void CorrectorBallistic::SetCorrectionThreshold(int ichannel, double threshold)
  {
    if (ichannel >= static_cast<int>(fCorrectionThreshold.size())) {
      const double &val = (fCorrectionThreshold.empty() ? 0. : fCorrectionThreshold.back());
      fCorrectionThreshold.resize(ichannel+1, val);
    }
    fCorrectionThreshold[ichannel] = threshold;
  }

  inline double CorrectorBallistic::GetCorrectionThreshold(int ichannel) const
  {
    if (0 <= ichannel && ichannel < static_cast<int>(fCorrectionThreshold.size()))
      return fCorrectionThreshold[ichannel];
    return NAN;
  }

} // namespace

#endif /* RED_CorrectorBallistic_hh */
