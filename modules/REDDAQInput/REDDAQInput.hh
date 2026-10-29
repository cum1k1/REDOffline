#ifndef RED_REDDAQInput_hh
#define RED_REDDAQInput_hh

#include "REDProcessing/InputModule.hh"
#include "REDEvent/RunInfo.hh"
#include <string>

namespace RED
{

  class DataFile;

  class REDDAQInput : public InputModule
  {
  public:

    struct RunHint {
      unsigned    number;
      std::string type;
      unsigned    sequence;
      bool        same_run;
      bool        format_ok;
    };

    REDDAQInput();
    ~REDDAQInput();

    int Initialize();

    ProcessingModule::EventStatus BeginOfRun(Event *);
    ProcessingModule::EventStatus BeginOfRunSegment(Event *);
    ProcessingModule::EventStatus ProcessEvent(Event *);
    ProcessingModule::EventStatus EndOfRunSegment(Event *);
    //ProcessingModule::EventStatus EndOfRun(Event *);

    int ShutDown();

  private:
    std::string   fFileName;      // Current filename
    DataFile     *fFile;          //! actual file
    RunHint       fRunHint;       // recovered from name if possible
    //RunInfo       fRunInfo; // caches values from file
    //std::map<Int_t,RunInfo> fRunMap;
    int           fRecordCounter; // cache value since file doesn't remember

    void ParseFileName();
    bool OpenSegment();
    bool CloseSegment();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(REDDAQInput)
    ClassDef(REDDAQInput,1)
  };

} // namespace

#endif /* RED_REDDAQInput_hh */
