#ifndef RED_File_hh
#define RED_File_hh

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// RED::File                                                            //
//                                                                      //
// This class provides simple and user friendly interface               //
// to read/write REDOffline data files.                                 //
//                                                                      //
// Not THREAD_SAFE                                                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <TNamed.h>
#include <TFile.h>
#include "TTree.h"
#include <string>


#include "REDEvent/RunInfo.hh"
#include "REDEvent/Waveform.hh"
#include "REDEvent/ProcessingInfo.hh"


namespace RED
{

  class Event;
//  class RunInfo;
  class ProcessingInfo;
  class Pulse;
  class Cluster;

  class File : public TNamed
  {
  protected:
    File(); // prohibit creation objects of interface class itself
    bool        fUseLegacyMode;

    TFile* fFile;
    TTree* fRunTree;
    TTree* fEventTree;
    TTree* fPulseTree;

    struct _Event;
    _Event *fEvent;

    struct _Run;
    _Run *fRun;

    struct _Pulse;
    _Pulse *fPulses;

    struct _Cluster;
    _Cluster *fClusters;

    void ReadRunInfo(int EntryNumber=0);

    int fRecordCounter;

    int fMaxNumOfChannels;
    void SetWaveformArraySize(int size);
    void SetWaveformBranchAddress();

    int fMaxNumOfPulses;
    void SetPulseArraySize(int size);
    void SetPulseBranchAddress();

    int fMaxNumOfClusters;
    void SetClusterArraySize(int size);
    void SetClusterBranchAddress();

    template<typename T>
    T* SetArraySize(T* ArrayPtr, unsigned int size) {
      if (ArrayPtr != 0) {
        delete [ ] ArrayPtr;
      }

      if (size != 0) {
        T* TmpPtr = new T[size];
        if (TmpPtr != 0) ArrayPtr = TmpPtr;
        return ArrayPtr;
      } else {
        ArrayPtr = 0;
        return ArrayPtr;
      }
    }

    void FillRunMap();
    void ClearRunMap();
//    int GetRunEntry(int RunNumber);

  public:
    virtual ~File();

//  virtual File& operator=( const File& );
    virtual bool operator==( const File& ) const;
    virtual void Print( Option_t* option = "") const;
    virtual void Clear( Option_t* option = "");

    virtual bool IsOpen() const;
    virtual bool IsWritable() const;

    int GetVerbose() const { return fVerbose; }
    void SetVerbose(int val) { fVerbose = val; }

    bool GetUseLegacyMode() const { return fUseLegacyMode; }
    void SetUseLegacyMode(bool val) { fUseLegacyMode = val; }

    const std::string& GetFilename() const { return fFileName; }

    virtual void SetFilename(const std::string& filename) { fFileName = filename;}

    virtual bool Open();
    virtual bool ReOpen();
    virtual bool Close();
    bool ReadEvent(Event *event, int irecord); // number of record in the tree
    bool ReadEvent(Event* event, int irun, int ievent); // find event by irun and ievent pair
    bool ReadNextEvent(Event *event);
    Event* ReadEvent(int irecord);
    int GetNumEvents() const;
    int GetMaxNumChannels() const;
    Long64_t GetFileSize() const;
    const RunInfo& GetRunInfo() const;
    const RunInfo& GetRunInfo(int run_id) const;
    const ProcessingInfo& GetProcessingInfo(int level = 0) const;

    // Identify trees in a root file.
    static const std::string GetEventTreeName() { return "event"; }
    static const std::string GetEventBranchName() { return "EventBranch"; }
    static const std::string GetEventTreeDescription() { return "Event data"; }
    static const std::string GetEventClassName() { return "RED::Event"; }
    static const std::string GetWaveformBranchName() { return "fWaveformData"; }

    static const std::string GetRunTreeName() { return "run"; }
    static const std::string GetRunBranchName() { return "RunBranch"; }
    static const std::string GetRunTreeDescription() { return "Run data"; }
    static const std::string GetRunClassName() { return "RED::RunInfo"; }


    //inline int GetTreeCompressionLevel() { return 4; }

//  int ReadWaveform(Waveform* Waveform, int& ChannelNumber);
  private:
    bool        fInit;
    int         fVerbose;
    std::string fFileName;
//  TFile      *fFile;                // moved in a protected field
    mutable RunInfo  fRunInfo;        // cache; mutable for GetRunInfo(run_id)
    ProcessingInfo fProcInfo;         // cache
    std::map<Int_t,RunInfo> fRunMap;  //! RunInfo map to keep RunInfos and read
                                      // files with multiple run entries correctly

    void ReadWaveform(Waveform*, int);
    void ReadPulse(Pulse*, int);
    void ReadCluster(Cluster*, int, Event*);


    ClassDef(File,1)
  };

  class InputFile : public File
  {
  public:
    InputFile();
    InputFile(const char *filename);
    InputFile(const std::string &filename);
//  InputFile(const InputFile &that);
    ~InputFile();

