#ifndef RED_ProcessingInfo_hh
#define RED_ProcessingInfo_hh

#include <TObject.h>
#include <TTimeStamp.h>

#include <vector>
#include <string>

namespace RED
{

  class ProcessingInfo : public TObject
  {
  public:
    typedef std::vector<std::string> StrVec;

  public:
    //REDProcessingInfo();
    //~REDProcessingInfo();
    //void Clear( Option_t* opt = "" );
    //void Print( Option_t* opt = "" ) const;
    //bool operator==(const REDProcessingInfo& sig) const;

    //void Print(Option_t * = "") const;
    //void SetPrevProcInfo( const REDProcessingInfo& );
    //const REDProcessingInfo* GetPrevProcInfo() const;

  protected:
    std::string fBuildID;         // Identification string of the build
    std::string fSVNRevision;     // SVN revision of the build
    std::string fErrorLoggerMsg;  // All output from the error logger (up to when the file was written)
    StrVec      fVectorOfModules; // List of modules used in order of usage
    StrVec      fCommandsCalled;  // List of commands used
    TTimeStamp  fStartTimeOfProcess;   // Start time of processing
    bool fCalibrationsFromDatabase;    // false if any calibrations used default values rather than database values
    ProcessingInfo* fPrevProc; // Previous processing information

    ClassDef( ProcessingInfo, 1 )
  };

} // namespace

#endif /* RED_ProcessingInfo_hh */
