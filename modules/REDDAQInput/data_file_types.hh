#ifndef DATA_FILE_TYPES_HH
#define DATA_FILE_TYPES_HH

#include <stdint.h>
typedef float  float32_t;
typedef double float64_t;

/*struct {
  uint32_t magic;
  struct {
    uint32_t code;
    uint32_t len;
    //struct ? value;
  } records[];
} data_file;
struct file_header {
  uint32_t nrecords;
  struct timespec ctime;
  struct timespec mtime;
  uint32_t store_mode;
  uint32_t compress;
};*/

struct run_header_v1 {
  uint32_t  irun;       // run number, ID
  uint32_t  daq_id;     // hex-coded program ID
  uint32_t  daq_vers;   // byte-coded program version
  uint32_t  file_vers;  // byte-coded structures version
  //char run_type[32];  // type of run (ECAL, NCAL, muon, SE, bkg, ... )
  // settings
  char      username[32]; // user that started
  // TTimeStamp
  int32_t   start_gsec,start_sec,start_nsec; // start time
  int32_t   stop_gsec,stop_sec,stop_nsec; // stop time
  int32_t   act_gsec,act_sec,act_nsec; // total duration of active acquisition
  int32_t   nchannels;  // channels in acquisition
  //uint32_t  trigger_mode;
  //char      conf_file[256]; will go to descr as a line 'Used configuration file \'filename\'.'
  char      descr[1024]; // short description of data
  //uint32_t  ntriggers;  // total triggers got
  int32_t   nevents;    // total events got
  int32_t   nentries;   // events for this run in file
  int32_t   ev_ientry;  // ientry of first event record
  int32_t   sl_ientry;  // ientry of first slow control record
  //
  char reserved[32];
  //
  //void start(const struct timespec &t);
  //struct timespec start();
};
// "RED\0" = 0x52454400

#define DATA_RUN_VERS(A)   (((A)>>24)&0xff) // run_header, channel_header, run_control
#define DATA_SLOW_VERS(A)  (((A)>>16)&0xff) // slow_control
#define DATA_EVENT_VERS(A) (((A)>> 8)&0xff) // event_header, event_channel, time_line
#define DATA_PLS_VERS(A)   (((A)    )&0xff) // event_pulse
#define DATA_FILE_VERS(A1,A2,A3,A4) ((((A1)&0xff)<<24)+(((A2)&0xff)<<16)+(((A3)&0xff)<<8)+(((A4)&0xff)))

enum run_control_type {
  run_control_unkn,
  run_control_start,
  run_control_pause,
  run_control_resume,
  run_control_stop,
  run_control_update
};
struct run_control_v1 {
  uint32_t  irun;
  int32_t   time_gsec,time_sec,time_nsec; // record time
  char      sender[32];   // who
  int32_t   type;         // what (start,pause,resume,stop,update)
  char      reason[256];  // // empty, hw_bad, partial, overload
  int32_t   nevents;      // number of events since last record
  float32_t trigger_rate; // current average
  float32_t system_load;  // current average
  // hw state ???
  //
  char reserved[32];
};
typedef run_control_v1 run_control;

struct slow_control_v1 {
  uint32_t  irun;
  int32_t   time_gsec,time_sec,time_nsec;
  //   
  char reserved[112];
};

struct channel_header_v1 {
  uint32_t  irun;
  int32_t   ichannel;
  char      label[32];
  float32_t gain;
  float32_t offset;    // voltage = data*gain+offset
  float32_t threshold; // in volts
  float32_t period;    // sampling period = 1/rate
  float32_t delay;     // time = index*period+delay
  int32_t   nsamples;  // size of full timeline
  int32_t   trigger;   // trigger position in samples
  int32_t   nbits;     // bit width of data points
  // board ID, board channel ID
  char reserved[32];
  //
  bool save; // FIXME move to data_file
};

struct event_header_v1 {
  uint32_t  irun;
  uint32_t  ievent;    // event number, ID
  int32_t   time_gsec, time_sec, time_nsec;
  //uint32_t synctime; 
  int32_t   trigger_count; // actual trigger number
  int32_t   nchannels; // channels in event
  uint32_t  dio[8];
  float32_t dtime[8];
  int32_t   npulses;
  int32_t   ch_ientry;
  int32_t   pls_ientry;
  int32_t   sl_ientry;
  //
  char reserved[32];
  //
};

struct event_channel_v1 {
  uint32_t  irun;
  uint32_t  ievent;
  int32_t   ichannel;
  int32_t   nsamples; // full timeline for this channel
  uint64_t  clock_value; // ADC clock value at trigger // align!
  int32_t   npulses;
  int32_t   ev_ientry;
  float32_t line_min, line_max;
  float32_t line_mean, line_rms;
  float32_t line_base, line_noise;
  //
  //overlapping
  //saturated
  char reserved[32];
};

struct waveform_v1 {
  int32_t   nsamples; // samples in this waveform
  int32_t   length;   // packed length of waveform
  int32_t   basetime; // waveform base sample index (event_index = pulse_index + base)
  int32_t   modified; // how many times data was modified, e.g. through filtering
  int32_t   packing;  // packing mode
  //
  char reserved[32];
  //
  // same is hw_int for correct data propagation
  uint32_t* data;     // length // FIXME
};
typedef waveform_v1 waveform;

struct event_pulse_v1 {
  uint32_t  irun;
  uint32_t  ievent;
  int32_t   ichannel;
  int32_t   ipulse;
  int32_t   ev_ientry;
  //
  int8_t    saturated, multipulse, partial, type;
  float32_t time, amplitude, width10, width50, width90, area, tau;
  float32_t fit[8];
};

#endif /* DATA_FILE_TYPES_HH */
