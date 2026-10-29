#include <TROOT.h>
#include <TApplication.h>
#include <TGClient.h>
#include <TGFrame.h>
#include <TGCanvas.h>
//#include <TGMenu.h>
//#include <TGStatusBar.h>
#include <TRootEmbeddedCanvas.h>
#include <TCanvas.h>
#include <TTimer.h>

#include <TGButton.h>
#include <TGLabel.h>
#include <TGNumberEntry.h>
#include <TGComboBox.h>
//#include <TGTextEntry.h>
//#include <TGListBox.h>
#include <TGMsgBox.h>
#include <TGFileDialog.h>

#include <TList.h>
#include <TColor.h>
#include <TPaveText.h>
#include <TFile.h>
#include <TTree.h>
#include <TLeaf.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
#include <TGraph.h>

class MyMainFrame : public TGMainFrame
{

public:
  // draw style
  enum DrawMode_t {
    kDrawNone = 0,
    kDrawSimple,
    kDrawSE,
    kDrawGamma,
  };
  // channel type
  enum ChannelType_t {
    kChUnknown = 0,
    kChTopPmt,
    kChBotPmt,
    kChExtra,
  };
  static const int kNumChTypes = 4;
  // store channel parameters
  struct ch_info {
    Int_t type;
    Int_t nsamples;
    double v_bin, v_off;
    double t_bin, t_off;
    char label[32];
    double line_min, line_max, line_base, line_noise;
  };
  struct my_pal {
    Pixel_t GuiBad;
    Pixel_t GuiGood;
    Int_t ChType[kNumChTypes];
    //Pixel_t Palette[16];
  } fColors;
  struct pls_info {
    int ichannel;
    int itype;
    double time;
    double width;
    double amplitude;
    double area;
  };
  struct cl_info {
    int itype;
    double time;
    double width;
    double amplitude;
    double area;
    double nspe;
  };

private:
  // GUI
  TGTextButton *fCtrlRawFile;
  TGTextButton *fCtrlProcFile;
  TGNumberEntry *fCtrlIRecord;
  TGTextEntry *fCtrlIRun;
  TGTextEntry *fCtrlIEvent;
  TGComboBox *fCtrlDrawMode;
  TGTextButton *fCtrlDraw;
  TGTextButton *fCtrlExit;
  TCanvas *fCanvas;
  // cache
  TFile *fRawFile;
  //TTree *fRawEventTree;
  TFile *fProcFile;
  //TTree *fProcEventTree;
  Int_t fNumChannels;
  struct ch_info *fChInfo;
  TH1 **fWF;
  Int_t fNumPulses;
  struct pls_info *fPulses;
  Int_t fNumClusters;
  struct cl_info *fClusters;

public:
  MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
  virtual ~MyMainFrame();
  void DoExit();
  void OpenRawFile();
  Bool_t OpenRawFile(const char *filename);
  void OpenProcFile();
  Bool_t OpenProcFile(const char *filename);
  void ReadEntry();
  Bool_t ReadEntry(UInt_t ientry);
  void ReadEntry_PostProc();
  void PrepareDraw();
  void DoDraw();
  void DrawModeSimple();
  void DrawModeSE();
  void DrawModeSE_DrawTopWaveforms();
  void DrawModeSE_DrawBotWaveforms();
  void DrawModeSE_DrawTopXYform();
  void DrawModeSE_DrawBotXYform();
  void DrawModeGamma();
  void DrawModeGamma_DrawTopWaveforms();
  void DrawModeGamma_DrawBotWaveforms();
  void DrawModeGamma_DrawTopXYform();
  void DrawModeGamma_DrawBotXYform();
  //
  Int_t GetNumEntries() const;
  //
  void DoSelect();
  void HandleCanvas(Int_t,Int_t,Int_t,TObject*);
  void TimerEvent();
  void HandleButtons();
  void PrintSelected();
  void PrintInfo();

  ClassDef(MyMainFrame, 1)
};

MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h) :
  TGMainFrame(p, w, h), fRawFile(0), fProcFile(0), fNumChannels(0), fChInfo(0), fWF(0),
  fNumPulses(0), fPulses(0), fNumClusters(0), fClusters(0)
{
  // Create main frame
  Printf("MyMainFrame()");

  /*enum ELayoutHints {
    kLHintsNoHints = 0 , 
    kLHintsLeft = (1ULL << ( 0 )) , 
    kLHintsCenterX = (1ULL << ( 1 )) , 
    kLHintsRight = (1ULL << ( 2 )) ,
    kLHintsTop = (1ULL << ( 3 )) , 
    kLHintsCenterY = (1ULL << ( 4 )) , 
    kLHintsBottom = (1ULL << ( 5 )) , 
    kLHintsExpandX = (1ULL << ( 6 )) ,
    kLHintsExpandY = (1ULL << ( 7 )) , 
    kLHintsNormal = (kLHintsLeft | kLHintsTop)
  }*/
  //TGLayoutHints (ULong_t hints=kLHintsNormal, Int_t padleft=0, Int_t padright=0, Int_t padtop=0, Int_t padbottom=0)
  gClient->GetColorByName("#ff9999", fColors.GuiBad);
  gClient->GetColorByName("#99ff99", fColors.GuiGood);
  fColors.ChType[0] = TColor::GetColor("#000000");
  fColors.ChType[1] = TColor::GetColor("#000099");
  fColors.ChType[2] = TColor::GetColor("#006600");
  fColors.ChType[3] = TColor::GetColor("#cc0000");
  for (int i=4; i<kNumChTypes; i++)
    fColors.ChType[i] = 0;

  // Create a horizontal frame containing button(s)
  TGHorizontalFrame *hframe = new TGHorizontalFrame(this, 550, 30, kFixedWidth);
  TGLayoutHints *lhint = new TGLayoutHints(kLHintsLeft | kLHintsCenterY, 3, 3, 0, 0);
  fCtrlRawFile = new TGTextButton(hframe, "&Raw file");
  fCtrlRawFile->SetToolTipText("Open raw data file for waveforms");
  fCtrlRawFile->SetBackgroundColor(fColors.GuiBad);
  fCtrlRawFile->Connect("Pressed()", "MyMainFrame", this, "OpenRawFile()");
  hframe->AddFrame(fCtrlRawFile, lhint);
  fCtrlProcFile = new TGTextButton(hframe, "&Proc file");
  fCtrlProcFile->SetToolTipText("Open processed data file for pulses");
  fCtrlProcFile->SetBackgroundColor(fColors.GuiBad);
  fCtrlProcFile->Connect("Pressed()", "MyMainFrame", this, "OpenProcFile()");
  hframe->AddFrame(fCtrlProcFile, lhint);
  TGLabel *l1 = new TGLabel(hframe, "Record:");
  hframe->AddFrame(l1, lhint);
  fCtrlIRecord = new TGNumberEntry(hframe, 0, 4, 9999, TGNumberFormat::kNESInteger, TGNumberFormat::kNEANonNegative, TGNumberFormat::kNELLimitMinMax, 0, 0);
  fCtrlIRecord->Connect("ValueSet(Long_t)", "MyMainFrame", this, "ReadEntry()");
  (fCtrlIRecord->GetNumberEntry())->Connect("ReturnPressed()", "MyMainFrame", this, "ReadEntry()");
  //fCtrlIRecord->SetToolTipText("Enter record number to plot");
  hframe->AddFrame(fCtrlIRecord, lhint);
  TGLabel *l2 = new TGLabel(hframe, "Run/Event:");
  hframe->AddFrame(l2, lhint);
  fCtrlIRun = new TGTextEntry(hframe,"");
  fCtrlIRun->SetWidth(40);
  fCtrlIRun->SetAlignment(kTextRight);
  fCtrlIRun->SetEnabled(kFALSE);
  hframe->AddFrame(fCtrlIRun, lhint);
  fCtrlIEvent = new TGTextEntry(hframe,"");
  fCtrlIEvent->SetWidth(60);
  fCtrlIEvent->SetAlignment(kTextRight);
  fCtrlIEvent->SetEnabled(kFALSE);
  hframe->AddFrame(fCtrlIEvent, lhint);
  TGTextButton *info = new TGTextButton(hframe, "&Info");
  info->SetToolTipText("Print run and event information");
  info->Connect("Pressed()", "MyMainFrame", this, "PrintInfo()");
  hframe->AddFrame(info, lhint);
  TGLabel *l3 = new TGLabel(hframe, "Mode:");
  hframe->AddFrame(l3, lhint);
  fCtrlDrawMode = new TGComboBox(hframe);
  fCtrlDrawMode->AddEntry("Simple",kDrawSimple);
  fCtrlDrawMode->AddEntry("SE",kDrawSE);
  fCtrlDrawMode->AddEntry("Gamma",kDrawGamma);
  fCtrlDrawMode->Resize(100,22);
  hframe->AddFrame(fCtrlDrawMode, lhint);
  fCtrlDrawMode->Select(kDrawSimple);
  fCtrlDrawMode->Connect("Selected(Int_t)", "MyMainFrame", this, "PrepareDraw()");
  fCtrlDraw = new TGTextButton(hframe, "&Draw");
  fCtrlDraw->SetBackgroundColor(fColors.GuiBad);
  fCtrlDraw->Connect("Pressed()", "MyMainFrame", this, "DoDraw()");
  hframe->AddFrame(fCtrlDraw, lhint);
  fCtrlExit = new TGTextButton(hframe, "E&xit ");
  fCtrlExit->Connect("Pressed()", "MyMainFrame", this, "DoExit()");
  hframe->AddFrame(fCtrlExit, lhint);
  AddFrame(hframe, new TGLayoutHints(kLHintsExpandX, 2, 2, 5, 1));

  // add canvas
  TRootEmbeddedCanvas *canv = new TRootEmbeddedCanvas("ec1",this,1400,750);
  fCanvas = canv->GetCanvas();
  fCanvas->SetBorderMode(0);
//  fCanvas->SetBit(kNoContextMenu);
  fCanvas->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)", "MyMainFrame", this, 
		   "HandleCanvas(Int_t,Int_t,Int_t,TObject*)");
  AddFrame(canv, new TGLayoutHints(kLHintsTop | kLHintsLeft | 
                                     kLHintsExpandX  | kLHintsExpandY,1,1,1,1));
  //

  // Set a name to the main frame
  SetWindowName("RED-100 event viewer");
  MapSubwindows();

  // Initialize the layout algorithm via Resize()
  Resize(GetDefaultSize());

  // Map main frame
  MapWindow();

  TTimer *timer = new TTimer();
  timer->Connect("Timeout()","MyMainFrame",this,"TimerEvent()");
  timer->Start(1000);
}

