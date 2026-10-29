#ifndef RED_Event_hh
#define RED_Event_hh

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// RED::Event                                                           //
//                                                                      //
// Encapsulation class for Event Data in RED.                           //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <TObject.h>
#include <TClonesArray.h>
#include "TTimeStamp.h"

//#include "TBits.h"
//#include <cstddef> //for size_t
#include <map>

#include "REDEvent/Waveform.hh"
#include "REDEvent/Pulse.hh"
#include "REDEvent/Cluster.hh"

namespace RED
{

  class RunInfo;
  //class Waveform;
  //class Pulse;
  //class Cluster;
  class ProcessingInfo;

  class Event : public TObject
  {

  public:
    TRef        fRunInfo;
    //
    Int_t       fRunNumber;                   // Run number
    Int_t       fEventNumber;                 // Unique event number.
    Int_t       fNumChannels;                 // Number of channels in event.
    Int_t       fTriggerCount;                // Trigger count.
    TTimeStamp  fTriggerTime;                 // when trigger happened, may be less accurate than expected
    UInt_t      fTriggerSource;               // Trigger source.
    Bool_t      fIsMonteCarloEvent;           // True if the event originates from a
    Bool_t      fTaggedAsMuon;                // True if a module tags the event
    Bool_t      fTaggedAsNoise;               // True if a module tags the event as noise
    //

    Bool_t      fHasSaturatedChannel;         // true when at least one channel is saturated.  Set by recon.
    Bool_t      fSkippedByClustering;         // true when event was skipped by the clustering module.

  public:
    Event();
    Event( const Event& );
    ~Event();

    Event& operator=( const Event& );
    bool operator==( const Event& ) const;
    void Print( Option_t* option = "") const;
    void Clear( Option_t* option = "");

    //void InitializeArrays();
    //void ResetForReconstruction();

    const RunInfo* GetRunInfo() const;
    RunInfo* GetRunInfo();
    void ResetRunInfo();
    void SetRunInfo(const RunInfo& runInfo);
    void SetRunInfo(const RunInfo* runInfo);

    TClonesArray* GetWaveformArray();
    Waveform* GetWaveform(int i);
    const Waveform* GetWaveform(int i) const;
    Waveform* GetNewWaveform();
    int GetNumWaveforms() const;
    int FindWaveformLocation(int ichannel) const;
    //int FindWaveformLocation(const char *channel) const;
    void Remove(const Waveform *);
    bool ClearWaveformArray();


    TClonesArray* GetPulsesArray();
    Pulse* GetPulse(int i);
    const Pulse* GetPulse(int i) const;
    Pulse* GetNewPulse();
    int GetNumPulses() const;
    void Remove(const Pulse*);
    bool ClearPulsesArray();


    TClonesArray* GetClustersArray();
    Cluster* GetCluster(int i);
    const Cluster* GetCluster(int i) const;
    Cluster* GetNewCluster();
    int GetNumClusters() const;
    void Remove(const Cluster*);
    bool ClearClustersArray();

  protected:

    // InitializeArrays is called to properly initialize the
    ProcessingInfo   *fProcInfo;
    // TClonesArrays
    //typedef std::map<Int_t, size_t> WFMap;
    //mutable WFMap     fChanMap;        // Channel map to give index of channels
    TClonesArray*     fWaveforms;      // Waveforms
    TClonesArray*     fPulses;         // pulses found
    TClonesArray*     fClusters;       // reconstructed clusters
    //TBits             fNoiseTags;

    ClassDef(Event,3)
  };

//---- inlines -----------------------------------------------------------------

  inline TClonesArray* Event::GetWaveformArray()
  {
    // Get array of waveforms.
    // Normally access should go through GetWavefomrs and GetNumWaveforms.
    return fWaveforms;
  }

  inline Waveform* Event::GetWaveform(int idx)
  {
    // Get waveform at index i.
    // The general mechanism to loop over wavefroms is the following:
    //
    // Event ev;
    // for (int i=0;i<ev->GetNumWavefroms();i++) {
    //   Waveforms *wf = ev->GetWaveform(i);
    //   ...
    // }
    //
    // For individual channels, look for FindWaveformLocation()
    //
    //return static_cast<Waveform*>(fWaveforms->ConstructedAt(i));
    return static_cast<Waveform*>(fWaveforms->ConstructedAt(idx));
  }

