#include <iostream>
#include <vector>
#include <cmath>
#include <TH1F.h>
#include <TFitResult.h>

#include "REDEvent/Waveform.hh"
#include "REDEvent/RunInfo.hh"
#include "REDEvent/Pulse.hh"
#include "REDEvent/Event.hh"

#include "REDProcessing/PulseFinder.hh"

#define DEBUG(V,A) if (1) { A }

using namespace RED;
using std::clog;
using std::cout;
using std::endl;

RED_PROCESSING_MODULE_IMPLEMENT( PulseFinder )
ClassImp( PulseFinder )


PulseFinder::PulseFinder() :
  fChannel(0)

{
  fFitVariation = 0.004;
  fFitVariationMultiplier = 6;
  fProcedureChoiceRelation = 0.11;
  fPulsePreSamples = 2;
  fPulsePostSamples = 3;
  fPulseMinDuration = 10;
  fPulseMinInterval = 0;
  fUseAbsoluteThreshold = false;
  fUseThresholdInPulse = false;
}

PulseFinder::~PulseFinder()
{
  ;
}

void PulseFinder::CheckChannelParameters(int MaxNumChannels)
{
  // Extend all vectors of channel parameters up to a full size, so the any
  // indexing operation with channel number work fine. Using a value of 0 isn't
  // important, since we actually set channel size()+1, which is after the last
  // used channel.
  if (MaxNumChannels > static_cast<int>(fPulseDetectThreshold.size())) {
    SetPulseDetectThreshold(MaxNumChannels, 0.);
  }
  if (MaxNumChannels > static_cast<int>(fPulseGateThreshold.size())) {
    SetPulseGateThreshold(MaxNumChannels, 0.);
  }
  if (MaxNumChannels > static_cast<int>(fBaselineExpected.size())) {
    SetBaselineExpected(MaxNumChannels, 0.);
  }
  if (MaxNumChannels > static_cast<int>(fBaselineDeviation.size())) {
    SetBaselineDeviation(MaxNumChannels, 0.);
  }
  if (MaxNumChannels > static_cast<int>(fBaselineStartTime.size())) {
    SetBaselineStartTime(MaxNumChannels, 0.);
  }
  if (MaxNumChannels > static_cast<int>(fBaselineEndTime.size())) {
    SetBaselineEndTime(MaxNumChannels, 0.);
  }
}

ProcessingModule::EventStatus PulseFinder::ProcessEvent(Event *event)
{

  event->ClearPulsesArray();
  CheckChannelParameters(event->GetRunInfo()->fNumChannels);

  for(int i=0; i<event->GetNumWaveforms(); i++) {
    Waveform *wf = (event->GetWaveform(i));
    if (wf->fNumSamples > 0) {
      fChannel = wf->fChannel;
      double gain = wf->fGain;
      double offset = wf->fOffset;

      fBaselineParams = GetBaselineParameters(wf, fBaselineExpected[fChannel], fBaselineDeviation[fChannel],
                                              fBaselineStartTime[fChannel], fBaselineEndTime[fChannel]);

      if (fBaselineParams.fBaselineError<=0) {
        clog << ClassName() << ": likely baseline fit failed at: run " << event->fRunNumber <<" event "<< event->fEventNumber <<" channel "<< wf->fChannel << endl;
      }

      wf->fSignalBase  = fBaselineParams.fBaseline;
      wf->fSignalNoise = fBaselineParams.fNoise;
      wf->fSignalMin   = fBaselineParams.fSignalMin;
      wf->fSignalMax   = fBaselineParams.fSignalMax;

      wf->fBaselineFitAmp = fBaselineParams.fBaselineFitAmp;
      wf->fBaselineFitLow = fBaselineParams.fBaselineFitLow;
      wf->fBaselineFitUp  = fBaselineParams.fBaselineFitUp;

      double threshold = fUseAbsoluteThreshold ? fPulseDetectThreshold[fChannel] : (fBaselineParams.fBaseline - fPulseDetectThreshold[fChannel]*fBaselineParams.fNoise);
      LocatePulses(wf, threshold);

      for(unsigned int j = 0; j < fRanges.size(); j++) {
        Pulse *pulse = event->GetNewPulse();

        FillPulseParameters(pulse, fRanges[j].StartSample, fRanges[j].EndSample, wf, threshold);

        pulse->fTimeError = 0;
        pulse->fAreaEff = 0;
        pulse->fAreaDiff = 0;
        pulse->fChiSquare = 0;
        pulse->fOverlayed = 0;
        pulse->fPartial = 0;
      }
    }
    Clear();
  }
  return kOk;
}

