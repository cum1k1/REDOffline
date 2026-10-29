#ifndef RED_ProcessingModule_hh
#define RED_ProcessingModule_hh

//#ifndef REDProcessingModuleFactory_hh
#include "REDProcessing/ProcessingModuleFactory.hh"
//#endif
#include <TNamed.h>

//class std::ostream;

namespace RED
{

  class Event;

  class ProcessingModule : public TNamed
  {
    //friend class ProcessingManager;
  public:
    enum ModuleStatus {
      kNone = 0,
      kCreated,      // created ok
      kInit,         // init ok
      kGood,         // processing ok
      kEndSegment,   // reached last event in segment (file)
      kEndRun,       // reached the end of run
      kEndAll,       // reached the very end
      kErrorEvent,   // found error, single event involved
      kErrorSegment, // more serious error, segment (file) not readable
      kErrorRun,     // the rest of the run isn't readable
      kAbort         // abort processing
    };

    enum EventStatus {
      kError  = -1, // failed
      kOk = 0,
      kDrop         // want to drop
    };

    //enum {
    //  irev = 18 // do not remove a751e9ae
    //};
    //static const int crev;

  protected:

    ModuleStatus fStatus;
    int          fVerbose;

  public:
    virtual ~ProcessingModule();

    // main processing chain
    // These virtual methods are intended to be overloaded by derived classes

    virtual int Initialize();

    virtual EventStatus BeginOfRun(Event *);        // when new run begins
    virtual EventStatus BeginOfRunSegment(Event *); // when new file of run begins
    virtual EventStatus ProcessEvent(Event *);      // for each event
    virtual EventStatus EndOfRunSegment(Event *);   // when file of run ends
    virtual EventStatus EndOfRun(Event *);          // when run ends

    virtual int ShutDown();

    // features of a partucular module
    virtual bool CanGenerateEvents() { return false; } // module will fill event from scratch
    virtual bool CanDropEvents() { return false; }     // module will filter-out some events
    virtual bool CanChangeEvents() { return false; }   // module will change something in event
    virtual bool CanBeManifold() { return true; }      // module allows multiple instances

    // get/set routines
    virtual ModuleStatus GetStatus() const { return fStatus; }
    virtual ModuleStatus ClearStatus() { return fStatus; }
    virtual bool StatusGood() const { return fStatus & (kInit | kGood | kEndSegment | kEndRun); }
    virtual bool StatusError() const { return fStatus & (kErrorEvent | kErrorSegment | kErrorRun | kAbort); }
    int GetVerbose() const { return fVerbose; }
    void SetVerbose(int v) { fVerbose = v; }
    void SetName(const char* name);
    void SetNameTitle(const char* name, const char* title);

    // prevent some operations for class
  protected:
    // don't allow objects
    ProcessingModule();
  private:
    // no copying
    ProcessingModule& operator=(const ProcessingModule&); // not implemented
    TObject* Clone(const char* newname="") const { return 0; }
    void Copy(TObject &object) const { ; }

  public:
    /*! The following lines are an essential macro for each module.
        It defines important properties of the module including 
        name and ROOT class. It also automatically registers the
        class with the factory. It is also necessary to include
        the directives:

        RED_PROCESSING_MODULE_IMPLEMENT( ClassName )
        ClassImp( ClassName )

        at the top of the module source file after include statements
        where ClassName should be replaced with the implemented
        class name.  */
    RED_PROCESSING_MODULE_DEFINE( ProcessingModule )
    ClassDef( ProcessingModule, 1 )

  };
//--------------------inlines----------------------------------------

} // namespace

std::ostream& operator<<(std::ostream&, const RED::ProcessingModule::ModuleStatus);
std::ostream& operator<<(std::ostream&, const RED::ProcessingModule::EventStatus);

#endif /* RED_ProcessingModule_hh */
