#include <iostream>
//#include <vector>
#include <cmath>

#include "REDEvent/Waveform.hh"
#include "REDEvent/RunInfo.hh"
#include "REDEvent/Pulse.hh"
#include "REDEvent/Event.hh"

#include "Inspector.hh"

#include <TGFrame.h>
//#include <GuiTypes.h> // Error_t
#include <TGLabel.h>
#include <TGXYLayout.h>
#include <TGComboBox.h>
#include <TGNumberEntry.h>
#include <TGButton.h>
#include <TGTextEntry.h>
#include <TGTextView.h>
#include <TRootEmbeddedCanvas.h>
#include <TCanvas.h>
//#include <.h>

#include <TGraph.h>
#include <TMultiGraph.h>
#include <TBox.h>
#include <TLine.h>
#include <TH2F.h>
#include <TF1.h>

#include <TStyle.h> // SetPalette
#include <TSystem.h> // sleep()
#include <TApplication.h> // ProcessLine

using namespace RED;
using std::cout;
using std::cerr;
using std::endl;

extern int g_techChannels; // FIXME a bit mask of channels to skip by CorrectorBallistic
                           // (the same as skipped by clustering)

RED_PROCESSING_MODULE_IMPLEMENT( Inspector )
ClassImp( Inspector )

#define MAKE_LINE(S,N,V) do { s+=(N); s+=" = "; s+=(V); s+="\n"; } while (0);

Inspector::Inspector()
{
  fSkipNumEvents = 0;
  fMain = 0;
  fPad = 0;
  if (gStyle) gStyle->SetPalette(1);
  fHeatPrintMode = kCluster;
//  CreateWindow(); // FIXME move to Initialize()
}

Inspector::~Inspector()
{
  if (fMain) CloseWindow();
}

ProcessingModule::EventStatus Inspector::ProcessEvent(Event *event)
{
  cout << __PRETTY_FUNCTION__ <<": skip " << fSkipNumEvents << endl;

  // skip number of events as user asked
  if (fSkipNumEvents>0) {
    fSkipNumEvents--;
    return kOk;
  }

  // create window on first run
  if (!fMain) CreateWindow();

  fCacheEvent = event;
  DoDraw();
  WaitUser();
  fCacheEvent = 0;

  return kOk;
}