MyMainFrame::~MyMainFrame()
{
  // Clean up main frame...
  Printf("~MyMainFrame()");
  // FIXME
  Cleanup();
}

void MyMainFrame::DoExit()
{
  Printf("DoExit()");
  gApplication->Terminate(0);
}

void MyMainFrame::OpenRawFile()
{
  //Printf("OpenRawFile()");

  static TString dir("."); // directory for file load/save
  const char* filetypes[] = { 
    "Raw data files", "data-*.root",
    "ROOT files", "*.root",
    "All files", "*",
    0, 0 };
  TGFileInfo fi;
  fi.fFileTypes = filetypes;
  fi.fIniDir = StrDup(dir);
  fi.fOverwrite = false;
  fi.fMultipleSelection = false;
  new TGFileDialog(gClient->GetRoot(), this, kFDOpen, &fi);
  if (fi.fFilename) { // have a file
    TString file(fi.fFilename);
    Printf("open data file '%s'", file.Data());
    if (!OpenRawFile(file))
      new TGMsgBox(gClient->GetRoot(), this,
                 "Alarm", "Open file failed",
                 kMBIconExclamation, kMBOk);

  }
  if (fRawFile) {
    fCtrlRawFile->ChangeBackground(fColors.GuiGood);
    fCtrlIRecord->SetLimitValues(0,GetNumEntries());
    fCtrlIRecord->SetIntNumber(0);
    //fCtrlIRecord->Activate(kTRUE);
  } else {
    fCtrlRawFile->ChangeBackground(fColors.GuiBad);
    fCtrlIRecord->SetLimitValues(0,0);
    //fCtrlIRecord->Activate(kFALSE);
  }
  ReadEntry();
}

Bool_t MyMainFrame::OpenRawFile(const char *filename)
{
  //Printf("OpenRawFile() '%s'",filename);

  if (fRawFile) {
    delete fRawFile;
    fRawFile = 0;
  }
  TDirectory *cur = gDirectory;
  fRawFile = TFile::Open(filename,"READ");
  if (!fRawFile || fRawFile->IsZombie()) {
    fRawFile = 0;
    return kFALSE;
  }
  fRawFile->ls();
  cur->cd();
  bool is_good = (!fRawFile->Get("run") || !fRawFile->Get("run_channel") ||
                  !fRawFile->Get("event") || !fRawFile->Get("event_channel"));
  if (is_good) {
    Printf("Bad data file: can't find data trees");
    delete fRawFile;
    fRawFile = 0;
    return kFALSE;
  }
  return kTRUE;
}

void MyMainFrame::OpenProcFile()
{
  //Printf("OpenProcFile()");

  static TString dir("."); // directory for file load/save
  const char* filetypes[] = { 
    "Processed data files", "proc-*.root",
    "ROOT files", "*.root",
    "All files", "*",
    0, 0 };
  TGFileInfo fi;
  fi.fFileTypes = filetypes;
  fi.fIniDir = StrDup(dir);
  fi.fOverwrite = false;
  fi.fMultipleSelection = false;
  new TGFileDialog(gClient->GetRoot(), this, kFDOpen, &fi);
  if (fi.fFilename) { // have a file
    TString file(fi.fFilename);
    Printf("open data file '%s'", file.Data());
    if (!OpenProcFile(file))
      new TGMsgBox(gClient->GetRoot(), this,
                 "Alarm", "Open file failed",
                 kMBIconExclamation, kMBOk);

  }
  if (fProcFile) {
    fCtrlProcFile->ChangeBackground(fColors.GuiGood);
    fCtrlIRecord->SetLimitValues(0,GetNumEntries());
    fCtrlIRecord->SetIntNumber(0);
    //fCtrlIRecord->Activate(kTRUE);
  } else {
    fCtrlProcFile->ChangeBackground(fColors.GuiBad);
    fCtrlIRecord->SetLimitValues(0,0);
    //fCtrlIRecord->Activate(kFALSE);
  }
}

Bool_t MyMainFrame::OpenProcFile(const char *filename)
{
  //Printf("OpenProcFile() '%s'",filename);

  if (fProcFile) {
    delete fProcFile;
    fProcFile = 0;
  }
  TDirectory *cur = gDirectory;
  fProcFile = TFile::Open(filename,"READ");
  if (!fProcFile || fProcFile->IsZombie()) {
    fProcFile = 0;
    return kFALSE;
  }
  fProcFile->ls();
  cur->cd();
  if (!fProcFile->Get("run") ||
      !fProcFile->Get("event")) {
    Printf("Bad data file: can't find data trees");
    delete fProcFile;
    fProcFile = 0;
    return kFALSE;
  }
  return kTRUE;
}

class WFCorr {
public:
  WFCorr(int nSamples, double period, double delay, double gain, double offset) {
    nsamples = nSamples, t_bin = period, t_off = delay, v_bin = gain, v_off = offset;
    Clear();
  }
  ~WFCorr() { ; }
  void Print(const char * = "") {
    Printf("WFCorr(%d, %g, %g, %g, %g)",nsamples,t_bin,t_off,v_bin,v_off);
    Printf("  baseline = (%d, %d), threshold = (%f %f), filter = (%f, %f)",baseline_min, baseline_max, threshold_noise, threshold_signal, filter_p_regular, filter_p_signal);
    Printf("  chunks = (%d, %d, %d), pulse = (%d, %d)",num_chunks,chunk_len,chunk_off,pre_pulse_margin,post_pulse_margin);
  }
  void Clear(const char * = "") {
    SetBaselineRegion(-0.05,+0.05); // V
    SetThresholds(0.01,0.1); // V
    SetFilterCut(10.e6); // Hz
    SetChunkSize(1.e-6); // s
    SetPulseMargin(10.e-9,10.e-9); // s
  }
  inline double TimeToUser(double it) { return t_off+t_bin*it; }
  inline double TimeFromUser(double t) { return (t-t_off)/t_bin; }
  inline double AmplToUser(double iv) { return v_off+v_bin*iv; }
  inline double AmplFromUser(double v) { return (v-v_off)/v_bin; }
  void SetBaselineRegion(double vmin, double vmax) {
    baseline_min = int(floor(AmplFromUser(vmin)));
    baseline_max = int(ceil(AmplFromUser(vmax))); }
  void SetThresholds(double vnoise, double vsignal) {
    threshold_noise = vnoise/v_bin;
    threshold_signal = vsignal/v_bin; }
  void SetFilterCut(double fcut) {
    double omt = 2*TMath::Pi()*fcut*t_bin;
    double p = -(1-sin(omt))/cos(omt);
    filter_p_regular = 1+p, filter_p_signal = 0.1*(1+p); }
  void SetChunkSize(double duration) {
    chunk_len = int(floor(duration/t_bin));
    num_chunks = int(ceil(1.*nsamples/chunk_len));
    int delta = num_chunks*chunk_len - nsamples;
    chunk_off = -delta/2; }
  void SetPulseMargin(double pre, double post) {
    pre_pulse_margin = int(ceil(pre/t_bin));
    post_pulse_margin = int(ceil(post/t_bin)); }
  void Process_Old(Int_t *wf_raw, bool plot = false);
  void Process_Spline(Int_t *wf_raw, bool plot = false);
  //
  double FindBaseline(const Double_t *wf);
  TH1D* SmoothWaveform1(const TH1D* h1);
  TH1D* SmoothWaveform3(const TH1D* h1);
  TSpline* ConstructSpline(const TH1D* h1, const TH1D* h2, bool plot = false);
private:
  int nsamples;
  double t_bin, t_off;
  double v_bin, v_off;
  int baseline_min, baseline_max;
  double threshold_noise, threshold_signal;
  double filter_p_regular, filter_p_signal; // my 'p'
  int num_chunks, chunk_len, chunk_off;
  int pre_pulse_margin, post_pulse_margin;
};

double WFCorr::FindBaseline(const Double_t *wf)
{
  // let's make amplitude histogram
  int nbins = (nsamples>1000 ? 1000 : 100);
  int baseline_nbins = baseline_max-baseline_min;
  int nbins_scale = floor(baseline_nbins/nbins+0.5);
  if (nbins_scale==0) nbins_scale = 1;
  nbins = baseline_nbins/nbins_scale;
  TH1I *h2 = new TH1I("htemp","",nbins,baseline_min,baseline_min+nbins*nbins_scale);
  for(int i=0; i<nsamples; i++)
    h2->Fill(wf[i]);

  // let's find the highest peak
  // peak is continuous part of histogram with counts above threshold
  int thresh = h2->GetEntries()/h2->GetNbinsX()/2; // can be as low as 0
  Long64_t sy = 0., sxy = 0.; int x1, x2, sn = 0;
  int peak_x1, peak_x2, peak_sy = 0; // cache found peak
  for (int i=1; i<=h2->GetNbinsX(); i++) {
    const double &y = h2->GetArray()[i];
    if (y>thresh) {      // if number of counts is significant
      if (sn==0) x1 = i;
      sy += y, sxy += i*y, sn++;
    } else if (sn>0) {   // if empty, but there was something before
      x2 = i;
      if (peak_sy<sy)
        peak_x1 = x1, peak_x2 = x2, peak_sy = sy;
      //Printf(" base %d (%d, %d) %f %d",sn,x1,x2,1.*sxy/sy,sy);
      sy = 0, sxy = 0, sn = 0;
    }
  }
  if (sn>0) { // finish last peak if not yet
    x2 = h2->GetNbinsX()+1;
    if (peak_sy<sy)
      peak_x1 = x1, peak_x2 = x2, peak_sy = sy;
    //Printf(" base %d (%d, %d) %f",sn,x1,x2,1.*sxy/sy);
  }

  // let's measure the peak better
  thresh = peak_sy/(peak_x2-peak_x1)/2; // ~1/4 of amplitude for gaussian
  sy = 0, sxy = 0, sn = 0;
  for (int i=peak_x1; i<peak_x2; i++) {
    const double &y = h2->GetArray()[i];
    if (y>thresh)
      sy += y, sxy += i*y, sn++;
  }
  double res = h2->GetXaxis()->GetXmin()+h2->GetXaxis()->GetBinWidth(1)*sxy/sy;
  delete h2;
  Printf("baseline %d %d %d = %d %f %f",peak_x1,peak_x2,thresh, sn, 1.*sxy/sy,res);

  return res;
}

