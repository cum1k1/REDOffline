//______________________________________________________________________________
//  REDProcessingModule
//
//  Base class for all processing modules.
//  Module object is created upon processing chain assembly and remains till the end.
//  Processing is executed in the following order:
//
//  Initialize()
//  foreach (runs) {
//    BeginOfRun()
//    foreach (files) {
//      BeginOfRunSegment()
//      foreach (events) {
//        ProcessEvent()
//      }
//      EndOfRunSegment()
//    }
//    EndOfRun()
//  }
//  ShutDown()
//
//  Do we need shared objects?
//
//  ======================================================================================

//#include <iostream>
#include <TROOT.h>

#include "REDProcessing/ProcessingModule.hh"

using namespace RED;

ClassImp(ProcessingModule)

//______________________________________________________________________________
//const int ProcessingModule::crev = ProcessingModule::irev;

//______________________________________________________________________________
ProcessingModule::ProcessingModule()
{
  fStatus = kNone;
  fVerbose = 0;
}

//______________________________________________________________________________
ProcessingModule::~ProcessingModule()
{
  gROOT->GetDirectory("/")->Remove(this);
}

//______________________________________________________________________________
int ProcessingModule::Initialize()
{
  if (fStatus==kCreated) fStatus = kInit;
  return 0;
}

//______________________________________________________________________________
ProcessingModule::EventStatus ProcessingModule::BeginOfRun(Event *ev)
{
  return kOk;
}

//______________________________________________________________________________
ProcessingModule::EventStatus ProcessingModule::BeginOfRunSegment(Event *ev)
{
  return kOk;
}

//______________________________________________________________________________
ProcessingModule::EventStatus ProcessingModule::ProcessEvent(Event *ev)
{
  return kOk;
}

//______________________________________________________________________________
ProcessingModule::EventStatus ProcessingModule::EndOfRunSegment(Event *ev)
{
  return kOk;
}

//______________________________________________________________________________
ProcessingModule::EventStatus ProcessingModule::EndOfRun(Event *ev)
{
  return kOk;
}

//______________________________________________________________________________
int ProcessingModule::ShutDown()
{
  if (fStatus!=kAbort) fStatus = kCreated;
  return 0;
}

//______________________________________________________________________________
void ProcessingModule::SetName(const char* name)
{
  // modules are named objects in root directory
  gROOT->GetDirectory("/")->Remove(this);
  fName = name;
  gROOT->GetDirectory("/")->Append(this);
}

//______________________________________________________________________________
void ProcessingModule::SetNameTitle(const char* name, const char* title)
{
  SetName(name);
  SetTitle(title);
}

std::ostream& operator<<(std::ostream& os, const RED::ProcessingModule::ModuleStatus status)
{
  switch(status) {
  case RED::ProcessingModule::kNone: os << "kNone"; break;
  case RED::ProcessingModule::kCreated: os << "kCreated"; break;
  case RED::ProcessingModule::kInit: os << "kInit"; break;
  case RED::ProcessingModule::kGood: os << "kGood"; break;
  case RED::ProcessingModule::kEndSegment: os << "kEndSegment"; break;
  case RED::ProcessingModule::kEndRun: os << "kEndRun"; break;
  case RED::ProcessingModule::kEndAll: os << "kEndAll"; break;
  case RED::ProcessingModule::kErrorEvent: os << "kErrorEvent"; break;
  case RED::ProcessingModule::kErrorSegment: os << "kErrorSegment"; break;
  case RED::ProcessingModule::kErrorRun: os << "kErrorRun"; break;
  case RED::ProcessingModule::kAbort: os << "kAbort"; break;
  }
  return os;
}
std::ostream& operator<<(std::ostream& os, const RED::ProcessingModule::EventStatus status)
{
  switch(status) {
  case RED::ProcessingModule::kError: os << "kError"; break;
  case RED::ProcessingModule::kOk: os << "kOk"; break;
  case RED::ProcessingModule::kDrop: os << "kDrop"; break;
  }
  return os;
}
