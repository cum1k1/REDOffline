#include <iostream>

#include "z3file_types.h"

using namespace std;

ostream& operator<<(ostream& os, const file_header_v1 &fh)
{
  os << "{\n"
     << "  .daq_id= '" << fh.daq_id << "',\n"
     << "  .version_id[] = " << fh.version_id[0] << '.' << fh.version_id[1] << '.' << fh.version_id[2] << ",\n"
     << "  .runtype_str[] = '" << fh.runtype_str << "',\n"
     << "  .runtype_id = " << fh.runtype_id << ",\n"
     << "  .username[] = '" << fh.username << "',\n"
     << "  .start_time[] = '" << fh.start_time << "',\n"
     << "  .stop_time[] = '" << fh.stop_time << "',\n"
     << "  .t_sampling = " << fh.t_sampling << ",\n"
     << "  .t_samples = " << fh.t_samples << ",\n"
     << "  .t_segments = " << fh.t_segments << ",\n"
     << "  .t_delay = " << fh.t_delay << ",\n"
     << "  .t_channel = " << fh.t_channel << ",\n"
     << "  .t_coupling = " << fh.t_coupling << ",\n"
     << "  .t_slope = " << fh.t_slope << ",\n"
     << "  .t_level = " << fh.t_level << ",\n"
     << "}";
  return os;
}
ostream& operator<<(ostream& os, const channel_header_v1 &ch)
{
  os << "  {\n"
     << "    .gain = " << ch.c_gain << ",\n"
     << "    .offset = " << ch.c_offset << ",\n"
     << "    .coupling = " << ch.c_coupling << ",\n"
     << "    .saved = " << ch.c_saved << ",\n"
     << "    .min_amp_cut = " << ch.c_min_amp_cut << ",\n"
     << "    .in_range = " << ch.c_in_range << ",\n"
     << "    .satur_cut = " << ch.c_satur_cut << ",\n"
     << "    .label[] = '" << ch.c_label << "',\n"
     << "  }";
  return os;
}
ostream& operator<<(ostream& os, const event_header_v1 &eh)
{
  os << "{"
     << eh.horPos << ", " << eh.timeStampLo << ", " << eh.timeStampHi << ", "
     << "}";
  return os;
}
ostream& operator<<(ostream& os, const data_channel_header_v1 &dch)
{
  os << "{"
     << dch.SamplesPerSeg << ", " << dch.iFirstPoint << ", "
     << dch.sampTime << ", " << dch.vGain << ", " << dch.vOffset << ", "
     << dch.nSegments << ", " << dch.nbrAvgWforms << ", "
     << dch.actualTriggersInAcqLo << ", " << dch.actualTriggersInAcqHi << ", "
     << "}";
  return os;
}

//
ostream& operator<<(ostream& os, const event_header_v3 &eh)
{
  os << "{"
     << eh.evTime << ", " << eh.hp_time << ", "
     << eh.timestamp << ", " << eh.temp[0] << ", "
     << eh.pres[0] << " ... " << eh.trgrate << ", "
     << eh.horPos << ", " << eh.timeStampLo << ", " << eh.timeStampHi << ", "
     << "}";
  return os;
}
//ostream& operator<<(ostream& os, const data_channel_header_v3 &dch) { os << *((data_channel_header_v1*)&dch); return os; }