RED::BaselineParameters PulseFinder::GetBaselineParameters( const Waveform *wf,
                                                            double BaselineExpected, double BaselineDeviation,
                                                            double StartTime, double EndTime)
{
  RED::BaselineParameters baseParams;
  double SignalMin = 0;
  double SignalMax = 0;
  double BaselineFitLow = 0;
  double BaselineFitUp = 0;
  double Baseline = 0;
  double BaselineError = 0;
  double Noise = 0;
  double BaselineFitAmp = 0;

  if (EndTime <= StartTime) {
    StartTime = wf->fDelay;
    EndTime = (wf->fNumSamples-1)*wf->fPeriod + wf->fDelay;
  }

  // In order to fit properly, histogram bins must match ADC bins
  // So let's convert expectations to ADC units
  double expected_ADC = floor((BaselineExpected-wf->fOffset)/wf->fGain+0.5);
  double deviation_ADC = floor(BaselineDeviation/wf->fGain+0.5);

  // The edges of the histogram are shifted by 0.5 ADC so that the amplitudes
  // are in the centers of corresponding bins.
  int nbins = 2*int(deviation_ADC)+1;
  double low_edge  = (expected_ADC-deviation_ADC-0.5)*wf->fGain + wf->fOffset;
  double high_edge = (expected_ADC+deviation_ADC+0.5)*wf->fGain + wf->fOffset;

  TH1D *h1 = new TH1D("htemp","",nbins,low_edge,high_edge);
  h1->SetTitle(TString::Format("Amplitude hist for Channel %i",wf->fChannel));
  h1->GetXaxis()->SetTitle("U, mV");

  double bin_content = 0;
  double bin_time = 0;
  for(unsigned int i = 0; i < wf->fData.size(); i++) {
    bin_content = wf->fData[i]*wf->fGain + wf->fOffset;
    bin_time = i*wf->fPeriod + wf->fDelay;
    if (bin_time < StartTime || bin_time > EndTime) continue;
    h1->Fill(bin_content);
    if (i == 0) {
      SignalMax = SignalMin = bin_content;
    } else {
      if (SignalMin > bin_content) SignalMin = bin_content;
      if (SignalMax < bin_content) SignalMax = bin_content;
    }
  }
  baseParams.fSignalMin = SignalMin;
  baseParams.fSignalMax = SignalMax;

  // making fit options
  char draw_fit[8];
  draw_fit[0]='Q';
  draw_fit[1]='S';
  draw_fit[2]='N';
  draw_fit[3]='\0';

  double MaxBin = h1->GetMaximumBin();
  double MaxBinTime = h1->GetXaxis()->GetBinCenter(MaxBin);

  // special care for highly saturated waveforms
  double fit_range_factor = 1.;
  if (h1->GetBinContent(MaxBin) < fProcedureChoiceRelation * wf->fNumSamples)
    fit_range_factor = fFitVariationMultiplier;

  BaselineFitLow = MaxBinTime-fit_range_factor*fFitVariation;
  BaselineFitUp  = MaxBinTime+fit_range_factor*fFitVariation;

  baseParams.fBaselineFitLow = BaselineFitLow;
  baseParams.fBaselineFitUp = BaselineFitUp;

  TFitResultPtr fit = h1->Fit("gaus",draw_fit, "",BaselineFitLow,BaselineFitUp);

  if (fit.Get()) {
    Baseline = fit->GetParams()[1];
    BaselineError = (fit->GetErrors()[1]);
    Noise = fit->GetParams()[2];
    BaselineFitAmp = fit->GetParams()[0];
  } else {
    clog << ClassName() << ": Failed to fit baseline for channel #" << wf->fChannel << endl;
    // use trivial guesses for results
    Baseline = h1->GetMean();
    BaselineError = -h1->GetMeanError(); // FIXME, error flag should propagate differently
      // this value will also go to output file and can be caught during analysis
    Noise = h1->GetRMS();
    BaselineFitAmp = h1->GetMaximum();
  }

  baseParams.fBaseline = Baseline;
  baseParams.fBaselineError = BaselineError;
  baseParams.fNoise = Noise;
  baseParams.fBaselineFitAmp = BaselineFitAmp;

  delete h1;

  return baseParams;
}

