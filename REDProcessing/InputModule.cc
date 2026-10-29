#include <iostream>

#include "REDUtils/String.hh"
#include "REDUtils/System.hh"

#include "REDProcessing/InputModule.hh"

using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( InputModule )
ClassImp( InputModule )


//InputModule::InputModule(){ProcessingModule::fStatus = kCreated;}

InputModule::~InputModule()
{
  ;
}

/*
int InputModule::Initialize()
{
  if(fSegments.empty()) {
    ProcessingModule::fStatus = kErrorRun;
    return -1;
  }
  ProcessingModule::fStatus = kInit;
  return 0;
}

ProcessingModule::EventStatus InputModule::BeginOfRun(Event *event){return kOk;}

ProcessingModule::EventStatus InputModule::BeginOfRunSegment(Event *event){return kOk;}

ProcessingModule::EventStatus InputModule::ProcessEvent(Event *event){return kOk;}

ProcessingModule::EventStatus InputModule::EndOfRunSegment(Event *event){return kOk;}

ProcessingModule::EventStatus InputModule::EndOfRun(Event *event)
{
  ProcessingModule::fStatus = kEndRun;
  return kOk;
}

int InputModule::ShutDown()
{
  fSegments.clear();
  ProcessingModule::fStatus = kCreated;
  return 0;
}
*/

int InputModule::AddURI(const std::string &uri)
{
  int ret = 0;
  String::URI_parts URI = String::SplitURI(uri);
  if (URI.scheme.empty()) {
    // simple way, provided is path (maybe with wildcards)
    std::vector<std::string> list = System::GlobPathName(System::ExpandPathName(uri));
    ret = list.size();
    for (unsigned i = 0; i < list.size(); i++)
      fSegments.push_back("file:"+list[i]);
  } else {
    ret = 1;
    fSegments.push_back(uri);
  }
  // do we need extra sort in Initialize?
  return ret;
}
bool InputModule::SeekEvent(size_t irecord) { return false; }
bool InputModule::SearchEvent(Int_t runNumber, Int_t eventNumber) { return false; }

void InputModule::PrintSegments() const
{
  unsigned ot = (fStatus>kInit)?fCurrSegment:-1;
  std::cout << "InputModule fSegments[" << fSegments.size() << "] = {\n";
  for (unsigned it = 0; it < fSegments.size(); it++) {
    std::cout << "  '" << fSegments[it] << ((it==ot)?"', // <-- current\n":"',\n");
  }
  std::cout << "}" << std::endl;
}

bool InputModule::OpenSegment() { return false; }
bool InputModule::CloseSegment() { return false; }