TH1D* WFCorr::SmoothWaveform1(const TH1D* h1)
{
  TH1D *h2 = (TH1D*)h1->Clone("h2");
  h2->Reset();
  double baseline = FindBaseline(h1->GetArray()+1);
  double s1 = baseline;
  for (int i=1; i<=h1->GetNbinsX(); i++) {
    const double &y = h1->GetArray()[i];
    //double dy = h1->GetArray()[i]-s1;
    double dy = 0.5*h1->GetArray()[i]+0.5*h1->GetArray()[i-1]-s1;
    if (fabs(y-baseline)<=threshold_signal)
      s1 += (fabs(dy)<=threshold_noise ? filter_p_regular*dy : filter_p_signal*dy);
    h2->GetArray()[i] = s1;
  }
  h2->SetEntries(h1->GetEntries());
  return h2;
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

TH1D* WFCorr::SmoothWaveform3(const TH1D* h1)
{
  TH1D *h2 = (TH1D*)h1->Clone("h2");
  h2->Reset();
  double baseline = FindBaseline(h1->GetArray()+1);
  //int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  int n_ovfl, n_ovfl_old = 0;
  double s1 = baseline;
  double s2 = baseline;
  double old_s1 = s1, old_s2 = s2;
  for(int k=0; k<num_chunks; k++) {
    // iterate over chunks
    for (int l=0; l<10; l++) {
      // for each chunk we try several passes
      s1 = old_s1, s2 = old_s2; n_ovfl = 0;
      //n1 = 0, n2 = 0, n3 = 0, n4 = 0;
      for (int j=0,i=k*chunk_len+chunk_off; j<chunk_len; j++,i++) {
        if (i<1 || i>nsamples) continue;
        const double &y = h1->GetArray()[i];
        double dy = y-s1;
        if (l==0) {
          if (fabs(y-baseline)<=threshold_signal)
            s1 += (fabs(dy)<=threshold_noise ? filter_p_regular*dy : filter_p_signal*dy);
        } else {
          s1 = h2->GetArray()[i]<s1-100 ? s1 : h2->GetArray()[i];
        }
        if (y>s1-threshold_noise) {
          s2 = (1-filter_p_regular)*s2 + filter_p_regular*y;
          h2->GetArray()[i] = s2;
          /*if (y<s2-th) n1++;
          else if (y<s2) n2++;
          else if (y<s2+th) n3++;
          else n4++;*/
          if (y>s2+threshold_noise) n_ovfl++;
        } else {
          h2->GetArray()[i] = s2-200;
        }
      }
      //Printf("   %d = %d %d %d %d = %d",l,n1,n2,n3,n4,n_ovfl);
      // if overflow is small or not changing we're done
      if (n_ovfl<10 || n_ovfl==n_ovfl_old) break;
      n_ovfl_old = n_ovfl;
    }
    old_s1 = s1, old_s2 = s2;
    Printf("smooth %d - %d %f %f",k,n_ovfl,s1,s2);
  }
  h2->SetEntries(h1->GetEntries());
  return h2;
}

TSpline* WFCorr::ConstructSpline(const TH1D* h1, const TH1D* h2, bool plot)
{
  // we will use one point in each chunk, plus extra point at begin/end
  int npoints = num_chunks+2;
  double xx[npoints], yy[npoints]; int nn[npoints];
  for(int i=0;i<npoints;i++) nn[i]=0;

  // make linear fit in chunks
  LinearFitter fit(0.5*chunk_len,0.);
  //double slope1, slope2;
  TH1 *h = (TH1*)gROOT->FindObject("h_amp");
  for(int k=0; k<num_chunks; k++) {
    fit.Clear();
    int i1 = k*chunk_len+chunk_off+1, i2 = i1+chunk_len;
    if (i1<1) i1=1; if (i2>nsamples) i2 = nsamples;
    double s1 = h2->GetArray()[i1];
    int after_pulse = 0;
    for (int j=0,i=i1; i<i2; j++,i++) {
      const double &y = h1->GetArray()[i];
      double s1 = h2->GetArray()[i]<s1-100 ? s1 : h2->GetArray()[i];
      if (y>s1-threshold_noise) after_pulse++; else after_pulse = 0;
      //if (j>2 && after_pulse>10 && k==6)
      //  ;//Printf("    %d %d %d %f %f",k,j,i,h1->GetArray()[i-2],h2->GetArray()[i-2]);
      if (after_pulse>post_pulse_margin) {
        fit.Add(j-pre_pulse_margin,h1->GetArray()[i-pre_pulse_margin]);
        nn[k+1]++;
      }
      if (h) h->Fill(h1->GetArray()[i-2]);
    }
    //fit.Print();
    double p0 = fit.GetParameter(0), p1 = fit.GetParameter(1);
    Printf("linfit %d - %d %d %f %f",k,i1,i2,p0,p1);
    if (plot) {
      TLine *l = new TLine(h1->GetBinCenter(i1),p0,h1->GetBinCenter(i2),p0+p1*(i2-i1));
      l->SetLineColor(kMagenta);
      l->Draw();
    }
    if (!TMath::IsNaN(p0)) {
      xx[k+1] = h1->GetBinCenter(i1+fit.GetXmean());
      yy[k+1] = fit.GetYmean();
    } else {
      xx[k+1] = h1->GetBinCenter(i1+chunk_len/2);
      yy[k+1] = yy[k];
    }
    if (k==0) {
      xx[0] = h1->GetBinCenter(-chunk_len/2);
      if (!TMath::IsNaN(p0)) {
        yy[0] = p0-p1*chunk_len/2;
      } else {
        yy[0] = yy[1];
      }
      nn[0] = -1;
      //slope1 = fit.GetParameter(1)/h1->GetBinWidth(1);
    }
    if (k==num_chunks-1) {
      xx[npoints-1] = h1->GetBinCenter(h1->GetNbinsX()+chunk_len/2);
      if (!TMath::IsNaN(p0)) {
        yy[npoints-1] = p0+p1*(i2-i1+chunk_len/2);
      } else {
        yy[npoints-1] = yy[npoints-2];
      }
      nn[npoints-1] = -1;
      //slope2 = fit.GetParameter(1)/h1->GetBinWidth(1);
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
  if (plot) {
    for(int k=0;k<npoints2;k++) {
      Printf("spline %d - %f %f %d",k,xx[k],yy[k],nn[k]);
      TMarker *m = new TMarker(xx[k],yy[k],20);
      m->SetMarkerColor(kGreen);
      m->Draw();
    }
  }

  TSpline3 *spl = new TSpline3("spl",xx,yy,npoints2);//,"b1e1",slope1,slope2);
  return spl;
}

// new spline-based corrector
void WFCorr::Process_Spline(Int_t *wf_raw_, bool plot)
{
  TH1D *h_wf = new TH1D("h_wf","",nsamples,0,nsamples);
  for(int i=0; i<nsamples; i++)
    h_wf->SetBinContent(i+1,wf_raw_[i]);
  Double_t *wf_raw = h_wf->GetArray();
  if (plot) {
    h_wf->SetStats(0);
    h_wf->Draw();
    TH1D *h_w2 = SmoothWaveform1(h_wf);
    h_w2->SetLineColor(kGreen+2);
    h_w2->Draw("same");
  }
  TH1D *h_w3 = SmoothWaveform3(h_wf);
  if (plot) {
    h_w3->SetLineColor(kRed+2);
    h_w3->Draw("same");
  }
  TSpline *spl = ConstructSpline(h_wf,h_w3,plot);
  if (plot) {
    spl->SetLineColor(kOrange);
    spl->SetLineWidth(3);
    spl->SetMarkerColor(kBlue);
    spl->SetMarkerStyle(20);
    spl->SetMarkerSize(1.0);
    spl->Draw("lcsame");
  }
  double base = AmplFromUser(0.);
  for(int i=0; i<nsamples; i++) {
    double y1 = h_wf->GetArray()[i+1];
    double y2 = y1-spl->Eval(h_wf->GetBinCenter(i+1))+base;
    wf_raw_[i] = int(floor(y2+0.5));
  }
  if (!plot) {
    delete spl;
    delete h_w3;
    delete h_wf;
  }
}

// "old" piecewise corrector
void WFCorr::Process_Old(Int_t *wf_raw, bool plot)
{
  int nSamples = nsamples;
  double gain = v_bin, offset = v_off;
  Printf("CorrectWF");
  const int step = 1875;
  const int num_steps = 8;// nSamples/step; //-- don't know why this results in 0
  char f_name[16];

  int start_step = 0;
  int stop_step = num_steps;
  Printf("  %d %d %d %d %d",start_step,stop_step,nSamples,num_steps,nSamples/step);

  TGraph *gr;
  TF1* f_base[num_steps];

  Int_t point_cnt = 0;

  gr = new TGraph();
  for (int i=0; i<nSamples; i++)
  {
    gr->SetPoint(point_cnt,i,wf_raw[i]);
    point_cnt++;
  }

  for (int part=start_step; part<stop_step; part++)
  {
    sprintf(f_name,"base_func_%d",part);
    f_base[part]=new TF1(f_name,"pol1",step*part,step*(part+1));
    gr->Fit(f_base[part],"WRQ");
  }

  Int_t corr_amp = 0;
  for (int i=0; i<nSamples; i++)
  {
    corr_amp = wf_raw[i] - Int_t(f_base[int(i/step)]->Eval(i)+0.5);
    wf_raw[i] = corr_amp;
  }

  delete gr;
  for (int part=start_step; part<stop_step; part++)
    delete f_base[part];

  //second_iteration
  point_cnt = 0;

  gr = new TGraph();
  for (int i=0; i<nSamples; i++)
    if (abs(wf_raw[i]*gain)<0.01)
    {
      gr->SetPoint(point_cnt,i,wf_raw[i]);
      point_cnt++;
    }

  for (int part=start_step; part<stop_step; part++){
    sprintf(f_name,"base_func_%d",part);
    f_base[part]=new TF1(f_name,"pol1",step*part,step*(part+1));
    gr->Fit(f_base[part],"WRQ");
  }

  for (int i=0; i<nSamples; i++)
  {
    corr_amp = wf_raw[i] - int(f_base[int(i/step)]->Eval(i)+0.5) - int(offset/gain+0.5);
    wf_raw[i] =  corr_amp;
  }

   delete gr;
   for (int part=start_step; part<stop_step; part++)
     delete f_base[part];
};

//___________________________________________________________________

double LinearFit(TH1 *h_wf, int xmin, int xmax, double *par)
{
  int n = xmax-xmin+1;
  if (n<=0) {
    return -1.;
  } else if (n==1) {
    par[0] = h_wf->GetBinContent(xmin);
    par[1] = 0.;
    return 0.;
  } else if (n==2) {
    par[0] = (h_wf->GetBinContent(xmin)+h_wf->GetBinContent(xmax))*0.5;
    par[1] = (h_wf->GetBinContent(xmax)-h_wf->GetBinContent(xmin))/(h_wf->GetBinCenter(xmax)-h_wf->GetBinCenter(xmin));
    return 0.;
  }
  int xmed = (xmin+xmax)/2;
  double x0 = h_wf->GetBinCenter(xmed);
  double sx = 0., sy = 0., sxy = 0., sx2 = 0.;
  for (int k=xmin;k<=xmax;k++) {
    double x = h_wf->GetBinCenter(k)-x0;
    double y = h_wf->GetBinContent(k);
    sx += x, sy += y, sxy += x*y, sx2 += x*x;
  }
  double d = n*sx2-sx*sx;
  if (d!=0.) {
    par[1] = (n*sxy-sx*sy)/d;
    par[0] = (sx2*sy-sx*sxy)/d - par[1]*x0;
  } else {
    par[1] = 0.;
    par[0] = sy/n;
  }
  double s = 0.;
  for (int k=xmin;k<=xmax;k++) {
    double x = h_wf->GetBinCenter(k);
    double y = h_wf->GetBinContent(k);
    s += y-(par[0]+x*par[1]);
  }
  return s;
}
double Integrate(TH1 *h_wf, int xmin, int xmax, double thresh)
{
  double par[2];
  int nn = xmax-xmin+1;
  if (nn<5) nn = 5;
  int n = nn/10;
  if (n<2) n = 2;
  LinearFit(h_wf,xmin,xmin+n,par);
  double y_xmin = par[0]+par[1]*h_wf->GetBinCenter(xmin);
  LinearFit(h_wf,xmax-n,xmax,par);
  double y_xmax = par[0]+par[1]*h_wf->GetBinCenter(xmax);
  par[1] = (y_xmax-y_xmin)/(xmax-xmin);
  par[0] = y_xmin - par[1]*xmin;
  //Printf("int %d %d %g %g - %g %g = %g %g",nn,n,y_xmin,y_xmax,par[0],par[1],par[0]+par[1]*xmin,par[0]+par[1]*xmax);
  double s = 0.;
  for (int k=xmin;k<=xmax;k++) {
    double y = h_wf->GetBinContent(k) - (par[0]+par[1]*k);
    if (fabs(y)>thresh)
      s += y;
  }
  return s*h_wf->GetBinWidth(1);
}

void MyMainFrame::ReadEntry()
{
  Printf("ReadEntry()");
  UInt_t ientry = fCtrlIRecord->GetNumber();
  if (ReadEntry(ientry)) {
    fCtrlDraw->ChangeBackground(fColors.GuiGood);
  } else {
    fCtrlDraw->ChangeBackground(fColors.GuiBad);
  }
  
}

Bool_t MyMainFrame::ReadEntry(UInt_t ientry)
{
  //Printf("ReadEntry() %d",ientry);
  ULong64_t event_id = -1;
  if (fProcFile) {
    TTree *event = (TTree*)fProcFile->Get("event");
    int ret = event->GetEntry(ientry);
    if (ret<=0) {
      fCtrlIRun->SetText("?");
      fCtrlIEvent->SetText("?");
      return kFALSE;
    }
    int irun = event->GetLeaf("fRunNumber")->GetValue(0);
    int ievent = event->GetLeaf("fEventNumber")->GetValue(0);
    fCtrlIRun->SetText(TString::Format("%d",irun));
    fCtrlIEvent->SetText(TString::Format("%d",ievent));
    event_id = (ULong64_t(irun)<<32) + ievent;

    // here we assume that channel mapping is the same between raw and proc files,
    // which is truly unreliable
    int npls = event->GetLeaf("fPulses_")->GetLen();
    if (fNumPulses!=npls) {
      if (fPulses) delete [] fPulses;
      fPulses = new pls_info[npls];
    }
    fNumPulses = npls;
    for (int i=0; i<fNumPulses; i++) {
      fPulses[i].ichannel = event->GetLeaf("fPulses.fChannel")->GetValue(i);
      fPulses[i].itype = event->GetLeaf("fPulses.fType")->GetValue(i);
      if (fPulses[i].ichannel < fNumChannels) {
        int ich = fPulses[i].ichannel;
        int first = event->GetLeaf("fPulses.fFirstSample")->GetValue(i);
        int last = event->GetLeaf("fPulses.fLastSample")->GetValue(i);
        fPulses[i].time = first*fChInfo[ich].t_bin+fChInfo[ich].t_off;
        fPulses[i].width = (last-first)*fChInfo[ich].t_bin;
      } else {
        fPulses[i].time = event->GetLeaf("fPulses.fTime")->GetValue(i)*1e6; // to us
        fPulses[i].width = event->GetLeaf("fPulses.fWidth10")->GetValue(i)*1e6; // to us
      }
      fPulses[i].amplitude = event->GetLeaf("fPulses.fAmplitude")->GetValue(i)*1e3; // to mV
      fPulses[i].area = event->GetLeaf("fPulses.fArea")->GetValue(i)*1e9; // to nVs
    }
    int ncl = event->GetLeaf("fClusters_")->GetLen();
    if (fNumClusters!=ncl) {
      if (fClusters) delete [] fClusters;
      fClusters = new cl_info[ncl];
    }
    fNumClusters = ncl;
    for (int i=0; i<fNumClusters; i++) {
      fClusters[i].itype = event->GetLeaf("fClusters.fType")->GetValue(i);
      fClusters[i].time = event->GetLeaf("fClusters.fTime")->GetValue(i)*1e6; // to us
      fClusters[i].width = event->GetLeaf("fClusters.fWidth")->GetValue(i)*1e6; // to us
      fClusters[i].amplitude = event->GetLeaf("fClusters.fAmplitude")->GetValue(i)*1e3; // to mV
      fClusters[i].area = event->GetLeaf("fClusters.fArea")->GetValue(i)*1e9; // to nVs
      fClusters[i].nspe = event->GetLeaf("fClusters.fNumSPE")->GetValue(i);
    }
    //return kTRUE; continue to fRawFile
  }
  if (fRawFile) {
    TTree *event = (TTree*)fRawFile->Get("event");
    int ret = event->GetEntry(ientry);
    if (ret<=0) {
      fCtrlIRun->SetText("?");
      fCtrlIEvent->SetText("?");
      return kFALSE;
    }
    int irun = event->GetLeaf("irun")->GetValue(0);
    int ievent = event->GetLeaf("ievent")->GetValue(0);
    if (event_id != -1 && event_id != ((ULong64_t(irun)<<32) + ievent)) {
      Printf("ERROR: Event record mismatch");
      return kFALSE;
    }
    fCtrlIRun->SetText(TString::Format("%d",irun));
    fCtrlIEvent->SetText(TString::Format("%d",ievent));
    TTree *run = (TTree*)fRawFile->Get("run");
    run->GetEntry(0);
    int nch = run->GetLeaf("nchannels")->GetValue(0);
    if (fNumChannels!=nch) {
      if (fChInfo) delete [] fChInfo;
      fChInfo = new ch_info[nch];
      if (fWF) delete [] fWF;
      fWF = new TH1*[nch];
      for (int i=0;i<nch;i++) fWF[i] = 0;
      fNumChannels = nch;
    }
    TTree *run_ch = (TTree*)fRawFile->Get("run_channel");
    int NumExtraCh = 0;
    int MaxNumSamples = 0;
    for (int ich=0;ich<nch;ich++) {
      run_ch->GetEntry(ich);
      fChInfo[ich].nsamples = run_ch->GetLeaf("nsamples")->GetValue(0);
      if (fChInfo[ich].nsamples > MaxNumSamples)
        MaxNumSamples = fChInfo[ich].nsamples;
      fChInfo[ich].v_bin = run_ch->GetLeaf("gain")->GetValue(0)*1000; // to mV
      fChInfo[ich].v_off = run_ch->GetLeaf("offset")->GetValue(0)*1000; // to mV
      fChInfo[ich].t_bin = run_ch->GetLeaf("period")->GetValue(0)*1.e6; // to us
      fChInfo[ich].t_off = run_ch->GetLeaf("delay")->GetValue(0)*1.e6; // to us
      for (int i=0; i<32; i++)
        fChInfo[ich].label[i] = run_ch->GetLeaf("label")->GetValue(i);
      ChannelType_t it = kChUnknown; Int_t ii = 0;
      if (strncmp(fChInfo[ich].label,"top-",4)==0)
        it = kChTopPmt, ii = strtoul(fChInfo[ich].label+4,0,10);
      else if (strncmp(fChInfo[ich].label,"bottom-",7)==0)
        it = kChBotPmt, ii = strtoul(fChInfo[ich].label+7,0,10);
      else
        it = kChExtra, ii = ++NumExtraCh;
      fChInfo[ich].type = (Int_t(it)<<8) + ii;
    }
    int first_entry = event->GetLeaf("ch_ientry")->GetValue(0);
    Int_t *wf_raw = new Int_t[MaxNumSamples];
    TTree *ev_ch = (TTree*)fRawFile->Get("event_channel");
    ev_ch->GetBranch("event_channel_data")->SetAddress(wf_raw);
    for (int i=0;i<nch;i++)
      if (fWF[i])
        fWF[i]->Reset();
    for (int i=0;i<nch;i++) {
      ev_ch->GetEntry(first_entry+i);
      int iev = ev_ch->GetLeaf("ievent")->GetValue(0);
      int ich = ev_ch->GetLeaf("ichannel")->GetValue(0);
      if ( iev != ievent || ich >= fNumChannels ) break;
      int ns = ev_ch->GetLeaf("nsamples")->GetValue(0);
      fChInfo[ich].line_min = ev_ch->GetLeaf("line_min")->GetValue(0)*1000; // to mV
      fChInfo[ich].line_max = ev_ch->GetLeaf("line_max")->GetValue(0)*1000; // to mV
      fChInfo[ich].line_base = ev_ch->GetLeaf("line_base")->GetValue(0)*1000; // to mV
      fChInfo[ich].line_noise = ev_ch->GetLeaf("line_noise")->GetValue(0)*1000; // to mV
      if (!fWF[ich] || fWF[ich]->GetNbinsX() != fChInfo[ich].nsamples) {
        if (fWF[ich]) delete fWF[ich];
        double xmin = (                    0*fChInfo[ich].t_bin+fChInfo[ich].t_off);
        double xmax = (fChInfo[ich].nsamples*fChInfo[ich].t_bin+fChInfo[ich].t_off);
        fWF[ich] = new TH1D(TString::Format("h_wf_%02d",ich),"",fChInfo[ich].nsamples,xmin,xmax);
        fWF[ich]->SetStats(0);
        fWF[ich]->SetTitle(TString::Format("Waveform (run=%d, event=%d, ch='%.16s')",irun,iev,fChInfo[ich].label));
        fWF[ich]->GetXaxis()->SetTitle("time, #mus");
        fWF[ich]->GetYaxis()->SetTitle("amplitude, mV");
      }
      TH1 *h_wf = fWF[ich];
      if (i<23) {
        WFCorr corr(fChInfo[ich].nsamples,fChInfo[ich].t_bin,fChInfo[ich].t_off,fChInfo[ich].v_bin,fChInfo[ich].v_off);
        corr.SetBaselineRegion(-50.,+50.); // mV
        corr.SetThresholds(3.,10.); // mV
        corr.SetFilterCut(2.5); // MHz
        corr.SetChunkSize(3.75); // us
        corr.SetPulseMargin(4.e-3,20.e-3); // us
        corr.Print();
        corr.Process_Spline(wf_raw,false);
      }
      for (int j=0;j<ns;j++) {
        //double v = ev_ch->GetLeaf("waveform")->GetValue(j)*fChInfo[ich].v_bin+fChInfo[ich].v_off;
        double v = wf_raw[j]*fChInfo[ich].v_bin+fChInfo[ich].v_off;
        h_wf->SetBinContent(j+1,v);
      }
    }
    delete [] wf_raw;
    ReadEntry_PostProc();
    return kTRUE;
  }
  return kFALSE;
}

void MyMainFrame::ReadEntry_PostProc()
{
  //Printf("ReadEntry_PostProc()");
  if (!fWF || !fWF[0]) return;

  //TAxis *xaxis = fWF[0]->GetXaxis();
  bool do_corr = kTRUE;
  TH1D *h_wf;
  h_wf = dynamic_cast<TH1D*>(gROOT->FindObject("h_wf_top"));
  if (!h_wf || h_wf->GetNbinsX() != fChInfo[0].nsamples) {
    if (h_wf) delete h_wf;
    int ich = 0;
    double xmin = (                    0*fChInfo[ich].t_bin+fChInfo[ich].t_off);
    double xmax = (fChInfo[ich].nsamples*fChInfo[ich].t_bin+fChInfo[ich].t_off);
    h_wf = new TH1D("h_wf_top","",fChInfo[ich].nsamples,xmin,xmax);
    h_wf->SetStats(0);
    h_wf->GetXaxis()->SetTitle("time, #mus");
    h_wf->GetYaxis()->SetTitle("amplitude, mV");
  } else
    h_wf->Reset();
  TH1D *h_wf_top = h_wf;
  h_wf = dynamic_cast<TH1D*>(gROOT->FindObject("h_wf_bot"));
  if (!h_wf || h_wf->GetNbinsX() != fChInfo[0].nsamples) {
    if (h_wf) delete h_wf;
    int ich = 0;
    double xmin = (                    0*fChInfo[ich].t_bin+fChInfo[ich].t_off);
    double xmax = (fChInfo[ich].nsamples*fChInfo[ich].t_bin+fChInfo[ich].t_off);
    h_wf = new TH1D("h_wf_bot","",fChInfo[ich].nsamples,xmin,xmax);
    h_wf->SetStats(0);
    h_wf->GetXaxis()->SetTitle("time, #mus");
    h_wf->GetYaxis()->SetTitle("amplitude, mV");
  } else
    h_wf->Reset();
  TH1D *h_wf_bot = h_wf;

  int nch_top = 0, nch_bot = 0;
  for (int i=0;i<fNumChannels;i++) {
    int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
    //Printf("  %d %d %d - %p",i,it,ii,fWF[i]);
    if (!(fWF[i] && fWF[i]->GetEntries()>0))
      continue;
    h_wf = (TH1D*)fWF[i];
    switch(it) {
    case kChUnknown:
      break;
    case kChTopPmt:
      nch_top++;
      if (do_corr)
        ;//CorrectWF(h_wf);
      for (int j=1; j<=h_wf->GetNbinsX(); j++)
        h_wf_top->GetArray()[j+1] += h_wf->GetArray()[j+1];
      break;
    case kChBotPmt:
      nch_bot++;
      if (do_corr)
        ;//CorrectWF(h_wf);
      for (int j=1; j<=h_wf->GetNbinsX(); j++)
        h_wf_bot->GetArray()[j+1] += h_wf->GetArray()[j+1];
      break;
    case kChExtra:
      break;
    }
  }
  h_wf_top->SetTitle(TString::Format("Waveform (run=%s, event=%s, ch='sum-top', nch=%d)",fCtrlIRun->GetText(),fCtrlIEvent->GetText(),nch_top));
  h_wf_bot->SetTitle(TString::Format("Waveform (run=%s, event=%s, ch='sum-bottom', nch=%d)",fCtrlIRun->GetText(),fCtrlIEvent->GetText(),nch_bot));
}

void MyMainFrame::PrepareDraw()
{
  //Printf("PrepareDraw()");
  DrawMode_t mode = (DrawMode_t)fCtrlDrawMode->GetSelected();
  switch(mode) {
  case kDrawNone:
    break;
  case kDrawSimple: {
    fCanvas->Clear();
    //
  } break;
  case kDrawSE: {
    fCanvas->Clear();
    fCanvas->cd();
    // left-right
    TPad *pad0 = new TPad("pad0", "waveforms", 0.0,0.0,0.7,1.0);
    TPad *pad1 = new TPad("pad1", "layout",    0.7,0.0,1.0,1.0);
    pad0->Draw();
    pad1->Draw();
    pad0->cd();
    TPad *pad00 = new TPad("pad00", "bottom", 0.0,0.0,1.0,0.3);
    TPad *pad01 = new TPad("pad01", "top",    0.0,0.3,1.0,1.0);
    pad00->Draw();
    pad00->SetTopMargin(0.01);
    pad01->Draw();
    pad1->cd();
    TPad *pad10 = new TPad("pad10", "bottom", 0.0,0.0,1.0,0.5);
    TPad *pad11 = new TPad("pad11", "top",    0.0,0.5,1.0,1.0);
    pad10->Draw();
    pad11->Draw();
    fCanvas->cd();
  } break;
  case kDrawGamma: {
    fCanvas->Clear();
    fCanvas->cd();
    // left-right
    TPad *pad0 = new TPad("pad0", "waveforms", 0.0,0.0,0.7,1.0);
    TPad *pad1 = new TPad("pad1", "layout",    0.7,0.0,1.0,1.0);
    pad0->Draw();
    pad1->Draw();
    pad0->cd();
    TPad *pad00 = new TPad("pad00", "bottom", 0.0,0.0,1.0,0.5);
    TPad *pad01 = new TPad("pad01", "top",    0.0,0.5,1.0,1.0);
    pad00->Draw();
    //pad00->SetTopMargin(0.01);
    pad01->Draw();
    pad1->cd();
    TPad *pad10 = new TPad("pad10", "bottom", 0.0,0.0,1.0,0.5);
    TPad *pad11 = new TPad("pad11", "top",    0.0,0.5,1.0,1.0);
    pad10->Draw();
    pad11->Draw();
    fCanvas->cd();
  } break;
  default:
    Printf("PrepareDraw: Unhandled mode %d",int(mode));
  }
  fCanvas->Update();
}

void MyMainFrame::DoDraw()
{
  //Printf("DoDraw()");
  DrawMode_t mode = (DrawMode_t)fCtrlDrawMode->GetSelected();
  switch(mode) {
  case kDrawNone:
    break;
  case kDrawSimple:
    DrawModeSimple();
    break;
  case kDrawSE:
    DrawModeSE();
    break;
  case kDrawGamma:
    DrawModeGamma();
    break;
  default:
    Printf("DoDraw: Unhandled mode %d",int(mode));
  }
}

void MyMainFrame::DrawModeSimple()
{
  Printf("DrawModeSimple()");
  // list of all waveforms
  if (!fWF || !fWF[0]) return;

  fCanvas->cd();
  TAxis *xaxis = fWF[0]->GetXaxis();
  TH2 *hf = dynamic_cast<TH2*>(gROOT->FindObject("hf1"));
  if (hf) {
    hf->GetXaxis()->SetRange(1,xaxis->GetNbins()/10);
    hf->GetYaxis()->SetRange(1,100);
  } else {
    hf = new TH2C("hf1","",xaxis->GetNbins()/10,xaxis->GetXmin(),xaxis->GetXmax(),100,-2,fNumChannels);
    hf->SetStats(0);
    hf->GetXaxis()->SetTitle(fWF[0]->GetXaxis()->GetTitle());
    hf->GetYaxis()->SetTitle("amplitude, a.u.");
  }
  hf->Draw();
  int n[kNumChTypes]; double s[kNumChTypes];
  for (int i=0; i<kNumChTypes; i++)
    n[i] = 0, s[i] = 0.;
  for (int i=0; i<fNumChannels; i++) {
    if (fWF[i] && fWF[i]->GetEntries()>0) {
      int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
      double v1 = fChInfo[i].line_max-fChInfo[i].line_base;
      double v2 = fChInfo[i].line_base-fChInfo[i].line_min;
      n[it]++; s[it] += ( v1>v2 ? v1 : v2 );
    }
  }
  for (int i=0; i<kNumChTypes; i++) {
    if (n[i] > 0)
      s[i] *= 1.1/n[i];
    else
      s[i] = 1.;
    Printf("  scale for zone %d is %lf",i,s[i]);
  }
  for (int i=0; i<fNumChannels; i++) {
    if (fWF[i] && fWF[i]->GetEntries()>0) {
      TH1D *h = dynamic_cast<TH1D*>(fWF[i]->DrawCopy("same"));
      if (!h) {
        Printf("DrawSimple: Wrong TH1 type");
        continue;
      }
      int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
      //Printf("  %d %d %d %d %lf - %x",i,it,ii,n[it],s[it],fColors.ChType[it]);
      for (int j=1; j<=h->GetNbinsX(); j++)
        h->GetArray()[j+1] = h->GetArray()[j+1]/s[it] + i;
      h->SetLineColor(fColors.ChType[it]);
    }
  }
  double xsize = xaxis->GetXmax()-xaxis->GetXmin();
  double text_x1 = xaxis->GetXmax()+0.01*xsize; // 
  double text_x2 = text_x1+0.07*xsize; // should depend on max(len(label))
  for (int i=0; i<fNumChannels; i++) {
    TPaveText *text = new TPaveText(text_x1,i-0.5,text_x2,i+0.25);
    text->AddText(fChInfo[i].label);
    text->SetTextAlign(12);
    text->SetFillStyle(1001);
    text->SetFillColor(kBlue-10);
    text->Draw("same");
  }
  for (int i=0; i<fNumClusters; i++) {
    TBox *b = new TBox(fClusters[i].time,-0.5,fClusters[i].time+fClusters[i].width,fNumChannels-0.5);
    b->SetLineColor(kMagenta);
    b->SetFillStyle(0);
    b->Draw("same");
    gPad->GetListOfPrimitives()->Add(b);
  }
  fCanvas->Update();
}

void MyMainFrame::DrawModeSE_DrawTopWaveforms()
{
  const int nch = 19;
  TAxis *xaxis = fWF[0]->GetXaxis();
  TH2 *hf = dynamic_cast<TH2*>(gROOT->FindObject("hf2_01"));
  if (hf) {
    hf->GetXaxis()->SetRange(1,xaxis->GetNbins()/10);
    hf->GetYaxis()->SetRange(1,100);
  } else {
    hf = new TH2C("hf2_01","",xaxis->GetNbins()/10,xaxis->GetXmin(),xaxis->GetXmax(),100,-20,20*nch);
    hf->SetStats(0);
    hf->GetXaxis()->SetTitle(fWF[0]->GetXaxis()->GetTitle());
    hf->GetYaxis()->SetTitle("amplitude, mV (offset=ichannel*20mV)");
  }
  hf->SetTitle(TString::Format("SE event (run=%s, event=%s)",fCtrlIRun->GetText(),fCtrlIEvent->GetText()));
  hf->Draw();
  double xsize = xaxis->GetXmax()-xaxis->GetXmin();
  double text_x1 = xaxis->GetXmax()+0.01*xsize; // 
  double text_x2 = text_x1+0.07*xsize; // should depend on max(len(label))
  for (int i=0; i<fNumChannels; i++) {
    int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
    if (it!=kChTopPmt)
      continue;
    double voff = 20.0*(ii-1);
    if (fWF[i] && fWF[i]->GetEntries()>0) {
      TH1D *h = dynamic_cast<TH1D*>(fWF[i]->DrawCopy("same"));
      if (!h) {
        Printf("DrawSimple: Wrong TH1 type");
        continue;
      }
      //Printf("  %d %d %d %s - %p",i,it,ii,fWF[i]->GetName(),h);
      for (int j=1; j<=h->GetNbinsX(); j++)
        h->GetArray()[j+1] += voff;
      h->SetLineColor(fColors.ChType[it]);
    }
    TPaveText *text = new TPaveText(text_x1,voff-10,text_x2,voff+5);
    text->AddText(fChInfo[i].label);
    text->SetTextAlign(12);
    text->SetFillStyle(1001);
    text->SetFillColor(kBlue-10);
    text->Draw("same");
  }
  for (int i=0; i<fNumPulses; i++) {
    int j = fPulses[i].ichannel;
    int it = (fChInfo[j].type>>8)&0xff, ii = (fChInfo[j].type)&0xff;
    if (it!=kChTopPmt)
      continue;
    double voff = 20.0*(ii-1);
    //Printf("  %d %d %g %g %g",i,j,fPulses[i].time,fPulses[i].width,fPulses[i].amplitude);
    TBox *b = new TBox(fPulses[i].time,voff-fPulses[i].amplitude,fPulses[i].time+fPulses[i].width,voff);
    b->SetLineColor(kRed);
    b->SetFillStyle(0);
    b->SetToolTipText(TString::Format("Pulse #%d\\n  area = %g\\n  nspe = %g",i,fPulses[i].area,fPulses[i].area/0.08));
    b->Draw("same");
    gPad->GetListOfPrimitives()->Add(b);
  }
  for (int i=0; i<fNumClusters; i++) {
    TBox *b = new TBox(fClusters[i].time,-10.,fClusters[i].time+fClusters[i].width,20.*nch-10.);
    b->SetLineColor(kMagenta);
    b->SetFillStyle(0);
    b->SetToolTipText(TString::Format("Cluster #%d\\n  area = %g\\n  nspe = %g",i,fClusters[i].area,fClusters[i].nspe));
    b->Draw("same");
    gPad->GetListOfPrimitives()->Add(b);
  }
}
void MyMainFrame::DrawModeSE_DrawBotWaveforms()
{
  const int nch = 7;
  TAxis *xaxis = fWF[0]->GetXaxis();
  TH2 *hf = dynamic_cast<TH2*>(gROOT->FindObject("hf2_00"));
  if (hf) {
    hf->GetXaxis()->SetRange(1,xaxis->GetNbins()/10);
    hf->GetYaxis()->SetRange(1,100);
  } else {
    hf = new TH2C("hf2_00","",xaxis->GetNbins()/10,xaxis->GetXmin(),xaxis->GetXmax(),100,-20,20*nch);
    hf->SetStats(0);
    hf->GetXaxis()->SetTitle(fWF[0]->GetXaxis()->GetTitle());
    hf->GetXaxis()->SetLabelSize(0.08);
    hf->GetYaxis()->SetTitle("amplitude, mV");
    hf->GetYaxis()->SetLabelSize(0.08);
    //hf->SetTitle(TString::Format("SE event (run=%s, event=%s)",fCtrlIRun->GetText(),fCtrlIEvent->GetText()));
  }
  hf->Draw();
  double xsize = xaxis->GetXmax()-xaxis->GetXmin();
  double text_x1 = xaxis->GetXmax()+0.01*xsize; // 
  double text_x2 = text_x1+0.07*xsize; // should depend on max(len(label))
  for (int i=0; i<fNumChannels; i++) {
    int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
    if (it!=kChBotPmt)
      continue;
    double voff = 20.0*(ii-1);
    if (fWF[i] && fWF[i]->GetEntries()>0) {
      TH1D *h = dynamic_cast<TH1D*>(fWF[i]->DrawCopy("same"));
      if (!h) {
        Printf("DrawSimple: Wrong TH1 type");
        continue;
      }
      //Printf("  %d %d %d %s - %p",i,it,ii,fWF[i]->GetName(),h);
      for (int j=1; j<=h->GetNbinsX(); j++)
        h->GetArray()[j+1] += voff;
      h->SetLineColor(fColors.ChType[it]);
    }
    TPaveText *text = new TPaveText(text_x1,voff-10,text_x2,voff+5);
    text->AddText(fChInfo[i].label);
    text->SetTextAlign(12);
    text->SetFillStyle(1001);
    text->SetFillColor(kBlue-10);
    text->Draw("same");
  }
  for (int i=0; i<fNumPulses; i++) {
    int j = fPulses[i].ichannel;
    int it = (fChInfo[j].type>>8)&0xff, ii = (fChInfo[j].type)&0xff;
    if (it!=kChBotPmt)
      continue;
    double voff = 20.0*(ii-1);
    //Printf("  %d %d %g %g %g",i,j,fPulses[i].time,fPulses[i].width,fPulses[i].amplitude);
    TBox *b = new TBox(fPulses[i].time,voff-fPulses[i].amplitude,fPulses[i].time+fPulses[i].width,voff);
    b->SetLineColor(kRed);
    b->SetFillStyle(0);
    b->SetToolTipText(TString::Format("Pulse #%d\\n  area = %g\\n  nspe = %g",i,fPulses[i].area,fPulses[i].area/0.08));
    b->Draw("same");
    gPad->GetListOfPrimitives()->Add(b);
  }
  for (int i=0; i<fNumClusters; i++) {
    TBox *b = new TBox(fClusters[i].time,-10.,fClusters[i].time+fClusters[i].width,20.*nch-10.);
    b->SetLineColor(kMagenta);
    b->SetFillStyle(0);
    b->SetToolTipText(TString::Format("Cluster #%d\\n  area = %g\\n  nspe = %g",i,fClusters[i].area,fClusters[i].nspe));
    b->Draw("same");
    gPad->GetListOfPrimitives()->Add(b);
  }
}
void MyMainFrame::DrawModeSE_DrawTopXYform()
{
  const int nch = 19;
  const double PMT_top[][3] = {
    { 0, 0, 0 },
    { -79, 0, 0 }, { -39.5, 68.416, 0 }, { 39.5, 68.416, 0 }, { 79, 0, 0 }, { 39.5, -68.416, 0 }, { -39.5, -68.416, 0 },
    { -158, 0, 0 }, { -118.5, 68.416, 0 }, { -79, 136.832, 0 }, { 0, 136.832, 0 }, { 79, 136.832, 0 }, { 118.5, 68.416, 0 },
    { 158, 0, 0 }, { 118.5, -68.416, 0 }, { 79, -136.832, 0 }, { 0, -136.832, 0 }, { -79, -136.832, 0 }, { -118.5, -68.416, 0 },
  };
  TH2 *hf = dynamic_cast<TH2*>(gROOT->FindObject("hf2_11"));
  if (hf) {
    hf->Reset();
  } else {
    hf = new TH2F("hf2_11","",10,-198,198,5,-176,176);
    hf->GetXaxis()->SetTitle("X, mm");
    hf->GetYaxis()->SetTitle("Y, mm");
    hf->SetStats(0);
  }
  int xmin = 1, xmax = 1;
  double tmin = 0., tmax = 0.;
  {
    TH1 *hf01 = dynamic_cast<TH1*>(gROOT->FindObject("hf2_01"));
    xmin = hf01->GetXaxis()->GetFirst()*10-9;
    xmax = hf01->GetXaxis()->GetLast()*10;
    tmin = hf01->GetXaxis()->GetBinLowEdge(hf01->GetXaxis()->GetFirst());
    tmax = hf01->GetXaxis()->GetBinUpEdge(hf01->GetXaxis()->GetLast());
  }
  double aarea[nch];
  for (int i=0; i<fNumChannels; i++) {
    int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
    if (it!=kChTopPmt)
      continue;
    if (!(fWF[i] && fWF[i]->GetEntries()>0))
      continue;
    double area = 0.;
    if (fNumPulses>0) {
      for (int j=0;j<fNumPulses;++j) {
        if (fPulses[j].ichannel==i && tmin<=fPulses[j].time && fPulses[j].time<tmax)
          area += fPulses[j].area;
      }
    } else {
      area = -Integrate(fWF[i],xmin,xmax,2);
    }
    aarea[ii-1] = area;
    //Printf("  %d %d %d %s - %d %d %lf",i,it,ii,fWF[i]->GetName(),xmin,xmax,area);
    hf->Fill(PMT_top[ii-1][0]-10,PMT_top[ii-1][1],area/2);
    hf->Fill(PMT_top[ii-1][0]+10,PMT_top[ii-1][1],area/2);
  }
  hf->Draw("colz");
  for (int i=0; i<nch; i++) {
    TText *text = new TText(PMT_top[i][0],PMT_top[i][1],TString::Format("%.1lf",aarea[i]));
    text->SetTextAlign(22);
    text->SetTextFont(40);
    text->SetTextSize(0.07);
    text->Draw("");
  }
}
void MyMainFrame::DrawModeSE_DrawBotXYform()
{
  const int nch = 19;
  const double PMT_top[][3] = {
    { 0, 0, 0 },
    { -79, 0, 0 }, { -39.5, 68.416, 0 }, { 39.5, 68.416, 0 }, { 79, 0, 0 }, { 39.5, -68.416, 0 }, { -39.5, -68.416, 0 },
    { -158, 0, 0 }, { -118.5, 68.416, 0 }, { -79, 136.832, 0 }, { 0, 136.832, 0 }, { 79, 136.832, 0 }, { 118.5, 68.416, 0 },
    { 158, 0, 0 }, { 118.5, -68.416, 0 }, { 79, -136.832, 0 }, { 0, -136.832, 0 }, { -79, -136.832, 0 }, { -118.5, -68.416, 0 },
  };
  TH2 *hf = dynamic_cast<TH2*>(gROOT->FindObject("hf2_10"));
  if (hf) {
    hf->Reset();
  } else {
    hf = new TH2F("hf2_10","",10,-198,198,5,-176,176);
    hf->GetXaxis()->SetTitle("X, mm");
    hf->GetYaxis()->SetTitle("Y, mm");
    hf->SetStats(0);
  }
  int xmin = 1, xmax = 1;
  double tmin = 0., tmax = 0.;
  {
    TH1 *hf00 = dynamic_cast<TH1*>(gROOT->FindObject("hf2_00"));
    xmin = hf00->GetXaxis()->GetFirst()*10-9;
    xmax = hf00->GetXaxis()->GetLast()*10;
    tmin = hf00->GetXaxis()->GetBinLowEdge(hf00->GetXaxis()->GetFirst());
    tmax = hf00->GetXaxis()->GetBinUpEdge(hf00->GetXaxis()->GetLast());
  }
  for (int i=0; i<fNumChannels; i++) {
    int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
    if (it!=kChBotPmt)
      continue;
    if (!(fWF[i] && fWF[i]->GetEntries()>0))
      continue;
    double area = 0.;
    if (fNumPulses>0) {
      for (int j=0;j<fNumPulses;++j) {
        if (fPulses[j].ichannel==i && tmin<=fPulses[j].time && fPulses[j].time<tmax)
          area += fPulses[j].area;
      }
    } else {
      area = -Integrate(fWF[i],xmin,xmax,2);
    }
    //Printf("  %d %d %d %s - %d %d %lf",i,it,ii,fWF[i]->GetName(),xmin,xmax,area);
    hf->Fill(PMT_top[ii-1][0]-10,PMT_top[ii-1][1],area/2);
    hf->Fill(PMT_top[ii-1][0]+10,PMT_top[ii-1][1],area/2);
  }
  hf->Draw("colz");
}
void MyMainFrame::DrawModeSE()
{
  //Printf("DrawModeSE()");
  if (!fWF || !fWF[0]) return;

  TPad *pad;
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad01"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeSE_DrawTopWaveforms();
  }
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad00"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeSE_DrawBotWaveforms();
  }
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad11"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeSE_DrawTopXYform();
  }
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad10"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeSE_DrawBotXYform();
  }
  fCanvas->Update();
}