    bool Open();
    bool ReOpen();
    bool Close();

    void SetFilename(const std::string &filename);

//____________________ADDED________________
//
    bool IsWritable() const;
    bool IsOpen() const;

    int GetNumEntries() const;
    int GetRunNumber() const;

    ClassDef(InputFile,1)
  };

  class OutputFile : public File
  {
  public:
    OutputFile();
    OutputFile(const char *filename);
    OutputFile(const std::string &filename);
//  OutputFile(const OutputFile &that);
    ~OutputFile();

    void SetFilename(const std::string &filename);
    bool IsOpen() const;

    bool Open();
    bool ReOpen();
    bool Close();

    bool WriteEvent(const Event *event);
    void AddRunInfo(const RunInfo *run);
    void SetProcessingInfo(const ProcessingInfo&);

//_______________Added________________________
  private:
    RunInfo *fRunInfoCached;

    void InitEventTree();
    void InitRunTree();

//__________________________________________
    ClassDef(OutputFile,1)
  };


  struct File::_Event {
    Int_t       fRunNumber;
    Int_t       fEventNumber;
    Int_t       fTriggerCount;
    UInt_t      fTriggerTime_fSec;
    UInt_t      fTriggerTime_fNanoSec;
    UInt_t      fTriggerSource;
    Bool_t      fIsMonteCarloEvent;
    Bool_t      fTaggedAsMuon;
    Bool_t      fTaggedAsNoise;
    Int_t       fNumChannels;
    Int_t       fNumPulses;
    Int_t       fNumClusters;
    Int_t       fNumWaveforms;
    Bool_t      fHasSaturatedChannel;
    Bool_t      fSkippedByClustering;

    //arrays
    Int_t* fChannel;
    Bool_t* fIsCompressed;
    Int_t* fIsModified;
    Int_t* fNumSamples;
    Double_t* fPeriod;
    Double_t* fDelay;
    Double_t* fGain;
    Double_t* fOffset;
    Int_t* fPlaceOfTrigger;
    Int_t* fBitWidth;
    Double_t* fSignalMin;
    Double_t* fSignalMax;
    Double_t* fSignalBase;
    Double_t* fSignalNoise;
    Bool_t* fSignalSaturated;
    std::vector<std::vector<float> > *fData;

    _Event();
    ~_Event();
  };

  struct File::_Run {
    Int_t       fRunNumber;
    Int_t       fNumEvents;
    std::string* fDAQ_ID;
    std::string* fRunType;
    std::vector<std::string>*  fLabels;
    std::string* fLabelsJoined;
    UInt_t  fStart;
    UInt_t  fStop;
    UInt_t  fAcquisition;
    Int_t   fActualNumOfChannels;
    Int_t   fMaxNumOfChannels;
    Int_t   fTriggerMode;
    Int_t   fFirstRecord;
    std::string* fDescription;

    _Run();
// Run& operator=(Run &run);
    ~_Run();
  };

  struct File::_Pulse {
    Int_t*       fChannel;
    Int_t*       fType;
    Double_t*    fBaseline;
    Double_t*    fBaselineError;
    Double_t*    fNoise;
    Double_t*    fTime;
    Double_t*    fTimeError;
    Double_t*    fTau;
    Int_t*       fFirstSample;
    Int_t*       fLastSample;
    Double_t*    fWidth10;
    Double_t*    fWidth50;
    Double_t*    fWidth90;
    Double_t*    fRisetime;
    Double_t*    fFalltime;
    Double_t*    fDecaytime;
    Double_t*    fAmplitude;
    Double_t*    fPeakTime;
    Double_t*    fArea;
    Double_t*    fAreaEff;
    Double_t*    fAreaDiff;
    Double_t*    fChiSquare;
//  Double_t    fFitParameters[8];
    Int_t*       fSaturated;
    Bool_t*      fOverlayed;
    Bool_t*      fPartial;

    _Pulse();
//  Pulse& operator=(const Pulse&);
    ~_Pulse() { ; }
  };

  struct File::_Cluster {
    Int_t*      fType;
    Double_t*   fTime;
    Double_t*   fWidth;
    Int_t*      fSaturated;
    Int_t*      fPeakChannel;
    Double_t*   fAmplitude;
    Double_t*   fArea;
    Double_t*   fAreaEff;
    Double_t*   fAreaDiff;
    Int_t*      fNumSPE;
    Int_t*      fNumPMTTop;
    Int_t*      fNumPMTBottom;

    Double_t*   fX;
    Double_t*   fY;
    Double_t*   fZ;
    Double_t*   fDriftTime;

    Double_t*   fRawEnergy;
    Double_t*   fRawEnergyError;
    Double_t*   fCorrectedEnergy;
    Double_t*   fCorrectedEnergyError;

    std::vector<std::vector<int> > *fPulsesArray;
    _Cluster();
    ~_Cluster();
  };
//---- inlines -----------------------------------------------------------------

} // namespace

#endif /* RED_File_hh */