double PulseFinder::GetBaselineParametersFast(const Waveform *wf) const
{
  return GetBaselineParametersFast(wf,fBaselineStartTime[wf->fChannel],fBaselineEndTime[wf->fChannel]);
}
double PulseFinder::GetBaselineParametersFast(const Waveform *wf, double aStartTime, double aEndTime) const
{
  return GetBaselineParametersFast(wf,aStartTime,aEndTime,fBaselineExpected[wf->fChannel],fBaselineDeviation[wf->fChannel]);
}
double PulseFinder::GetBaselineParametersFast(const Waveform *wf, double aStartTime, double aEndTime,
      double aExpected, double aDeviation) const
{
  //cout << __func__ <<" "<< aExpected <<" "<< aDeviation <<" "<< aStartTime <<" "<< aStartTime <<" "<< wf->fNumSamples << endl;
  if (aEndTime <= aStartTime) {
    aStartTime = wf->TimeToUser(0.);
    aEndTime = wf->TimeToUser(wf->fNumSamples);
  }

  // let's make amplitude histogram
  int nbins = (wf->fNumSamples>1000 ? 1000 : 100);
  int baseline_min = floor(wf->AmplFromUser(aExpected-aDeviation));
  int baseline_max =  ceil(wf->AmplFromUser(aExpected+aDeviation));
  int baseline_nbins = baseline_max-baseline_min;
  int nbins_scale = floor(baseline_nbins/nbins+0.5);
  if (nbins_scale==0) nbins_scale = 1;
  nbins = baseline_nbins/nbins_scale;
  TH1I *htemp = new TH1I("htemp","",nbins,baseline_min,baseline_min+nbins*nbins_scale);
  unsigned int begin_sample = std::max(int(floor(wf->TimeFromUser(aStartTime))),0);
  unsigned int   end_sample = std::min(int( ceil(wf->TimeFromUser(  aEndTime))),wf->fNumSamples);
  //cout << __func__ <<" "<< baseline_min <<" "<< baseline_max <<" "<< begin_sample <<" "<< end_sample <<" "<< nbins << endl;
  for(unsigned int i = begin_sample; i < end_sample; i++)
    htemp->Fill(wf->fData[i]);
  if (htemp->GetEntries() == 0) {
    clog << ClassName() << ": Failed to get any points of baseline for channel #" << wf->fChannel << endl;
    return NAN;
  }

  // let's find the highest peak
  // peak is continuous part of histogram with counts above threshold
  int thresh = htemp->GetEntries()/htemp->GetNbinsX()/2; // can be as low as 0
  int x_min, x_max, y_max = 0, sum_x = 0, sum_y = 0;
  int peak_x_min, peak_x_max, peak_y_max, peak_sum_y = 0; // cache found peak
  for (int i=1; i<=htemp->GetNbinsX(); i++) {
    const Int_t &y = htemp->GetArray()[i];
    if (y > thresh) {        // if number of counts is significant
      if (sum_x == 0) x_min = i;
      if (y_max < y) y_max = y;
      sum_x++, sum_y += y;
    } else if (sum_x > 0) {  // if bin is empty, but there was something before
      x_max = i;
      if (peak_sum_y < sum_y)
        peak_x_min = x_min, peak_x_max = x_max, peak_y_max = y_max, peak_sum_y = sum_y;
      //Printf(" base %d (%d, %d) %d %d",sum_x,x_min,x_max,y_max,sum_y);
      sum_x = 0, sum_y = 0;
    }
  }
  if (sum_x > 0) { // finish last peak if not yet
    x_max = htemp->GetNbinsX()+1;
    if (peak_sum_y < sum_y)
      peak_x_min = x_min, peak_x_max = x_max, peak_y_max = y_max, peak_sum_y = sum_y;
    //Printf(" base %d (%d, %d) %d %d",sum_x,x_min,x_max,y_max,sum_y);
  }
  if (peak_sum_y == 0) {
    clog << ClassName() << ": Failed to locate a baseline for channel #" << wf->fChannel << endl;
    return NAN;
  }

  // let's measure the peak better
  thresh = peak_sum_y/(peak_x_max-peak_x_min)/2; // ~1/4 of amplitude for gaussian
  sum_x = 0, sum_y = 0; int64_t sum_xy = 0;
  for (int i = peak_x_min; i < peak_x_max; i++) {
    const double &y = htemp->GetArray()[i];
    if (y > thresh)
      sum_x++, sum_y += y, sum_xy += i*y;
  }
  double res = htemp->GetXaxis()->GetXmin()+htemp->GetXaxis()->GetBinWidth(1)*sum_xy/sum_y;
  delete htemp;
  //cout << "baseline "<< peak_x_min <<" "<< peak_x_max <<" "<< thresh <<" = "<< sum_x <<" "<< 1.*sum_xy/sum_y <<" "<< res <<" "<< wf->AmplToUser(res) << endl;

  // can't returen RED::BaselineParameters at the moment
  return res;
}


