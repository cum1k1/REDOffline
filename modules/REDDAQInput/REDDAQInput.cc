#include <iostream>
#include "REDUtils/String.hh"

#include "REDDAQInput.hh"
#include "REDEvent/Event.hh"
#include "DataFile.hh"

using std::cout;
using std::clog;
using std::endl;
using std::string;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( REDDAQInput )
ClassImp( REDDAQInput )


REDDAQInput::REDDAQInput():
  fFileName(), fFile(0)
{
  cout << __PRETTY_FUNCTION__ << endl;
  fCurrSegment = 0;
  fRunHint.number = 0;
  fRunHint.type = "";
  fRunHint.sequence = 0;
  fRunHint.same_run = false;
  fRunHint.format_ok = false;
}
REDDAQInput::~REDDAQInput()
{
  cout << __PRETTY_FUNCTION__ << endl;
  // just for the case
  CloseSegment();
}

int REDDAQInput::Initialize()
{
  cout << __PRETTY_FUNCTION__ << endl;
  if (fStatus==kCreated) fStatus = kInit;
  fCurrSegment = 0;
  fFile = new DataFile();
  return 0;
}

ProcessingModule::EventStatus REDDAQInput::BeginOfRun(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;
  event->ResetRunInfo();
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
  //int prev_run_number = fFile->GetRunNumber();
  fFile->ReadRunInfo(event);

  return kOk;
}

ProcessingModule::EventStatus REDDAQInput::BeginOfRunSegment(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  // here we have file opened anyway
  fStatus = kGood;
  if (!fFile->IsOpen()) {
    fStatus = kErrorSegment;
    return kError;
  }

  // update some info in RunInfo
  fFile->ReadRunInfo(event);
  event->GetRunInfo()->fRunType = fRunHint.type;
  fRecordCounter = -1;

  //event->fRunInfo->Print();
  return kOk;
}

ProcessingModule::EventStatus REDDAQInput::ProcessEvent(Event *event)
{
  //cout << __PRETTY_FUNCTION__ <<" "<< fStatus << endl;
  //if (fStatus!=kGood) return kError;

  ++fRecordCounter;
  if (fRecordCounter >= fFile->GetNumEntries()) {
    fStatus = kEndSegment;
    return kError;
  }
  if (!fFile->ReadEvent(event,fRecordCounter)) {
    // read failed
    clog << ClassName() << ": Failed to read event record #" << fRecordCounter << endl;
    fStatus = kErrorEvent;
    return kError;
  }
  if (fRecordCounter == 1) {
    fFile->ReadRunInfo(event);
  }
  if (fFile->GetRunNumber() != event->fRunNumber ) {
    ProcessingModule::fStatus = kEndRun;
    return kError;
  }
  event->GetRunInfo()->fRunType = fRunHint.type;

  //event->GetRunInfo()->Print();
  //if (fRecordCounter>100) { fStatus = kEndSegment; return kError; }

  //event->Print();
  return kOk;
}

ProcessingModule::EventStatus REDDAQInput::EndOfRunSegment(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  int prev_run = fFile->GetRunNumber();
  CloseSegment();
  // add things to fRunInfo

  // what's next
  fCurrSegment++;
  if (fCurrSegment<fSegments.size()) {
    ParseFileName();
    if (OpenSegment() && fFile->GetRunNumber()!=prev_run)
      fStatus = kEndRun;
    else
      fStatus = kEndSegment;
  } else {
    fStatus = kEndAll;
  }
  cout << fFileName <<" "<< fStatus << endl;
  return kOk;
}

int REDDAQInput::ShutDown()
{
  cout << __PRETTY_FUNCTION__ << endl;
  fStatus = kCreated;
  fCurrSegment = 0;
  if (fFile) {
    delete fFile;
    fFile = 0;
  }
  return 0;
}

void REDDAQInput::ParseFileName()
{
  // url: [file:]<path/file>
  // name: ^data-(\d+)-([^.]+)\.(\d+)\.root$
  // 1=run name, 2=run number, 3=run type, 4=sequence number, 5=file is compressed
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

  string ext, seq;
  j = name.rfind('.');
  if (j!=string::npos) ext.assign(name,j+1,string::npos);
  if (ext=="root" && j>0) {
    k = name.rfind('.',j-1);
    if (k!=string::npos) {
      if (k+1<j) seq.assign(name,k+1,j-k-1);
      j = k;
    }
  }
  fRunHint.sequence = (seq.find_first_not_of("0123456789")==string::npos)?strtol(seq.c_str(),0,10):0;
  name.erase(j,string::npos);

  string base, num;
  j = name.find('-');
  if (j!=string::npos) {
    if (j>0) base.assign(name,0,j);
    k = name.find('-',j+1);
    if (k!=string::npos) {
      if (j+1<k) num.assign(name,j+1,k-j-1);
      j = k;
    }
    name.erase(0,j+1);
  }
  k = (num.find_first_not_of("0123456789")==string::npos)?strtol(num.c_str(),0,10):0;
  if (fRunHint.number != unsigned(k)) fRunHint.number = k, fRunHint.same_run = false;
  if (fRunHint.type != name) fRunHint.type = name, fRunHint.same_run = false;
  fRunHint.format_ok = (base=="data" && k>0 && !name.empty() && ext=="root");

  //cout << "fRunHint { '" << fRunHint.number <<"' '"<< fRunHint.type <<"' '"<< fRunHint.sequence <<"' "<< (fRunHint.same_run?1:0) <<" "<< (fRunHint.format_ok?1:0) <<" }"<< endl;
  fFileName = URI.path;
  return;
}

bool REDDAQInput::OpenSegment()
{
  if (fFile->IsOpen()) return true;

  InputModule::OpenSegment();
  //fFile->verbose = fVerbose;
  // we don't trust DataFile so feed it with pure file names
  bool status = fFile->Open(fFileName);
  if (fFile==0 || !fFile->IsOpen() || !status) {
    clog << "Can't open file '" << fFileName << "'" << endl;
    return false;
  }
  return true;
}
bool REDDAQInput::CloseSegment()
{
  InputModule::CloseSegment();
  if (fFile) {
    fFile->Close();
  }
  return true;
}
