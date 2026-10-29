#include <iostream>
#ifdef LINUX
#include <byteswap.h>
#endif
#ifdef DARWIN
//#include <> don't know what to include
#define bswap_16(X) OSSwapInt16(X)
#define bswap_32(X) OSSwapInt32(X)
#define bswap_64(X) OSSwapInt64(X)
#endif
#include <cstdlib>
#include <cstring>
#include <cstdio>

//#include "zstream.h"

#include "z3file_types.h"
#include "z3file.hh"

using namespace std;


///////////////////////////////////////////////////
//
// Here comes hell and black magic
//
///////////////////////////////////////////////////

inline void bswap(void *mem, size_t s)
{
  char t, *q, *p, *m = (char *)mem;
  for(p=m,q=m+s-1;p<q;p++,q--) { t = *p; *p = *q; *q = t; }
}
void swab(char m[]) { ; }
template <class T> void swab(T &m) { bswap(&m,sizeof(T)); }

#define malign(A,B) ({ struct { B z; A a; B b; }x; (char*)&x.b-(char*)&x.a; })
int malign[4][6] = {
};
void minit(void)
{
  int i, j;
  for(i=0;i<4;i++)
    for(j=0;j<6;j++)
      malign[i][j] = 1<<j;
  malign[1][1] = malign[2][1] = malign(char,int16_t);
  malign[1][2] = malign[2][2] = malign(char,int32_t);
  malign[1][3] = malign[2][3] = malign(char,int64_t);
  malign[3][2] = malign(char,float);
  malign[3][3] = malign(char,double);
  malign[3][4] = malign(char,long double);
  cout << "malign: ";
  for(i=0;i<4;i++)
    for(j=0;j<6;j++)
      cout << malign[i][j] << ' ';
  cout << endl;
}
int mwx(void *mem_, char *buf, const char *desc, int mode)
{
  char *p, *q, *r, *d = (char*)desc;
  char *mem = (char *)mem_;
  int itype, type, isize, size, bitsize, count, alignment, psize = 0;
  int ret = 0;

  //printf("%s: desc = '%s'\n",__func__,desc);
  while(*d!='\0') {
    // size
    switch(*d) {
    case 'Q': isize = 0, size = 1; break;
    case 'H': isize = 1, size = 2; break;
    case 'S': isize = 2, size = 4; break;
    case 'D': isize = 3, size = 8; break;
    case 'T': isize = 4, size = 16; break;
    case 'O': isize = 5, size = 32; break;
    default:
      isize = 0, size = 0;
      fprintf(stderr,"%s: unknown size %c\n",__func__,*d);
    }
    // type
    switch(*(p=d+1)) {
    case 'C': itype = 0, type = 1; break;
    case 'I': itype = 1, type = 2; break;
    case 'U': itype = 2, type = 3; break;
    case 'F': itype = 3, type = 4; break;
      break;
    default:
      itype = 0, type = 0;
      fprintf(stderr,"%s: unknown mode %c\n",__func__,*p);
    }
    q = p+1;
    if(*q=='(') {
      bitsize = strtol(q+1,&q,10);
      if (*q!=')') fprintf(stderr,"%s: mismatched parethesis: '%s'\n",__func__,d);
      else q++;
    } else {
      bitsize = 0;
    }
    if(*q=='*' || *q=='[') {
      count = strtol(q+1,&r,10);
      if (*q=='[') {
        if (*r!=']') fprintf(stderr,"%s: mismatched parethesis: '%s'\n",__func__,d);
        else r++;
      }
    } else {
      count = 1;
      r = q;
    }
    if (*r==',') r++;
    alignment = malign[itype][isize];
    psize = ((size_t)mem%alignment)?(alignment-(size_t)mem%alignment):0; // FIXME
    //printf("write %d: %C%d(%d)[%d] %d %d <- '%s'\n",mode,*p,size,bitsize,count,alignment,psize,r);
    // FIXME bitsize
    mem += psize;
    switch(mode) {
    case 1: ret += psize+size*count; break;
    case 2: ret += size*count; break;
    case 3: {
      int i;
      union {
        uint16_t u16;
        uint32_t u32;
        uint64_t u64;
        char c[8];
      } x;
      switch(isize) {
      case 0: 
        memcpy(buf,mem,size*count);
        mem += size*count; buf += size*count;
        break;
      case 1: {
        for(i=0;i<count;i++) {
          x.u16 = bswap_16(*(uint16_t *)mem); mem += size;
          *buf++ = x.c[0], *buf++ = x.c[1]; }
        break; }
      case 2: {
        for(i=0;i<count;i++) {
          x.u32 = bswap_32(*(uint32_t *)mem); mem += size;
          *buf++ = x.c[0], *buf++ = x.c[1], *buf++ = x.c[2], *buf++ = x.c[3]; }
        break; }
      case 3: {
        for(i=0;i<count;i++) {
          x.u64 = bswap_64(*(uint64_t *)mem); mem += size;
          *buf++ = x.c[0], *buf++ = x.c[1], *buf++ = x.c[2], *buf++ = x.c[3];
          *buf++ = x.c[4], *buf++ = x.c[5], *buf++ = x.c[6], *buf++ = x.c[7]; }
        break; }
      case 4:
      case 5:
        memcpy(buf,mem,size*count);
        for(i=0;i<count;i++,buf+=size) bswap(buf,size);
        mem += size*count; //buf += size*count;
        break;
      default:
        ;
      }
    } break;
    case 4: { // FIXME PDP
      int i;
      for(i=0;i<count;i++,buf+=size) bswap(buf,size);
      memcpy(mem,buf-size*count,size*count);
      mem += size*count; //buf += size*count;
    } break;
    case 5: {
      int i;
      for(i=0;i<count;i++,buf+=size) bswap(buf,size);
#ifdef BYTE_ORDER
# if BYTE_ORDER+0==LITTLE_ENDIAN+0
# elif BYTE_ORDER+0==BIG_ENDIAN+0
# elif BYTE_ORDER+0==PDP_ENDIAN+0
# endif
#else
#endif
    } break;
    default:
      fprintf(stderr,"%s: unknown mode: %d\n",__func__,mode);
    }
    d = r;
  }
  return ret;
}
inline void mcheckinit() { if(malign[0][0]!=1) minit(); }
inline int mmemcalc(const char *desc) { mcheckinit(); return mwx(0,0,desc,1); }
inline int mbufcalc(const char *desc) { mcheckinit(); return mwx(0,0,desc,2); }
inline int mcode(void *mem, char *buf, const char *desc) { mcheckinit(); return mwx(mem,buf,desc,3); }
inline int mdecode(void *mem, char *buf, const char *desc) { mcheckinit(); return mwx(mem,buf,desc,4); }
inline int mswab(char *buf, const char *desc) { mcheckinit(); return mwx(0,buf,desc,5); }

