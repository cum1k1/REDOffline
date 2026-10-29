#include <iostream>
#include <TRandom.h>
#include <TMath.h>

#include "REDUtils/SystemOfUnits.h"
#include "REDProcessing/Generator.hh"
#include "REDEvent/Event.hh"
#include "REDEvent/Waveform.hh"

using std::cout;
using std::endl;
using namespace CLHEP;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( Generator )
ClassImp( Generator )


Generator::Generator()
{
  fMode = 0;
  fNumChannels = 0;
  fNumSamples = 1;
  fPeriod = 1.;
  rnd = new TRandom();
}
Generator::~Generator()
{
  delete rnd;
}

ProcessingModule::EventStatus Generator::ProcessEvent(Event *ev)
{
  ev->Clear();

  cout << __func__ <<" "<< endl;
  for (int i=0; i<fNumChannels; i++) {
    Waveform *wf = ev->GetNewWaveform();//new REDWaveform();
    cout <<"\t"<< i <<" "<< fNumSamples <<" "<< wf << endl;
    wf->fChannel = i;
    wf->fNumSamples = fNumSamples;
    wf->fData.resize(fNumSamples);
    wf->fPeriod = fPeriod;
    wf->fDelay = 0.;
    wf->fGain = 0.001;
    wf->fOffset = 0.;
    wf->fPlaceOfTrigger = 0;
    wf->fBitWidth = 16;
    wf->fNameOfWaveform = "generator";
    double s1t  = rnd->Gaus(2000.*ns,1000.*ns)/fPeriod;
    double s1t1 = s1t + -10.*ns/fPeriod;
    double s1t2 = s1t + 400.*ns/fPeriod;
    double s2t  = s1t + rnd->Uniform(10000.*ns)/fPeriod;
    double s2t1 = s2t + -100.*ns/fPeriod;
    double s2t2 = s2t + 2000.*ns/fPeriod;
    double r = TMath::Sqrt(rnd->Uniform(0,10000));
    double s1a = 100.*TMath::Gaus(r,0,100);
    double s2a = 100.*TMath::Gaus(r,0,30);
    for (int j=0; j<fNumSamples; j++) {
      int signal = rnd->Gaus(0,1);
      if (s1t1<j && j<s1t2) {
        double s = s1a*((j<s1t)?
                        (TMath::Gaus(j,s1t,1.)):
                        (TMath::Exp(-(j-s1t)*fPeriod/(30.*ns))));
        signal -= rnd->Poisson(s);
      }
      if (s2t1<j && j<s2t2) {
        double s = s2a*((j<s2t)?
                        (TMath::Gaus(j,s2t,10.)):
                        ((j<s2t+1000.*ns/fPeriod)?
                         (1.):
                         (TMath::Exp(-(j-s2t-1000.*ns/fPeriod)*fPeriod/(100.*ns)))));
        signal -= rnd->Poisson(s);
      }
      //cout << "\t"<< i <<" "<< j <<" "<< signal <<" "<< s1t1 <<" "<< s1t2 << endl;
      wf->fData[j] = signal;
    }
    //ev->AddWaveform();
  }

  return kOk;
}