void PulseFinder::LocatePulses(const Waveform* wf, const double threshold)
{

  double BinContent = 0;
  bool InPulse = false;
  PulseRange tmpRange; // here we remember the last pulse

  int nsamples = wf->fData.size();
  for (int i = 0; i < nsamples; ++i) {
    BinContent = wf->fData[i]*wf->fGain + wf->fOffset;

    if (!InPulse) {
      if (BinContent <= threshold) {
        InPulse = true;
        if (fRanges.empty() && tmpRange.StartSample < 0) 
          // a start of the first pulse.
          tmpRange.StartSample = std::max(i - (int)fPulsePreSamples, 0);
        else {
          // we have a previous pulse
          int start = i - fPulsePreSamples;
          if (start - tmpRange.EndSample > (int)fPulseMinInterval &&
              tmpRange.EndSample > 0) {
            // which is actually too far
            fRanges.push_back(tmpRange);
            tmpRange.Clear();
            tmpRange.StartSample = start;
          } else {
            // consume new pulse
            tmpRange.EndSample = -1;
          }
        }
      }

    } else {
      if (BinContent > threshold) {
        tmpRange.EndSample = std::min(std::max(i + (int)fPulsePostSamples, tmpRange.StartSample + (int)fPulseMinDuration), nsamples);
        InPulse = false;
      }
    }
  }
  if (tmpRange.StartSample > 0) {
    // we have pulse not stored
    if (tmpRange.EndSample < 0)
      // it isn't even ended yet
      tmpRange.EndSample = wf->fData.size();
    fRanges.push_back(tmpRange);
  }
}


void PulseFinder::FillPulseParameters(Pulse* pulse, const int StartSample , const int EndSample, const Waveform* wf, const double threshold)
{


  double PeakSample = -1;
  double Amplitude = 0;
  double BinContent = 0;

  for (int i = StartSample; i < EndSample; i++) {
    BinContent = wf->fData[i]*wf->fGain + wf->fOffset;
    if (BinContent <= threshold && -(BinContent - fBaselineParams.fBaseline) > Amplitude) {
      Amplitude = -(BinContent - fBaselineParams.fBaseline);
      PeakSample = i;
    }
  }


  double width10 = 0;
  double width50 = 0;
  double width90 = 0;

  double tmpRisetime = 0;
  double tmpFalltime = 0;

  double tmpArea = 0;
  double tmpTau = 0;

  double BinAmplitude = 0;
  double amplitude10 = 0.1 * Amplitude;
  double amplitude50 = 0.5 * Amplitude;
  double amplitude90 = 0.9 * Amplitude;
  double saturated = 0;

  for (int j = StartSample; j < EndSample; j++ ) {
    BinContent = wf->fData[j]*wf->fGain + wf->fOffset;
    if ((!fUseThresholdInPulse) || (BinContent <= threshold)) {
      BinAmplitude = -(BinContent - fBaselineParams.fBaseline);
      if (BinAmplitude >= amplitude10) width10 += 1;
      if (BinAmplitude >= amplitude50) width50 += 1;
      if (BinAmplitude >= amplitude90) width90 += 1;

      tmpTau += j * (BinAmplitude);

      if (wf->fData[j] <= 0 || wf->fData[j] >= pow(2,wf->fBitWidth)-1)
        saturated += 1;

      tmpArea += (BinAmplitude);

      if (BinAmplitude >= amplitude10 &&
          BinAmplitude <= amplitude90 &&
          j < PeakSample)
        tmpRisetime += 1;

      if (j > PeakSample &&
          BinAmplitude <= amplitude90 &&
          BinAmplitude >= amplitude10)
        tmpFalltime += 1;
    }
  }

  pulse->fChannel = wf->fChannel;
  pulse->fBaseline = fBaselineParams.fBaseline;
  pulse->fBaselineError = fBaselineParams.fBaselineError;
  pulse->fNoise = fBaselineParams.fNoise;
  pulse->fTime = StartSample*wf->fPeriod + wf->fDelay;
  pulse->fFirstSample = StartSample;
  pulse->fLastSample = EndSample;
  pulse->fWidth10 = width10 * wf->fPeriod;
  pulse->fWidth50 = width50 * wf->fPeriod;
  pulse->fWidth90 = width90 * wf->fPeriod;
  pulse->fRisetime = tmpRisetime * wf->fPeriod;
  pulse->fFalltime = tmpFalltime * wf->fPeriod;
  pulse->fPeakTime = PeakSample;
  pulse->fAmplitude = Amplitude;
  pulse->fArea = tmpArea * wf->fPeriod;
  pulse->fTau = tmpTau * wf->fPeriod/tmpArea + wf->fDelay;
  pulse->fSaturated = saturated;
}

void PulseFinder::Clear()
{
  fRanges.clear();
  fBaselineParams.Clear();
}