///////////////////////////////////////////////////

//  size = 1,2,4,8,16,32, = Q,H,S,D,T,O,
bool read(izstream& is, file_header_v1 &m) {
  const char *desc = "QC[8],HI[3],QC[6],HI,QC[32],QC[32],QC[32],QC[2],DF,SI*2,DF,SI*3,DF";
  int size = mbufcalc(desc);
  char buf[size];
  is.read(buf,size); // FIXME count
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  mswab(buf,desc); // thanks to DAQ
#endif
  mdecode((char*)&m,buf,desc);
  return is;
}
bool read(izstream& is, event_header_v1 &m) {
  const char *desc = "QC[6],DF,SU*2";
  int size = mbufcalc(desc);
  char buf[size];
  is.read(buf,size);
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  mswab(buf,desc);
#endif
  mdecode((char*)&m,buf,desc);
  return is;
}
bool read(izstream& is, event_header_v3 &m) {
  const char *desc = "QC[6],SU,DF,SU,SF[32],SF[21],SF*15,DF,SU*2";
  int size = mbufcalc(desc);
  char buf[size];
  is.read(buf,size);
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  mswab(buf,desc);
#endif
  mdecode((char*)&m,buf,desc);
  return is;
}
bool read(izstream& is, data_channel_header_v3 &m) {
  const char *desc = "SI*2,DF*3,SU*4,QC[16]";
  int size = mbufcalc(desc);
  char buf[size];
  is.read(buf,size);
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  mswab(buf,desc);
#endif
  mdecode((char*)&m,buf,desc);
  return is;
}
template <class T> bool read(izstream& is, T &m, size_t count = 1) { 
  is.read(&m,sizeof(m)*count);
  T *p;
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  p = &m; for(size_t i=0;i<count;i++,p++) swab(*p);
#endif
  p = &m; for(size_t i=0;i<count;i++,p++) swab(*p);
  return is;
}
bool write(ozstream& os, const file_header_v1 &m) {
  const char *desc = "QC[8],HI[3],QC[6],HI,QC[32],QC[32],QC[32],QC[2],DF,SI*2,DF,SI*3,DF";
  int size = mbufcalc(desc);
  char buf[size];
  mcode((char*)&m,buf,desc);
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  mswab(buf,desc); // thanks to DAQ
#endif
  os.write(buf,size); // FIXME count
  return os;
}
bool write(ozstream& os, const event_header_v3 &m) {
  const char *desc = "QC[6],SU,DF,SU,SF[32],SF[21],SF*15,DF,SU*2";
  int size = mbufcalc(desc);
  char buf[size];
  mcode((char*)&m,buf,desc);
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  mswab(buf,desc); // thanks to DAQ
#endif
  os.write(buf,size); // FIXME count
  return os;
}
bool write(ozstream& os, const data_channel_header_v3 &m) {
  const char *desc = "SI*2,DF*3,SU*4,QC[16]";
  int size = mbufcalc(desc);
  char buf[size];
  mcode((char*)&m,buf,desc);
#if BYTE_ORDER+0!=BIG_ENDIAN+0
  mswab(buf,desc); // thanks to DAQ
#endif
  os.write(buf,size); // FIXME count
  return os;
}
template <class T> bool write(ozstream& os, const T &m, size_t count = 1) { 
  const T *p = &m; T t;
  for(size_t i=0;i<count;i++,p++) {
    memcpy(&t,p,sizeof(T));
#if BYTE_ORDER+0!=BIG_ENDIAN+0
    swab(t);
#endif
    swab(t);
    os.write(&t,sizeof(T));
  }
  return os;
}

