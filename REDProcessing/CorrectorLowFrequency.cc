/******************************************************************************
 *
 *  This module corrects waveforms for low frequency baseline drift.
 *
 *  Here we presume:
 *  - Drift is effectively a pileup that adds to a true signal
 *  - Drift is much slower than any signal
 *  - Signals are fast negative pulses with sharp edges
 *  - Signal pulses can come in dense packs, up to a full cover, where
 *    they stack on each other, so the amplitude is bigger than baseline drift
 *
 *  The chosen method is based on approximation of baseline using spline with
 *  further subtraction of spline interpolation. The waveform is splitted into
 *  chunks. Each chunk provides a knot for the spline calculated as an average
 *  of time and amplitude among samples that don't belong to a pulse. Pulses
 *  are determined using the moving average, which is calculated using a
 *  digital low-pass filter of the first order. For a better experience the
 *  filter is made with two stages. The first stage is stepwise symmetric:
 *          { y_{i-1}, if |x_{i} - A_{base}| >= A_{pulse}
 *  y_{i} = { y_{i-1}*(1-q) + (x_{i}+x_{i-1})/2*q,
 *          { y_{i-1}*(1-p) + (x_{i}+x_{i-1})/2*p, if |x_{i}-y_{i-1}| < A_{noise}
 *  The second stage is stepwise asymmetric:
 *  y_{i} = z_{i}
 *          { z_{i-1}, if y_{i} - x_{i} >= A_{noise}
 *  z_{i} = { z_{i-1}*(1-p)+x_{i}*p
 *  This stage can be reiterated if too many samples lie above moving average.
 *  All samples with amplitude above moving average minus A_{noise} are
 *  treated as baseline samples and do participate in calculation of straight
 *  line approximation for each chunk. If there are too few samples in a chunk,
 *  then the knot in this chunk is omitted.
 *  Then one extra knot is added in the front and one knot in the end of chunk
 *  list. These knots are calculated by extrapolation of corresponding chunks.
 *  Using calculated knots, a cubic spline is constructed.
 *
 *  Author: Vladimir Belov <belov@itep.ru> 2022
 *
 *****************************************************************************/

#include "CorrectorLowFrequency.hh"

#include <iostream>
#include <TROOT.h>
#include <TSpline.h>
#include "REDProcessing/PulseFinder.hh"

#include "REDEvent/Event.hh"
#include "REDEvent/RunInfo.hh"

using std::cout;
using std::cerr;
using std::endl;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( CorrectorLowFrequency )
ClassImp( CorrectorLowFrequency )

extern int g_techChannels; // FIXME a bit mask of channels to skip by CorrectorLowFrequency
                           // (the same as skipped by clustering)

CorrectorLowFrequency::CorrectorLowFrequency()
  : fFinder(nullptr)
{
  fBaselineStartTime = 0.;
  fBaselineEndTime = 0.;
  fChunkDuration = 1.e-6;
  fCutFrequency = 1.e+6;
  fPrePulseMargin = 0.1e-6;
  fPostPulseMargin = 0.1e-6;
  fThresholdSignal.push_back(0.1);
  fThresholdNoise.push_back(0.03);
}
CorrectorLowFrequency::~CorrectorLowFrequency()
{
}

