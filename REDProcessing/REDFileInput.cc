#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>


#include "REDFile/File.hh"
#include "REDEvent/Event.hh"
#include "REDEvent/RunInfo.hh"

#include "REDProcessing/REDFileInput.hh"

using namespace RED;
using std::cout;
using std::endl;

RED_PROCESSING_MODULE_IMPLEMENT( REDFileInput )
ClassImp( REDFileInput )


struct REDFileInput::FileInfo {
  int fRunNumber;
  std::string fRunType;
  std::string fExtension;
};


REDFileInput::REDFileInput():
  fREDFile(0), fNumberOfEntries(0),
  fCurrentRunNumber(-1), fNextRunNumber(0), fTotalEventsRead(0),
  fEventCounter(0), fRecordCounter(-1), fFileCounter(-1),
  fFileInfo(0)
{

  ProcessingModule::fStatus = kCreated;

}

REDFileInput::~REDFileInput()
{
  ;
}

void REDFileInput::FillFilenameInfo()
{

  std::string::size_type FirstDash = 0;
  std::string::size_type SecondDash = 0;
  std::string::size_type FirstDot = 0;
  std::string::size_type SecondDot = 0;
  std::string::size_type LastSlash = 0;

  std::string REDTypeBegin = "proc";


  for (unsigned int file = 0; file < fSegments.size(); file++) {
    const std::string& name = fSegments[file];

    LastSlash = name.find_last_of("/");
    FirstDash = name.find_first_of("-", LastSlash+1);

      SecondDash = name.find_first_of("-", FirstDash+1);
      fFileInfo[file].fRunNumber = atoi((name.substr(FirstDash+1, SecondDash - FirstDash + 1)).c_str());

        FirstDot = name.rfind(".");
        fFileInfo[file].fRunType = name.substr(SecondDash+1, FirstDot-SecondDash-1);
        fFileInfo[file].fExtension = name.substr(FirstDot+1, name.size()-FirstDot+1);

//    std::cout<<fSegments[i]<<"    "<<fFileType[i]<<"    "<<fRunNumber[i]<<"    "
//             <<fRunType[i]<<"    "<<fExtension[i]<<std::endl;
  }

}

int REDFileInput::Initialize()
{
  std::cout << __PRETTY_FUNCTION__ <<" "<< 0 << std::endl;
  if(fSegments.empty()) {
    ProcessingModule::fStatus = kErrorRun;
    return -1;
  }

  fFileInfo = new FileInfo[fSegments.size()];

  FillFilenameInfo();

  fREDFile = new InputFile();
  fFileClosed = true;
  ProcessingModule::fStatus = kInit;

  return 0;
}



ProcessingModule::EventStatus REDFileInput::BeginOfRun(Event *m_event)
{
  std::cout << __PRETTY_FUNCTION__ <<" "<< 0 << std::endl;
  ResetRunInfo(m_event);

  bool status = false;
  fCurrentRunNumber = -1;

    if (fFileClosed) {          // check if previous file has been read completely.
      fEventCounter = 0;
      fFileCounter++;
        fREDFile->SetFilename(fSegments[fFileCounter]);
        status = fREDFile->Open();
    } else status = true;

    if (status) {
        if (fRecordCounter >= 0)
          m_event->SetRunInfo(fREDFile->GetRunInfo(fNextRunNumber));
        else
          m_event->SetRunInfo(fREDFile->GetRunInfo());
        fCurrentRunNumber = fREDFile->GetRunNumber();
    }

  if (status) {
    if (!fNewRun) fNewRun = true;
    ProcessingModule::fStatus = kGood;
    return kOk;
  } else {
    ProcessingModule::fStatus =  kErrorRun;

    return kError;
  }
}

