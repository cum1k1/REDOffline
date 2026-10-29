#ifndef RED_Z3DAQInput_hh
#define RED_Z3DAQInput_hh

#include "REDProcessing/InputModule.hh"
#include "REDEvent/RunInfo.hh"
#include <string>

class z3file;

namespace RED
{

  class Z3DAQInput : public InputModule
  {
  public:
    Z3DAQInput();
    ~Z3DAQInput();

    int Initialize();

    ProcessingModule::EventStatus BeginOfRun(Event *);
    ProcessingModule::EventStatus BeginOfRunSegment(Event *);
    ProcessingModule::EventStatus ProcessEvent(Event *);
    ProcessingModule::EventStatus EndOfRunSegment(Event *);
    //ProcessingModule::EventStatus EndOfRun(Event *);

    //int ShutDown();

  private:
    std::string   fFileName;
    z3file       *fFile; //!
    struct {
      std::string name;
      unsigned    number;
      std::string type;
      unsigned    sequence;
      bool        compressed;
      bool        same_run;
      bool        format_ok;
    } fRunHint; // recovered from name if possible
    RunInfo       fRunInfo; // caches values from file

    void ParseFileName();
    bool OpenSegment();
    bool CloseSegment();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(Z3DAQInput)
    ClassDef(Z3DAQInput,1)
  };

} // namespace

#endif /* RED_Z3DAQInput_hh */