void MyMainFrame::DrawModeGamma_DrawTopWaveforms()
{
  //const int nch = 19;
  TAxis *xaxis = fWF[0]->GetXaxis();
  TH1D *hf = dynamic_cast<TH1D*>(gROOT->FindObject("h_wf_top"));
  if (hf) {
    hf->GetXaxis()->SetRange(1,xaxis->GetNbins());
    //hf->SetLineColor(fColors.ChType[kChTopPmt]);
    hf->Draw();
  }
  for (int i=0; i<fNumClusters; i++) {
    TBox *b = new TBox(fClusters[i].time,hf->GetMinimum(),fClusters[i].time+fClusters[i].width,hf->GetMaximum());
    b->SetLineColor(kMagenta);
    b->SetFillStyle(0);
    b->Draw("same");
    gPad->GetListOfPrimitives()->Add(b);
  }
}
void MyMainFrame::DrawModeGamma_DrawBotWaveforms()
{
  //const int nch = 19;
  TAxis *xaxis = fWF[0]->GetXaxis();
  TH1D *hf = dynamic_cast<TH1D*>(gROOT->FindObject("h_wf_bot"));
  if (hf) {
    hf->GetXaxis()->SetRange(1,xaxis->GetNbins());
    //hf->SetLineColor(fColors.ChType[kChTopPmt]);
    hf->Draw();
  }
  for (int i=0; i<fNumClusters; i++) {
    TBox *b = new TBox(fClusters[i].time,hf->GetMinimum(),fClusters[i].time+fClusters[i].width,hf->GetMaximum());
    b->SetLineColor(kMagenta);
    b->SetFillStyle(0);
    b->Draw("same");
    gPad->GetListOfPrimitives()->Add(b);
  }
}
void MyMainFrame::DrawModeGamma_DrawTopXYform()
{
  const int nch = 19;
  const double PMT_top[][3] = {
    { 0, 0, 0 },
    { -79, 0, 0 }, { -39.5, 68.416, 0 }, { 39.5, 68.416, 0 }, { 79, 0, 0 }, { 39.5, -68.416, 0 }, { -39.5, -68.416, 0 },
    { -158, 0, 0 }, { -118.5, 68.416, 0 }, { -79, 136.832, 0 }, { 0, 136.832, 0 }, { 79, 136.832, 0 }, { 118.5, 68.416, 0 },
    { 158, 0, 0 }, { 118.5, -68.416, 0 }, { 79, -136.832, 0 }, { 0, -136.832, 0 }, { -79, -136.832, 0 }, { -118.5, -68.416, 0 },
  };
  TH2 *hf = dynamic_cast<TH2*>(gROOT->FindObject("hf2_11"));
  if (hf) {
    hf->Reset();
  } else {
    hf = new TH2F("hf2_11","",10,-198,198,5,-176,176);
    hf->GetXaxis()->SetTitle("X, mm");
    hf->GetYaxis()->SetTitle("Y, mm");
    hf->SetStats(0);
  }
  int xmin = 1, xmax = 1;
  {
    TH1 *hf01 = dynamic_cast<TH1*>(gROOT->FindObject("h_wf_top"));
    xmin = hf01->GetXaxis()->GetFirst();
    xmax = hf01->GetXaxis()->GetLast();
  }
  for (int i=0; i<fNumChannels; i++) {
    int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
    if (it!=kChTopPmt)
      continue;
    if (!(fWF[i] && fWF[i]->GetEntries()>0))
      continue;
    double area = -Integrate(fWF[i],xmin,xmax,2);
    //Printf("  %d %d %d %s - %d %d %lf",i,it,ii,fWF[i]->GetName(),xmin,xmax,area);
    hf->Fill(PMT_top[ii-1][0]-10,PMT_top[ii-1][1],area/2);
    hf->Fill(PMT_top[ii-1][0]+10,PMT_top[ii-1][1],area/2);
  }
  hf->Draw("colz");
}
void MyMainFrame::DrawModeGamma_DrawBotXYform()
{
  const int nch = 19;
  const double PMT_top[][3] = {
    { 0, 0, 0 },
    { -79, 0, 0 }, { -39.5, 68.416, 0 }, { 39.5, 68.416, 0 }, { 79, 0, 0 }, { 39.5, -68.416, 0 }, { -39.5, -68.416, 0 },
    { -158, 0, 0 }, { -118.5, 68.416, 0 }, { -79, 136.832, 0 }, { 0, 136.832, 0 }, { 79, 136.832, 0 }, { 118.5, 68.416, 0 },
    { 158, 0, 0 }, { 118.5, -68.416, 0 }, { 79, -136.832, 0 }, { 0, -136.832, 0 }, { -79, -136.832, 0 }, { -118.5, -68.416, 0 },
  };
  TH2 *hf = dynamic_cast<TH2*>(gROOT->FindObject("hf2_10"));
  if (hf) {
    hf->Reset();
  } else {
    hf = new TH2F("hf2_10","",10,-198,198,5,-176,176);
    hf->GetXaxis()->SetTitle("X, mm");
    hf->GetYaxis()->SetTitle("Y, mm");
    hf->SetStats(0);
  }
  int xmin = 1, xmax = 1;
  {
    TH1 *hf00 = dynamic_cast<TH1*>(gROOT->FindObject("h_wf_bot"));
    xmin = hf00->GetXaxis()->GetFirst();
    xmax = hf00->GetXaxis()->GetLast();
  }
  for (int i=0; i<fNumChannels; i++) {
    int it = (fChInfo[i].type>>8)&0xff, ii = (fChInfo[i].type)&0xff;
    if (it!=kChBotPmt)
      continue;
    if (!(fWF[i] && fWF[i]->GetEntries()>0))
      continue;
    double area = -Integrate(fWF[i],xmin,xmax,2);
    //Printf("  %d %d %d %s - %d %d %lf",i,it,ii,fWF[i]->GetName(),xmin,xmax,area);
    hf->Fill(PMT_top[ii-1][0]-10,PMT_top[ii-1][1],area/2);
    hf->Fill(PMT_top[ii-1][0]+10,PMT_top[ii-1][1],area/2);
  }
  hf->Draw("colz");
}
void MyMainFrame::DrawModeGamma()
{
  //Printf("DrawModeSE()");
  if (!fWF || !fWF[0]) return;

  TPad *pad;
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad01"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeGamma_DrawTopWaveforms();
  }
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad00"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeGamma_DrawBotWaveforms();
  }
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad11"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeGamma_DrawTopXYform();
  }
  pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad10"));
  if (pad) {
    pad->cd();
    pad->Clear();
    DrawModeGamma_DrawBotXYform();
  }
  fCanvas->Update();
}

