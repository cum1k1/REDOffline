#include <iostream>
#include <cmath>

#include "REDEvent/RunInfo.hh"
#include "REDEvent/Event.hh"
#include "REDEvent/Pulse.hh"
#include "REDEvent/Waveform.hh"
#include "REDEvent/Cluster.hh"

#include "REDProcessing/ClusteringModule.hh"

int g_techChannels = 0; // a bit mask of channels to skip in clustering

using std::cout;
using std::endl;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( ClusteringModule )
ClassImp( ClusteringModule )


ClusteringModule::ClusteringModule():
  fNumPulses(0), fHasHSLSChannels(false), fNumPMTs(0),
  fPulsesCounter(0), fClusterBegin(0), fClusterEnd(0)
{
}

ClusteringModule::~ClusteringModule()
{
  ;
}

void ClusteringModule::SetChannelGain(int channel, double gain)
{
  fChannelGain.at(channel) = gain;
}

void ClusteringModule::SetGainArray(int array_size, const double *gain_array)
{
  fChannelGain.clear();
  fChannelGain.insert(fChannelGain.begin(),gain_array,gain_array+array_size);
}

void ClusteringModule::SetGainArray(const std::vector<double> &gain_array)
{
  fChannelGain = gain_array;
}

ProcessingModule::EventStatus ClusteringModule::ProcessEvent(Event* event)
{

  event->ClearClustersArray();
  int counter = 0;

  if (fChannelGain.empty()) {
    const Waveform *LastWaveform = event->GetWaveform(event->fNumChannels-1);
    // This number should be taken from ChannelManager, but now we simply guess from first run.
    fChannelGain.resize(LastWaveform->fChannel+1, 1);
  }

  if (fNumPulses < event->GetNumPulses()) {
    fNumPulses = event->GetNumPulses();

    fUnusedPulse.resize(fNumPulses);
  }

  for (int i = 0; i < fNumPulses; i++)
    fUnusedPulse[i] = 1;


  fPulsesCounter = event->GetNumPulses();


  std::string run_type = event->GetRunInfo()->fDAQ_ID;
  if (!run_type.compare("CsI NI PCI-5153")) {
      
    FindClusters_CsI(event);
  } else if (!run_type.compare("1380271153")) {
      FindClusters_RED(event);
  } else if (!run_type.compare("1380271154")) {
      FindClusters_RED(event);
  } else if (!run_type.compare("Zep31.8")) {
      FindClusters_Z3(event);
  } else {
    return kError;
  }

  return kOk;
}

/////////////////////////////////////////////////////////
//
//                    Main Cluster Cycles
//
////////////////////////////////////////////////////////

void ClusteringModule::FindClusters_CsI(Event *event)
{
  fLimitPulseInterval = 2.0e-6;
  fNumPMTs = 1;

  Cluster* cluster = 0;
  while (fPulsesCounter > 0) {

    cluster = LocateNewCluster_CsI(event);
    
        
    if (cluster != 0) {
      FillClusterParameters_CsI(cluster, event);
        
      cluster->fType = 0;
      cluster->fSaturated = 0;
      cluster->fAreaDiff = 0;
      cluster->fAreaEff = 0;
      cluster->fNumSPE = 0;
      cluster->fNumPMTTop = 0;
      cluster->fNumPMTBottom = 0;
      cluster->fX = 0;
      cluster->fY = 0;
      cluster->fZ = 0;
      cluster->fDriftTime = 0;
      cluster->fRawEnergy = 0;
      cluster->fRawEnergyError = 0;
      cluster->fCorrectedEnergy = 0;
      cluster->fCorrectedEnergyError = 0;
    }

    Clear();
  }

}

