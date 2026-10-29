#ifndef RED_DataFile_hh
#define RED_DataFile_hh

class TFile;
//class std::string;

namespace RED
{

class Event;
class Waveform;
class RunInfo;

struct DAQTrees;
struct EventData;
struct RunData;

class DataFile
{
private:
  TFile       *fFile;                              //input file
  DAQTrees    *fInputTree;
  int          fNumSamples;                        // number of samples to read
                                                   // from DAQ output file
  void ResizeWaveform(unsigned int *waveform, int nsamples);

public:
  // keep this public for simple access
  EventData   *fData;
  RunData     *fRun;
  RunInfo  *fRunInfo;


  DataFile();
 // DataFile( const DataFile& );
 // DataFile& operator=( const DataFile & );
  ~DataFile();


  //open actions
  bool IsOpen();

  void NewFileOpen(std::string);
  void NewFileOpen( const char *FileName);

  bool Open(const std::string&);
  bool Open( const char* FileName);

  //read actions
  bool ReadEvent(Event*, int);
  bool ReadWaveform(Waveform*);
  bool ReadRunInfo();
  bool ReadRunInfo(Event*);

  int GetNumEvents();
  int GetNumEntries();
  int GetRunNumber() const;

  void Close();

//  ProcessingModule::EventStatus


};

} // namespace

#endif /* RED_DataFile_hh */
