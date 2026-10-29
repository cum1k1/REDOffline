#ifndef RED_RunInfo_hh
#define RED_RunInfo_hh

#include <TObject.h>
#include <TTimeStamp.h>

namespace RED
{

  class RunInfo : public TObject
  {
  public:
    Int_t       fRunNumber;
    std::string fDAQ_ID;
    std::string fRunType;
    std::vector<std::string> fLabels;
    TTimeStamp  fStart;
    TTimeStamp  fStop;
    TTimeStamp  fAcquisition;
    Int_t       fNumChannels;
    Int_t       fTriggerMode;
    std::string fDescription;
    Int_t       fNumEvents;
    Int_t       fFirstRecord;

  public:
    RunInfo();
    ~RunInfo();
    RunInfo( const RunInfo& );
    void Clear( Option_t* opt = "" );
    void Print( Option_t* opt = "" ) const;
    bool operator==(const RunInfo& ) const;
    RunInfo& operator=( const RunInfo& );

  protected:
    //TRefArray      fRefClusters; // clusters this signal went into.

    ClassDef( RunInfo, 1 )
  };

} // namespace

#endif /* RED_RunInfo_hh */