void ClusteringModule::FindClusters_RED(Event *event)
{
  fLimitPulseInterval = 2.0e-7;
  //fLimitPulseInterval = 1.0e-7;
  fHasHSLSChannels = false;
  fNumPMTs = 22;


  Cluster* cluster = 0;
  while (fPulsesCounter > 0) {

    cluster = LocateNewCluster_RED(event);

    if (cluster != 0) {
      FillClusterParameters_RED(cluster, event);
       
      cluster->fType = 0;
      cluster->fSaturated = 0;
      cluster->fAreaDiff = 0;
      cluster->fAreaEff = 0;
      cluster->fNumSPE = 0;
      cluster->fNumPMTTop = 0;
      cluster->fNumPMTBottom = 0;
      cluster->fX = 0;
      cluster->fY = 0;
      cluster->fZ = 0;
      cluster->fDriftTime = 0;
      cluster->fRawEnergy = 0;
      cluster->fRawEnergyError = 0;
      cluster->fCorrectedEnergy = 0;
      cluster->fCorrectedEnergyError = 0;
      
    }
   
    Clear();
  }

}

void ClusteringModule::FindClusters_Z3(Event *event)
{
  fLimitPulseInterval = 1.0e-7;
  fNumPMTs = 31;


  Cluster* cluster = 0;
  while (fPulsesCounter > 0) {

    cluster = LocateNewCluster_Z3(event);
    if (cluster != 0) {
      FillClusterParameters_Z3(cluster, event);

      cluster->fType = 0;
      cluster->fSaturated = 0;
      cluster->fAreaDiff = 0;
      cluster->fAreaEff = 0;
      cluster->fNumSPE = 0;
      cluster->fNumPMTTop = 0;
      cluster->fNumPMTBottom = 0;
      cluster->fX = 0;
      cluster->fY = 0;
      cluster->fZ = 0;
      cluster->fDriftTime = 0;
      cluster->fRawEnergy = 0;
      cluster->fRawEnergyError = 0;
      cluster->fCorrectedEnergy = 0;
      cluster->fCorrectedEnergyError = 0;
    }

    Clear();
  }
}
//////////////////////////////////////////////////////////////////
//
//              Locate New Cluster
//
/////////////////////////////////////////////////////////////////

Cluster* ClusteringModule::LocateNewCluster_CsI(Event* event)
{
  Cluster *cluster = 0;
  Waveform *wf = 0;
  Pulse *pulse = 0;


  int channel = 0;
  int pulsecounter = 0;

  if (fPulsesCounter > 0) {

    // Search for the first free pulse

    for (int i = 0; i < event->GetNumPulses(); i++)
      if (fUnusedPulse[i] == 1) {
        fUnusedPulse[i] = 0;
        fPulsesCounter--;

        pulse = event->GetPulse(i);
        channel = pulse->fChannel;
        wf = event->GetWaveform(pulse->fChannel);

        if (channel >= 0 && !(::g_techChannels & (1 << channel))) {
          cluster = event->GetNewCluster();
          cluster->AddPulse(pulse);
          pulse->SetCluster(cluster);
          fClusterBegin = pulse->fFirstSample*wf->fPeriod + wf->fDelay;
          fClusterEnd = pulse->fLastSample*wf->fPeriod + wf->fDelay;
          break;
        }
      }

    // Search for all other all remaining pulses in cluster

    while (true) {
      pulsecounter = 0;

      for (int j = 0; j < event->GetNumPulses(); j++) {
        if (fUnusedPulse[j] == 1) {

          pulse = event->GetPulse(j);

          if (channel != pulse->fChannel) {
            channel = pulse->fChannel;
            wf = event->GetWaveform(channel);
          }

          if (((pulse->fFirstSample*wf->fPeriod + wf->fDelay) - fClusterEnd <= fLimitPulseInterval) &&
              (fClusterBegin - (pulse->fLastSample*wf->fPeriod + wf->fDelay)) <= fLimitPulseInterval) {

            if (channel >= 0 && !(::g_techChannels & (1 << channel))) {

              if (fClusterBegin > (pulse->fFirstSample*wf->fPeriod + wf->fDelay))
                fClusterBegin = pulse->fFirstSample*wf->fPeriod + wf->fDelay;

              if (fClusterEnd < (pulse->fLastSample*wf->fPeriod + wf->fDelay))
                fClusterEnd = pulse->fLastSample*wf->fPeriod + wf->fDelay;

              cluster->AddPulse(pulse);
              pulse->SetCluster(cluster);
            }
            fPulsesCounter -= 1;
            fUnusedPulse[j] = 0;
            pulsecounter += 1;
          }
        }
      }
      if (pulsecounter == 0) break;
    }
  }
  return cluster;
}

