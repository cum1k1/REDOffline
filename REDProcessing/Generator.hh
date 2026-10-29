#ifndef RED_Generator_hh
#define RED_Generator_hh

#include "REDProcessing/ProcessingModule.hh"

class TRandom;

namespace RED
{

  class Generator : public ProcessingModule
  {
  public:
    Generator();
    ~Generator();

    EventStatus ProcessEvent(Event *);

    //
    void SetMode(int v) { fMode = v; }
    void SetNumChannels(int v) { fNumChannels = v; }
    void SetNumSamples(int v) { fNumSamples = v; }
    void SetSamplingPeriod(double v) { fPeriod = v; }

  private:
    int      fMode;
    int      fNumChannels;
    int      fNumSamples;
    double   fPeriod;
    TRandom *rnd;

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(Generator)
    ClassDef(Generator,1)
  };

} // namespace

#endif /* RED_Generator_hh */