  inline const Waveform* Event::GetWaveform(int idx) const
  {
    return static_cast<Waveform*>(fWaveforms->At(idx));
  }

  inline Waveform* Event::GetNewWaveform()
  {
    //
    //return static_cast<Waveform*>(fWaveforms->ConstructedAt(GetNumWaveforms()));
    return static_cast<Waveform*>(fWaveforms->ConstructedAt(GetNumWaveforms()));
  }
  inline int Event::GetNumWaveforms() const
  {
    return fWaveforms->GetEntriesFast();
  }
  inline int Event::FindWaveformLocation(int ichannel) const
  {
    for (int i = 0; i < GetNumWaveforms(); ++i) {
      const Waveform *wf = static_cast<const Waveform*>((*fWaveforms)[i]);
      if (wf && wf->fChannel == ichannel)
        return i;
    }
    return -1;
  }
    //int Event::FindWaveformLocation(const char *channel) const;

  inline void Event::Remove(const Waveform *wf)
  {
    // remove this waveform from the event
    //fWaveforms->RemoveAndCompress(wf);
    int idx = fWaveforms->IndexOf(wf);
    if (idx<0) return;
    bool compress = true;//!(idx==fWaveforms->GetAbsLast());
    fWaveforms->RemoveAt(idx);
    if (compress) fWaveforms->Compress();
  }

  inline bool Event::ClearWaveformArray()
  {
    if (GetNumWaveforms() > 0) {
      fWaveforms->Clear("C");
      return true;
    } else return false;
  }

//###################__Pulses_Part__#################################

  inline TClonesArray* Event::GetPulsesArray()
  {

    return fPulses;
  }


  inline Pulse* Event::GetPulse(int idy)
  {
    return static_cast<Pulse*>(fPulses->ConstructedAt(idy));
  }

  inline const Pulse* Event::GetPulse(int idy) const
  {
    return static_cast<Pulse*>(fPulses->At(idy));
  }

  inline Pulse* Event::GetNewPulse()
  {
    return static_cast<Pulse*>(fPulses->ConstructedAt(GetNumPulses()));
  }


  inline int Event::GetNumPulses() const
  {
    return fPulses->GetEntriesFast();
  }

  inline void Event::Remove(const Pulse *pulse)
  {
    int idy = fPulses->IndexOf(pulse);
    if (idy<0) return;
    bool compress = true;
    fPulses->RemoveAt(idy);
    if (compress) fPulses->Compress();
  }

  inline bool Event::ClearPulsesArray()
  {
    if (GetNumPulses() > 0) {
      fPulses->Clear("C");
      return true;
    } else return false;
  }

//##################__Clusters_Part__################################

  inline TClonesArray* Event::GetClustersArray()
  {

    return fClusters;
  }


  inline Cluster* Event::GetCluster(int idy)
  {
    return static_cast<Cluster*>(fClusters->ConstructedAt(idy));
  }

  inline const Cluster* Event::GetCluster(int idy) const
  {
    return static_cast<Cluster*>(fClusters->At(idy));
  }

  inline Cluster* Event::GetNewCluster()
  {
    return static_cast<Cluster*>(fClusters->ConstructedAt(GetNumClusters()));
  }


  inline int Event::GetNumClusters() const
  {
    return fClusters->GetEntriesFast();
  }

  inline void Event::Remove(const Cluster *cluster)
  {
    int idy = fClusters->IndexOf(cluster);
    if (idy<0) return;
    bool compress = true;
    fClusters->RemoveAt(idy);
    if (compress) fClusters->Compress();
  }

  inline bool Event::ClearClustersArray()
  {
    if (GetNumClusters() > 0) {
      fClusters->Clear("C");
      return true;
    } else return false;
  }

} // namespace

#endif /* RED_Event_hh */
