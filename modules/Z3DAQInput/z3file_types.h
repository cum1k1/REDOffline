#ifndef Z3FILE_TYPES_H
#define Z3FILE_TYPES_H

#include <stdint.h>
typedef float float32_t;
typedef double float64_t;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
typedef struct {
 /****** DAQ SETTINGS ******/
 //written in the beggining of every data file
 //these values will be the defaults if no others
 //are specified
  //char head_id[4];
  char daq_id[8];
  uint16_t version_id[3];
  char runtype_str[5];
  uint16_t runtype_id;
  char username[32];
  char start_time[32];
  char stop_time[32];
  /* trigger struct: sizeof(trigger_t)=44 */
  float64_t t_sampling;
  int32_t t_samples;
  int32_t t_segments;
  float64_t t_delay;
  int32_t t_channel;
  int32_t t_coupling;
  int32_t t_slope;
  float64_t t_level;
  /* channel set-ups: sizeof(detector[].channels) = CHANS*66 */
  //
  //char comment[1024];
  /****** DAQ SETTINGS ******/
} file_header_v1;

typedef struct {
  float64_t c_gain;
  float64_t c_offset;
  int32_t c_coupling;
  int16_t c_saved;
  float64_t c_min_amp_cut;
  int16_t c_in_range;
  int16_t c_satur_cut;
  char c_label[32];
  //
} channel_header_v1;

typedef struct {
  //char ev_id[4]
  char ev_id_tail[6];
  float64_t horPos;
  uint32_t timeStampLo;
  uint32_t timeStampHi;
} event_header_v1;

typedef struct {
  int32_t SamplesPerSeg;  // number of points
  int32_t iFirstPoint;    // first valid point
  float64_t  sampTime;
  float64_t  vGain;           // voltage = digital * vGain + vOffset
  float64_t  vOffset;         // 
  int32_t nSegments;       // When reading multiple segments in one waveform
  int32_t nbrAvgWforms;
  uint32_t actualTriggersInAcqLo; 
  uint32_t actualTriggersInAcqHi;
  char reserved[16];
} data_channel_header_v1;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// !!! begin must correspond to v1 !!!
typedef struct{
 /****** DAQ SETTINGS ******/
 //written in the beggining of every data file
 //these values will be the defaults if no others
 //are specified
  //char head_id[4];
  char daq_id[8];
  int16_t version_id[3];
  char runtype_str[5];
  int16_t runtype_id;
  char username[32];
  char start_time[32];
  char stop_time[32];
  /* trigger struct: sizeof(trigger_t)=44 */
  float64_t t_sampling;
  int32_t t_samples;
  int32_t t_segments;
  float64_t t_delay;
  int32_t t_channel;
  int32_t t_coupling;
  int32_t t_slope;
  float64_t t_level;
  //
  uint16_t irun;     // run id
  uint16_t nchannels;// number of channels
  uint32_t nevents;  // number of events
  char reserved[16];
  /* channel set-ups: sizeof(detector[].channels) = CHANS*66 */
  //
  //char comment[1024];
  /****** DAQ SETTINGS ******/
} file_header_v2;

typedef struct {
  float64_t c_gain;
  float64_t c_offset;
  int32_t c_coupling;
  int16_t c_saved;
  float64_t c_min_amp_cut;
  int16_t c_in_range;
  int16_t c_satur_cut;
  char c_label[32];
  //
  uint16_t nsamples; // desired nsamples
  uint16_t resample; // reserved
  uint16_t filter;   // reserved
  char reserved[4];
  //
} channel_header_v2;

typedef struct {
  //char ev_id[4], ev_id_tail[6];
  float64_t horPos;      // ?
  uint32_t timeStampLo;  // timestamp
  uint32_t timeStampHi;  // hi <-> lo ? what is difference
  //
  int32_t ievent; // event id
} event_header_v2;

typedef struct {
  int32_t SamplesPerSeg;  // number of points
  int32_t iFirstPoint;    // first valid point
  float64_t  sampTime;
  float64_t  vGain;           // voltage = digital * vGain + vOffset
  float64_t  vOffset;         // 
  int32_t nSegments;       // When reading multiple segments in one waveform
  int32_t nbrAvgWforms;
  uint32_t actualTriggersInAcqLo; 
  uint32_t actualTriggersInAcqHi;
  //
  uint16_t data_len;
  uint16_t nsamples;
  uint16_t BitsInSample;
  uint16_t BitsInData;
  char reserved[8];
} data_channel_header_v2;
#define BITS_IN_CHAR 8

typedef file_header_v1 file_header_v3;
//  char satCut;
//  int nRejected;
typedef channel_header_v1 channel_header_v3;
typedef struct {
  //char ev_id[4];
  char ev_id_tail[6];
  uint32_t evTime; // timesec
  float64_t hp_time; // timeusec
  //scdata slowcon;
  uint32_t timestamp;
  float32_t temp[16];  // temperature
  float32_t pres[4];   // pressure
  float32_t level[4];  // level
  float32_t vac[8];    // vacuum
  //hvdata hv[3];    // HV structure
  struct { 
    int32_t status;
    float32_t vcur;  // currently set voltage
    float32_t v;     // measured voltage
    float32_t vaver; // measured voltage averaged over last minute
    float32_t i;     // measured current
    float32_t iaver; // measured current averaged over last minute
    float32_t ipeak; // last minute peak current
  } hv[3]; //
  //envdata env;     // environment data structure
  float32_t p;      // atmospheric pressure
  float32_t t1;     // ambient temperature 1
  float32_t t2;     // ambient temperature 2
  float32_t res[3]; // reserved
  //
  int32_t trgrate;     // trigger rate
  float32_t res2[8];    // reserved
  //
  float64_t horPos;      // more precise trigger ?
  uint32_t timeStampLo;  // timestamp
  uint32_t timeStampHi;  // hi <-> lo ? what is difference
} event_header_v3;
typedef data_channel_header_v1 data_channel_header_v3;

#ifdef __cplusplus

#include <iostream>

std::ostream& operator<<(std::ostream& os, const file_header_v1 &fh);
std::ostream& operator<<(std::ostream& os, const channel_header_v1 &ch);
std::ostream& operator<<(std::ostream& os, const event_header_v1 &eh);
std::ostream& operator<<(std::ostream& os, const data_channel_header_v1 &dch);
std::ostream& operator<<(std::ostream& os, const event_header_v3 &eh);
//std::ostream& operator<<(std::ostream& os, const data_channel_header_v3 &dch);

#endif /* __cplusplus */

#endif /* z3file_types.h */
