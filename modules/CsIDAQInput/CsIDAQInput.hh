#ifndef RED_CsIDAQInput_hh
#define RED_CsIDAQInput_hh

#include "REDProcessing/InputModule.hh"
#include "REDEvent/RunInfo.hh"
#include <string>

class TFile;
class TTree;

namespace RED
{

  class CsIDAQInput : public InputModule
  {
  public:
    CsIDAQInput();
    ~CsIDAQInput();

    int Initialize();

    ProcessingModule::EventStatus BeginOfRun(Event *);
    ProcessingModule::EventStatus BeginOfRunSegment(Event *);
    ProcessingModule::EventStatus ProcessEvent(Event *);
    ProcessingModule::EventStatus EndOfRunSegment(Event *);
    //ProcessingModule::EventStatus EndOfRun(Event *);

    //int ShutDown();

    void SetRunType(const char* v) { fRunHint.type = v; }
    void SetRunNumber(unsigned v) { fRunHint.number = v; }

  private:
    TFile        *fFile; //!
    struct {
      std::string type;   // provided by user
      unsigned    number; // provided by user
      unsigned    date;
      unsigned    time;
      bool        same_run;
      bool        format_ok;
    } fRunHint; // recovered from name if possible
    TTree        *fEventTree; //!
    class EventData;
    EventData    *fEventData; //! IO structure
    TTree        *fRunSettingsTree; //!
    class RunSettings;
    RunSettings  *fRunSettings; //! IO structure
    Long64_t      fEntry;     // current entry number
    Int_t         fEventNumber; // event number throught run
    RunInfo       fRunInfo; // caches values from file

    void ParseFileName();
    bool OpenSegment();
    void FillRunInfo();
    bool CloseSegment();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(CsIDAQInput)
    ClassDef(CsIDAQInput,1)
  };

} // namespace

#endif /* RED_CsIDAQInput_hh */
