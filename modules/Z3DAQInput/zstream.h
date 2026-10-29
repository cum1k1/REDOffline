#ifndef ZSTREAM_HH
#define ZSTREAM_HH

#include <iostream>
#include <zlib.h>

namespace std {
  class izstream {
  public:
    gzFile fp;
    ios::iostate state;
    //
  public:
    izstream(): fp(0),state(ios::badbit) {}
    izstream(const string &name): fp(0),state(ios::badbit) { 
      fp = gzopen(name.c_str(),"r"); if (fp!=0) state = ios::goodbit; }
    ~izstream() { if (fp) gzclose(fp); }
    //
    inline ios::iostate rdstate() const { return state; }
    inline bool bad() const { return state & ios::badbit; }
    inline bool eof() const { return state & ios::eofbit; }
    inline bool fail() const { return state & ios::failbit; }
    inline bool good() const { return state==ios::goodbit; }
    inline void clear(ios_base::iostate flags = ios::goodbit) { state = flags; }
    inline void setstate(ios_base::iostate flags) { state = flags; }
    //
    inline bool is_open() const { return fp; }
    inline operator bool() const { return good(); }
    izstream& read(void* v, size_t s) { 
      int i = gzread(fp,v,s);
      if (i==-1) clear(ios::badbit);
      else if (i==0) clear(ios::eofbit);
      else if (0<i && (unsigned)i<s) clear(ios::failbit); // FIXME
      return *this; }
    off_t seek(off_t off, int dir) { 
      off_t pos = gzseek(fp,off,dir); 
      if (pos==-1) clear(ios::failbit);
      return pos; }
    off_t tell() { return seek(0L,SEEK_CUR); }
    //
    bool open(const string &name) {
      if (fp) gzclose(fp);
      fp = gzopen(name.c_str(),"r"); if (fp!=0) state = ios::goodbit; 
      return is_open(); }
  };
  //inline izstream& operator>>(izstream& is, uint32_t &u) {gzread(is.fp,&u,sizeof(u));return is;}

  class ozstream {
  public:
    gzFile fp;
    ios::iostate state;
    //
  public:
    ozstream(): fp(0),state(ios::badbit) { }
    ozstream(const string &name):state(ios::badbit) { 
      fp = gzopen(name.c_str(),"w"); if (fp!=0) state = ios::goodbit; }
    ~ozstream() { if (fp) gzclose(fp); }
    //
    inline ios::iostate rdstate() const { return state; }
    inline bool bad() const { return state & ios::badbit; }
    inline bool eof() const { return state & ios::eofbit; }
    inline bool fail() const { return state & ios::failbit; }
    inline bool good() const { return state==ios::goodbit; }
    inline void clear(ios_base::iostate flags = ios::goodbit) { state = flags; }
    inline void setstate(ios_base::iostate flags) { state = flags; }
    //
    inline bool is_open() const { return fp; }
    inline operator bool() const { return good(); }
    ozstream& write(const void* v, size_t s) { 
      int i = gzwrite(fp,v,s);
      if (i==-1) clear(ios::badbit);
      else if (i==0) clear(ios::eofbit);
      else if (0<i && (unsigned)i<s) clear(ios::failbit); // FIXME
      return *this; }
    off_t seek(off_t off, int dir) { 
      off_t pos = gzseek(fp,off,dir); 
      if (pos==-1) clear(ios::failbit);
      return pos; }
    off_t tell() { return seek(0L,SEEK_CUR); }
    //
    bool open(const string &name) {
      if (fp) gzclose(fp);
      fp = gzopen(name.c_str(),"w"); if (fp!=0) state = ios::goodbit; 
      return is_open(); }
  };
};

#endif /* ZSTREAM_HH */
