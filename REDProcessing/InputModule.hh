#ifndef RED_InputModule_hh
#define RED_InputModule_hh

#include <vector>
#include <string>

#include "REDProcessing/ProcessingModule.hh"

namespace RED
{

  class Event;

  class InputModule : public ProcessingModule
  {
  public:
    virtual ~InputModule();
    /*
    virtual int Initialize();

    virtual ProcessingModule::EventStatus BeginOfRun(Event *);
    virtual ProcessingModule::EventStatus BeginOfRunSegment(Event *);
    virtual ProcessingModule::EventStatus ProcessEvent(Event *);
    virtual ProcessingModule::EventStatus EndOfRunSegment(Event *);
    virtual ProcessingModule::EventStatus EndOfRun(Event *);

    virtual int ShutDown();
    */
    virtual bool CanGenerateEvents() { return true; } // module will fill event from scratch
    virtual bool CanChangeEvents() { return true; }   // module will change something in event

    // This is how we give sources for input.
    // Please notice that it is in form of URI. This allows for transparent use
    // use of path wildcards, and indirect lists in form of REST or SQL queries.
    virtual int AddURI(const std::string &URI);
    // compartibility for simple files
    int AddFile(const std::string& name) { return AddURI(name); }

    // The following try to simulate random acces for the sake of GUI. Though one
    // should remember that such access could be unavailable or very slow.
    // Seek input to a particular event given its record number in current segment.
    virtual bool SeekEvent(size_t irecord);
    // Sry to find an event by its run and event numbers in current segment and seek to it.
    virtual bool SearchEvent(Int_t runNumber, Int_t eventNumber);

    // Print just contents of fSegments, unlike Print() that prints entire object.
    void PrintSegments() const;

  protected:
    // Here we use vector to simplify for derived classes handling of
    // potential extra properties for each segment.
    // We use word 'segment' because it could be something more complicated.
    // It naturally comes even with TFile.
    typedef std::vector<std::string> SegmentsList;
    SegmentsList fSegments;    // A list of files to process
    unsigned int fCurrSegment; // Index in fSegments for current file

    virtual bool OpenSegment();
    virtual bool CloseSegment();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(InputModule)
    ClassDef(InputModule,1)
  };

} // namespace

#endif /* RED_InputModule_hh */