Cluster* ClusteringModule::LocateNewCluster_RED(Event* event)
{
  Cluster *cluster = 0;
  Waveform *wf = 0;
  Pulse *pulse = 0;


  int channel = 0;
  int pulsecounter = 0;

  if (fPulsesCounter > 0) {

    // Search for the first free pulse

    for (int i = 0; i < event->GetNumPulses(); i++)
      if (fUnusedPulse[i] == 1) {
        fUnusedPulse[i] = 0;
        fPulsesCounter--;

        pulse = event->GetPulse(i);
        channel = pulse->fChannel;
        wf = event->GetWaveform(pulse->fChannel);

       if (channel >= 0 && !(::g_techChannels & (1 << channel))) {
       for (int a = i+1; a < event->GetNumPulses(); a++)
       { 
          if (a != i) {
          if (fUnusedPulse[a] == 1) {
             RED:: Pulse *v = event -> GetPulse(a);
        
             //cout<< v->fTime << " -( " << pulse->fLastSample << " * " << wf->fPeriod<<" + " << wf->fDelay << ") < " << fLimitPulseInterval << '\n';
              //cout<< pulse->fTime << " -( " << v->fLastSample << " * " << wf->fPeriod<<" + " << wf->fDelay << ") < " << fLimitPulseInterval << '\n';
             // getchar();
              
             if( (fabs(v->fTime - (pulse->fLastSample*wf->fPeriod + wf->fDelay)) < fLimitPulseInterval) || (fabs(pulse->fTime - (v->fLastSample*wf->fPeriod + wf->fDelay)) < fLimitPulseInterval) ) {
         
              cluster = event->GetNewCluster();
              cluster->AddPulse(pulse);
              pulse->SetCluster(cluster);
              cluster->AddPulse(v);
              v->SetCluster(cluster);
              fUnusedPulse[a]=0;
              fPulsesCounter--;
              
              if( pulse->fTime < v->fTime ){
                fClusterBegin = pulse->fFirstSample*wf->fPeriod + wf->fDelay;
                fClusterEnd = v->fLastSample*wf->fPeriod + wf->fDelay;
              } else {
                fClusterBegin = v->fFirstSample*wf->fPeriod + wf->fDelay;
                fClusterEnd = pulse->fLastSample*wf->fPeriod + wf->fDelay;
              }
//cout<<fClusterBegin<<"|| break1 ||"  ;  
             
              break; 
            } // end of cluster condidtion
          } // if a unused
          } // end of a!=i
        } // end of inner 'for' loop
        if (cluster != 0) break;
      } // end of outer 'for' loop
      
}  

//cout<<fClusterEnd<<"||";
    // Search for all other all remaining pulses in cluster

    while (true) {
      pulsecounter = 0;

      for (int j = 0; j < event->GetNumPulses(); j++) {
        if (fUnusedPulse[j] == 1 ) {
          pulse = event->GetPulse(j);
         // if (pulse->GetCluster() == nullptr){
          double pulse_Begin = pulse->fFirstSample*wf->fPeriod + wf->fDelay;
          double pulse_End = pulse->fLastSample*wf->fPeriod + wf->fDelay;
          if (channel != pulse->fChannel) {
            channel = pulse->fChannel;
            wf = event->GetWaveform(channel);
          }

          if ((pulse_Begin <= (fLimitPulseInterval + fClusterEnd) && (pulse_End >= (fClusterBegin - fLimitPulseInterval) ))) {

            if (channel >= 0 && !(::g_techChannels & (1 << channel))) {

              if (fClusterBegin > pulse_Begin)
                {fClusterBegin = pulse_Begin;}

              if (fClusterEnd < pulse_End)
                {fClusterEnd = pulse_End;}
 
              cluster->AddPulse(pulse);
              pulse->SetCluster(cluster);
            }

            fPulsesCounter -= 1;
            fUnusedPulse[j] = 0;
            pulsecounter += 1;
          
          }
        //}
        }
      }
       
   //  cout<<fClusterBegin<<" || cluster || ";
      if (pulsecounter == 0) break;
    }
  }

  return cluster;
}