void Inspector::CreateWindow()
{
  int w = 800, h = 400;
  if (fMain!=0) return; // already initialized

  cout << "InspectorFrame" << endl;
  //gApplication->ProcessLine(".class Inspector");
  fMain = new TGMainFrame(gClient->GetRoot(), w, h, kHorizontalFrame);
  fMain->SetWindowName("RED Inspector");
  fMain->Connect("CloseWindow()","RED::Inspector",this,"CloseWindow()");
  //fMain->Connect("ProcessedEvent(Event_t*)","Inspector::InspectorFrame",this,"ProcessedEvent(Event_t*)");
  //gApplication->Connect("ReturnPressed(char*)","Inspector::InspectorFrame",this,"ChangeSkip()");

  //TGGroupFrame *fControls = new TGGroupFrame(fMain,"Controls",kFixedSize);
  TGVerticalFrame *vframe = new TGVerticalFrame(fMain);
  {
    TGHorizontalFrame *hframe = 0;
    hframe = new TGHorizontalFrame(vframe);
    hframe->AddFrame(new TGLabel(hframe,"Mode"),
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 0, 0, 3, 0));
    fModeSelector = new TGComboBox(hframe);
    fModeSelector->AddEntry("kModeNone",kModeNone);
    fModeSelector->AddEntry("kModeWaveform",kModeWaveform);
    fModeSelector->AddEntry("kModeAmplHist",kModeAmplHist);
    fModeSelector->AddEntry("kModeHeatplot",kModeHeatplot);
    fModeSelector->AddEntry("kModePlanes",kModePlanes);
    fModeSelector->AddEntry("kModeEvent3D",kModeEvent3D);
    fModeSelector->AddEntry("kModeClusters",kModeClusters);
    fModeSelector->Resize(100,22);
    fModeSelector->Select(0);
    fModeSelector->Connect("Selected(Int_t)","RED::Inspector",this,"ChangeMode()");
    hframe->AddFrame(fModeSelector,
                     new TGLayoutHints(kLHintsExpandX | kLHintsTop, 5, 0, 0, 0));
    vframe->AddFrame(hframe,
                     new TGLayoutHints(kLHintsExpandX | kLHintsTop, 0, 0, 2, 0));

    hframe = new TGHorizontalFrame(vframe);
    hframe->AddFrame(new TGLabel(hframe,"Skip"),
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 0, 0, 3, 0));
    fSkipEvents = new TGNumberEntry(hframe, 0, 5, -1, TGNumberFormat::kNESInteger, TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax, 0, 99999);
    fSkipEvents->Connect("ValueSet(Long_t)","RED::Inspector",this,"ChangeNext()");
    hframe->AddFrame(fSkipEvents,
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 0, 0, 0));
    hframe->AddFrame(new TGLabel(hframe,"events"),
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 0, 3, 0));
    fNext = new TGTextButton(hframe,"Next");
    fNext->Connect("Clicked()","RED::Inspector",this,"NextEvent()");
    hframe->AddFrame(fNext,
                     new TGLayoutHints(kLHintsRight | kLHintsTop, 5, 1, 0, 0));
    vframe->AddFrame(hframe,
                     new TGLayoutHints(kLHintsExpandX | kLHintsTop, 0, 0, 2, 0));

    hframe = new TGHorizontalFrame(vframe);
    hframe->AddFrame(new TGLabel(hframe,"Channel"),
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 0, 0, 3, 0));
    fChannelNumber = new TGNumberEntry(hframe, 1, 4, -1, TGNumberFormat::kNESInteger, TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax, 1, 1);
    fChannelNumber->Connect("ValueSet(Long_t)","RED::Inspector",this,"ChangeChannel()");
    hframe->AddFrame(fChannelNumber,
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 0, 0, 0));
    fChannelLabel = new TGTextEntry(hframe,"");
    fChannelLabel->SetEnabled(false);
    fChannelLabel->SetWidth(60);
    hframe->AddFrame(fChannelLabel,
                     new TGLayoutHints(kLHintsExpandX | kLHintsTop, 5, 0, 0, 0));
    vframe->AddFrame(hframe,
                     new TGLayoutHints(kLHintsExpandX | kLHintsTop, 0, 0, 5, 0));

    hframe = new TGHorizontalFrame(vframe);
    hframe->AddFrame(new TGLabel(hframe,"Index"),
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 0, 0, 3, 0));
    fIndex = new TGNumberEntry(hframe, 1, 4, -1, TGNumberFormat::kNESInteger, TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax, 1, 1);
    fIndex->Connect("ValueSet(Long_t)","RED::Inspector",this,"ChangeIndex()");
    hframe->AddFrame(fIndex,
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 5, 0, 0, 0));
    vframe->AddFrame(hframe,
                     new TGLayoutHints(kLHintsExpandX | kLHintsTop, 0, 0, 5, 0));

    vframe->AddFrame(new TGLabel(vframe,"Info"),
                     new TGLayoutHints(kLHintsLeft | kLHintsTop, 0, 0, 5, 0));
    fInfo = new TGTextView(vframe);
    fInfo->SetWidth(200);
    vframe->AddFrame(fInfo,
                     new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 0, 0, 2, 0));
  }
  fMain->AddFrame(vframe, new TGLayoutHints(kLHintsLeft | kLHintsExpandY, 5, 0, 5, 5));

  TRootEmbeddedCanvas *canv = new TRootEmbeddedCanvas("ec1", fMain, 600, 400);
  fMain->AddFrame(canv, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 5, 0, 0, 0));
  fPad = canv->GetCanvas();
  //fCanvas->SetBorderMode(0);

  fMain->MapSubwindows();
  fMain->Resize();
  fMain->MapWindow();
}
void Inspector::CloseWindow()
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fMain!=0) {
    fMain->Cleanup();
    fMain->DestroyWindow();
    delete fMain;
    fMain = 0;
  }
  fWait = false;
}
void Inspector::ChangeMode()
{
  Modes mode = (Modes)fModeSelector->GetSelected();
  cout << __PRETTY_FUNCTION__ <<" "<< fModeSelector->GetSelected() << endl;
  // change limits
  DoDraw();
}
void Inspector::ChangeNext()
{
  fNext->SetText((fSkipEvents->GetIntNumber()>0)?"Skip":"Next");
}
void Inspector::NextEvent()
{
  fWait = false;
  fSkipNumEvents = fSkipEvents->GetIntNumber();
}
void Inspector::ChangeChannel()
{
  cout << __PRETTY_FUNCTION__ << endl;
  DoDraw(); // FIXME switch (mode)
}
void Inspector::ChangeIndex()
{
  cout << __PRETTY_FUNCTION__ << endl;
}
void Inspector::WaitUser()
{
  cout << __PRETTY_FUNCTION__ << endl;
  // idea copied from TPad::WaitPrimitive()
  fWait = true;
  while (fWait && !gSystem->ProcessEvents()) {
    //cout << fCanvas->GetEvent() << endl;
    gSystem->Sleep(10);
  }
}
/*void Inspector::InspectorFrame::ProcessedEvent(Event_t *event)
{
  cout << __PRETTY_FUNCTION__ <<" "<< event << endl;
  }*/
