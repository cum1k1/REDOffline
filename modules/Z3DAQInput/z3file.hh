#ifndef Z3FILE_HH
#define Z3FILE_HH

#include <iostream>
#include "zstream.h"

#include "z3file_types.h"

#include "REDEvent/Event.hh"
#include "REDEvent/RunInfo.hh"

///////////////////////////////////////////////////
class z3file {
public:
  enum z3type {
    file_none,
    file_v1,
    file_v2,
    file_v3,
    file_v4,
  };
  z3type type;
  std::izstream fin;
  std::ozstream fout;
  union {
    file_header_v1 v1;
    file_header_v2 v2;
    file_header_v3 v3;
  } fh;
  size_t nch;
  union {
    channel_header_v1 v1;
    channel_header_v2 v2;
    channel_header_v3 v3;
  } ch[64];
  char comment[1024];
  int verbose;
  size_t ievent;
  bool write_;
  //
  z3file(const std::string &filename, bool write_ = false);
  ~z3file() { ; }
  //
  inline bool is_open() const { return (write_)?fout.is_open():fin.is_open(); }
  inline operator bool () const { return (write_)?(bool)fout:(bool)fin; }
  bool read_header();
  bool read_next_event(RED::Event &event);
  bool read_event(RED::Event &event, size_t ievent = 0);
  void set_type(z3type t);
  bool write_header();
  bool write_event(const RED::Event &event);
};

#endif /* Z3FILE_HH */