Cluster* ClusteringModule::LocateNewCluster_Z3(Event* event)
{
  Cluster *cluster = 0;
  Waveform *wf = 0;
  Pulse *pulse = 0;


  int channel = 0;
  int pulsecounter = 0;

  if (fPulsesCounter > 0) {

    // Search for the first free pulse

    for (int i = 0; i < event->GetNumPulses(); i++)
      if (fUnusedPulse[i] == 1) {
        fUnusedPulse[i] = 0;
        fPulsesCounter--;

        pulse = event->GetPulse(i);
        channel = pulse->fChannel;
        wf = event->GetWaveform(pulse->fChannel);

        if (channel >= 0 && !(::g_techChannels & (1 << channel))) {
          cluster = event->GetNewCluster();
          cluster->AddPulse(pulse);
          pulse->SetCluster(cluster);
          fClusterBegin = pulse->fFirstSample*wf->fPeriod + wf->fDelay;
          fClusterEnd = pulse->fLastSample*wf->fPeriod + wf->fDelay;
          break;
        }
      }

    // Search for all other all remaining pulses in cluster

    while (true) {
      pulsecounter = 0;

      for (int j = 0; j < event->GetNumPulses(); j++) {
        if (fUnusedPulse[j] == 1) {

          pulse = event->GetPulse(j);

          if (channel != pulse->fChannel) {
            channel = pulse->fChannel;
            wf = event->GetWaveform(channel);
          }

          if (((pulse->fFirstSample*wf->fPeriod + wf->fDelay) - fClusterEnd <= fLimitPulseInterval) &&
              (fClusterBegin - (pulse->fLastSample*wf->fPeriod + wf->fDelay)) <= fLimitPulseInterval) {

            if (channel >= 0 && !(::g_techChannels & (1 << channel))) {

              if (fClusterBegin > (pulse->fFirstSample*wf->fPeriod + wf->fDelay))
                fClusterBegin = pulse->fFirstSample*wf->fPeriod + wf->fDelay;

              if (fClusterEnd < (pulse->fLastSample*wf->fPeriod + wf->fDelay))
                fClusterEnd = pulse->fLastSample*wf->fPeriod + wf->fDelay;

              cluster->AddPulse(pulse);
              pulse->SetCluster(cluster);
            }
            fPulsesCounter -= 1;
            fUnusedPulse[j] = 0;
            pulsecounter += 1;
          }
        }
      }
      if (pulsecounter == 0) break;
    }
  }
  return cluster;
}

////////////////////////////////////////////////////////////////////////////////////
//
//                                  Fill Cluster Parameters
//
///////////////////////////////////////////////////////////////////////////////////

void ClusteringModule::FillClusterParameters_RED(Cluster* cluster, Event* event)
{
  double tmpTime = 0;
  double tmpWidth = 0;
  double tmpArea = 0;
  double tmpAmplitude = 0;
  double tmpPeakChannel = 0;
  Pulse* pulse = 0;
  Waveform *wf = 0;
  int channel = -1;

  double ChannelArea[event->fNumChannels];
  for (int i = 0; i < event->fNumChannels; i++)
    ChannelArea[i] = 0;

  for (int counter = 0; counter < cluster->GetNumPulses(); counter++) {
    pulse = cluster->GetPulse(counter);
    if (channel != pulse->fChannel) {
      channel = pulse->fChannel;
      wf = event->GetWaveform(channel);
    }
    if (channel < fNumPMTs) {
      if ( pulse->fSaturated == 0 ) {
        if (tmpAmplitude < pulse->fAmplitude) {
          tmpAmplitude = pulse->fAmplitude;
        }

        tmpArea += pulse->fArea*fChannelGain.at(pulse->fChannel);
        ChannelArea[pulse->fChannel] += pulse->fArea*fChannelGain.at(pulse->fChannel);

      } else if (pulse->fSaturated > 0 && fHasHSLSChannels) {
        wf = event->GetWaveform(channel + fNumPMTs);

        for (int i = 0; i < cluster->GetNumPulses(); i++) {
          pulse = cluster->GetPulse(i);
          if (pulse->fChannel == channel + fNumPMTs) {

            if (tmpAmplitude < pulse->fAmplitude) {
              tmpAmplitude = pulse->fAmplitude;
            }
            tmpArea += pulse->fArea*fChannelGain.at(pulse->fChannel);
            ChannelArea[pulse->fChannel] += pulse->fArea*fChannelGain.at(pulse->fChannel);
          }
        }
      }
    }
  }

  tmpPeakChannel = 0;

  for (int i = 1; i < event->fNumChannels; i++) {
    if (ChannelArea[i] > ChannelArea[i-1])
      tmpPeakChannel = i;
      
  }

  cluster->fWidth = (fClusterEnd - fClusterBegin);// * 1e+9;
  cluster->fTime = fClusterBegin;// 1e+9;
 
  cluster->fArea = tmpArea;
  cluster->fAmplitude = tmpAmplitude;
  cluster->fPeakChannel = tmpPeakChannel;

}


