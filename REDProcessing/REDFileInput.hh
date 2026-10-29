#ifndef RED_REDFileInput_hh
#define RED_REDFileInput_hh


#include "REDProcessing/InputModule.hh"

namespace RED
{

  class Event;
  class InputFile;

  class REDFileInput : public InputModule
  {
  public:

    REDFileInput();
    ~REDFileInput();

    int Initialize();

    ProcessingModule::EventStatus BeginOfRun(Event *m_event);
    ProcessingModule::EventStatus EndOfRun(Event *m_event);

    ProcessingModule::EventStatus ProcessEvent(Event *m_event);

    ProcessingModule::EventStatus BeginOfRunSegment(Event *m_event);
    ProcessingModule::EventStatus EndOfRunSegment(Event *m_event);

    int ShutDown();

    void FillFilenameInfo();

  private:
    InputFile *fREDFile;

    int        fNumberOfEntries;    // Number of entries in a segment.
    int        fCurrentRunNumber;   // The number of the current run.
    int        fNextRunNumber;      // The number of the next run.
    int        fTotalEventsRead;    // The total number of events read
                                    // while REDoffline worked.

    // Counters
    int        fEventCounter;      // Number of events read.
    int        fRecordCounter;     // Number current event.
    int        fFileCounter;       // Number of the processed file.

    // Flags
    bool       fNewRun;            // True if a new run begins; False otherwise.
    bool       fFileClosed;        // True if an input file it is the first file
                                   // to process or if the previous file
                                   // has been has been read completely and closed.
                                   // It used for BeginOfRun-BeginOfSegment info
                                   // exchange if previous file read completely
                                   // or not.

    // Info from filename
    struct FileInfo;
    FileInfo *fFileInfo;
    void ResetRunInfo(Event*);         // Reset RunInfo.

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(REDFileInput)
    ClassDef(REDFileInput,1)
  };

} // namespace

#endif /* RED_REDFileInput_hh */
