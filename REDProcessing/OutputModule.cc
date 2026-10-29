#include <iostream>
#include <string>

#include "REDEvent/Event.hh"
#include "REDFile/File.hh"
#include "REDProcessing/OutputModule.hh"

using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( OutputModule )
ClassImp( OutputModule )


OutputModule::OutputModule()
{
  fFilename.clear();
  fUseLegacyMode = false;
  ProcessingModule::fStatus = kCreated;
}

bool OutputModule::SetOutputName(const std::string Filename)
{
  fFilename = Filename;
  return true;
}

bool OutputModule::SetOutputName(const char* Filename)
{
  fFilename = Filename;
  return true;
}

int OutputModule::Initialize()
{
  fOutputFile = new OutputFile();
  if (!fFilename.empty()) fOutputFile->SetFilename(fFilename);
  else return 1;
  fOutputFile->SetUseLegacyMode(fUseLegacyMode); // pass through

  ProcessingModule::fStatus = kInit;
  return 0;
}

/*std::string OutputModule::GenFileName(Event *ev)
{
  char run_number[5];
  int zeros = 0;
  std::string begin = "proc-";
  std::string end = "-output.root";
  sprintf(run_number,"%i",m_event->fRunInfo->fRunNumber);

  for (int i = 0; i < 4; i++)
    if ((int)(ev->fRunInfo->fRunNumber/pow(10,i)) == 0 ) {
      zeros = i;
      break;
    }

  for (int j = 0; j < zeros; j++)
    begin += "0";

  begin += run_number;
  begin += end;
  return begin;
}*/
//______________________________________________________________________________
ProcessingModule::EventStatus OutputModule::BeginOfRun(Event *m_event)
{
// if (fFilename.empty()) fOutputFile->SetFilename(GenFileName(m_event));

  bool status = false;
  if (!fFilename.empty()) {
    status = fOutputFile->Open();
    if (status) {
      ProcessingModule::fStatus = kGood;
      return kOk;
    } else
      return kError;
  }
  return kError;
}

//______________________________________________________________________________
ProcessingModule::EventStatus OutputModule::BeginOfRunSegment(Event *m_event)
{
  if (!(fOutputFile->IsOpen())) fOutputFile->Open();
  ProcessingModule::fStatus = kGood;
  return kOk;
}

//______________________________________________________________________________
ProcessingModule::EventStatus OutputModule::ProcessEvent(Event *m_event)
{
  bool status = false;
  if (fOutputFile->IsOpen()) {
    status = fOutputFile->WriteEvent(m_event);
    if (status) {
      ProcessingModule::fStatus = kGood;
      return kOk;
    } else
      return kError;
  } else
    return kError;
}

//______________________________________________________________________________
ProcessingModule::EventStatus OutputModule::EndOfRunSegment(Event *m_event)
{

  /*  if (fOutputFile != 0 && fOutputFile->IsOpen()) {
      bool status = fOutputFile->Close();
      ProcessingModule::fStatus = kEndSegment;
    }*/
  ProcessingModule::fStatus = kEndSegment;

  return kOk;
}

//______________________________________________________________________________
ProcessingModule::EventStatus OutputModule::EndOfRun(Event *m_event)
{
  WriteRunInfo(m_event->GetRunInfo());

  ProcessingModule::fStatus = kEndRun;
  return kOk;
}

//______________________________________________________________________________
int OutputModule::ShutDown()
{
  if (fOutputFile != 0 && fOutputFile->IsOpen()) {
    bool status = fOutputFile->Close();
  }

  if( fOutputFile != 0) {
    delete fOutputFile;
    fOutputFile = 0;
  }

  ProcessingModule::fStatus = kCreated;
  return 0;
}

void OutputModule::WriteRunInfo(const RunInfo *info)
{
  if (fOutputFile->IsOpen()) {
    fOutputFile->AddRunInfo(info);
  }
}
//