Int_t MyMainFrame::GetNumEntries() const
{
  if (fProcFile) {
    TTree *event = (TTree*)fProcFile->Get("event");
    return event ? event->GetEntries() : 0;
  }
  if (fRawFile) {
    TTree *event = (TTree*)fRawFile->Get("event");
    return event ? event->GetEntries() : 0;
  }
  return 0;
}

void MyMainFrame::DoSelect()
{
  Printf("DoSelect()");
  fCanvas->cd();
  TF1 *fn = new TF1("fn","sin(x)/x",0,10);
  fn->Draw();
  fCanvas->Update();
}

void MyMainFrame::HandleButtons()
{
  Int_t id;
  TGButton *btn = (TGButton *) gTQSender;
  id = btn->WidgetId();
  printf("HandleButton: id = %d\n", id);
}
void MyMainFrame::HandleCanvas(Int_t event, Int_t x, Int_t y, TObject* selected)
{
  //Printf("event %d @ (%d,%d) with %s %p",event,x,y,(selected ? selected->ClassName() : "-"),(void*)selected);
  if (event==1 && selected && selected->IsA()==TPaveText::Class()) {
    TPaveText *pave = (TPaveText*)selected;
    const char *label = 0;
    //((pave->GetLine(0)!=0) ? pave->GetLine(0)->GetTitle() : 0); - fails in ROOT 5
    if (pave->GetLine(0)!=0) label = pave->GetLine(0)->GetTitle();
    int ich;
    for (ich=0; ich<fNumChannels; ich++)
      if (strcmp(fChInfo[ich].label,label)==0)
        break;
    TH1 *h_wf = dynamic_cast<TH1*>(gROOT->FindObject(TString::Format("h_wf_%02d",ich)));
    //Printf("  %s %d %p",pave->GetLine(0)->GetTitle(),ich,h_wf);
    if (h_wf) {
      TCanvas *c = dynamic_cast<TCanvas*>(gROOT->FindObject("c1"));
      if (c)
        c->Show();//RaiseWindow();
      else
        c = new TCanvas("c1","Single waveform view");
      c->cd();
      h_wf->Draw();
      c->Update();
    }
  }
}