struct WFCorr {
  double baseline;
  double threshold_noise, threshold_signal;
  double filter_p_regular, filter_p_signal;
  int num_chunks, chunk_len, chunk_off;
  int pre_pulse_margin, post_pulse_margin;
  void SmoothWaveform(const Waveform *wf_src, Waveform *wf_dst);
  TSpline* ConstructSpline(const Waveform *wf_orig, const Waveform *wf_smooth);
};
std::ostream& operator<< (std::ostream &os, const WFCorr &par)
{
  os << "WFCorr:"
     << " baseline = " << par.baseline <<","
     << " threshold = (" << par.threshold_noise <<", "<< par.threshold_signal <<"),"
     << " filter = (" << par.filter_p_regular <<", "<< par.filter_p_signal <<"),"
     << " chunks = (" << par.num_chunks <<", "<< par.chunk_len <<", "<< par.chunk_off <<"),"
     << " pulse = (" << par.pre_pulse_margin <<", "<< par.post_pulse_margin <<")";
  return os;
}
void WFCorr::SmoothWaveform(const Waveform *wf_src, Waveform *wf_dst)
{
  int n_ovfl, n_ovfl_old = 0;
  double s1 = baseline;
  double s2 = baseline;
    // estimate better the very beginning
    {
      int k = 0, chunk_len_short = chunk_len/10;
      int n = 0, s = 0;
      for (int j=0,i=0; j<chunk_len_short; j++,i++) {
        const double &y = wf_src->fData[i];
        if (fabs(y-baseline)<=threshold_signal)
          ++n, s+=y;
      }
      if (n>0)
        s1 = s2 = 1.*s/n;
    }
  double old_s1 = s1, old_s2 = s2;
  for(int k=0; k<num_chunks; k++) {
    // iterate over chunks
    for (int l=0; l<3; l++) {
      // for each chunk we try several passes
      s1 = old_s1, s2 = old_s2; n_ovfl = 0;
      for (int j=0,i=k*chunk_len+chunk_off; j<chunk_len; j++,i++) {
        if (i<0 || i>=wf_src->fNumSamples) continue;
        const double &y = wf_src->fData[i];
        double dy = i>0 ? 0.5*(wf_src->fData[i-1]+y)-s1 : y-s1;
        if (l==0) {
          if (fabs(y-baseline)<=threshold_signal)
            s1 += (fabs(dy)<=threshold_noise ? filter_p_regular*dy : filter_p_signal*dy);
        } else {
          s1 = wf_dst->fData[i]<s1-100 ? s1 : wf_dst->fData[i];
        }
        if (y>s1-threshold_noise) {
          s2 = (1-filter_p_regular)*s2 + filter_p_regular*y;
          wf_dst->fData[i] = s2;
          if (y>s2+threshold_noise) n_ovfl++;
        } else {
          wf_dst->fData[i] = s2-200;
        }
      }
      // if overflow is small or not changing then we're done
      if (n_ovfl<chunk_len/100 || n_ovfl==n_ovfl_old) break;
      n_ovfl_old = n_ovfl;
    }
    old_s1 = s1, old_s2 = s2;
    //cout << "smooth " << k <<" - "<< n_ovfl <<" "<< s1 <<" "<< s2 << endl;
  }
}

class LinearFitter {
private:
  double x0, y0;
  double sx, sy, sxy, sx2;
  unsigned n;
public:
  LinearFitter(double xmed = 0., double ymed = 0.): x0(xmed), y0(ymed) {
    sx = sy = sxy = sx2 = 0.; n = 0; }
  ~LinearFitter() { ; }
  void Add(double x_, double y_) {
    double x = x_ - x0, y = y_ - y0;
    sx += x, sy += y, sxy += x*y, sx2 += x*x;
    n++;
  }
  void Print(const char * = "") {
    Printf("LinearFitter(%g, %g)",x0,y0);
    Printf("  sx=%g sy=%g sxy=%g sx2=%g n=%d",sx,sy,sxy,sx2,n);
  }
  void Clear(const char * = "") {
    sx = sy = sxy = sx2 = 0.; n = 0; }
  double GetParameter(int i) {
    if (i>1 || n<=0)
      return NAN;
    if (n==1) {
      if (i==0) return y0+sy;
      else      return 0.;
    //} else if (n==2) {
      //if (i==0) return y0+yx*0.5;
      //else      return 
    } else {
      double d = n*sx2-sx*sx;
      if (d==0) {
        if (i==0) return y0+sy/n;
        else      return 0.;
      } else {
        double p1 = (n*sxy-sx*sy)/d;
        if (i==0) return y0+(sx2*sy-sx*sxy)/d-p1*x0;
        else      return p1;
      }
    }
  }
  double GetXmean() {
    if (n<=0)
      return NAN;
    if (n==1) {
      return x0+sx;
    } else {
      return x0+sx/n;
    }
  }
  double GetYmean() {
    if (n<=0)
      return NAN;
    if (n==1) {
      return y0+sy;
    } else {
      return y0+sy/n;
    }
  }
};