ProcessingModule::EventStatus REDFileInput::BeginOfRunSegment(Event *m_event)
{
  std::cout << __PRETTY_FUNCTION__ <<" "<< 0 << std::endl;
  bool status = true;
  fNumberOfEntries = 0;

  if (fFileClosed) {      // if previous file has been read completely.

    fRecordCounter = -1;  // Drop RecordCounter if new file is opened.
    if (!fNewRun)
      fFileCounter += 1;  // Increment file counter if new file if opened
                          // during the same run
  }

  if (fNewRun)
    m_event->GetRunInfo()->fFirstRecord = fTotalEventsRead;

    if (!fREDFile->IsOpen()) {
      fREDFile->SetFilename(fSegments[fFileCounter]);
      status = fREDFile->Open();
    }
    if (status) {
      fFileClosed = false;
      fNumberOfEntries = fREDFile->GetNumEntries();
      ProcessingModule::fStatus = kGood;
    } else ProcessingModule::fStatus = kErrorSegment;

  return kOk;
}

ProcessingModule::EventStatus REDFileInput::ProcessEvent(Event *m_event)
{
  //cout << __PRETTY_FUNCTION__ << endl;
  fRecordCounter += 1;

  //if (fRecordCounter == 10 && fNumberOfEntries > 20)
  //  fRecordCounter = fNumberOfEntries - 10;

  if (fRecordCounter < fNumberOfEntries) { // actually over _all_ events in file
      fREDFile->ReadEvent(m_event, fRecordCounter);
      if (m_event->fRunNumber == fCurrentRunNumber ) {
        ProcessingModule::fStatus = kGood;
        fEventCounter += 1;
      } else {
        fNextRunNumber = m_event->fRunNumber;
        fRecordCounter -= 1; // will read it again
        m_event->SetRunInfo(fREDFile->GetRunInfo(fCurrentRunNumber));
        ProcessingModule::fStatus = kEndRun;
      }
  } else {
    ProcessingModule::fStatus = kEndSegment;
    return kError;
  }

  return kOk;
}


ProcessingModule::EventStatus REDFileInput::EndOfRunSegment(Event *m_event)
{
  cout << __PRETTY_FUNCTION__ << endl;
  fNewRun = false;

  int ListLength = static_cast<int>(fSegments.size());
  if (ListLength - 1 > fFileCounter) {
    if (fFileInfo[fFileCounter+1].fRunNumber != fFileInfo[fFileCounter].fRunNumber)
      ProcessingModule::fStatus = kEndRun;
    else if (fStatus == kEndRun)
      ;
    else ProcessingModule::fStatus = kEndSegment;
  } else if (ListLength - 1 == fFileCounter)
    ProcessingModule::fStatus = kEndAll;

  if (fRecordCounter >= fNumberOfEntries) {
    fREDFile->Close();
    fFileClosed = true;
  } else {
    fFileClosed = false;
  }

  return kOk;

}

ProcessingModule::EventStatus REDFileInput::EndOfRun(Event *m_event)
{
  cout << __PRETTY_FUNCTION__ << endl;
  fTotalEventsRead += fEventCounter;
  if (fStatus == kEndAll)
    ;
  else
    ProcessingModule::fStatus = kEndRun;
  return kOk;
}

int REDFileInput::ShutDown()
{
  cout << __PRETTY_FUNCTION__ << endl;

  if (fREDFile != 0) {
    delete fREDFile;
    fREDFile = 0;
  }

  fEventCounter = 0;
  fRecordCounter = 0;
  fNumberOfEntries = 0;

  /*  if (m_event->fRunInfo != 0) {  // Can't do because m_event is undefined in ShutDown()
      delete m_event->fRunInfo;      // It will arise in fuction EndOfRun() of OutputModule
      m_event->fRunInfo = 0;
    }*/
  fSegments.clear();
  if (fFileInfo != 0) {
    delete [] fFileInfo;
    fFileInfo = 0;
  }


  ProcessingModule::fStatus = kCreated;


  return 0;
}

void REDFileInput::ResetRunInfo(Event* m_event)
{
  m_event->ResetRunInfo();
}
