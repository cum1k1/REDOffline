#include <iostream>
#include "REDUtils/String.hh"

#include "Z3DAQInput.hh"
#include "REDEvent/Event.hh"
#include "z3file.hh"

using std::cout;
using std::clog;
using std::endl;
using std::string;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( Z3DAQInput )
ClassImp( Z3DAQInput )


Z3DAQInput::Z3DAQInput():
  fFileName(), fFile(0)
{
  cout << __PRETTY_FUNCTION__ << endl;
  fCurrSegment = 0;
  fRunHint.name   = "";
  fRunHint.number = 0;
  fRunHint.type   = "";
}
Z3DAQInput::~Z3DAQInput()
{
  cout << __PRETTY_FUNCTION__ << endl;
  // just for the case
  CloseSegment();
}

int Z3DAQInput::Initialize()
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fStatus==kCreated) fStatus = kInit;
  fCurrSegment = 0;
  return 0;
}

ProcessingModule::EventStatus Z3DAQInput::BeginOfRun(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fCurrSegment>=fSegments.size()) {
    fStatus = kEndAll;
    return kError;
  }
  if(fCurrSegment==0)
    // Only for the very first call, later it's done in EndOfRunSegment
    ParseFileName();
  fStatus = kGood;
  if (!OpenSegment()) {
    fStatus = kErrorSegment;
    return kError;
  }

  // Make RunInfo.
  // new run, so full copy and corrections
  int prev_run_number = fRunInfo.fRunNumber;
  fRunInfo.Clear();
  switch(fFile->type) {
  case z3file::file_v1:
  case z3file::file_v3:
  case z3file::file_v4: {
    // do unique fRunNumber
    // This can't be done properly without information from run database, 
    // so we just fake it.
    fRunInfo.fRunNumber = (fRunHint.number*100)+(prev_run_number%100)+1;
    fRunInfo.fDAQ_ID = fFile->fh.v3.daq_id;
    fRunInfo.fRunType = fFile->fh.v3.runtype_str;
    for(unsigned i=0;i<fFile->nch;i++)
      if (fFile->ch[i].v3.c_saved)
        fRunInfo.fLabels.push_back(fFile->ch[i].v3.c_label);
    // demangle names
    int nPMTs = (fFile->nch-2)/2;
    for (int i=0; i<nPMTs; i++) {
      char buf[32];
      snprintf(buf,sizeof(buf),"bottom-%02d",i);
      fRunInfo.fLabels[i] = buf;
      snprintf(buf,sizeof(buf),"bottom-ls-%02d",i);
      fRunInfo.fLabels[i+nPMTs] = buf;
    }
    { int d,m,y,H,M,S; sscanf(fFile->fh.v3.start_time,"%d-%d-%d %d:%d:%d",&d,&m,&y,&H,&M,&S); fRunInfo.fStart.Set(y,m,d,H,M,S,0,true,0); }
    { int d,m,y,H,M,S; sscanf(fFile->fh.v3.stop_time,"%d-%d-%d %d:%d:%d",&d,&m,&y,&H,&M,&S); fRunInfo.fStop.Set(y,m,d,H,M,S,0,true,0); }
    // make acquisition time
    // This is improper because system has unknown dead time for each event.
    // But we expect this to be almost constant, so take it as stop-start with
    // a call for dead-time efficiency.
    //fFile->fRunInfo.fAcquisition = fFile->fRunInfo.fStop - fFile->fRunInfo.fStart
    fRunInfo.fNumChannels = fFile->nch;
    fRunInfo.fTriggerMode = 0;
    fRunInfo.fDescription = fFile->comment;
    // make-up description
    string::size_type i;
    i = fRunInfo.fDescription.find_first_not_of(" \t\v\n");
    if (i>0) fRunInfo.fDescription.erase(0,i);
    i = fRunInfo.fDescription.find_last_not_of(" \t\v\n");
    if (i!=string::npos) fRunInfo.fDescription.erase(i+1,string::npos);
    fRunInfo.fNumEvents = 0; // not available
    fRunInfo.fFirstRecord = 0;
  } break;
  default:
    clog << "Unsupported file type" << endl;
    fStatus = kErrorSegment;
    return kError;
  }

  return kOk;
}

ProcessingModule::EventStatus Z3DAQInput::BeginOfRunSegment(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  // try to open file
  if (fCurrSegment>=fSegments.size()) {
    fStatus = kEndAll;
    return kError;
  }
  fStatus = kGood;
  if (!OpenSegment()) {
    fStatus = kErrorSegment;
    return kError;
  }

  cout << fFileName <<" "<< fStatus << endl;
  // update some info in RunInfo
  if (fRunHint.same_run) {
    { int d,m,y,H,M,S; sscanf(fFile->fh.v3.stop_time,"%d-%d-%d %d:%d:%d",&d,&m,&y,&H,&M,&S); fRunInfo.fStop.Set(y,m,d,H,M,S,0,true,0); }
  }

  //fRunInfo.Print();
  return kOk;
}

