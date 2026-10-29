// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME EventDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/home/lev/Документы/REDOffline/REDEvent/Cluster.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/Event.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/MonteCarlo.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/ProcessingInfo.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/Pulse.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/RunInfo.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/Waveform.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_REDcLcLPulse(void *p = nullptr);
   static void *newArray_REDcLcLPulse(Long_t size, void *p);
   static void delete_REDcLcLPulse(void *p);
   static void deleteArray_REDcLcLPulse(void *p);
   static void destruct_REDcLcLPulse(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::Pulse*)
   {
      ::RED::Pulse *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::Pulse >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::Pulse", ::RED::Pulse::Class_Version(), "REDEvent/Pulse.hh", 19,
                  typeid(::RED::Pulse), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::Pulse::Dictionary, isa_proxy, 4,
                  sizeof(::RED::Pulse) );
      instance.SetNew(&new_REDcLcLPulse);
      instance.SetNewArray(&newArray_REDcLcLPulse);
      instance.SetDelete(&delete_REDcLcLPulse);
      instance.SetDeleteArray(&deleteArray_REDcLcLPulse);
      instance.SetDestructor(&destruct_REDcLcLPulse);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::Pulse*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::Pulse*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::Pulse*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLCluster(void *p = nullptr);
   static void *newArray_REDcLcLCluster(Long_t size, void *p);
   static void delete_REDcLcLCluster(void *p);
   static void deleteArray_REDcLcLCluster(void *p);
   static void destruct_REDcLcLCluster(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::Cluster*)
   {
      ::RED::Cluster *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::Cluster >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::Cluster", ::RED::Cluster::Class_Version(), "REDEvent/Cluster.hh", 17,
                  typeid(::RED::Cluster), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::Cluster::Dictionary, isa_proxy, 4,
                  sizeof(::RED::Cluster) );
      instance.SetNew(&new_REDcLcLCluster);
      instance.SetNewArray(&newArray_REDcLcLCluster);
      instance.SetDelete(&delete_REDcLcLCluster);
      instance.SetDeleteArray(&deleteArray_REDcLcLCluster);
      instance.SetDestructor(&destruct_REDcLcLCluster);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::Cluster*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::Cluster*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::Cluster*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLWaveform(void *p = nullptr);
   static void *newArray_REDcLcLWaveform(Long_t size, void *p);
   static void delete_REDcLcLWaveform(void *p);
   static void deleteArray_REDcLcLWaveform(void *p);
   static void destruct_REDcLcLWaveform(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::Waveform*)
   {
      ::RED::Waveform *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::Waveform >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::Waveform", ::RED::Waveform::Class_Version(), "REDEvent/Waveform.hh", 23,
                  typeid(::RED::Waveform), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::Waveform::Dictionary, isa_proxy, 4,
                  sizeof(::RED::Waveform) );
      instance.SetNew(&new_REDcLcLWaveform);
      instance.SetNewArray(&newArray_REDcLcLWaveform);
      instance.SetDelete(&delete_REDcLcLWaveform);
      instance.SetDeleteArray(&deleteArray_REDcLcLWaveform);
      instance.SetDestructor(&destruct_REDcLcLWaveform);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::Waveform*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::Waveform*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::Waveform*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLEvent(void *p = nullptr);
   static void *newArray_REDcLcLEvent(Long_t size, void *p);
   static void delete_REDcLcLEvent(void *p);
   static void deleteArray_REDcLcLEvent(void *p);
   static void destruct_REDcLcLEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::Event*)
   {
      ::RED::Event *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::Event >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::Event", ::RED::Event::Class_Version(), "REDEvent/Event.hh", 33,
                  typeid(::RED::Event), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::Event::Dictionary, isa_proxy, 4,
                  sizeof(::RED::Event) );
      instance.SetNew(&new_REDcLcLEvent);
      instance.SetNewArray(&newArray_REDcLcLEvent);
      instance.SetDelete(&delete_REDcLcLEvent);
      instance.SetDeleteArray(&deleteArray_REDcLcLEvent);
      instance.SetDestructor(&destruct_REDcLcLEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::Event*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::Event*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::Event*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLProcessingInfo(void *p = nullptr);
   static void *newArray_REDcLcLProcessingInfo(Long_t size, void *p);
   static void delete_REDcLcLProcessingInfo(void *p);
   static void deleteArray_REDcLcLProcessingInfo(void *p);
   static void destruct_REDcLcLProcessingInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::ProcessingInfo*)
   {
      ::RED::ProcessingInfo *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::ProcessingInfo >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::ProcessingInfo", ::RED::ProcessingInfo::Class_Version(), "REDEvent/ProcessingInfo.hh", 13,
                  typeid(::RED::ProcessingInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::ProcessingInfo::Dictionary, isa_proxy, 4,
                  sizeof(::RED::ProcessingInfo) );
      instance.SetNew(&new_REDcLcLProcessingInfo);
      instance.SetNewArray(&newArray_REDcLcLProcessingInfo);
      instance.SetDelete(&delete_REDcLcLProcessingInfo);
      instance.SetDeleteArray(&deleteArray_REDcLcLProcessingInfo);
      instance.SetDestructor(&destruct_REDcLcLProcessingInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::ProcessingInfo*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::ProcessingInfo*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::ProcessingInfo*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLRunInfo(void *p = nullptr);
   static void *newArray_REDcLcLRunInfo(Long_t size, void *p);
   static void delete_REDcLcLRunInfo(void *p);
   static void deleteArray_REDcLcLRunInfo(void *p);
   static void destruct_REDcLcLRunInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::RunInfo*)
   {
      ::RED::RunInfo *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::RunInfo >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::RunInfo", ::RED::RunInfo::Class_Version(), "REDEvent/RunInfo.hh", 10,
                  typeid(::RED::RunInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::RunInfo::Dictionary, isa_proxy, 4,
                  sizeof(::RED::RunInfo) );
      instance.SetNew(&new_REDcLcLRunInfo);
      instance.SetNewArray(&newArray_REDcLcLRunInfo);
      instance.SetDelete(&delete_REDcLcLRunInfo);
      instance.SetDeleteArray(&deleteArray_REDcLcLRunInfo);
      instance.SetDestructor(&destruct_REDcLcLRunInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::RunInfo*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::RunInfo*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::RunInfo*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr Pulse::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Pulse::Class_Name()
{
   return "RED::Pulse";
}

//______________________________________________________________________________
const char *Pulse::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Pulse*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Pulse::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Pulse*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Pulse::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Pulse*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Pulse::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Pulse*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr Cluster::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Cluster::Class_Name()
{
   return "RED::Cluster";
}

//______________________________________________________________________________
const char *Cluster::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Cluster*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Cluster::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Cluster*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Cluster::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Cluster*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Cluster::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Cluster*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr Waveform::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Waveform::Class_Name()
{
   return "RED::Waveform";
}

//______________________________________________________________________________
const char *Waveform::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Waveform*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Waveform::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Waveform*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Waveform::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Waveform*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Waveform::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Waveform*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr Event::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Event::Class_Name()
{
   return "RED::Event";
}

//______________________________________________________________________________
const char *Event::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Event*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Event::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Event*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Event::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Event*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Event::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Event*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr ProcessingInfo::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ProcessingInfo::Class_Name()
{
   return "RED::ProcessingInfo";
}

//______________________________________________________________________________
const char *ProcessingInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingInfo*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ProcessingInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingInfo*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ProcessingInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingInfo*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ProcessingInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingInfo*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr RunInfo::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RunInfo::Class_Name()
{
   return "RED::RunInfo";
}

//______________________________________________________________________________
const char *RunInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::RunInfo*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RunInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::RunInfo*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RunInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::RunInfo*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RunInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::RunInfo*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void Pulse::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::Pulse.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::Pulse::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::Pulse::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLPulse(void *p) {
      return  p ? new(p) ::RED::Pulse : new ::RED::Pulse;
   }
   static void *newArray_REDcLcLPulse(Long_t nElements, void *p) {
      return p ? new(p) ::RED::Pulse[nElements] : new ::RED::Pulse[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLPulse(void *p) {
      delete (static_cast<::RED::Pulse*>(p));
   }
   static void deleteArray_REDcLcLPulse(void *p) {
      delete [] (static_cast<::RED::Pulse*>(p));
   }
   static void destruct_REDcLcLPulse(void *p) {
      typedef ::RED::Pulse current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::Pulse

namespace RED {
//______________________________________________________________________________
void Cluster::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::Cluster.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::Cluster::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::Cluster::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLCluster(void *p) {
      return  p ? new(p) ::RED::Cluster : new ::RED::Cluster;
   }
   static void *newArray_REDcLcLCluster(Long_t nElements, void *p) {
      return p ? new(p) ::RED::Cluster[nElements] : new ::RED::Cluster[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLCluster(void *p) {
      delete (static_cast<::RED::Cluster*>(p));
   }
   static void deleteArray_REDcLcLCluster(void *p) {
      delete [] (static_cast<::RED::Cluster*>(p));
   }
   static void destruct_REDcLcLCluster(void *p) {
      typedef ::RED::Cluster current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::Cluster

namespace RED {
//______________________________________________________________________________
void Waveform::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::Waveform.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::Waveform::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::Waveform::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLWaveform(void *p) {
      return  p ? new(p) ::RED::Waveform : new ::RED::Waveform;
   }
   static void *newArray_REDcLcLWaveform(Long_t nElements, void *p) {
      return p ? new(p) ::RED::Waveform[nElements] : new ::RED::Waveform[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLWaveform(void *p) {
      delete (static_cast<::RED::Waveform*>(p));
   }
   static void deleteArray_REDcLcLWaveform(void *p) {
      delete [] (static_cast<::RED::Waveform*>(p));
   }
   static void destruct_REDcLcLWaveform(void *p) {
      typedef ::RED::Waveform current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::Waveform

namespace RED {
//______________________________________________________________________________
void Event::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::Event.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::Event::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::Event::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLEvent(void *p) {
      return  p ? new(p) ::RED::Event : new ::RED::Event;
   }
   static void *newArray_REDcLcLEvent(Long_t nElements, void *p) {
      return p ? new(p) ::RED::Event[nElements] : new ::RED::Event[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLEvent(void *p) {
      delete (static_cast<::RED::Event*>(p));
   }
   static void deleteArray_REDcLcLEvent(void *p) {
      delete [] (static_cast<::RED::Event*>(p));
   }
   static void destruct_REDcLcLEvent(void *p) {
      typedef ::RED::Event current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::Event

namespace RED {
//______________________________________________________________________________
void ProcessingInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::ProcessingInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::ProcessingInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::ProcessingInfo::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLProcessingInfo(void *p) {
      return  p ? new(p) ::RED::ProcessingInfo : new ::RED::ProcessingInfo;
   }
   static void *newArray_REDcLcLProcessingInfo(Long_t nElements, void *p) {
      return p ? new(p) ::RED::ProcessingInfo[nElements] : new ::RED::ProcessingInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLProcessingInfo(void *p) {
      delete (static_cast<::RED::ProcessingInfo*>(p));
   }
   static void deleteArray_REDcLcLProcessingInfo(void *p) {
      delete [] (static_cast<::RED::ProcessingInfo*>(p));
   }
   static void destruct_REDcLcLProcessingInfo(void *p) {
      typedef ::RED::ProcessingInfo current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::ProcessingInfo

namespace RED {
//______________________________________________________________________________
void RunInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::RunInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::RunInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::RunInfo::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLRunInfo(void *p) {
      return  p ? new(p) ::RED::RunInfo : new ::RED::RunInfo;
   }
   static void *newArray_REDcLcLRunInfo(Long_t nElements, void *p) {
      return p ? new(p) ::RED::RunInfo[nElements] : new ::RED::RunInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLRunInfo(void *p) {
      delete (static_cast<::RED::RunInfo*>(p));
   }
   static void deleteArray_REDcLcLRunInfo(void *p) {
      delete [] (static_cast<::RED::RunInfo*>(p));
   }
   static void destruct_REDcLcLRunInfo(void *p) {
      typedef ::RED::RunInfo current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::RunInfo

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = nullptr);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 458,
                  typeid(vector<string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<string>","std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<string>*>(nullptr))->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete (static_cast<vector<string>*>(p));
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] (static_cast<vector<string>*>(p));
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = nullptr);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 458,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<float>","std::vector<float, std::allocator<float> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr))->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete (static_cast<vector<float>*>(p));
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] (static_cast<vector<float>*>(p));
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_EventDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_EventDict) = RecordReadRules_EventDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_EventDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_EventDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/REDEvent/Cluster.hh",
"/home/lev/Документы/REDOffline/REDEvent/Event.hh",
"/home/lev/Документы/REDOffline/REDEvent/MonteCarlo.hh",
"/home/lev/Документы/REDOffline/REDEvent/ProcessingInfo.hh",
"/home/lev/Документы/REDOffline/REDEvent/Pulse.hh",
"/home/lev/Документы/REDOffline/REDEvent/RunInfo.hh",
"/home/lev/Документы/REDOffline/REDEvent/Waveform.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/REDEvent/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "EventDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$REDEvent/Pulse.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDEvent/Cluster.hh")))  Pulse;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDEvent/Cluster.hh")))  Cluster;}
namespace RED{class  __attribute__((annotate("$clingAutoload$REDEvent/Waveform.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDEvent/Event.hh")))  Waveform;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDEvent/Event.hh")))  Event;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDEvent/ProcessingInfo.hh")))  ProcessingInfo;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDEvent/RunInfo.hh")))  RunInfo;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "EventDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/REDEvent/Cluster.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/Event.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/MonteCarlo.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/ProcessingInfo.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/Pulse.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/RunInfo.hh"
#include "/home/lev/Документы/REDOffline/REDEvent/Waveform.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::Cluster", payloadCode, "@",
"RED::Event", payloadCode, "@",
"RED::ProcessingInfo", payloadCode, "@",
"RED::Pulse", payloadCode, "@",
"RED::RunInfo", payloadCode, "@",
"RED::Waveform", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("EventDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_EventDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_EventDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_EventDict() {
  TriggerDictionaryInitialization_EventDict_Impl();
}