void MyMainFrame::TimerEvent()
{
  //Printf("TimerEvent()");
  DrawMode_t mode = (DrawMode_t)fCtrlDrawMode->GetSelected();
  switch(mode) {
  case kDrawNone:
    break;
  case kDrawSimple:
    break;
  case kDrawSE: {
    TH1 *hf01 = dynamic_cast<TH1*>(gROOT->FindObject("hf2_01"));
    int top_xmin = -1, top_xmax = -1;
    if (hf01) {
      top_xmin = hf01->GetXaxis()->GetFirst();
      top_xmax = hf01->GetXaxis()->GetLast();
    }
    TH1 *hf00 = dynamic_cast<TH1*>(gROOT->FindObject("hf2_00"));
    const bool sync_time = true;
    if (hf00 && sync_time) {
      hf00->GetXaxis()->SetRange(top_xmin,top_xmax);
      //hf00->Modify();
      TPad *pad = dynamic_cast<TPad*>(gROOT->FindObject("pad00"));
      if (pad) { pad->Modified(); pad->Update(); }
    }
    int bot_xmin = -1, bot_xmax = -1;
    if (hf00) {
      bot_xmin = hf00->GetXaxis()->GetFirst();
      bot_xmax = hf00->GetXaxis()->GetLast();
    }
    //Printf("  top %d %d  bot %d %d",top_xmin,top_xmax,bot_xmin,bot_xmax);
    static int old_top_xmin = -1, old_top_xmax = -1;
    if (old_top_xmin!=top_xmin || old_top_xmax!=top_xmax) {
      //Printf("  top %d %d  bot %d %d",top_xmin,top_xmax,bot_xmin,bot_xmax);
      TPad *pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad11"));
      if (pad) {
        pad->cd();
        pad->Clear();
        DrawModeSE_DrawTopXYform();
      }
      old_top_xmin = top_xmin, old_top_xmax = top_xmax;
    }
    static int old_bot_xmin = -1, old_bot_xmax = -1;
    if (old_bot_xmin!=bot_xmin || old_bot_xmax!=bot_xmax) {
      Printf("  top %d %d  bot %d %d",top_xmin,top_xmax,bot_xmin,bot_xmax);
      TPad *pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad10"));
      if (pad) {
        pad->cd();
        pad->Clear();
        DrawModeSE_DrawBotXYform();
      }
      old_bot_xmin = bot_xmin, old_bot_xmax = bot_xmax;
    }
    fCanvas->Update();
  } break;
  case kDrawGamma: {
    TH1 *hf01 = dynamic_cast<TH1*>(gROOT->FindObject("h_wf_top"));
    int top_xmin = -1, top_xmax = -1;
    if (hf01) {
      top_xmin = hf01->GetXaxis()->GetFirst();
      top_xmax = hf01->GetXaxis()->GetLast();
    }
    TH1 *hf00 = dynamic_cast<TH1*>(gROOT->FindObject("h_wf_bot"));
    int bot_xmin = -1, bot_xmax = -1;
    if (hf00) {
      bot_xmin = hf00->GetXaxis()->GetFirst();
      bot_xmax = hf00->GetXaxis()->GetLast();
    }
    //Printf("  top %d %d  bot %d %d",top_xmin,top_xmax,bot_xmin,bot_xmax);
    static int old_top_xmin = -1, old_top_xmax = -1;
    if (old_top_xmin!=top_xmin || old_top_xmax!=top_xmax) {
      Printf("  top %d %d  bot %d %d",top_xmin,top_xmax,bot_xmin,bot_xmax);
      TPad *pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad11"));
      if (pad) {
        pad->cd();
        pad->Clear();
        DrawModeGamma_DrawTopXYform();
      }
      old_top_xmin = top_xmin, old_top_xmax = top_xmax;
    }
    static int old_bot_xmin = -1, old_bot_xmax = -1;
    if (old_bot_xmin!=bot_xmin || old_bot_xmax!=bot_xmax) {
      //Printf("  top %d %d  bot %d %d",top_xmin,top_xmax,bot_xmin,bot_xmax);
      TPad *pad = dynamic_cast<TPad*>(fCanvas->FindObject("pad10"));
      if (pad) {
        pad->cd();
        pad->Clear();
        DrawModeGamma_DrawBotXYform();
      }
      old_bot_xmin = bot_xmin, old_bot_xmax = bot_xmax;
    }
    fCanvas->Update();
  } break;
  default:
    Printf("TimerEvent: Unhandled mode %d",int(mode));
  }
}

