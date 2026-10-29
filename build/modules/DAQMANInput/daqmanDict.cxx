// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME daqmanDict
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
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Baseline.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/EventData.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Pulse.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/PulseFit.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Roi.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Spe.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/SumOfIntegral.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/TOF.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Unspikes.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/runinfo.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *pairlEstringcOstringgR_Dictionary();
   static void pairlEstringcOstringgR_TClassManip(TClass*);
   static void *new_pairlEstringcOstringgR(void *p = nullptr);
   static void *newArray_pairlEstringcOstringgR(Long_t size, void *p);
   static void delete_pairlEstringcOstringgR(void *p);
   static void deleteArray_pairlEstringcOstringgR(void *p);
   static void destruct_pairlEstringcOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<string,string>*)
   {
      pair<string,string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<string,string>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<string,string>", "string", 302,
                  typeid(pair<string,string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEstringcOstringgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<string,string>) );
      instance.SetNew(&new_pairlEstringcOstringgR);
      instance.SetNewArray(&newArray_pairlEstringcOstringgR);
      instance.SetDelete(&delete_pairlEstringcOstringgR);
      instance.SetDeleteArray(&deleteArray_pairlEstringcOstringgR);
      instance.SetDestructor(&destruct_pairlEstringcOstringgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("pair<string,string>","pair<std::string,std::string>"));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("pair<string,string>","std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const pair<string,string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEstringcOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const pair<string,string>*>(nullptr))->GetClass();
      pairlEstringcOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEstringcOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_Spe(void *p = nullptr);
   static void *newArray_Spe(Long_t size, void *p);
   static void delete_Spe(void *p);
   static void deleteArray_Spe(void *p);
   static void destruct_Spe(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Spe*)
   {
      ::Spe *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Spe >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Spe", ::Spe::Class_Version(), "Spe.hh", 17,
                  typeid(::Spe), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Spe::Dictionary, isa_proxy, 4,
                  sizeof(::Spe) );
      instance.SetNew(&new_Spe);
      instance.SetNewArray(&newArray_Spe);
      instance.SetDelete(&delete_Spe);
      instance.SetDeleteArray(&deleteArray_Spe);
      instance.SetDestructor(&destruct_Spe);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Spe*)
   {
      return GenerateInitInstanceLocal(static_cast<::Spe*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Spe*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Baseline(void *p = nullptr);
   static void *newArray_Baseline(Long_t size, void *p);
   static void delete_Baseline(void *p);
   static void deleteArray_Baseline(void *p);
   static void destruct_Baseline(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Baseline*)
   {
      ::Baseline *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Baseline >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Baseline", ::Baseline::Class_Version(), "Baseline.hh", 18,
                  typeid(::Baseline), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Baseline::Dictionary, isa_proxy, 4,
                  sizeof(::Baseline) );
      instance.SetNew(&new_Baseline);
      instance.SetNewArray(&newArray_Baseline);
      instance.SetDelete(&delete_Baseline);
      instance.SetDeleteArray(&deleteArray_Baseline);
      instance.SetDestructor(&destruct_Baseline);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Baseline*)
   {
      return GenerateInitInstanceLocal(static_cast<::Baseline*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Baseline*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_PulseFit(void *p = nullptr);
   static void *newArray_PulseFit(Long_t size, void *p);
   static void delete_PulseFit(void *p);
   static void deleteArray_PulseFit(void *p);
   static void destruct_PulseFit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PulseFit*)
   {
      ::PulseFit *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::PulseFit >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("PulseFit", ::PulseFit::Class_Version(), "PulseFit.hh", 21,
                  typeid(::PulseFit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::PulseFit::Dictionary, isa_proxy, 4,
                  sizeof(::PulseFit) );
      instance.SetNew(&new_PulseFit);
      instance.SetNewArray(&newArray_PulseFit);
      instance.SetDelete(&delete_PulseFit);
      instance.SetDeleteArray(&deleteArray_PulseFit);
      instance.SetDestructor(&destruct_PulseFit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PulseFit*)
   {
      return GenerateInitInstanceLocal(static_cast<::PulseFit*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::PulseFit*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Pulse(void *p = nullptr);
   static void *newArray_Pulse(Long_t size, void *p);
   static void delete_Pulse(void *p);
   static void deleteArray_Pulse(void *p);
   static void destruct_Pulse(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Pulse*)
   {
      ::Pulse *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Pulse >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Pulse", ::Pulse::Class_Version(), "Pulse.hh", 20,
                  typeid(::Pulse), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Pulse::Dictionary, isa_proxy, 4,
                  sizeof(::Pulse) );
      instance.SetNew(&new_Pulse);
      instance.SetNewArray(&newArray_Pulse);
      instance.SetDelete(&delete_Pulse);
      instance.SetDeleteArray(&deleteArray_Pulse);
      instance.SetDestructor(&destruct_Pulse);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Pulse*)
   {
      return GenerateInitInstanceLocal(static_cast<::Pulse*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Pulse*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Unspikes(void *p = nullptr);
   static void *newArray_Unspikes(Long_t size, void *p);
   static void delete_Unspikes(void *p);
   static void deleteArray_Unspikes(void *p);
   static void destruct_Unspikes(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Unspikes*)
   {
      ::Unspikes *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Unspikes >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Unspikes", ::Unspikes::Class_Version(), "Unspikes.hh", 17,
                  typeid(::Unspikes), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Unspikes::Dictionary, isa_proxy, 4,
                  sizeof(::Unspikes) );
      instance.SetNew(&new_Unspikes);
      instance.SetNewArray(&newArray_Unspikes);
      instance.SetDelete(&delete_Unspikes);
      instance.SetDeleteArray(&deleteArray_Unspikes);
      instance.SetDestructor(&destruct_Unspikes);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Unspikes*)
   {
      return GenerateInitInstanceLocal(static_cast<::Unspikes*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Unspikes*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Roi(void *p = nullptr);
   static void *newArray_Roi(Long_t size, void *p);
   static void delete_Roi(void *p);
   static void deleteArray_Roi(void *p);
   static void destruct_Roi(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Roi*)
   {
      ::Roi *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Roi >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Roi", ::Roi::Class_Version(), "Roi.hh", 18,
                  typeid(::Roi), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Roi::Dictionary, isa_proxy, 4,
                  sizeof(::Roi) );
      instance.SetNew(&new_Roi);
      instance.SetNewArray(&newArray_Roi);
      instance.SetDelete(&delete_Roi);
      instance.SetDeleteArray(&deleteArray_Roi);
      instance.SetDestructor(&destruct_Roi);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Roi*)
   {
      return GenerateInitInstanceLocal(static_cast<::Roi*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Roi*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TOF(void *p = nullptr);
   static void *newArray_TOF(Long_t size, void *p);
   static void delete_TOF(void *p);
   static void deleteArray_TOF(void *p);
   static void destruct_TOF(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TOF*)
   {
      ::TOF *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TOF >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TOF", ::TOF::Class_Version(), "TOF.hh", 16,
                  typeid(::TOF), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TOF::Dictionary, isa_proxy, 4,
                  sizeof(::TOF) );
      instance.SetNew(&new_TOF);
      instance.SetNewArray(&newArray_TOF);
      instance.SetDelete(&delete_TOF);
      instance.SetDeleteArray(&deleteArray_TOF);
      instance.SetDestructor(&destruct_TOF);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TOF*)
   {
      return GenerateInitInstanceLocal(static_cast<::TOF*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TOF*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ChannelData(void *p = nullptr);
   static void *newArray_ChannelData(Long_t size, void *p);
   static void delete_ChannelData(void *p);
   static void deleteArray_ChannelData(void *p);
   static void destruct_ChannelData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ChannelData*)
   {
      ::ChannelData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ChannelData >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("ChannelData", ::ChannelData::Class_Version(), "ChannelData.hh", 32,
                  typeid(::ChannelData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::ChannelData::Dictionary, isa_proxy, 4,
                  sizeof(::ChannelData) );
      instance.SetNew(&new_ChannelData);
      instance.SetNewArray(&newArray_ChannelData);
      instance.SetDelete(&delete_ChannelData);
      instance.SetDeleteArray(&deleteArray_ChannelData);
      instance.SetDestructor(&destruct_ChannelData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ChannelData*)
   {
      return GenerateInitInstanceLocal(static_cast<::ChannelData*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::ChannelData*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SumOfIntegral(void *p = nullptr);
   static void *newArray_SumOfIntegral(Long_t size, void *p);
   static void delete_SumOfIntegral(void *p);
   static void deleteArray_SumOfIntegral(void *p);
   static void destruct_SumOfIntegral(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SumOfIntegral*)
   {
      ::SumOfIntegral *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SumOfIntegral >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("SumOfIntegral", ::SumOfIntegral::Class_Version(), "SumOfIntegral.hh", 20,
                  typeid(::SumOfIntegral), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SumOfIntegral::Dictionary, isa_proxy, 4,
                  sizeof(::SumOfIntegral) );
      instance.SetNew(&new_SumOfIntegral);
      instance.SetNewArray(&newArray_SumOfIntegral);
      instance.SetDelete(&delete_SumOfIntegral);
      instance.SetDeleteArray(&deleteArray_SumOfIntegral);
      instance.SetDestructor(&destruct_SumOfIntegral);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SumOfIntegral*)
   {
      return GenerateInitInstanceLocal(static_cast<::SumOfIntegral*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::SumOfIntegral*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_EventData(void *p = nullptr);
   static void *newArray_EventData(Long_t size, void *p);
   static void delete_EventData(void *p);
   static void deleteArray_EventData(void *p);
   static void destruct_EventData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EventData*)
   {
      ::EventData *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EventData >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("EventData", ::EventData::Class_Version(), "EventData.hh", 28,
                  typeid(::EventData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::EventData::Dictionary, isa_proxy, 4,
                  sizeof(::EventData) );
      instance.SetNew(&new_EventData);
      instance.SetNewArray(&newArray_EventData);
      instance.SetDelete(&delete_EventData);
      instance.SetDeleteArray(&deleteArray_EventData);
      instance.SetDestructor(&destruct_EventData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EventData*)
   {
      return GenerateInitInstanceLocal(static_cast<::EventData*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::EventData*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_runinfo(void *p = nullptr);
   static void *newArray_runinfo(Long_t size, void *p);
   static void delete_runinfo(void *p);
   static void deleteArray_runinfo(void *p);
   static void destruct_runinfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::runinfo*)
   {
      ::runinfo *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::runinfo >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("runinfo", ::runinfo::Class_Version(), "runinfo.hh", 28,
                  typeid(::runinfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::runinfo::Dictionary, isa_proxy, 4,
                  sizeof(::runinfo) );
      instance.SetNew(&new_runinfo);
      instance.SetNewArray(&newArray_runinfo);
      instance.SetDelete(&delete_runinfo);
      instance.SetDeleteArray(&deleteArray_runinfo);
      instance.SetDestructor(&destruct_runinfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::runinfo*)
   {
      return GenerateInitInstanceLocal(static_cast<::runinfo*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::runinfo*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Spe::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Spe::Class_Name()
{
   return "Spe";
}

//______________________________________________________________________________
const char *Spe::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Spe*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Spe::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Spe*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Spe::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Spe*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Spe::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Spe*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Baseline::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Baseline::Class_Name()
{
   return "Baseline";
}

//______________________________________________________________________________
const char *Baseline::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Baseline*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Baseline::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Baseline*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Baseline::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Baseline*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Baseline::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Baseline*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr PulseFit::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PulseFit::Class_Name()
{
   return "PulseFit";
}

//______________________________________________________________________________
const char *PulseFit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PulseFit*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PulseFit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::PulseFit*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PulseFit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PulseFit*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PulseFit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::PulseFit*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Pulse::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Pulse::Class_Name()
{
   return "Pulse";
}

//______________________________________________________________________________
const char *Pulse::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pulse*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Pulse::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pulse*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Pulse::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pulse*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Pulse::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pulse*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Unspikes::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Unspikes::Class_Name()
{
   return "Unspikes";
}

//______________________________________________________________________________
const char *Unspikes::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Unspikes*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Unspikes::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Unspikes*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Unspikes::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Unspikes*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Unspikes::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Unspikes*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Roi::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Roi::Class_Name()
{
   return "Roi";
}

//______________________________________________________________________________
const char *Roi::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Roi*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Roi::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Roi*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Roi::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Roi*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Roi::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Roi*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TOF::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TOF::Class_Name()
{
   return "TOF";
}

//______________________________________________________________________________
const char *TOF::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TOF*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TOF::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TOF*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TOF::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TOF*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TOF::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TOF*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ChannelData::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ChannelData::Class_Name()
{
   return "ChannelData";
}

//______________________________________________________________________________
const char *ChannelData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ChannelData*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ChannelData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ChannelData*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ChannelData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ChannelData*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ChannelData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ChannelData*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SumOfIntegral::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SumOfIntegral::Class_Name()
{
   return "SumOfIntegral";
}

//______________________________________________________________________________
const char *SumOfIntegral::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SumOfIntegral*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SumOfIntegral::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SumOfIntegral*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SumOfIntegral::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SumOfIntegral*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SumOfIntegral::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SumOfIntegral*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr EventData::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventData::Class_Name()
{
   return "EventData";
}

//______________________________________________________________________________
const char *EventData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventData*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventData*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventData*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventData*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr runinfo::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *runinfo::Class_Name()
{
   return "runinfo";
}

//______________________________________________________________________________
const char *runinfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::runinfo*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int runinfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::runinfo*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *runinfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::runinfo*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *runinfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::runinfo*)nullptr)->GetClass(); }
   return fgIsA;
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEstringcOstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) pair<string,string> : new pair<string,string>;
   }
   static void *newArray_pairlEstringcOstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) pair<string,string>[nElements] : new pair<string,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEstringcOstringgR(void *p) {
      delete (static_cast<pair<string,string>*>(p));
   }
   static void deleteArray_pairlEstringcOstringgR(void *p) {
      delete [] (static_cast<pair<string,string>*>(p));
   }
   static void destruct_pairlEstringcOstringgR(void *p) {
      typedef pair<string,string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class pair<string,string>

//______________________________________________________________________________
void Spe::Streamer(TBuffer &R__b)
{
   // Stream an object of class Spe.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Spe::Class(),this);
   } else {
      R__b.WriteClassBuffer(Spe::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Spe(void *p) {
      return  p ? new(p) ::Spe : new ::Spe;
   }
   static void *newArray_Spe(Long_t nElements, void *p) {
      return p ? new(p) ::Spe[nElements] : new ::Spe[nElements];
   }
   // Wrapper around operator delete
   static void delete_Spe(void *p) {
      delete (static_cast<::Spe*>(p));
   }
   static void deleteArray_Spe(void *p) {
      delete [] (static_cast<::Spe*>(p));
   }
   static void destruct_Spe(void *p) {
      typedef ::Spe current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Spe

//______________________________________________________________________________
void Baseline::Streamer(TBuffer &R__b)
{
   // Stream an object of class Baseline.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Baseline::Class(),this);
   } else {
      R__b.WriteClassBuffer(Baseline::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Baseline(void *p) {
      return  p ? new(p) ::Baseline : new ::Baseline;
   }
   static void *newArray_Baseline(Long_t nElements, void *p) {
      return p ? new(p) ::Baseline[nElements] : new ::Baseline[nElements];
   }
   // Wrapper around operator delete
   static void delete_Baseline(void *p) {
      delete (static_cast<::Baseline*>(p));
   }
   static void deleteArray_Baseline(void *p) {
      delete [] (static_cast<::Baseline*>(p));
   }
   static void destruct_Baseline(void *p) {
      typedef ::Baseline current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Baseline

//______________________________________________________________________________
void PulseFit::Streamer(TBuffer &R__b)
{
   // Stream an object of class PulseFit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(PulseFit::Class(),this);
   } else {
      R__b.WriteClassBuffer(PulseFit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_PulseFit(void *p) {
      return  p ? new(p) ::PulseFit : new ::PulseFit;
   }
   static void *newArray_PulseFit(Long_t nElements, void *p) {
      return p ? new(p) ::PulseFit[nElements] : new ::PulseFit[nElements];
   }
   // Wrapper around operator delete
   static void delete_PulseFit(void *p) {
      delete (static_cast<::PulseFit*>(p));
   }
   static void deleteArray_PulseFit(void *p) {
      delete [] (static_cast<::PulseFit*>(p));
   }
   static void destruct_PulseFit(void *p) {
      typedef ::PulseFit current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::PulseFit

//______________________________________________________________________________
void Pulse::Streamer(TBuffer &R__b)
{
   // Stream an object of class Pulse.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Pulse::Class(),this);
   } else {
      R__b.WriteClassBuffer(Pulse::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Pulse(void *p) {
      return  p ? new(p) ::Pulse : new ::Pulse;
   }
   static void *newArray_Pulse(Long_t nElements, void *p) {
      return p ? new(p) ::Pulse[nElements] : new ::Pulse[nElements];
   }
   // Wrapper around operator delete
   static void delete_Pulse(void *p) {
      delete (static_cast<::Pulse*>(p));
   }
   static void deleteArray_Pulse(void *p) {
      delete [] (static_cast<::Pulse*>(p));
   }
   static void destruct_Pulse(void *p) {
      typedef ::Pulse current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Pulse

//______________________________________________________________________________
void Unspikes::Streamer(TBuffer &R__b)
{
   // Stream an object of class Unspikes.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Unspikes::Class(),this);
   } else {
      R__b.WriteClassBuffer(Unspikes::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Unspikes(void *p) {
      return  p ? new(p) ::Unspikes : new ::Unspikes;
   }
   static void *newArray_Unspikes(Long_t nElements, void *p) {
      return p ? new(p) ::Unspikes[nElements] : new ::Unspikes[nElements];
   }
   // Wrapper around operator delete
   static void delete_Unspikes(void *p) {
      delete (static_cast<::Unspikes*>(p));
   }
   static void deleteArray_Unspikes(void *p) {
      delete [] (static_cast<::Unspikes*>(p));
   }
   static void destruct_Unspikes(void *p) {
      typedef ::Unspikes current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Unspikes

//______________________________________________________________________________
void Roi::Streamer(TBuffer &R__b)
{
   // Stream an object of class Roi.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Roi::Class(),this);
   } else {
      R__b.WriteClassBuffer(Roi::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Roi(void *p) {
      return  p ? new(p) ::Roi : new ::Roi;
   }
   static void *newArray_Roi(Long_t nElements, void *p) {
      return p ? new(p) ::Roi[nElements] : new ::Roi[nElements];
   }
   // Wrapper around operator delete
   static void delete_Roi(void *p) {
      delete (static_cast<::Roi*>(p));
   }
   static void deleteArray_Roi(void *p) {
      delete [] (static_cast<::Roi*>(p));
   }
   static void destruct_Roi(void *p) {
      typedef ::Roi current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Roi

//______________________________________________________________________________
void TOF::Streamer(TBuffer &R__b)
{
   // Stream an object of class TOF.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TOF::Class(),this);
   } else {
      R__b.WriteClassBuffer(TOF::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TOF(void *p) {
      return  p ? new(p) ::TOF : new ::TOF;
   }
   static void *newArray_TOF(Long_t nElements, void *p) {
      return p ? new(p) ::TOF[nElements] : new ::TOF[nElements];
   }
   // Wrapper around operator delete
   static void delete_TOF(void *p) {
      delete (static_cast<::TOF*>(p));
   }
   static void deleteArray_TOF(void *p) {
      delete [] (static_cast<::TOF*>(p));
   }
   static void destruct_TOF(void *p) {
      typedef ::TOF current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TOF

//______________________________________________________________________________
void ChannelData::Streamer(TBuffer &R__b)
{
   // Stream an object of class ChannelData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ChannelData::Class(),this);
   } else {
      R__b.WriteClassBuffer(ChannelData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ChannelData(void *p) {
      return  p ? new(p) ::ChannelData : new ::ChannelData;
   }
   static void *newArray_ChannelData(Long_t nElements, void *p) {
      return p ? new(p) ::ChannelData[nElements] : new ::ChannelData[nElements];
   }
   // Wrapper around operator delete
   static void delete_ChannelData(void *p) {
      delete (static_cast<::ChannelData*>(p));
   }
   static void deleteArray_ChannelData(void *p) {
      delete [] (static_cast<::ChannelData*>(p));
   }
   static void destruct_ChannelData(void *p) {
      typedef ::ChannelData current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::ChannelData

//______________________________________________________________________________
void SumOfIntegral::Streamer(TBuffer &R__b)
{
   // Stream an object of class SumOfIntegral.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SumOfIntegral::Class(),this);
   } else {
      R__b.WriteClassBuffer(SumOfIntegral::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SumOfIntegral(void *p) {
      return  p ? new(p) ::SumOfIntegral : new ::SumOfIntegral;
   }
   static void *newArray_SumOfIntegral(Long_t nElements, void *p) {
      return p ? new(p) ::SumOfIntegral[nElements] : new ::SumOfIntegral[nElements];
   }
   // Wrapper around operator delete
   static void delete_SumOfIntegral(void *p) {
      delete (static_cast<::SumOfIntegral*>(p));
   }
   static void deleteArray_SumOfIntegral(void *p) {
      delete [] (static_cast<::SumOfIntegral*>(p));
   }
   static void destruct_SumOfIntegral(void *p) {
      typedef ::SumOfIntegral current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::SumOfIntegral

//______________________________________________________________________________
void EventData::Streamer(TBuffer &R__b)
{
   // Stream an object of class EventData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EventData::Class(),this);
   } else {
      R__b.WriteClassBuffer(EventData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_EventData(void *p) {
      return  p ? new(p) ::EventData : new ::EventData;
   }
   static void *newArray_EventData(Long_t nElements, void *p) {
      return p ? new(p) ::EventData[nElements] : new ::EventData[nElements];
   }
   // Wrapper around operator delete
   static void delete_EventData(void *p) {
      delete (static_cast<::EventData*>(p));
   }
   static void deleteArray_EventData(void *p) {
      delete [] (static_cast<::EventData*>(p));
   }
   static void destruct_EventData(void *p) {
      typedef ::EventData current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::EventData

//______________________________________________________________________________
void runinfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class runinfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(runinfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(runinfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_runinfo(void *p) {
      return  p ? new(p) ::runinfo : new ::runinfo;
   }
   static void *newArray_runinfo(Long_t nElements, void *p) {
      return p ? new(p) ::runinfo[nElements] : new ::runinfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_runinfo(void *p) {
      delete (static_cast<::runinfo*>(p));
   }
   static void deleteArray_runinfo(void *p) {
      delete [] (static_cast<::runinfo*>(p));
   }
   static void destruct_runinfo(void *p) {
      typedef ::runinfo current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::runinfo

namespace ROOT {
   static TClass *vectorlEpairlEintcOintgRsPgR_Dictionary();
   static void vectorlEpairlEintcOintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEintcOintgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEpairlEintcOintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEintcOintgRsPgR(void *p);
   static void deleteArray_vectorlEpairlEintcOintgRsPgR(void *p);
   static void destruct_vectorlEpairlEintcOintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<int,int> >*)
   {
      vector<pair<int,int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<int,int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<int,int> >", -2, "vector", 458,
                  typeid(vector<pair<int,int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlEintcOintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<pair<int,int> >) );
      instance.SetNew(&new_vectorlEpairlEintcOintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEintcOintgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEintcOintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEintcOintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEintcOintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<int,int> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<pair<int,int> >","std::vector<std::pair<int, int>, std::allocator<std::pair<int, int> > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<pair<int,int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEintcOintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<pair<int,int> >*>(nullptr))->GetClass();
      vectorlEpairlEintcOintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEintcOintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEintcOintgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<pair<int,int> > : new vector<pair<int,int> >;
   }
   static void *newArray_vectorlEpairlEintcOintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<pair<int,int> >[nElements] : new vector<pair<int,int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEintcOintgRsPgR(void *p) {
      delete (static_cast<vector<pair<int,int> >*>(p));
   }
   static void deleteArray_vectorlEpairlEintcOintgRsPgR(void *p) {
      delete [] (static_cast<vector<pair<int,int> >*>(p));
   }
   static void destruct_vectorlEpairlEintcOintgRsPgR(void *p) {
      typedef vector<pair<int,int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<pair<int,int> >

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = nullptr);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 458,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<double>","std::vector<double, std::allocator<double> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<double>*>(nullptr))->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete (static_cast<vector<double>*>(p));
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] (static_cast<vector<double>*>(p));
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlEUnspikesgR_Dictionary();
   static void vectorlEUnspikesgR_TClassManip(TClass*);
   static void *new_vectorlEUnspikesgR(void *p = nullptr);
   static void *newArray_vectorlEUnspikesgR(Long_t size, void *p);
   static void delete_vectorlEUnspikesgR(void *p);
   static void deleteArray_vectorlEUnspikesgR(void *p);
   static void destruct_vectorlEUnspikesgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Unspikes>*)
   {
      vector<Unspikes> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Unspikes>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Unspikes>", -2, "vector", 458,
                  typeid(vector<Unspikes>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEUnspikesgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Unspikes>) );
      instance.SetNew(&new_vectorlEUnspikesgR);
      instance.SetNewArray(&newArray_vectorlEUnspikesgR);
      instance.SetDelete(&delete_vectorlEUnspikesgR);
      instance.SetDeleteArray(&deleteArray_vectorlEUnspikesgR);
      instance.SetDestructor(&destruct_vectorlEUnspikesgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Unspikes> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<Unspikes>","std::vector<Unspikes, std::allocator<Unspikes> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<Unspikes>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEUnspikesgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<Unspikes>*>(nullptr))->GetClass();
      vectorlEUnspikesgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEUnspikesgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEUnspikesgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Unspikes> : new vector<Unspikes>;
   }
   static void *newArray_vectorlEUnspikesgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Unspikes>[nElements] : new vector<Unspikes>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEUnspikesgR(void *p) {
      delete (static_cast<vector<Unspikes>*>(p));
   }
   static void deleteArray_vectorlEUnspikesgR(void *p) {
      delete [] (static_cast<vector<Unspikes>*>(p));
   }
   static void destruct_vectorlEUnspikesgR(void *p) {
      typedef vector<Unspikes> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<Unspikes>

namespace ROOT {
   static TClass *vectorlESumOfIntegralgR_Dictionary();
   static void vectorlESumOfIntegralgR_TClassManip(TClass*);
   static void *new_vectorlESumOfIntegralgR(void *p = nullptr);
   static void *newArray_vectorlESumOfIntegralgR(Long_t size, void *p);
   static void delete_vectorlESumOfIntegralgR(void *p);
   static void deleteArray_vectorlESumOfIntegralgR(void *p);
   static void destruct_vectorlESumOfIntegralgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<SumOfIntegral>*)
   {
      vector<SumOfIntegral> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<SumOfIntegral>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<SumOfIntegral>", -2, "vector", 458,
                  typeid(vector<SumOfIntegral>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlESumOfIntegralgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<SumOfIntegral>) );
      instance.SetNew(&new_vectorlESumOfIntegralgR);
      instance.SetNewArray(&newArray_vectorlESumOfIntegralgR);
      instance.SetDelete(&delete_vectorlESumOfIntegralgR);
      instance.SetDeleteArray(&deleteArray_vectorlESumOfIntegralgR);
      instance.SetDestructor(&destruct_vectorlESumOfIntegralgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<SumOfIntegral> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<SumOfIntegral>","std::vector<SumOfIntegral, std::allocator<SumOfIntegral> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<SumOfIntegral>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlESumOfIntegralgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<SumOfIntegral>*>(nullptr))->GetClass();
      vectorlESumOfIntegralgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlESumOfIntegralgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlESumOfIntegralgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<SumOfIntegral> : new vector<SumOfIntegral>;
   }
   static void *newArray_vectorlESumOfIntegralgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<SumOfIntegral>[nElements] : new vector<SumOfIntegral>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlESumOfIntegralgR(void *p) {
      delete (static_cast<vector<SumOfIntegral>*>(p));
   }
   static void deleteArray_vectorlESumOfIntegralgR(void *p) {
      delete [] (static_cast<vector<SumOfIntegral>*>(p));
   }
   static void destruct_vectorlESumOfIntegralgR(void *p) {
      typedef vector<SumOfIntegral> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<SumOfIntegral>

namespace ROOT {
   static TClass *vectorlESpegR_Dictionary();
   static void vectorlESpegR_TClassManip(TClass*);
   static void *new_vectorlESpegR(void *p = nullptr);
   static void *newArray_vectorlESpegR(Long_t size, void *p);
   static void delete_vectorlESpegR(void *p);
   static void deleteArray_vectorlESpegR(void *p);
   static void destruct_vectorlESpegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Spe>*)
   {
      vector<Spe> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Spe>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Spe>", -2, "vector", 458,
                  typeid(vector<Spe>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlESpegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Spe>) );
      instance.SetNew(&new_vectorlESpegR);
      instance.SetNewArray(&newArray_vectorlESpegR);
      instance.SetDelete(&delete_vectorlESpegR);
      instance.SetDeleteArray(&deleteArray_vectorlESpegR);
      instance.SetDestructor(&destruct_vectorlESpegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Spe> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<Spe>","std::vector<Spe, std::allocator<Spe> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<Spe>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlESpegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<Spe>*>(nullptr))->GetClass();
      vectorlESpegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlESpegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlESpegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Spe> : new vector<Spe>;
   }
   static void *newArray_vectorlESpegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Spe>[nElements] : new vector<Spe>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlESpegR(void *p) {
      delete (static_cast<vector<Spe>*>(p));
   }
   static void deleteArray_vectorlESpegR(void *p) {
      delete [] (static_cast<vector<Spe>*>(p));
   }
   static void destruct_vectorlESpegR(void *p) {
      typedef vector<Spe> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<Spe>

namespace ROOT {
   static TClass *vectorlERoigR_Dictionary();
   static void vectorlERoigR_TClassManip(TClass*);
   static void *new_vectorlERoigR(void *p = nullptr);
   static void *newArray_vectorlERoigR(Long_t size, void *p);
   static void delete_vectorlERoigR(void *p);
   static void deleteArray_vectorlERoigR(void *p);
   static void destruct_vectorlERoigR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Roi>*)
   {
      vector<Roi> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Roi>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Roi>", -2, "vector", 458,
                  typeid(vector<Roi>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlERoigR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Roi>) );
      instance.SetNew(&new_vectorlERoigR);
      instance.SetNewArray(&newArray_vectorlERoigR);
      instance.SetDelete(&delete_vectorlERoigR);
      instance.SetDeleteArray(&deleteArray_vectorlERoigR);
      instance.SetDestructor(&destruct_vectorlERoigR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Roi> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<Roi>","std::vector<Roi, std::allocator<Roi> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<Roi>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERoigR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<Roi>*>(nullptr))->GetClass();
      vectorlERoigR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERoigR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERoigR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Roi> : new vector<Roi>;
   }
   static void *newArray_vectorlERoigR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Roi>[nElements] : new vector<Roi>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERoigR(void *p) {
      delete (static_cast<vector<Roi>*>(p));
   }
   static void deleteArray_vectorlERoigR(void *p) {
      delete [] (static_cast<vector<Roi>*>(p));
   }
   static void destruct_vectorlERoigR(void *p) {
      typedef vector<Roi> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<Roi>

namespace ROOT {
   static TClass *vectorlEPulsegR_Dictionary();
   static void vectorlEPulsegR_TClassManip(TClass*);
   static void *new_vectorlEPulsegR(void *p = nullptr);
   static void *newArray_vectorlEPulsegR(Long_t size, void *p);
   static void delete_vectorlEPulsegR(void *p);
   static void deleteArray_vectorlEPulsegR(void *p);
   static void destruct_vectorlEPulsegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Pulse>*)
   {
      vector<Pulse> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Pulse>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Pulse>", -2, "vector", 458,
                  typeid(vector<Pulse>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPulsegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<Pulse>) );
      instance.SetNew(&new_vectorlEPulsegR);
      instance.SetNewArray(&newArray_vectorlEPulsegR);
      instance.SetDelete(&delete_vectorlEPulsegR);
      instance.SetDeleteArray(&deleteArray_vectorlEPulsegR);
      instance.SetDestructor(&destruct_vectorlEPulsegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Pulse> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<Pulse>","std::vector<Pulse, std::allocator<Pulse> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<Pulse>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPulsegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<Pulse>*>(nullptr))->GetClass();
      vectorlEPulsegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPulsegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPulsegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Pulse> : new vector<Pulse>;
   }
   static void *newArray_vectorlEPulsegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<Pulse>[nElements] : new vector<Pulse>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPulsegR(void *p) {
      delete (static_cast<vector<Pulse>*>(p));
   }
   static void deleteArray_vectorlEPulsegR(void *p) {
      delete [] (static_cast<vector<Pulse>*>(p));
   }
   static void destruct_vectorlEPulsegR(void *p) {
      typedef vector<Pulse> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<Pulse>

namespace ROOT {
   static TClass *vectorlEChannelDatagR_Dictionary();
   static void vectorlEChannelDatagR_TClassManip(TClass*);
   static void *new_vectorlEChannelDatagR(void *p = nullptr);
   static void *newArray_vectorlEChannelDatagR(Long_t size, void *p);
   static void delete_vectorlEChannelDatagR(void *p);
   static void deleteArray_vectorlEChannelDatagR(void *p);
   static void destruct_vectorlEChannelDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<ChannelData>*)
   {
      vector<ChannelData> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<ChannelData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<ChannelData>", -2, "vector", 458,
                  typeid(vector<ChannelData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEChannelDatagR_Dictionary, isa_proxy, 0,
                  sizeof(vector<ChannelData>) );
      instance.SetNew(&new_vectorlEChannelDatagR);
      instance.SetNewArray(&newArray_vectorlEChannelDatagR);
      instance.SetDelete(&delete_vectorlEChannelDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlEChannelDatagR);
      instance.SetDestructor(&destruct_vectorlEChannelDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<ChannelData> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<ChannelData>","std::vector<ChannelData, std::allocator<ChannelData> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<ChannelData>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEChannelDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<ChannelData>*>(nullptr))->GetClass();
      vectorlEChannelDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEChannelDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEChannelDatagR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<ChannelData> : new vector<ChannelData>;
   }
   static void *newArray_vectorlEChannelDatagR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<ChannelData>[nElements] : new vector<ChannelData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEChannelDatagR(void *p) {
      delete (static_cast<vector<ChannelData>*>(p));
   }
   static void deleteArray_vectorlEChannelDatagR(void *p) {
      delete [] (static_cast<vector<ChannelData>*>(p));
   }
   static void destruct_vectorlEChannelDatagR(void *p) {
      typedef vector<ChannelData> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<ChannelData>

namespace ROOT {
   static TClass *maplEstringcOstringgR_Dictionary();
   static void maplEstringcOstringgR_TClassManip(TClass*);
   static void *new_maplEstringcOstringgR(void *p = nullptr);
   static void *newArray_maplEstringcOstringgR(Long_t size, void *p);
   static void delete_maplEstringcOstringgR(void *p);
   static void deleteArray_maplEstringcOstringgR(void *p);
   static void destruct_maplEstringcOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,string>*)
   {
      map<string,string> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,string>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,string>", -2, "map", 105,
                  typeid(map<string,string>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEstringcOstringgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,string>) );
      instance.SetNew(&new_maplEstringcOstringgR);
      instance.SetNewArray(&newArray_maplEstringcOstringgR);
      instance.SetDelete(&delete_maplEstringcOstringgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOstringgR);
      instance.SetDestructor(&destruct_maplEstringcOstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,string> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<string,string>","std::map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<string,string>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<string,string>*>(nullptr))->GetClass();
      maplEstringcOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOstringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,string> : new map<string,string>;
   }
   static void *newArray_maplEstringcOstringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<string,string>[nElements] : new map<string,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOstringgR(void *p) {
      delete (static_cast<map<string,string>*>(p));
   }
   static void deleteArray_maplEstringcOstringgR(void *p) {
      delete [] (static_cast<map<string,string>*>(p));
   }
   static void destruct_maplEstringcOstringgR(void *p) {
      typedef map<string,string> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<string,string>

namespace ROOT {
   static TClass *maplEintcOmaplEstringcOstringgRsPgR_Dictionary();
   static void maplEintcOmaplEstringcOstringgRsPgR_TClassManip(TClass*);
   static void *new_maplEintcOmaplEstringcOstringgRsPgR(void *p = nullptr);
   static void *newArray_maplEintcOmaplEstringcOstringgRsPgR(Long_t size, void *p);
   static void delete_maplEintcOmaplEstringcOstringgRsPgR(void *p);
   static void deleteArray_maplEintcOmaplEstringcOstringgRsPgR(void *p);
   static void destruct_maplEintcOmaplEstringcOstringgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,map<string,string> >*)
   {
      map<int,map<string,string> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,map<string,string> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,map<string,string> >", -2, "map", 105,
                  typeid(map<int,map<string,string> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOmaplEstringcOstringgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,map<string,string> >) );
      instance.SetNew(&new_maplEintcOmaplEstringcOstringgRsPgR);
      instance.SetNewArray(&newArray_maplEintcOmaplEstringcOstringgRsPgR);
      instance.SetDelete(&delete_maplEintcOmaplEstringcOstringgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOmaplEstringcOstringgRsPgR);
      instance.SetDestructor(&destruct_maplEintcOmaplEstringcOstringgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,map<string,string> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("map<int,map<string,string> >","std::map<int, std::map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::less<int>, std::allocator<std::pair<int const, std::map<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const map<int,map<string,string> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOmaplEstringcOstringgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const map<int,map<string,string> >*>(nullptr))->GetClass();
      maplEintcOmaplEstringcOstringgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOmaplEstringcOstringgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOmaplEstringcOstringgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,map<string,string> > : new map<int,map<string,string> >;
   }
   static void *newArray_maplEintcOmaplEstringcOstringgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) map<int,map<string,string> >[nElements] : new map<int,map<string,string> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOmaplEstringcOstringgRsPgR(void *p) {
      delete (static_cast<map<int,map<string,string> >*>(p));
   }
   static void deleteArray_maplEintcOmaplEstringcOstringgRsPgR(void *p) {
      delete [] (static_cast<map<int,map<string,string> >*>(p));
   }
   static void destruct_maplEintcOmaplEstringcOstringgRsPgR(void *p) {
      typedef map<int,map<string,string> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class map<int,map<string,string> >

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_daqmanDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_daqmanDict) = RecordReadRules_daqmanDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_daqmanDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_daqmanDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Baseline.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/EventData.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Pulse.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/PulseFit.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Roi.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Spe.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/SumOfIntegral.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/TOF.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Unspikes.hh",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/runinfo.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/modules/DAQMANInput/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "daqmanDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace std{template <typename _CharT> struct  __attribute__((annotate("$clingAutoload$bits/char_traits.h")))  __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
namespace std{template <typename > class  __attribute__((annotate("$clingAutoload$bits/memoryfwd.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class  __attribute__((annotate("$clingAutoload$Spe.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Baseline.hh")))  Spe;
class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Baseline.hh")))  Baseline;
class  __attribute__((annotate("$clingAutoload$PulseFit.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh")))  PulseFit;
class  __attribute__((annotate("$clingAutoload$Pulse.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh")))  Pulse;
class  __attribute__((annotate("$clingAutoload$Unspikes.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh")))  Unspikes;
class  __attribute__((annotate("$clingAutoload$Roi.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh")))  Roi;
class  __attribute__((annotate("$clingAutoload$TOF.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh")))  TOF;
class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh")))  ChannelData;
class  __attribute__((annotate("$clingAutoload$SumOfIntegral.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/EventData.hh")))  SumOfIntegral;
class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/EventData.hh")))  EventData;
class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/runinfo.hh")))  runinfo;
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "daqmanDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Baseline.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/ChannelData.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/EventData.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Pulse.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/PulseFit.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Roi.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Spe.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/SumOfIntegral.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/TOF.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/Unspikes.hh"
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/daqman/runinfo.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Baseline", payloadCode, "@",
"ChannelData", payloadCode, "@",
"EventData", payloadCode, "@",
"Pulse", payloadCode, "@",
"PulseFit", payloadCode, "@",
"Roi", payloadCode, "@",
"Spe", payloadCode, "@",
"SumOfIntegral", payloadCode, "@",
"TOF", payloadCode, "@",
"Unspikes", payloadCode, "@",
"runinfo", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("daqmanDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_daqmanDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_daqmanDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_daqmanDict() {
  TriggerDictionaryInitialization_daqmanDict_Impl();
}