TSpline* WFCorr::ConstructSpline(const Waveform *wf_orig, const Waveform *wf_smooth)
{
  // we will use one point in each chunk, plus extra point at begin/end
  int npoints = num_chunks+2;
  double xx[npoints], yy[npoints]; int nn[npoints];
  for(int i=0;i<npoints;i++) nn[i]=0;

  // make linear fit in chunks
  LinearFitter fit(0.5*chunk_len,0.);
  for(int k=0; k<num_chunks; k++) {
    fit.Clear();
    int i1 = k*chunk_len+chunk_off, i2 = i1+chunk_len;
    if (i1<0) i1=0; if (i2>wf_orig->fNumSamples) i2 = wf_orig->fNumSamples;
    double s1 = wf_smooth->fData[i1];
    int after_pulse = 0;
    for (int j=0,i=i1; i<i2; j++,i++) {
      const double &y = wf_orig->fData[i];
      s1 = wf_smooth->fData[i]<s1-100 ? s1 : wf_smooth->fData[i];
      if (y>s1-threshold_noise) after_pulse++; else after_pulse = 0;
      if (after_pulse>post_pulse_margin) {
        fit.Add(j-pre_pulse_margin,wf_orig->fData[i-pre_pulse_margin]);
        nn[k+1]++;
      }
    }
    //fit.Print();
    double p0 = fit.GetParameter(0), p1 = fit.GetParameter(1);
    //cout << "linfit " << k <<" - "<< i1 <<" "<< i2 <<" "<< p0 <<" "<< p1 << endl;;
    if (!std::isnan(p0)) {
      xx[k+1] = (i1+fit.GetXmean());
      yy[k+1] = fit.GetYmean();
    } else {
      xx[k+1] = (i1+chunk_len/2);
      yy[k+1] = yy[k];
    }
    if (k==0) {
      xx[0] = (-chunk_len/2);
      if (!std::isnan(p0)) {
        yy[0] = p0-p1*chunk_len/2;
      } else {
        yy[0] = yy[1];
      }
      nn[0] = -1;
    }
    if (k==num_chunks-1) {
      xx[npoints-1] = (wf_orig->fNumSamples+chunk_len/2);
      if (!std::isnan(p0)) {
        yy[npoints-1] = p0+p1*(i2-i1+chunk_len/2);
      } else {
        yy[npoints-1] = yy[npoints-2];
      }
      nn[npoints-1] = -1;
    }
  }

  // skip points with too little counts
  int thresh = chunk_len/10; int npoints2 = 0;
  for (int i=0;i<npoints;i++) {
    if (nn[i]>thresh || nn[i]==-1) {
      if (npoints2<i)
        xx[npoints2] = xx[i], yy[npoints2] = yy[i], nn[npoints2] = nn[i];
      npoints2++;
    }
  }

  if (npoints2<=2)
    // there is nothing but end points
    // we have no data to get correction right
    return nullptr;

  // recalculate end points
  if (npoints2==3) {
    // there is only one good point
    yy[0] = yy[2] = yy[1];
  } else {
    // there are at least 2 good points
    // use extrapolation from the two closest points
    int i = 1;
    yy[i-1] = yy[i]+(yy[i+1]-yy[i])/(xx[i+1]-xx[i])*(xx[i-1]-xx[i]);
    i = npoints2-2;
    yy[i+1] = yy[i]+(yy[i-1]-yy[i])/(xx[i-1]-xx[i])*(xx[i+1]-xx[i]);
  }

  TSpline3 *spl = new TSpline3("spl",xx,yy,npoints2);
  return spl;
}