void MyMainFrame::PrintSelected()
{
  Printf("PrintSelected()");
}

void MyMainFrame::PrintInfo()
{
  Printf("Dump");
  Printf("  fRawFile = %p,",fRawFile);
  Printf("  fProcFile = %p,",fProcFile);
  Printf("  fNumChannels = %d,",fNumChannels);
  Printf("  fChInfo = (%p),",fChInfo);
  if (fChInfo) {
    int nch = fNumChannels;
    for (int ich=0;ich<nch;ich++) {
      Printf("    [%d] samples=%d gain=%g offset=%.3f period=%g delay=%g label='%s'", ich, fChInfo[ich].nsamples, fChInfo[ich].v_bin, fChInfo[ich].v_off, fChInfo[ich].t_bin, fChInfo[ich].t_off, fChInfo[ich].label);
      //Printf("         line_min=%f line_max=%f line_base=%f line_noise=%f", fChInfo[ich].line_min, fChInfo[ich].line_max, fChInfo[ich].line_base, fChInfo[ich].line_noise);
    }
  }
  Printf("  fWF = (%p),",fWF);
  if (fWF) {
    int nch = fNumChannels;
    for (int ich=0;ich<nch;ich++)
      if (fWF[ich])
        Printf("    [%d] Samples=%d Left=%f Right=%f Min=%f Max=%f", ich, fWF[ich]->GetNbinsX(), fWF[ich]->GetXaxis()->GetBinLowEdge(0),fWF[ich]->GetXaxis()->GetBinUpEdge(fWF[ich]->GetNbinsX()),fWF[ich]->GetMinimum(),fWF[ich]->GetMaximum());
      else
        Printf("    [%d] (nil)",ich);
  }
  Printf("  fNumPulses = %d,",fNumPulses);
  Printf("  fPulses = (%p),",fPulses);
  if (fPulses) {
    for (int i=0; i<fNumPulses && i<20; i++)
      Printf("    [%d] ichannel=%d itype=%d time=%g width=%g amplitude=%g area=%g",i,fPulses[i].ichannel,fPulses[i].itype,fPulses[i].time,fPulses[i].width,fPulses[i].amplitude,fPulses[i].area);
  }
  Printf("  fNumClusters = %d,",fNumClusters);
  Printf("  fClusters = (%p),",fClusters);
  if (fClusters) {
    for (int i=0; i<fNumClusters && i<20; i++)
      Printf("    [%d] itype=%d time=%g width=%g amplitude=%g area=%g nspe=%f",i,fClusters[i].itype,fClusters[i].time,fClusters[i].width,fClusters[i].amplitude,fClusters[i].area,fClusters[i].nspe);
  }
}

#if defined(__CINT__) || defined(__CLING__)
void view_corr()
{
  // Popup the GUI...
  new MyMainFrame(gClient->GetRoot(), 200, 200);
}
#else
int main(int argc, char **argv)
{
  TApplication *app = new TApplication("AppMainFrame", &argc, argv);
  MyMainFrame *ui = new MyMainFrame(gClient->GetRoot(), 200, 200);
  Printf("UI %lu %p",sizeof(MyMainFrame),ui);
  app->Run(true);
  delete ui;
  //delete app;
  return 0;
}
#endif