void Inspector::DoDraw()
{
  ClearDrawnObjects();

  if (fMain==0 || fCacheEvent==0) return; // nothing to do
  Modes mode = (Modes)((fModeSelector!=0)?fModeSelector->GetSelected():1);
  int ichannel = ((fChannelNumber!=0)?fChannelNumber->GetIntNumber()-1:0);
  int index = ((fIndex!=0)?fIndex->GetIntNumber()-1:0);
  Event *event = fCacheEvent;
  cout << __PRETTY_FUNCTION__ << endl;
  fChannelNumber->SetLimitValues(1,event->GetNumWaveforms()); // FIXME

  TVirtualPad *old = gPad;
  fPad->cd();
  switch (mode) {
  case kModeNone: { // simple text dump
    event->Print("S");
    event->GetRunInfo()->Print();
    break;
  }
  case kModeWaveform: { // individual waveform plot
    TString s;
    MAKE_LINE(s,"fRunNumber",event->fRunNumber);
    MAKE_LINE(s,"fEventNumber",event->fEventNumber);
    MAKE_LINE(s,"GetNumWaveforms()",event->GetNumWaveforms());
    MAKE_LINE(s,"GetNumPulses()",event->GetNumPulses());
    MAKE_LINE(s,"GetNumClusters()",event->GetNumClusters());
    MAKE_LINE(s,"ichannel",ichannel);
    //MAKE_LINE("",);
    SetInfo(s);
    Waveform *wf = (event->GetWaveform(ichannel));
    if (wf) {
      TGraph *gr = new TGraph(wf->fNumSamples);
      RegisterDrawnObject(gr);
      gr->SetName("grtemp");
      gr->SetTitle(TString::Format("Inspector event (%d, %d), channel %d (%s)",
                                   event->fRunNumber,event->fEventNumber,
                                   ichannel,wf->fNameOfWaveform.c_str()));
      for (int i=0; i<gr->GetN(); i++)
        gr->SetPoint(i,i*wf->fPeriod+wf->fDelay,wf->fData[i]*wf->fGain+wf->fOffset);
      gr->Draw("AL");
      for (int i=0; i<event->GetNumPulses(); i++) {
        Pulse *pls = event->GetPulse(i);
        if (!pls || pls->fChannel!=wf->fChannel) continue;
        /*int j1 = (pls->fTime-wf->fDelay)/wf->fPeriod, j2 = j1 + pls->fWidth/wf->fPeriod;
        double z_min = wf->fData[j1], z_max = wf->fData[j1];
        for (;j1<j2;j1++) {
          if (z_min > wf->fData[j1]) z_min = wf->fData[j1];
          if (z_max < wf->fData[j1]) z_max = wf->fData[j1];
        }
        z_min = z_min*wf->fGain+wf->fOffset, z_max = z_max*wf->fGain+wf->fOffset;
        TBox *box = new TBox(pls->fTime, z_min, pls->fTime+pls->fWidth, z_max);*/
        TBox *box = new TBox(pls->fFirstSample*wf->fPeriod + wf->fDelay, pls->fBaseline, (pls->fLastSample)*wf->fPeriod + wf->fDelay, pls->fBaseline - pls->fAmplitude);
        RegisterDrawnObject(box);
        box->SetLineColor(kRed);
        box->SetFillStyle(0);
        box->Draw("same");
      }
    } else {
      cerr << __PRETTY_FUNCTION__ <<": can't find waveform for channel " << ichannel << endl;
      //return kError;
    }
    break;
  }
  case kModeAmplHist: { // make a histogram with samples of a waveform
    Waveform *wf = (event->GetWaveform(ichannel));
    if (wf) {
      // we want bin-to-bin match for the histogram, so number of bins is (max-min)+1
      // also we want empty bins at left and right edges, so +2
      int nbins = int(floor((wf->fSignalMax-wf->fSignalMin)/wf->fGain+0.5))+3;

      // and discrete values of voltage are at the histogram's bin centers (not lower edges) -> -0.5 shift
      TH1D *h_amplitudes = new TH1D("h_amplitudes","",nbins,
                                    wf->fSignalMin-1.5*wf->fGain,wf->fSignalMax+1.5*wf->fGain);
      RegisterDrawnObject(h_amplitudes);
      for (int sample_cnt=0; sample_cnt<wf->fNumSamples; sample_cnt++)
        h_amplitudes->Fill(wf->fData[sample_cnt]*wf->fGain+wf->fOffset);

      TF1 *baseline_fit = new TF1("baseline_fit","gaus",wf->fBaselineFitLow,wf->fBaselineFitUp);
      baseline_fit->SetParameter(0,wf->fBaselineFitAmp);
      baseline_fit->SetParameter(1,wf->fSignalBase);
      baseline_fit->SetParameter(2,wf->fSignalNoise);
      baseline_fit->SetLineColor(kBlue);
      h_amplitudes->GetListOfFunctions()->Add(baseline_fit); // now it belongs to histogram

      h_amplitudes->SetStats(false); // don't write stats
      h_amplitudes->SetFillStyle(0); // transparent histogram
      h_amplitudes->Draw("bar0 e0"); // drawn as a bar chart with statistical error bars

      TLine *baseline_amplitude = new TLine(wf->fSignalBase,0,wf->fSignalBase,h_amplitudes->GetMaximum());
      RegisterDrawnObject(baseline_amplitude);
      baseline_amplitude->SetLineColor(kRed);
      baseline_amplitude->SetLineWidth(2);
      baseline_amplitude->Draw("same");
    } else {
      cerr << __PRETTY_FUNCTION__ <<": can't find waveform for channel " << ichannel << endl;
      //return kError;
    }
    break;
  }
  case kModeHeatplot: { // full event heat plot
    int nch = event->GetRunInfo()->fNumChannels;
    bool wf_seen = false;
    int ich_min, ich_max;
    double t_min, t_max, dt_min;
    for (int i=0; i<nch; i++) {
      Waveform *wf = (event->GetWaveform(i));
      if (wf) {
        if (wf->fChannel < 0 || (::g_techChannels & (1 << wf->fChannel))) continue;
        if (!wf_seen) { // first found
          ich_min = ich_max = wf->fChannel;
          t_min = wf->fDelay, t_max = wf->fNumSamples*wf->fPeriod+wf->fDelay, dt_min = wf->fPeriod;
          wf_seen = true;
        } else {
          if (ich_min > wf->fChannel) ich_min = wf->fChannel;
          if (ich_max < wf->fChannel) ich_max = wf->fChannel;
          if (t_min > wf->fDelay) t_min = wf->fDelay;
          double x = wf->fNumSamples*wf->fPeriod+wf->fDelay;
          if (t_max < x) t_max = x;
          if (dt_min > wf->fPeriod) dt_min = wf->fPeriod;
        }
      }
    }
    TH2F *h = new TH2F("htemp","htemp",(t_max-t_min)/dt_min,t_min,t_max,ich_max-ich_min+1,ich_min-0.5,ich_max+0.5);
    h->SetTitle(TString::Format("Inspector event (%d, %d)",
                                event->fRunNumber,event->fEventNumber));
    h->SetStats(false);
    RegisterDrawnObject(h);

    for (int i=0; i<nch; i++) {
      Waveform *wf = (event->GetWaveform(i));
      if (wf) {
        if (wf->fChannel < 0 || (::g_techChannels & (1 << wf->fChannel))) continue;
        double z_mean = 0;
        for (int j=0; j<wf->fNumSamples; j++) z_mean += wf->fData[j];
        z_mean /= wf->fNumSamples;
        for (int j=0; j<h->GetNbinsX(); j++) {
          double x = ((t_min + dt_min*j)-wf->fDelay)/wf->fPeriod;
          int ix = ceil(x);
          double dx = ix-x;
          //if (j<20) cout <<"xxx "<< i <<" "<< j <<" "<< x <<" "<< ix <<" "<< 0 << endl;
          if (ix>1 && ix<wf->fNumSamples) {
            double z = (wf->fData[ix-1]*(dx)+wf->fData[ix]*(1.-dx));
            //if (j<20) cout <<"        "<< wf->fData[ix-1] <<" "<< wf->fData[ix] <<" "<< wf->fData[ix+1] <<" "<< z <<" "<< z-z_mean << endl;
            h->SetBinContent(j,wf->fChannel+1,-(z-z_mean)*wf->fGain);
          }
        }
      }
    }
    h->Draw("colz");
    if (fHeatPrintMode == kPulse) {
        for (int i=0; i<nch; i++) {
          Waveform *wf = (event->GetWaveform(i));
          for (int i=0; i<event->GetNumPulses(); i++) {
            Pulse *pls = event->GetPulse(i);
            //cout << "        "<< pls->fChannel <<" "<< pls->fTime <<" "<< pls->fAmplitude <<" "<< pls->fTime+pls->fWidth << endl;
            TBox *box = new TBox(pls->fFirstSample*wf->fPeriod + wf->fDelay, pls->fChannel-0.5, (pls->fLastSample*wf->fPeriod + wf->fDelay), pls->fChannel+0.5);
            RegisterDrawnObject(box);
            box->SetLineColor(kMagenta);
            box->SetFillStyle(0);
            box->Draw();
          }
        }
    } else if (fHeatPrintMode == kCluster) {

      struct ChannelPulses {
        int ChannelUsed;
        int StartSample;
        int EndSample;
        double Period;
        double Delay;

        ChannelPulses():ChannelUsed(-1), StartSample(-1), EndSample(-1),
        Period(-1), Delay(-1)
        { ; }
        ~ChannelPulses()
        { ; }
        void Clear()
        {
          ChannelUsed = -1;
          StartSample = -1;
          EndSample = -1;
          Period = -1;
          Delay = -1;
        }
      };

      ChannelPulses *pulses = new ChannelPulses[event->fNumChannels];

      if (event->fNumChannels>0) {
        for (int i=0; i<event->GetNumClusters(); i++) {
          Cluster* cluster=event->GetCluster(i);
          for (int pls=0; pls<cluster->GetNumPulses(); pls++) {
            Pulse *pulse = cluster->GetPulse(pls);
            if (pulse) {
              //            std::cout << "StartSample "<< pulse->fFirstSample<< std::endl;
              if (pulses[pulse->fChannel].StartSample == -1 || pulses[pulse->fChannel].StartSample > pulse->fFirstSample)
                pulses[pulse->fChannel].StartSample = pulse->fFirstSample;

              if (pulses[pulse->fChannel].EndSample == -1 || pulses[pulse->fChannel].EndSample < pulse->fLastSample)
                pulses[pulse->fChannel].EndSample = pulse->fLastSample;

              if (pulses[pulse->fChannel].Period < 0 || pulses[pulse->fChannel].Delay < 0) {
                Waveform *wf = event->GetWaveform(pulse->fChannel);
                pulses[pulse->fChannel].Period = wf->fPeriod;
                pulses[pulse->fChannel].Delay = wf->fDelay;
              }
            }

            if (pulses[pulse->fChannel].ChannelUsed<0) pulses[pulse->fChannel].ChannelUsed=1;

          }

   //        for (int j=0; j<GetNumClusters(); j++) {
          for (int j=0; j<event->fNumChannels; j++) {
            if (pulses[j].ChannelUsed == 1) {
              TBox *box = new TBox(pulses[j].StartSample*pulses[j].Period + pulses[j].Delay, j-0.5, (pulses[j].EndSample*pulses[j].Period+pulses[j].Delay), j+0.5);
              RegisterDrawnObject(box);
              box->SetLineColor(kMagenta);
              box->SetFillStyle(0);
              box->Draw();
            }
          }

          for (int clusters=0; clusters<event->fNumChannels; clusters++) pulses[clusters].Clear();
        }

      }
      delete [] pulses;
    }
    break;
  }
  case kModeClusters: {

    Cluster *cluster = 0;
    Pulse *pulse = 0;
    int wf_index = 0;
    double tmp_amplitude = 0;
    int cl_index = 0;

    for (int i=0; i<event->GetNumClusters();i++) {
      if (event->GetCluster(i)->fAmplitude > tmp_amplitude) {
        tmp_amplitude = event->GetCluster(i)->fAmplitude;
        cl_index = i;
      }
    }
    double baseline = 0;
    cluster = event->GetCluster(cl_index);
    tmp_amplitude = 0;
    for (int i=0; i<cluster->GetNumPulses();i++) {
      if (cluster->GetPulse(i)->fAmplitude > tmp_amplitude) {
        tmp_amplitude = cluster->GetPulse(i)->fAmplitude;
        wf_index = event->FindWaveformLocation(cluster->GetPulse(i)->fChannel);
        baseline = cluster->GetPulse(i)->fBaseline;
      }
    }
    Waveform *wf = event->GetWaveform(wf_index);

    if (wf) {
      TGraph *gr = new TGraph(wf->fNumSamples);
      RegisterDrawnObject(gr);
      gr->SetLineColor(kBlack);
      for (int j=0; j<gr->GetN(); j++) {
        gr->SetPoint(j,j*wf->fPeriod+wf->fDelay,wf->fData[j]*wf->fGain+wf->fOffset);
      }
      gr->SetTitle(TString::Format("Inspector event (%d, %d)",
                                 event->fRunNumber,event->fEventNumber));
      gr->Draw("AL");

    for (int i = 0; i < event->GetNumClusters(); i++) {
      cluster = event->GetCluster(i);
      for (int j=0; j< cluster->GetNumPulses();j++) {
        TBox *box = new TBox(cluster->fTime, baseline, cluster->fTime + cluster->fWidth, baseline - cluster->fAmplitude);
        RegisterDrawnObject(box);
        box->SetLineColor(kRed+1);
        box->SetLineWidth(2);
        box->SetFillStyle(0);
        box->Draw("same");
      }
    }
    }

    TString s;
    MAKE_LINE(s,"fRunNumber",event->fRunNumber);
    MAKE_LINE(s,"fEventNumber",event->fEventNumber);
    MAKE_LINE(s,"GetNumPulses()",event->GetNumPulses());
    MAKE_LINE(s,"GetNumClusters()",event->GetNumClusters());
    if (wf) MAKE_LINE(s,"ichannel",wf->fChannel);
    SetInfo(s);

    break;
  }
  default:
    cout << __PRETTY_FUNCTION__ <<": unknown mode: " << mode << endl;
  }
  gPad->Update();
  if (old!=0) old->cd();
}
void Inspector::SetInfo(const TString& text)
{
  TString s;
  TGText *gt = fInfo->GetText();
  gt->Clear();
  for (Ssiz_t i=0,j=0,k=0; i<text.Length(); i=j+1) {
    j = text.Index("\n",i);
    s = text(i,j-i);
    gt->InsLine(k++,s.Data());
  }
  fInfo->Update();
}

void Inspector::ClearDrawnObjects()
{
  for (unsigned int i=0; i<fDrawnObjects.size(); i++)
   delete fDrawnObjects[i];

  fDrawnObjects.clear();
  cout << __PRETTY_FUNCTION__ << endl;
}

void Inspector::SetHeatPrintMode(const char* mode)
{
  if (strcmp(mode,"cluster") == 0)
    fHeatPrintMode = kCluster;
  else if (strcmp(mode,"pulse") == 0)
    fHeatPrintMode = kPulse;
}
