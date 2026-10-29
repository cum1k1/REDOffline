#ifndef RED_ExampleModule_hh
#define RED_ExampleModule_hh

#include "REDProcessing/ProcessingModule.hh"

namespace RED
{

  class ExampleModule : public ProcessingModule
  {
  private:
    // Here you can define parameters for this module
    int         mode;
    double      level;
    std::string option;

  public:
    ExampleModule();
    ~ExampleModule();

    int Initialize(); // before processing

    EventStatus BeginOfRun(Event *);        // when new run begins
    EventStatus BeginOfRunSegment(Event *); // when new input file begins
    EventStatus ProcessEvent(Event *);      // for each event
    EventStatus EndOfRunSegment(Event *);   // when input file ends
    EventStatus EndOfRun(Event *);          // when run ends

    int ShutDown();   // after processing

    //
    void SetMode(int v) { mode = v; }
    void SetLevel(double v) { level = v; }
    void SetOption(const std::string &v) { option = v; }

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(ExampleModule)
    ClassDef(ExampleModule,1)
  };

} // namespace

#endif /* RED_ExampleModule_hh */