ProcessingModule::EventStatus Z3DAQInput::ProcessEvent(Event *event)
{
  if (fStatus!=kGood) return kError;

  if (!fFile->read_next_event(*event)) {
    // read failed
    if (!fFile->fin.eof()) {
      clog << "Failed to read event #" << fFile->ievent << endl;
      // in theory this could be only a single event failure,
      // but underlying code won't go further so next event is unreachable
      fStatus = kErrorSegment;
    } else
      fStatus = kEndSegment;
    return kError;
  }
  if (fFile->ievent>100) { fStatus = kEndSegment; return kError; }

  fRunInfo.fNumEvents++;
  event->fRunInfo = &fRunInfo;
  event->fRunNumber = fRunInfo.fRunNumber;
  event->fEventNumber = fRunInfo.fNumEvents;

  //event->Print();
  return kOk;
}

ProcessingModule::EventStatus Z3DAQInput::EndOfRunSegment(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  CloseSegment();
  // add things to fRunInfo

  // what's next
  fCurrSegment++;
  if (fCurrSegment<fSegments.size()) {
    ParseFileName();
    if (fRunHint.same_run)
      fStatus = kEndSegment;
    else
      fStatus = kEndRun;
  } else {
    fStatus = kEndAll;
  }
  cout << fFileName <<" "<< fStatus << endl;
  return kOk;
}

void Z3DAQInput::ParseFileName()
{
  // url: [file:]<path/file>
  // name: ^z3_([^_]+)_([0-9]{6})\.([^.]+)\.([0-9]{4})(\.gz)?$
  // 1=run name, 2=run number, 3=run type, 4=sequence number, 5=file is compressed
  const string& uri = fSegments[fCurrSegment];
  string::size_type j,k;
  fRunHint.same_run = true;

  String::URI_parts URI = String::SplitURI(fSegments[fCurrSegment]);
  if (URI.scheme!="file" && !URI.scheme.empty()) {
    clog << "Only 'file' scheme is supported" << endl;
    fFileName.clear();
    return;
  }
  if (!URI.authority.empty() || !URI.query.empty() || !URI.fragment.empty()) {
    clog << "Extra parts in URI " << URI << endl;
  }

  string name;
  j = URI.path.rfind('/');
  if (j==string::npos) j = -1;
  name.assign(URI.path,j+1,string::npos);

  string ext;
  j = name.rfind('.');
  if (j!=string::npos) ext.assign(name,j+1,string::npos);
  if (ext=="gz" && j>0) {
    fRunHint.compressed = true;
    // compressed, find previous
    k = name.rfind('.',j-1);
    if (k!=string::npos) {
      if (k+1<j) ext.assign(name,k+1,j-k-1);
      j = k;
    } else ext.clear();
  } else
    fRunHint.compressed = false;
  fRunHint.sequence = (ext.find_first_not_of("0123456789")==string::npos)?strtol(ext.c_str(),0,10):0;

  string type;
  if (j!=string::npos && j>0) {
    k = name.rfind('.',j-1);
    if (k!=string::npos) {
      if (k+1<j) type.assign(name,k+1,j-k-1);
      j = k;
    }
  }
  if (fRunHint.type != type) fRunHint.type = type, fRunHint.same_run = false;

  string date;
  if (j!=string::npos && j>0) {
    k = name.rfind('_',j-1);
    if (k!=string::npos) {
      if (k+1<j) date.assign(name,k+1,j-k-1);
      j = k;
    }
  }
  k = (date.find_first_not_of("0123456789")==string::npos)?strtoul(date.c_str(),0,10):0;
  if (fRunHint.number != k) fRunHint.number = k, fRunHint.same_run = false;

  k = (name.compare(0,3,"z3_")==0)?3:0;
  fRunHint.format_ok = (k==3 && j>5);
  name.erase(j,string::npos).erase(0,k);
  fRunHint.name = name;

  //cout << "fRunHint { '" << fRunHint.name <<"' '"<< fRunHint.number <<"' '"<< fRunHint.type <<"' '"<< fRunHint.sequence <<"' "<< (fRunHint.compressed?1:0) <<" "<< (fRunHint.same_run?1:0) <<" "<< (fRunHint.format_ok?1:0) <<" }"<< endl;
  fFileName = URI.path;
  return;
}

bool Z3DAQInput::OpenSegment()
{
  if (fFile!=0) return true;

  InputModule::OpenSegment();
  fFile = new z3file(fFileName);
  //fFile->verbose = fVerbose;
  if (fFile==0 || !fFile->is_open() || !fFile->read_header()) {
    clog << "Can't open file '" << fFileName << "'" << endl;
    return false;
  }
  return true;
}
bool Z3DAQInput::CloseSegment()
{
  InputModule::CloseSegment();
  if (fFile) {
    delete fFile;
    fFile = 0;
  }
  return true;
}