///////////////////////////////////////////////////
//
// Here comes actual z3file class
//
///////////////////////////////////////////////////

z3file::z3file(const std::string &filename, bool write__):
  type(file_none),fin(),fout(),nch(0),verbose(0),ievent(0),write_(write__) {
  if (write_) fout.open(filename); else fin.open(filename);
  memset(&fh,0,sizeof(fh));
  memset(&ch,0,sizeof(ch));
  memset(comment,0,sizeof(comment));
}
bool z3file::read_header()
{
  if (!fin) return false;
  uint32_t code;
  if (!read(fin,code)) return false; // head_id
  if (verbose>2)
    cout << "head_id[] = '" << hex << code << dec << "'" << endl;
  if        (code==0x00313041) { type = file_v1; nch = 64; // A01\0=v1
  } else if (code==0x00323041) { type = file_v2; nch = 16; // A02\0=v2
  } else if (code==0x00333041) { type = file_v3; nch = 64; // A03\0=v3
  } else if (code==0x00343041) { type = file_v4; nch = 64; // A04\0=v4
  } else { 
    type = file_none; nch = 0;
    cerr << __func__ << ": unknown head_id: '" << hex << code << dec << "'\n";
    return false;
  }
  switch (type) {
  case file_v2:
    cerr << "not implemented" << endl;
    break;
  case file_v1: // FIXME
  case file_v3:
  case file_v4: {
    if (!read(fin,fh.v3)) return false;
    if (verbose>0)
      cout << "file_header = " << fh.v3 << endl;
    size_t i,j;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_gain)) return false;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_offset)) return false;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_coupling)) return false;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_saved)) return false;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_min_amp_cut)) return false;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_in_range)) return false;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_satur_cut)) return false;
    for(i=0;i<nch;i++) if (!read(fin,ch[i].v3.c_label)) return false;
    if (verbose>0) {
      cout << "channel_header[" << nch << "] = {\n";
      for(i=0;i<nch;i++) cout << "  .[" << i << "] =" << ch[i].v3 << ",\n";
      cout << "}" << endl;
    }
    for(i=0,j=0;i<nch;i++) if (ch[i].v3.c_saved) j++;
    if (type==file_v3) nch = j; // recalc nch
    if (!fin.read(comment,1024)) return false; comment[1023]='\0';
    if (verbose>0)
      cout << "comment[] = '" << comment << "'" << endl;
    if (type==file_v3 || type==file_v4) {
      struct {
        char satCut;
        int nRejected;
      } xxx;
      if (!fin.read(&xxx,sizeof(xxx))) return false;
      if (verbose>0)
        cout << "extra: " << (int)xxx.satCut << ", " << xxx.nRejected << endl;
    }
  } break;
  default:
    ;
  };
  return true;
}
//izstream& read(izstream &is, uint32_t &m) { cerr << __func__ << endl; return is.read(&m,sizeof(m)); }
bool z3file::read_next_event(RED::Event &event)
{
  if (!fin) return false;
  uint32_t code;
  event.Clear();
  //evpos[irec] = fin.tell(); // store pos
  if (!read(fin,code)) return false; // event_id
  if (verbose>2)
    cout << "  .event_id[" << ievent << "] = '" << hex << code 
         << "', // at 0x" << fin.tell() << dec << endl;
  if (code==0x31303045) { // E001
    switch (type) {
    case file_v1: {
      event_header_v1 eh;
      if (!read(fin,eh)) return false;
      if (verbose>2) cout << "  .eh = " << eh << endl;
      event.fRunNumber = 0; // actually not contained
      event.fEventNumber = ++ievent;
      event.fNumChannels = nch;
      //event.fTriggerCount = 0;
      event.fTriggerTime.SetSec(eh.timeStampHi);
      event.fTriggerTime.SetNanoSec(eh.timeStampLo);
      size_t i,j, length, len, nsamples = fh.v1.t_samples;
      data_channel_header_v1 dch;
      int8_t t[nsamples];
      for(i=0;i<nch;i++) {
        if (!read(fin,dch)) return false;
        length = nsamples;//dch.SamplesPerSeg*dch.nSegments;
        len = (nsamples<length)?nsamples:length;
        if (verbose>2)
          cout << "  .ch[" << i << "] = " << dch << " " << len << endl;
        RED::Waveform *wf = event.GetNewWaveform();
        wf->fChannel = i;
        wf->fIsCompressed = false;
        wf->fIsModified = 0;
        wf->fNumSamples = length;
        wf->fPeriod = fh.v3.t_sampling;
        wf->fDelay = fh.v3.t_delay;
        wf->fGain = dch.vGain;
        wf->fOffset = -dch.vOffset-128*dch.vGain;
        wf->fPlaceOfTrigger = -fh.v3.t_delay/fh.v3.t_sampling;
        wf->fBitWidth = 8;
        wf->fNameOfWaveform = ch[i].v3.c_label;
        if (!read(fin,t[0],len)) return false; 
        if (length>len) fin.seek(length-len,SEEK_CUR);
        wf->fData.resize(wf->fNumSamples);
        for(j=0;j<len;j++) wf->fData[j] = t[j]+128;
      }
    } break;
    case file_v2:
      cerr << "not implemented" << endl;
      break;
    case file_v3:
    case file_v4: {
      event_header_v3 eh;
      if (!read(fin,eh)) return false;
      if (verbose>2) cout << "  .eh = " << eh << endl;
      event.fRunNumber = 0; // actually not contained
      event.fEventNumber = ++ievent;
      event.fNumChannels = nch;
      //event.fTriggerCount = 0;
      event.fTriggerTime.SetSec(eh.evTime);
      event.fTriggerTime.SetNanoSec(int(eh.hp_time*1.e3));
      event.fTriggerSource = 0;
      event.fIsMonteCarloEvent = false;
      uint32_t syncstamp;
      if (type==file_v4) read(fin,syncstamp);
      size_t i,j, length, len, nsamples = fh.v3.t_samples;
      data_channel_header_v3 dch;
      int8_t t[nsamples];
      //uint32_t tt[nsamples];
      for(i=0;i<nch;i++) {
        if (!read(fin,dch)) return false;
        length = dch.SamplesPerSeg*dch.nSegments;
        len = (nsamples<length)?nsamples:length;
        if (verbose>2)
          cout << "  .ch[" << i << "] = " << dch << " " << len << endl;
        RED::Waveform *wf = event.GetNewWaveform();
        wf->fChannel = i;
        wf->fIsCompressed = false;
        wf->fIsModified = 0;
        wf->fNumSamples = length;
        wf->fPeriod = fh.v3.t_sampling;
        wf->fDelay = fh.v3.t_delay;
        wf->fGain = dch.vGain;
        wf->fOffset = -dch.vOffset-128*dch.vGain;
        wf->fPlaceOfTrigger = -fh.v3.t_delay/fh.v3.t_sampling;
        wf->fBitWidth = 8;
        wf->fNameOfWaveform = ch[i].v3.c_label;
        if (!read(fin,t[0],len)) return false; 
        if (length>len) fin.seek(length-len,SEEK_CUR);
        wf->fData.resize(wf->fNumSamples);
        for(j=0;j<len;j++) wf->fData[j] = t[j]+128;
      }
    } break;
    default:
      ;
    }
  } else {
    cerr << __func__ << ": unknown event_id: '" << hex << code << dec << "'\n";
    return false;
  }
  return true;
}
void z3file::set_type(z3type t)
{
  if(file_none<=t && t<=file_v4) type = t; 
  switch (type) {
  case file_v1: nch = 64; break;
  case file_v2: nch = 16; break;
  case file_v3: nch = 64; break;
  case file_v4: nch = 64; break;
  default: ;
  }
  // FIXME convert structes?
}
bool z3file::write_header()
{
  if (!fout) return false;
  uint32_t code = 0;
  switch (type) {
  case file_v1: code = 0x00313041; break; // A01\0=v1
  case file_v2: code = 0x00323041; break; // A02\0=v2
  case file_v3: code = 0x00333041; break; // A03\0=v3
  default: ;
  }
  if (!code || !write(fout,code)) return false; // head_id
  if (verbose>2)
    cout << "head_id[] = '" << hex << code << dec << "'" << endl;
  switch (type) {
  case file_v2:
    cerr << __func__ << ": file_v2 not implemented" << endl;
    break;
  case file_v1: // FIXME
  case file_v3: {
    if (!write(fout,fh.v3)) return false;
    if (verbose>0)
      cout << "file_header = " << fh.v3 << endl;
    size_t i,j;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_gain)) return false;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_offset)) return false;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_coupling)) return false;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_saved)) return false;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_min_amp_cut)) return false;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_in_range)) return false;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_satur_cut)) return false;
    for(i=0;i<64;i++) if (!write(fout,ch[i].v3.c_label)) return false;
    if (verbose>0) {
      cout << "channel_header[" << nch << "] = {\n";
      for(i=0;i<nch;i++) cout << "  .[" << i << "] =" << ch[i].v3 << ",\n";
      cout << "}" << endl;
    }
    for(i=0,j=0;i<nch;i++) if (ch[i].v3.c_saved) j++;
    if (type==file_v3) nch = j; // recalc nch
    comment[1023]='\0'; if (!fout.write(comment,1024)) return false;
    if (verbose>0)
      cout << "comment[] = '" << comment << "'" << endl;
    if (type==file_v3) {
      struct {
        char satCut;
        int nRejected;
      } xxx = { 0, 0};
      if (!fout.write(&xxx,sizeof(xxx))) return false;
      if (verbose>0)
        cout << "extra: " << (int)xxx.satCut << ", " << xxx.nRejected << endl;
    }
  } break;
  default:
    ;
  };
  return true;
}
bool z3file::write_event(const RED::Event &event)
{
  return false;
/*
  if (!fout) return false;
  uint32_t code;
  code = 0x31303045; // E001
  if (!write(fout,code)) return false; // event_id
  if (verbose>2)
    cout << "  .event_id[" << ievent << "] = '" << hex << code 
         << "', // at 0x" << fout.tell() << dec << endl;
  switch (type) {
  case file_v1: {
    if (!write(fout,event.eh.v1)) return false;
    / *ievent++; event.ievent = ievent;
    if (verbose>2) cout << "  .eh = " << event.eh.v1 << endl;
    size_t i;
    data_channel_header_v1 dch;
    for(i=0;i<nch;i++) {
      read(fin,dch);
      size_t len = dch.SamplesPerSeg*dch.nSegments;
      if (verbose>2)
        cout << "  .ch[" << i << "] = " << dch << " " << len << endl;
      gzseek(fin.fp,len,SEEK_CUR);
      //gzread(fp,tt,t[0]);
      //for(k=0;k<t[0];k++) if (j<31) th[k]+=tt[k]; else tl[k]+=tt[k];
      }* /
  } break;
  case file_v2:
    cerr << "not implemented" << endl;
    break;
  case file_v3: {
    if (!write(fout,event.eh.v3)) return false;
    ievent++; //event.ievent = ievent;
    if (verbose>2) cout << "  .eh = " << event.eh.v3 << endl;
    size_t i,j, length, len, nsamples = fh.v3.t_samples;
    data_channel_header_v3 dch;
    int8_t t[nsamples];
    //uint32_t tt[nsamples];
    for(i=0;i<nch;i++) {
      dch.SamplesPerSeg = fh.v3.t_samples;
      dch.iFirstPoint = 0;
      dch.sampTime = fh.v3.t_sampling;
      dch.vGain = event.channel[i].vbin;
      dch.vOffset = -event.channel[i].voffset-128*dch.vGain;
      dch.nSegments = 1;
      dch.nbrAvgWforms = 0;
      dch.actualTriggersInAcqLo = 0;
      dch.actualTriggersInAcqHi = 0;
      if (!write(fout,dch)) return false;
      length = dch.SamplesPerSeg*dch.nSegments;
      len = (nsamples<length)?nsamples:length;
      if (verbose>2)
        cout << "  .ch[" << i << "] = " << dch << " " << len << endl;
      for(j=0;j<len;j++) t[j] = event.channel[i].hs[j]-128;
      if (!write(fout,t[0],len)) return false; 
      //fin.seek(length-len,SEEK_CUR);
    }
  } break;
  default:
    ;
  }
  return true;
*/
}

