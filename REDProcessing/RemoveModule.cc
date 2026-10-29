#include "REDEvent/Event.hh"
#include "REDEvent/Waveform.hh"

#include "REDProcessing/RemoveModule.hh"

using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( RemoveModule )
ClassImp( RemoveModule )

RemoveModule::RemoveModule(): fSaveWaveformData(false)
{ ; }

RemoveModule::~RemoveModule()
{ ; }

ProcessingModule::EventStatus RemoveModule::ProcessEvent(Event* event)
{
  if (!fSaveWaveformData) {
    for (int i = 0; i < event->GetNumWaveforms(); i++) {
      Waveform *wf = (event->GetWaveform(i));
      wf->fData.clear();
      wf->fNumSamples = 0;
    }
  }

  return kOk;
}
