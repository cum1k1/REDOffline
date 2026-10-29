#ifndef RED_DAQMANInput_hh
#define RED_DAQMANInput_hh

#include "REDProcessing/InputModule.hh"
#include "REDEvent/RunInfo.hh"

class TFile;
class TTree;
class EventData;

namespace RED
{

  class DAQMANInput: public InputModule
  {
  private:
    // Here you can define parameters for this module
    int         mode;
    double      level;
    std::string option;

    unsigned int fEntry;          // current entry number
    TFile        *fFile;          //! ROOT file object
    TTree        *fEventTree;     //! ROOT event tree
    EventData    *fEvent;         //!
    RunInfo      fRunInfo;        // caches values from file
    Int_t        fEventNumber;    // number of event through the run

    bool OpenSegment();
    void FillRunInfo();
    bool CloseSegment();

  public:
    DAQMANInput();
    ~DAQMANInput();

    int Initialize(); // before processing

    EventStatus BeginOfRun(Event *event);        // when new run begins
    EventStatus BeginOfRunSegment(Event *event); // when new input file begins
    EventStatus ProcessEvent(Event *event);      // for each event
    EventStatus EndOfRunSegment(Event *event);   // when input file ends
    EventStatus EndOfRun(Event *event);          // when run ends

    int ShutDown();   // after processing

    //
    void SetMode(int v) { mode = v; }
    void SetLevel(double v) { level = v; }
    void SetOption(const std::string &v) { option = v; }

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(DAQMANInput)
    ClassDef(DAQMANInput,1)
  };

} // namespace

#endif /* RED_DAQMANInput_hh */