ProcessingModule::EventStatus CorrectorLowFrequency::ProcessEvent(Event *event)
{
  //cout << __PRETTY_FUNCTION__ <<" "<< (void*)fFinder << endl;

  if (!fFinder)
    fFinder = FindPulseFinder();
  if (!fFinder) return kError;

  const int MaxNumChannels = event->GetRunInfo()->fNumChannels;
  if (MaxNumChannels > static_cast<int>(fThresholdSignal.size())) {
    SetThresholdSignal(MaxNumChannels, 0.);
  }
  if (MaxNumChannels > static_cast<int>(fThresholdNoise.size())) {
    SetThresholdNoise(MaxNumChannels, 0.);
  }
  fFinder->CheckChannelParameters(event->GetRunInfo()->fNumChannels);

  for (int iwf = 0; iwf < event->GetNumWaveforms(); iwf++) {
    Waveform *wf = event->GetWaveform(iwf);
    const int &ichannel = wf->fChannel;
    if (ichannel >= 0 && !(::g_techChannels & (1 << ichannel))) {

      // we determine position of rough baseline using PulseFinder method and parameters
      WFCorr corr;
      corr.baseline = fBaselineStartTime!=0. && fBaselineEndTime!=0. ?
        fFinder->GetBaselineParametersFast(wf,fBaselineStartTime,fBaselineEndTime) :
        fFinder->GetBaselineParametersFast(wf);
      // now fill corrector parameters
      corr.threshold_noise = fThresholdNoise[wf->fChannel]/wf->fGain;
      corr.threshold_signal = fThresholdSignal[wf->fChannel]/wf->fGain;
      double omt = 2*M_PI*fCutFrequency*wf->fPeriod;
      double p = -(1-sin(omt))/cos(omt);
      corr.filter_p_regular = 1+p;
      corr.filter_p_signal = 0.1*(1+p);
      corr.chunk_len = int(floor(fChunkDuration/wf->fPeriod));
      corr.num_chunks = int(ceil(1.*wf->fNumSamples/corr.chunk_len));
      int delta = corr.num_chunks*corr.chunk_len - wf->fNumSamples;
      corr.chunk_off = -delta/2;
      corr.pre_pulse_margin = int(ceil(fPrePulseMargin/wf->fPeriod));
      corr.post_pulse_margin = int(ceil(fPostPulseMargin/wf->fPeriod));

      // create smoothed waveform
      Waveform *wf_smooth = new Waveform();
      wf_smooth->fNumSamples = wf->fNumSamples;
      wf_smooth->fData.resize(wf->fNumSamples);
      wf_smooth->fNameOfWaveform = "smoothed waveform";
      corr.SmoothWaveform(wf,wf_smooth);

      TSpline* spl = corr.ConstructSpline(wf,wf_smooth);
      if (!spl) {
        // there is no spline
        cerr << ClassName() << ": Correction failed at: run " << event->fRunNumber <<" event "<< event->fEventNumber <<" channel "<< wf->fChannel << endl;
        // let's skip this waveform
        continue;
      }
      double base = wf->AmplFromUser(0.); // where 0. is
      for(int i = 0; i < wf->fNumSamples; i++)
        wf->fData[i] = wf->fData[i] - spl->Eval(i) + base;
      ++(wf->fIsModified);

      delete spl;
      delete wf_smooth;
    }
  }

  return kOk;
}

PulseFinder* CorrectorLowFrequency::FindPulseFinder()
{
  ProcessingModule *module = static_cast<RED::ProcessingModule*>(gROOT->FindObject(fFinderName));
  PulseFinder* pf = dynamic_cast<RED::PulseFinder*>(module);
  return pf;
}
