#ifndef RED_RemoveModule_hh
#define RED_RemoveModule_hh

#include "REDProcessing/ProcessingModule.hh"

namespace RED
{

  class Event;

  class RemoveModule: public ProcessingModule
  {
  public:
    RemoveModule();
    ~RemoveModule();

    void SetSaveWaveformData(bool save_waveform) { fSaveWaveformData = save_waveform; }
    bool GetSaveWaveformData() const { return fSaveWaveformData; }

    EventStatus ProcessEvent(Event *);

    bool CanChangeEvents() { return true; }

  private:
    bool fSaveWaveformData;

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(RemoveModule)
    ClassDef(RemoveModule,1)
  };
//--------------------inlines----------------------------------------

} // namespace

#endif /* RED_ProcessingModule_hh */
