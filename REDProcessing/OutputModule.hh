#ifndef RED_OutputModule_hh
#define RED_OutputModule_hh

#include <string>

#include "REDProcessing/ProcessingModule.hh"
#include "REDFile/File.hh" // rootcint needs it

namespace RED
{

  class Event;
  class RunInfo;
  class OutputFile;

  class OutputModule : public ProcessingModule
  {
  public:

    OutputModule();
    ~OutputModule() { ; }

    int Initialize();

    ProcessingModule::EventStatus BeginOfRun(Event *);        // when new run begins
    ProcessingModule::EventStatus BeginOfRunSegment(Event *); // when new file of run begins
    ProcessingModule::EventStatus ProcessEvent(Event *);      // for each event
    ProcessingModule::EventStatus EndOfRunSegment(Event *);   // when file of run ends
    ProcessingModule::EventStatus EndOfRun(Event *);          // when run ends

    int ShutDown();


    bool SetOutputName(const std::string);
    bool SetOutputName(const char*);

    bool GetUseLegacyMode() const { return fUseLegacyMode; }
    void SetUseLegacyMode(bool val) { fUseLegacyMode = val; }

//  std::string GenFileName();


  private:
    std::string fFilename;    // Name for an output file
    bool        fUseLegacyMode; // store event as plain structure instead of object
    OutputFile* fOutputFile;  //! actual file
    void WriteRunInfo(const RunInfo *);

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(OutputModule)
    ClassDef(OutputModule,1)
  };
//--------------------inlines----------------------------------------

} // namespace

#endif /* REDOutputModule_hh */