void ClusteringModule::FillClusterParameters_CsI(Cluster* cluster, Event* event)
{
  double tmpTime = 0;
  double tmpWidth = 0;
  double tmpArea = 0;
  double tmpAmplitude = 0;
  double tmpPeakChannel = 0;
  Pulse* pulse = 0;
  Waveform *wf = 0;
  int channel = -1;

  double ChannelArea[event->fNumChannels];
  for (int i = 0; i < event->fNumChannels; i++)
    ChannelArea[i] = 0;

  for (int counter = 0; counter < cluster->GetNumPulses(); counter++) {
    pulse = cluster->GetPulse(counter);
    if (channel != pulse->fChannel) {
      channel = pulse->fChannel;
      wf = event->GetWaveform(channel);
    }
      if ( !pulse->fSaturated ) {
        if (tmpAmplitude < pulse->fAmplitude) {
          tmpAmplitude = pulse->fAmplitude;
        }

        tmpArea += pulse->fArea*fChannelGain.at(pulse->fChannel);
        ChannelArea[pulse->fChannel] += pulse->fArea*fChannelGain.at(pulse->fChannel);

      }
  }

  tmpPeakChannel = 0;

  for (int i = 1; i < event->fNumChannels; i++) {
    if (ChannelArea[i] > ChannelArea[i-1])
      tmpPeakChannel = i;
  }

  cluster->fWidth = (fClusterEnd - fClusterBegin);// * 1e+9;
  cluster->fTime = fClusterBegin;// 1e+9;
  cluster->fArea = tmpArea;
  cluster->fAmplitude = tmpAmplitude;
  cluster->fPeakChannel = tmpPeakChannel;
  

}

void ClusteringModule::FillClusterParameters_Z3(Cluster* cluster, Event* event)
{
  double tmpTime = 0;
  double tmpWidth = 0;
  double tmpArea = 0;
  double tmpAmplitude = 0;
  double tmpPeakChannel = 0;
  Pulse* pulse = 0;
  Waveform *wf = 0;
  int channel = -1;

  double ChannelArea[event->fNumChannels];
  for (int i = 0; i < event->fNumChannels; i++)
    ChannelArea[i] = 0;

  for (int counter = 0; counter < cluster->GetNumPulses(); counter++) {
    pulse = cluster->GetPulse(counter);
    if (channel != pulse->fChannel) {
      channel = pulse->fChannel;
      wf = event->GetWaveform(channel);
    }
      if ( !pulse->fSaturated ) {
        if (tmpAmplitude < pulse->fAmplitude) {
          tmpAmplitude = pulse->fAmplitude;
        }

        tmpArea += pulse->fArea*fChannelGain.at(pulse->fChannel);
        ChannelArea[pulse->fChannel] += pulse->fArea*fChannelGain.at(pulse->fChannel);


     }
  }

  tmpPeakChannel = 0;

  for (int i = 1; i < event->fNumChannels; i++) {
    if (ChannelArea[i] > ChannelArea[i-1])
      tmpPeakChannel = i;
  }

  cluster->fWidth = (fClusterEnd - fClusterBegin);// * 1e+9;
  cluster->fTime = fClusterBegin;// 1e+9;
  cluster->fArea = tmpArea;
  cluster->fAmplitude = tmpAmplitude;
  cluster->fPeakChannel = tmpPeakChannel;
  

}

void ClusteringModule::Clear()
{
  fClusterBegin = 0;
  fClusterEnd = 0;
}
