/******************************************************************************
 *
 *  This module corrects for baseline shift due to electronics shaping.
 *
 *  It is effectively a digital baseline restorer based on a simple model.
 *  Here we presume:
 *  - Baseline shift is proportional to the effective charge buildup
 *  - This effective charge is accumulated from signals rather than noise
 *  - This effective charge decays with measured lifetime tau
 *
 *  This way one can obtain for direct integration:
 *    Q_{i} = Q_{i-1} + A_{i}*dt
 *    A^{corr}_{i} = (Q_{i} e^(-dt/tau) - Q_{i-1})/dt
 *  Unfortunately this method is very sensitive to the smallest shifts in
 *  actual baseline, since any discrepancy between real zero and ADC zero
 *  will accumulate in efefctive charge with every step.
 *
 *  The right way would be to use true signal amplitude for calculations,
 *  but this is unknown, so we assume it equals to seen amplitude minus
 *  correction. Thus the formulae can be turned to:
 *    Q_{i} = Q_{i-1} * e^{-dt/tau} + A^{corr}_{i-1} * dt
 *    A^{corr}_{i} ~= A_{i} + Q_{i}/dt * (1-e^{-dt/tau))
 *  This way we can naturally introduce a threshold on A^{corr}, that
 *  will allow to account for real signals only rather than noise.
 *  With proper calculations, Q here is equal to Q in direct integration.
 *
 *  This method keeps any DC offset and assumes it can be evaluated from
 *  waveform data.
 *
 *  Author: Vladimir Belov <belov@itep.ru> 2017
 *
 *****************************************************************************/

#include "CorrectorBallistic.hh"

#include <iostream>
#include <TROOT.h>
#include "REDProcessing/PulseFinder.hh"

#include "REDEvent/Event.hh"
#include "REDEvent/RunInfo.hh"

using std::cout;
using std::endl;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( CorrectorBallistic )
ClassImp( CorrectorBallistic )

extern int g_techChannels; // FIXME a bit mask of channels to skip by CorrectorBallistic
                           // (the same as skipped by clustering)

CorrectorBallistic::CorrectorBallistic()
  : fStartTime(0.),fEndTime(0.),fFinder(nullptr)
{
}
CorrectorBallistic::~CorrectorBallistic()
{
}

ProcessingModule::EventStatus CorrectorBallistic::ProcessEvent(Event *event)
{
  //cout << __PRETTY_FUNCTION__ <<" "<< (void*)fFinder << endl;

  if (!fFinder)
    fFinder = FindPulseFinder();
  if (!fFinder) return kError;

  const int MaxNumChannels = event->GetRunInfo()->fNumChannels;
  if (MaxNumChannels > static_cast<int>(fCorrectionTau.size())) {
    SetCorrectionTau(MaxNumChannels, 0.);
  }
  if (MaxNumChannels > static_cast<int>(fCorrectionThreshold.size())) {
    SetCorrectionThreshold(MaxNumChannels, 0.);
  }

  int ichannel = 0;
  double threshold = 0.; // only samples bigger than threshold are signals
  double tau = 0.;       // charge relaxation time
  double baseline = 0.;  // this is where 0 volts are
  double delta = 0.;     // signal amplitude
  double charge = 0.;    // accumulated signal = effective charge
  double p1, p2;

  for (int iwf = 0; iwf < event->GetNumWaveforms(); iwf++) {
    Waveform *wf = event->GetWaveform(iwf);
    ichannel = wf->fChannel;
    if (ichannel >= 0 && !(::g_techChannels & (1 << ichannel))) {
      threshold = fCorrectionThreshold[ichannel]/wf->fGain;
      tau = fCorrectionTau[ichannel]/wf->fPeriod;
      // we determine position of real zero using PulseFinder method and parameters
      const BaselineParameters blpar = fFinder->GetBaselineParameters(
        wf, fFinder->GetBaselineExpected(ichannel), fFinder->GetBaselineDeviation(ichannel),
        (fStartTime != 0. ? fStartTime : fFinder->GetBaselineStartTime(ichannel)),
        (fEndTime != 0. ? fEndTime : fFinder->GetBaselineEndTime(ichannel))
      );
      baseline = (blpar.fBaseline - wf->fOffset)/wf->fGain;

      // here we calculate in ADC units, so dt === 1
      charge = 0.; p1 = 1./tau; p2 = exp(-p1);
      for (int i=0; i<wf->fNumSamples; i++) {
        delta = wf->fData[i] + charge*p1 - baseline;
        charge = charge*p2 + ((fabs(delta)>threshold) ? delta : 0.);
        wf->fData[i] =  wf->fData[i] + charge*p1;
      }
    }
  }

  return kOk;
}

PulseFinder* CorrectorBallistic::FindPulseFinder()
{
  ProcessingModule *module = static_cast<RED::ProcessingModule*>(gROOT->FindObject(fFinderName));
  PulseFinder* pf = dynamic_cast<RED::PulseFinder*>(module);
  return pf;
}
