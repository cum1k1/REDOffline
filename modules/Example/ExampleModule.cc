#include <iostream>

#include "ExampleModule.hh"
#include "REDEvent/Event.hh"

using std::cout;
using std::endl;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( ExampleModule )
ClassImp( ExampleModule )


ExampleModule::ExampleModule()
  :mode(0), level(0.0), option()
{
  cout << __PRETTY_FUNCTION__ << endl;
  SetVerbose(1);
}
ExampleModule::~ExampleModule()
{
  cout << __PRETTY_FUNCTION__ << endl;
}

int ExampleModule::Initialize()
{
  cout << __PRETTY_FUNCTION__ << endl;
  return 0;
}
ProcessingModule::EventStatus ExampleModule::BeginOfRun(Event *)
{
  cout << __PRETTY_FUNCTION__ << endl;
  return kOk;
}
ProcessingModule::EventStatus ExampleModule::BeginOfRunSegment(Event *)
{
  cout << __PRETTY_FUNCTION__ << endl;
  return kOk;
}

ProcessingModule::EventStatus ExampleModule::ProcessEvent(Event *event)
{

  cout << __PRETTY_FUNCTION__ <<"\n"
       <<"  run_number="<< event->fRunNumber <<" event_number="<< event->fEventNumber << endl;
  if (fVerbose>1) {
    event->Print();
  }

  return kOk;
}

ProcessingModule::EventStatus ExampleModule::EndOfRunSegment(Event *)
{
  cout << __PRETTY_FUNCTION__ << endl;
  return kOk;
}
ProcessingModule::EventStatus ExampleModule::EndOfRun(Event *)
{
  cout << __PRETTY_FUNCTION__ << endl;
  return kOk;
}
int ExampleModule::ShutDown()
{
  cout << __PRETTY_FUNCTION__ << endl;
  return 0;
}
