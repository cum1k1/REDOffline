// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ProcessingDict
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
#include "/home/lev/Документы/REDOffline/REDProcessing/ClusteringModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/CorrectorBallistic.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/CorrectorLowFrequency.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/Generator.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/InputModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/OutputModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/ProcessingModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/ProcessingModuleFactory.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/PulseFinder.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/REDFileInput.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/RemoveModule.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void delete_REDcLcLProcessingModule(void *p);
   static void deleteArray_REDcLcLProcessingModule(void *p);
   static void destruct_REDcLcLProcessingModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::ProcessingModule*)
   {
      ::RED::ProcessingModule *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::ProcessingModule >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::ProcessingModule", ::RED::ProcessingModule::Class_Version(), "REDProcessing/ProcessingModule.hh", 16,
                  typeid(::RED::ProcessingModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::ProcessingModule::Dictionary, isa_proxy, 4,
                  sizeof(::RED::ProcessingModule) );
      instance.SetDelete(&delete_REDcLcLProcessingModule);
      instance.SetDeleteArray(&deleteArray_REDcLcLProcessingModule);
      instance.SetDestructor(&destruct_REDcLcLProcessingModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::ProcessingModule*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::ProcessingModule*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::ProcessingModule*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLClusteringModule(void *p = nullptr);
   static void *newArray_REDcLcLClusteringModule(Long_t size, void *p);
   static void delete_REDcLcLClusteringModule(void *p);
   static void deleteArray_REDcLcLClusteringModule(void *p);
   static void destruct_REDcLcLClusteringModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::ClusteringModule*)
   {
      ::RED::ClusteringModule *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::ClusteringModule >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::ClusteringModule", ::RED::ClusteringModule::Class_Version(), "REDProcessing/ClusteringModule.hh", 15,
                  typeid(::RED::ClusteringModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::ClusteringModule::Dictionary, isa_proxy, 4,
                  sizeof(::RED::ClusteringModule) );
      instance.SetNew(&new_REDcLcLClusteringModule);
      instance.SetNewArray(&newArray_REDcLcLClusteringModule);
      instance.SetDelete(&delete_REDcLcLClusteringModule);
      instance.SetDeleteArray(&deleteArray_REDcLcLClusteringModule);
      instance.SetDestructor(&destruct_REDcLcLClusteringModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::ClusteringModule*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::ClusteringModule*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::ClusteringModule*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLCorrectorBallistic(void *p = nullptr);
   static void *newArray_REDcLcLCorrectorBallistic(Long_t size, void *p);
   static void delete_REDcLcLCorrectorBallistic(void *p);
   static void deleteArray_REDcLcLCorrectorBallistic(void *p);
   static void destruct_REDcLcLCorrectorBallistic(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::CorrectorBallistic*)
   {
      ::RED::CorrectorBallistic *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::CorrectorBallistic >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::CorrectorBallistic", ::RED::CorrectorBallistic::Class_Version(), "REDProcessing/CorrectorBallistic.hh", 14,
                  typeid(::RED::CorrectorBallistic), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::CorrectorBallistic::Dictionary, isa_proxy, 4,
                  sizeof(::RED::CorrectorBallistic) );
      instance.SetNew(&new_REDcLcLCorrectorBallistic);
      instance.SetNewArray(&newArray_REDcLcLCorrectorBallistic);
      instance.SetDelete(&delete_REDcLcLCorrectorBallistic);
      instance.SetDeleteArray(&deleteArray_REDcLcLCorrectorBallistic);
      instance.SetDestructor(&destruct_REDcLcLCorrectorBallistic);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::CorrectorBallistic*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::CorrectorBallistic*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::CorrectorBallistic*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLCorrectorLowFrequency(void *p = nullptr);
   static void *newArray_REDcLcLCorrectorLowFrequency(Long_t size, void *p);
   static void delete_REDcLcLCorrectorLowFrequency(void *p);
   static void deleteArray_REDcLcLCorrectorLowFrequency(void *p);
   static void destruct_REDcLcLCorrectorLowFrequency(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::CorrectorLowFrequency*)
   {
      ::RED::CorrectorLowFrequency *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::CorrectorLowFrequency >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::CorrectorLowFrequency", ::RED::CorrectorLowFrequency::Class_Version(), "REDProcessing/CorrectorLowFrequency.hh", 14,
                  typeid(::RED::CorrectorLowFrequency), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::CorrectorLowFrequency::Dictionary, isa_proxy, 4,
                  sizeof(::RED::CorrectorLowFrequency) );
      instance.SetNew(&new_REDcLcLCorrectorLowFrequency);
      instance.SetNewArray(&newArray_REDcLcLCorrectorLowFrequency);
      instance.SetDelete(&delete_REDcLcLCorrectorLowFrequency);
      instance.SetDeleteArray(&deleteArray_REDcLcLCorrectorLowFrequency);
      instance.SetDestructor(&destruct_REDcLcLCorrectorLowFrequency);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::CorrectorLowFrequency*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::CorrectorLowFrequency*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::CorrectorLowFrequency*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLGenerator(void *p = nullptr);
   static void *newArray_REDcLcLGenerator(Long_t size, void *p);
   static void delete_REDcLcLGenerator(void *p);
   static void deleteArray_REDcLcLGenerator(void *p);
   static void destruct_REDcLcLGenerator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::Generator*)
   {
      ::RED::Generator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::Generator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::Generator", ::RED::Generator::Class_Version(), "REDProcessing/Generator.hh", 11,
                  typeid(::RED::Generator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::Generator::Dictionary, isa_proxy, 4,
                  sizeof(::RED::Generator) );
      instance.SetNew(&new_REDcLcLGenerator);
      instance.SetNewArray(&newArray_REDcLcLGenerator);
      instance.SetDelete(&delete_REDcLcLGenerator);
      instance.SetDeleteArray(&deleteArray_REDcLcLGenerator);
      instance.SetDestructor(&destruct_REDcLcLGenerator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::Generator*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::Generator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::Generator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLInputModule(void *p = nullptr);
   static void *newArray_REDcLcLInputModule(Long_t size, void *p);
   static void delete_REDcLcLInputModule(void *p);
   static void deleteArray_REDcLcLInputModule(void *p);
   static void destruct_REDcLcLInputModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::InputModule*)
   {
      ::RED::InputModule *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::InputModule >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::InputModule", ::RED::InputModule::Class_Version(), "REDProcessing/InputModule.hh", 14,
                  typeid(::RED::InputModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::InputModule::Dictionary, isa_proxy, 4,
                  sizeof(::RED::InputModule) );
      instance.SetNew(&new_REDcLcLInputModule);
      instance.SetNewArray(&newArray_REDcLcLInputModule);
      instance.SetDelete(&delete_REDcLcLInputModule);
      instance.SetDeleteArray(&deleteArray_REDcLcLInputModule);
      instance.SetDestructor(&destruct_REDcLcLInputModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::InputModule*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::InputModule*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::InputModule*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLOutputModule(void *p = nullptr);
   static void *newArray_REDcLcLOutputModule(Long_t size, void *p);
   static void delete_REDcLcLOutputModule(void *p);
   static void deleteArray_REDcLcLOutputModule(void *p);
   static void destruct_REDcLcLOutputModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::OutputModule*)
   {
      ::RED::OutputModule *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::OutputModule >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::OutputModule", ::RED::OutputModule::Class_Version(), "REDProcessing/OutputModule.hh", 16,
                  typeid(::RED::OutputModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::OutputModule::Dictionary, isa_proxy, 4,
                  sizeof(::RED::OutputModule) );
      instance.SetNew(&new_REDcLcLOutputModule);
      instance.SetNewArray(&newArray_REDcLcLOutputModule);
      instance.SetDelete(&delete_REDcLcLOutputModule);
      instance.SetDeleteArray(&deleteArray_REDcLcLOutputModule);
      instance.SetDestructor(&destruct_REDcLcLOutputModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::OutputModule*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::OutputModule*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::OutputModule*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *REDcLcLBaselineParameters_Dictionary();
   static void REDcLcLBaselineParameters_TClassManip(TClass*);
   static void *new_REDcLcLBaselineParameters(void *p = nullptr);
   static void *newArray_REDcLcLBaselineParameters(Long_t size, void *p);
   static void delete_REDcLcLBaselineParameters(void *p);
   static void deleteArray_REDcLcLBaselineParameters(void *p);
   static void destruct_REDcLcLBaselineParameters(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::BaselineParameters*)
   {
      ::RED::BaselineParameters *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RED::BaselineParameters));
      static ::ROOT::TGenericClassInfo 
         instance("RED::BaselineParameters", "REDProcessing/PulseFinder.hh", 14,
                  typeid(::RED::BaselineParameters), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &REDcLcLBaselineParameters_Dictionary, isa_proxy, 4,
                  sizeof(::RED::BaselineParameters) );
      instance.SetNew(&new_REDcLcLBaselineParameters);
      instance.SetNewArray(&newArray_REDcLcLBaselineParameters);
      instance.SetDelete(&delete_REDcLcLBaselineParameters);
      instance.SetDeleteArray(&deleteArray_REDcLcLBaselineParameters);
      instance.SetDestructor(&destruct_REDcLcLBaselineParameters);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::BaselineParameters*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::BaselineParameters*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::BaselineParameters*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *REDcLcLBaselineParameters_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::RED::BaselineParameters*>(nullptr))->GetClass();
      REDcLcLBaselineParameters_TClassManip(theClass);
   return theClass;
   }

   static void REDcLcLBaselineParameters_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLPulseFinder(void *p = nullptr);
   static void *newArray_REDcLcLPulseFinder(Long_t size, void *p);
   static void delete_REDcLcLPulseFinder(void *p);
   static void deleteArray_REDcLcLPulseFinder(void *p);
   static void destruct_REDcLcLPulseFinder(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::PulseFinder*)
   {
      ::RED::PulseFinder *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::PulseFinder >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::PulseFinder", ::RED::PulseFinder::Class_Version(), "REDProcessing/PulseFinder.hh", 74,
                  typeid(::RED::PulseFinder), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::PulseFinder::Dictionary, isa_proxy, 4,
                  sizeof(::RED::PulseFinder) );
      instance.SetNew(&new_REDcLcLPulseFinder);
      instance.SetNewArray(&newArray_REDcLcLPulseFinder);
      instance.SetDelete(&delete_REDcLcLPulseFinder);
      instance.SetDeleteArray(&deleteArray_REDcLcLPulseFinder);
      instance.SetDestructor(&destruct_REDcLcLPulseFinder);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::PulseFinder*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::PulseFinder*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::PulseFinder*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLREDFileInput(void *p = nullptr);
   static void *newArray_REDcLcLREDFileInput(Long_t size, void *p);
   static void delete_REDcLcLREDFileInput(void *p);
   static void deleteArray_REDcLcLREDFileInput(void *p);
   static void destruct_REDcLcLREDFileInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::REDFileInput*)
   {
      ::RED::REDFileInput *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::REDFileInput >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::REDFileInput", ::RED::REDFileInput::Class_Version(), "REDProcessing/REDFileInput.hh", 13,
                  typeid(::RED::REDFileInput), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::REDFileInput::Dictionary, isa_proxy, 4,
                  sizeof(::RED::REDFileInput) );
      instance.SetNew(&new_REDcLcLREDFileInput);
      instance.SetNewArray(&newArray_REDcLcLREDFileInput);
      instance.SetDelete(&delete_REDcLcLREDFileInput);
      instance.SetDeleteArray(&deleteArray_REDcLcLREDFileInput);
      instance.SetDestructor(&destruct_REDcLcLREDFileInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::REDFileInput*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::REDFileInput*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::REDFileInput*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLRemoveModule(void *p = nullptr);
   static void *newArray_REDcLcLRemoveModule(Long_t size, void *p);
   static void delete_REDcLcLRemoveModule(void *p);
   static void deleteArray_REDcLcLRemoveModule(void *p);
   static void destruct_REDcLcLRemoveModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::RemoveModule*)
   {
      ::RED::RemoveModule *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::RemoveModule >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::RemoveModule", ::RED::RemoveModule::Class_Version(), "REDProcessing/RemoveModule.hh", 11,
                  typeid(::RED::RemoveModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::RemoveModule::Dictionary, isa_proxy, 4,
                  sizeof(::RED::RemoveModule) );
      instance.SetNew(&new_REDcLcLRemoveModule);
      instance.SetNewArray(&newArray_REDcLcLRemoveModule);
      instance.SetDelete(&delete_REDcLcLRemoveModule);
      instance.SetDeleteArray(&deleteArray_REDcLcLRemoveModule);
      instance.SetDestructor(&destruct_REDcLcLRemoveModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::RemoveModule*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::RemoveModule*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::RemoveModule*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr ProcessingModule::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ProcessingModule::Class_Name()
{
   return "RED::ProcessingModule";
}

//______________________________________________________________________________
const char *ProcessingModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingModule*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ProcessingModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingModule*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ProcessingModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingModule*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ProcessingModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ProcessingModule*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr ClusteringModule::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ClusteringModule::Class_Name()
{
   return "RED::ClusteringModule";
}

//______________________________________________________________________________
const char *ClusteringModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ClusteringModule*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ClusteringModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ClusteringModule*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ClusteringModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ClusteringModule*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ClusteringModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ClusteringModule*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr CorrectorBallistic::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CorrectorBallistic::Class_Name()
{
   return "RED::CorrectorBallistic";
}

//______________________________________________________________________________
const char *CorrectorBallistic::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorBallistic*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CorrectorBallistic::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorBallistic*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CorrectorBallistic::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorBallistic*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CorrectorBallistic::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorBallistic*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr CorrectorLowFrequency::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CorrectorLowFrequency::Class_Name()
{
   return "RED::CorrectorLowFrequency";
}

//______________________________________________________________________________
const char *CorrectorLowFrequency::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorLowFrequency*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CorrectorLowFrequency::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorLowFrequency*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CorrectorLowFrequency::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorLowFrequency*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CorrectorLowFrequency::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::CorrectorLowFrequency*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr Generator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Generator::Class_Name()
{
   return "RED::Generator";
}

//______________________________________________________________________________
const char *Generator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Generator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Generator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Generator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Generator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Generator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Generator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Generator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr InputModule::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *InputModule::Class_Name()
{
   return "RED::InputModule";
}

//______________________________________________________________________________
const char *InputModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::InputModule*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int InputModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::InputModule*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *InputModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::InputModule*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *InputModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::InputModule*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr OutputModule::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *OutputModule::Class_Name()
{
   return "RED::OutputModule";
}

//______________________________________________________________________________
const char *OutputModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputModule*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int OutputModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputModule*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *OutputModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputModule*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *OutputModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputModule*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr PulseFinder::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PulseFinder::Class_Name()
{
   return "RED::PulseFinder";
}

//______________________________________________________________________________
const char *PulseFinder::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::PulseFinder*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PulseFinder::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::PulseFinder*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PulseFinder::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::PulseFinder*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PulseFinder::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::PulseFinder*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr REDFileInput::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *REDFileInput::Class_Name()
{
   return "RED::REDFileInput";
}

//______________________________________________________________________________
const char *REDFileInput::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::REDFileInput*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int REDFileInput::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::REDFileInput*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *REDFileInput::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::REDFileInput*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *REDFileInput::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::REDFileInput*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr RemoveModule::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RemoveModule::Class_Name()
{
   return "RED::RemoveModule";
}

//______________________________________________________________________________
const char *RemoveModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::RemoveModule*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RemoveModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::RemoveModule*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RemoveModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::RemoveModule*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RemoveModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::RemoveModule*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void ProcessingModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::ProcessingModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::ProcessingModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::ProcessingModule::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrapper around operator delete
   static void delete_REDcLcLProcessingModule(void *p) {
      delete (static_cast<::RED::ProcessingModule*>(p));
   }
   static void deleteArray_REDcLcLProcessingModule(void *p) {
      delete [] (static_cast<::RED::ProcessingModule*>(p));
   }
   static void destruct_REDcLcLProcessingModule(void *p) {
      typedef ::RED::ProcessingModule current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::ProcessingModule

namespace RED {
//______________________________________________________________________________
void ClusteringModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::ClusteringModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::ClusteringModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::ClusteringModule::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLClusteringModule(void *p) {
      return  p ? new(p) ::RED::ClusteringModule : new ::RED::ClusteringModule;
   }
   static void *newArray_REDcLcLClusteringModule(Long_t nElements, void *p) {
      return p ? new(p) ::RED::ClusteringModule[nElements] : new ::RED::ClusteringModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLClusteringModule(void *p) {
      delete (static_cast<::RED::ClusteringModule*>(p));
   }
   static void deleteArray_REDcLcLClusteringModule(void *p) {
      delete [] (static_cast<::RED::ClusteringModule*>(p));
   }
   static void destruct_REDcLcLClusteringModule(void *p) {
      typedef ::RED::ClusteringModule current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::ClusteringModule

namespace RED {
//______________________________________________________________________________
void CorrectorBallistic::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::CorrectorBallistic.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::CorrectorBallistic::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::CorrectorBallistic::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLCorrectorBallistic(void *p) {
      return  p ? new(p) ::RED::CorrectorBallistic : new ::RED::CorrectorBallistic;
   }
   static void *newArray_REDcLcLCorrectorBallistic(Long_t nElements, void *p) {
      return p ? new(p) ::RED::CorrectorBallistic[nElements] : new ::RED::CorrectorBallistic[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLCorrectorBallistic(void *p) {
      delete (static_cast<::RED::CorrectorBallistic*>(p));
   }
   static void deleteArray_REDcLcLCorrectorBallistic(void *p) {
      delete [] (static_cast<::RED::CorrectorBallistic*>(p));
   }
   static void destruct_REDcLcLCorrectorBallistic(void *p) {
      typedef ::RED::CorrectorBallistic current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::CorrectorBallistic

namespace RED {
//______________________________________________________________________________
void CorrectorLowFrequency::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::CorrectorLowFrequency.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::CorrectorLowFrequency::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::CorrectorLowFrequency::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLCorrectorLowFrequency(void *p) {
      return  p ? new(p) ::RED::CorrectorLowFrequency : new ::RED::CorrectorLowFrequency;
   }
   static void *newArray_REDcLcLCorrectorLowFrequency(Long_t nElements, void *p) {
      return p ? new(p) ::RED::CorrectorLowFrequency[nElements] : new ::RED::CorrectorLowFrequency[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLCorrectorLowFrequency(void *p) {
      delete (static_cast<::RED::CorrectorLowFrequency*>(p));
   }
   static void deleteArray_REDcLcLCorrectorLowFrequency(void *p) {
      delete [] (static_cast<::RED::CorrectorLowFrequency*>(p));
   }
   static void destruct_REDcLcLCorrectorLowFrequency(void *p) {
      typedef ::RED::CorrectorLowFrequency current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::CorrectorLowFrequency

namespace RED {
//______________________________________________________________________________
void Generator::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::Generator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::Generator::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::Generator::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLGenerator(void *p) {
      return  p ? new(p) ::RED::Generator : new ::RED::Generator;
   }
   static void *newArray_REDcLcLGenerator(Long_t nElements, void *p) {
      return p ? new(p) ::RED::Generator[nElements] : new ::RED::Generator[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLGenerator(void *p) {
      delete (static_cast<::RED::Generator*>(p));
   }
   static void deleteArray_REDcLcLGenerator(void *p) {
      delete [] (static_cast<::RED::Generator*>(p));
   }
   static void destruct_REDcLcLGenerator(void *p) {
      typedef ::RED::Generator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::Generator

namespace RED {
//______________________________________________________________________________
void InputModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::InputModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::InputModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::InputModule::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLInputModule(void *p) {
      return  p ? new(p) ::RED::InputModule : new ::RED::InputModule;
   }
   static void *newArray_REDcLcLInputModule(Long_t nElements, void *p) {
      return p ? new(p) ::RED::InputModule[nElements] : new ::RED::InputModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLInputModule(void *p) {
      delete (static_cast<::RED::InputModule*>(p));
   }
   static void deleteArray_REDcLcLInputModule(void *p) {
      delete [] (static_cast<::RED::InputModule*>(p));
   }
   static void destruct_REDcLcLInputModule(void *p) {
      typedef ::RED::InputModule current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::InputModule

namespace RED {
//______________________________________________________________________________
void OutputModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::OutputModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::OutputModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::OutputModule::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLOutputModule(void *p) {
      return  p ? new(p) ::RED::OutputModule : new ::RED::OutputModule;
   }
   static void *newArray_REDcLcLOutputModule(Long_t nElements, void *p) {
      return p ? new(p) ::RED::OutputModule[nElements] : new ::RED::OutputModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLOutputModule(void *p) {
      delete (static_cast<::RED::OutputModule*>(p));
   }
   static void deleteArray_REDcLcLOutputModule(void *p) {
      delete [] (static_cast<::RED::OutputModule*>(p));
   }
   static void destruct_REDcLcLOutputModule(void *p) {
      typedef ::RED::OutputModule current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::OutputModule

namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLBaselineParameters(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::RED::BaselineParameters : new ::RED::BaselineParameters;
   }
   static void *newArray_REDcLcLBaselineParameters(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::RED::BaselineParameters[nElements] : new ::RED::BaselineParameters[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLBaselineParameters(void *p) {
      delete (static_cast<::RED::BaselineParameters*>(p));
   }
   static void deleteArray_REDcLcLBaselineParameters(void *p) {
      delete [] (static_cast<::RED::BaselineParameters*>(p));
   }
   static void destruct_REDcLcLBaselineParameters(void *p) {
      typedef ::RED::BaselineParameters current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::BaselineParameters

namespace RED {
//______________________________________________________________________________
void PulseFinder::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::PulseFinder.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::PulseFinder::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::PulseFinder::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLPulseFinder(void *p) {
      return  p ? new(p) ::RED::PulseFinder : new ::RED::PulseFinder;
   }
   static void *newArray_REDcLcLPulseFinder(Long_t nElements, void *p) {
      return p ? new(p) ::RED::PulseFinder[nElements] : new ::RED::PulseFinder[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLPulseFinder(void *p) {
      delete (static_cast<::RED::PulseFinder*>(p));
   }
   static void deleteArray_REDcLcLPulseFinder(void *p) {
      delete [] (static_cast<::RED::PulseFinder*>(p));
   }
   static void destruct_REDcLcLPulseFinder(void *p) {
      typedef ::RED::PulseFinder current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::PulseFinder

namespace RED {
//______________________________________________________________________________
void REDFileInput::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::REDFileInput.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::REDFileInput::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::REDFileInput::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLREDFileInput(void *p) {
      return  p ? new(p) ::RED::REDFileInput : new ::RED::REDFileInput;
   }
   static void *newArray_REDcLcLREDFileInput(Long_t nElements, void *p) {
      return p ? new(p) ::RED::REDFileInput[nElements] : new ::RED::REDFileInput[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLREDFileInput(void *p) {
      delete (static_cast<::RED::REDFileInput*>(p));
   }
   static void deleteArray_REDcLcLREDFileInput(void *p) {
      delete [] (static_cast<::RED::REDFileInput*>(p));
   }
   static void destruct_REDcLcLREDFileInput(void *p) {
      typedef ::RED::REDFileInput current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::REDFileInput

namespace RED {
//______________________________________________________________________________
void RemoveModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::RemoveModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::RemoveModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::RemoveModule::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLRemoveModule(void *p) {
      return  p ? new(p) ::RED::RemoveModule : new ::RED::RemoveModule;
   }
   static void *newArray_REDcLcLRemoveModule(Long_t nElements, void *p) {
      return p ? new(p) ::RED::RemoveModule[nElements] : new ::RED::RemoveModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLRemoveModule(void *p) {
      delete (static_cast<::RED::RemoveModule*>(p));
   }
   static void deleteArray_REDcLcLRemoveModule(void *p) {
      delete [] (static_cast<::RED::RemoveModule*>(p));
   }
   static void destruct_REDcLcLRemoveModule(void *p) {
      typedef ::RED::RemoveModule current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::RemoveModule

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
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 458,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<int>*>(nullptr))->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete (static_cast<vector<int>*>(p));
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] (static_cast<vector<int>*>(p));
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<int>

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
   // Registration Schema evolution read functions
   int RecordReadRules_ProcessingDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_ProcessingDict) = RecordReadRules_ProcessingDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_ProcessingDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_ProcessingDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/REDProcessing/ClusteringModule.hh",
"/home/lev/Документы/REDOffline/REDProcessing/CorrectorBallistic.hh",
"/home/lev/Документы/REDOffline/REDProcessing/CorrectorLowFrequency.hh",
"/home/lev/Документы/REDOffline/REDProcessing/Generator.hh",
"/home/lev/Документы/REDOffline/REDProcessing/InputModule.hh",
"/home/lev/Документы/REDOffline/REDProcessing/OutputModule.hh",
"/home/lev/Документы/REDOffline/REDProcessing/ProcessingModule.hh",
"/home/lev/Документы/REDOffline/REDProcessing/ProcessingModuleFactory.hh",
"/home/lev/Документы/REDOffline/REDProcessing/PulseFinder.hh",
"/home/lev/Документы/REDOffline/REDProcessing/REDFileInput.hh",
"/home/lev/Документы/REDOffline/REDProcessing/RemoveModule.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/REDProcessing/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ProcessingDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$REDProcessing/ProcessingModule.hh")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/ClusteringModule.hh")))  ProcessingModule;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/ClusteringModule.hh")))  ClusteringModule;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/CorrectorBallistic.hh")))  CorrectorBallistic;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/CorrectorLowFrequency.hh")))  CorrectorLowFrequency;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/Generator.hh")))  Generator;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/InputModule.hh")))  InputModule;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/OutputModule.hh")))  OutputModule;}
namespace RED{struct  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/PulseFinder.hh")))  BaselineParameters;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/PulseFinder.hh")))  PulseFinder;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/REDFileInput.hh")))  REDFileInput;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDProcessing/RemoveModule.hh")))  RemoveModule;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ProcessingDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/REDProcessing/ClusteringModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/CorrectorBallistic.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/CorrectorLowFrequency.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/Generator.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/InputModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/OutputModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/ProcessingModule.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/ProcessingModuleFactory.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/PulseFinder.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/REDFileInput.hh"
#include "/home/lev/Документы/REDOffline/REDProcessing/RemoveModule.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::BaselineParameters", payloadCode, "@",
"RED::ClusteringModule", payloadCode, "@",
"RED::CorrectorBallistic", payloadCode, "@",
"RED::CorrectorLowFrequency", payloadCode, "@",
"RED::Generator", payloadCode, "@",
"RED::InputModule", payloadCode, "@",
"RED::OutputModule", payloadCode, "@",
"RED::ProcessingModule", payloadCode, "@",
"RED::PulseFinder", payloadCode, "@",
"RED::REDFileInput", payloadCode, "@",
"RED::RemoveModule", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ProcessingDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ProcessingDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ProcessingDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ProcessingDict() {
  TriggerDictionaryInitialization_ProcessingDict_Impl();
}
