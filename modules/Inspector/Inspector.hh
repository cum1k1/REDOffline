#ifndef RED_Inspector_hh
#define RED_Inspector_hh

#include "REDProcessing/ProcessingModule.hh"

class TGMainFrame;
class TGComboBox;
class TGNumberEntry;
class TGTextButton;
class TGTextEntry;
class TGTextView;
class TCanvas;

namespace RED
{

  class Inspector : public ProcessingModule
  {

  public:
    Inspector();
    ~Inspector();

    EventStatus ProcessEvent(Event*);

  private:
    enum Modes {
      kModeNone = 0,
      kModeWaveform,
      kModeAmplHist,
      kModeHeatplot,
      kModePlanes,
      kModeEvent3D,
      kModeClusters
    };
    bool           fWait;          // loop in graphical events cycle while user plays with this event
    int            fSkipNumEvents; // skip this number of next events
    Event         *fCacheEvent;    //! cache event to draw

    // graphical objects
    TGMainFrame   *fMain;          //! window of a widget frame, also flag that window was created
    TGComboBox    *fModeSelector;  //!
    TGNumberEntry *fSkipEvents;    //!
    TGTextButton  *fNext;          //!
    TGNumberEntry *fChannelNumber; //!
    TGTextEntry   *fChannelLabel;  //!
    TGNumberEntry *fIndex;         //!
    TGTextView    *fInfo;          //! text field to display useful information
    TCanvas       *fPad;           //! TCanvas where things are drawn

    std::vector<TObject*> fDrawnObjects; //! keep list of drawn objects to delete them manually
    void RegisterDrawnObject(TObject* object) { fDrawnObjects.push_back(object); }
    void ClearDrawnObjects();

    enum HeatPrintMode {
       kPulse = 0,
       kCluster
    };
    HeatPrintMode fHeatPrintMode;

  public: // need for signals
    void CreateWindow();  // create all window objects
    void CloseWindow();   // handle window close
    void ChangeMode();    // redraw with new mode
    void ChangeNext();    // change 'Next' button label on fSkipEvents change
    void NextEvent();     // handle Next/Skip button
    void ChangeChannel(); // handle channel change
    void ChangeIndex();   // handle index change
    void WaitUser();      // wait for user to finish with this event
    void DoDraw();        // (re)draw canvas and info
    //void ProcessedEvent(Event_t *event);
    void SetInfo(const TString& s);

    void SetHeatPrintMode(const char* mode = "cluster");

    // module defines
    RED_PROCESSING_MODULE_DEFINE(Inspector)
    ClassDef(Inspector,1)
  };

} // namespace

#endif /* RED_Inspector_hh */
