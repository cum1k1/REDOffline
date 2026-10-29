#include "ChannelData.hh"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TAxis.h"
#include "TLine.h"
#include "TBox.h"
#include "TPad.h"
#include "TList.h"
#include "TGaxis.h"
#include "TMarker.h"
#include <algorithm>
#include <cmath>

class Scale{
  double _offset;
  double _stretch;
public:
  Scale(double offset, double stretch) : _offset(offset), _stretch(stretch) {}
  double operator()(double x){ return _stretch*x + _offset; }
};

TGraph* ChannelData::GetTGraph(bool baseline_subtracted, int downsample) const
{
  if( nsamps < 2 || waveform.empty())
    return 0;
  if( baseline_subtracted && subtracted_waveform.empty())
    return 0;
  if(downsample < 1) downsample = 1;
  std::vector<double> x(nsamps/downsample);
  std::vector<double> ycpy( downsample>1 ? nsamps/downsample : 0);
  //double y[(const int)nsamps];
  const double* y = (baseline_subtracted ? GetBaselineSubtractedWaveform() :
		     GetWaveform() );
  for(int i=0; i<nsamps/downsample; i++){
    x[i] = (i*downsample - trigger_index) / sample_rate;
    if(downsample > 1)
      ycpy[i] = y[i*downsample];
  }
  TGraph* graph = new TGraph(nsamps/downsample,&x[0],
			     (downsample > 1 ? &(ycpy[0]) : y) );
  char name[30];
  if(label != "")
    sprintf(name,"%i-%s",channel_id, label.c_str());
  else
    sprintf(name,"%i",channel_id);
  graph->SetName(name);
  graph->SetTitle(name);
  graph->SetEditable(false);
  //graph->GetXaxis()->SetTitle("sample time [#mu s]");
  //graph->SetMarkerStyle(7);
  return graph;
}

void ChannelData::Draw(bool baseline_subtracted, int downsample,
		       bool autoscalex, bool autoscaley,
		       double xmin, double xmax, double ymin, double ymax)
{ ; }

void ChannelData::Print(int verbosity)
{ ; }
