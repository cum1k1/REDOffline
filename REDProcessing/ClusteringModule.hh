#ifndef RED_ClusteringModule_hh
#define RED_ClusteringModule_hh

#include <vector>

#include "REDProcessing/ProcessingModule.hh"

namespace RED
{

  class Event;
  class Pulse;
  class Cluster;

  class ClusteringModule: public ProcessingModule
  {
  public:
    ClusteringModule();
    ~ClusteringModule();

    EventStatus ProcessEvent(Event* event);

    void SetHSLSChannels(bool HSLSChannels) { fHasHSLSChannels = HSLSChannels; }
    void SetNumPMTs (int number) { fNumPMTs = number; }
    void SetPulseIntervalBound (double bound) { fLimitPulseInterval = bound; }

    bool GetHSLSChannels() const { return fHasHSLSChannels; }
    int GetNumPMTs() const { return fNumPMTs; }
    double GetPulseIntervalBound() const { return fLimitPulseInterval; }

    void SetGainArraySize(int size) { fChannelGain.resize(size, 1); }
    int GetGainArraySize() const { return fChannelGain.size(); }
    void SetChannelGain(int channel, double gain);
    double GetChannelGain(int channel) const { return fChannelGain.at(channel); }
    void SetGainArray(int array_size, const double *gain_array);
    void SetGainArray(const std::vector<double> &gain_array);
    const std::vector<double>& GetGainArray() const { return fChannelGain; }

  private:

    int fNumPulses;

    bool fHasHSLSChannels;

    int fNumPMTs;

    std::vector<int> fUnusedPulse;
    int fPulsesCounter;

    std::vector<double> fChannelGain; // this array contains individual relative gains for all channels
      // Gains are selected to equalize channels in area sum for cluster.

    double fClusterBegin;
    double fClusterEnd;

    double fLimitPulseInterval;

    void FindClusters_CsI(Event *event);
    void FindClusters_RED(Event *event);
    void FindClusters_Z3(Event *event);

    Cluster* LocateNewCluster_CsI(Event* event);
    Cluster* LocateNewCluster_RED(Event* event);
    Cluster* LocateNewCluster_Z3(Event* event);

    void FillClusterParameters_CsI(Cluster* cluster, Event* event);
    void FillClusterParameters_RED(Cluster* cluster, Event* event);
    void FillClusterParameters_Z3(Cluster* cluster, Event* event);

    void Clear();

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(ClusteringModule)
    ClassDef(ClusteringModule,1)
  };

} // namespace

#endif /* RED_ClusteringModule_hh */
