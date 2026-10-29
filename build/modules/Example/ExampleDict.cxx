// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ExampleDict
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
#include "/home/lev/Документы/REDOffline/modules/Example/ExampleModule.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_REDcLcLExampleModule(void *p = nullptr);
   static void *newArray_REDcLcLExampleModule(Long_t size, void *p);
   static void delete_REDcLcLExampleModule(void *p);
   static void deleteArray_REDcLcLExampleModule(void *p);
   static void destruct_REDcLcLExampleModule(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::ExampleModule*)
   {
      ::RED::ExampleModule *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::ExampleModule >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::ExampleModule", ::RED::ExampleModule::Class_Version(), "modules/Example/ExampleModule.hh", 9,
                  typeid(::RED::ExampleModule), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::ExampleModule::Dictionary, isa_proxy, 4,
                  sizeof(::RED::ExampleModule) );
      instance.SetNew(&new_REDcLcLExampleModule);
      instance.SetNewArray(&newArray_REDcLcLExampleModule);
      instance.SetDelete(&delete_REDcLcLExampleModule);
      instance.SetDeleteArray(&deleteArray_REDcLcLExampleModule);
      instance.SetDestructor(&destruct_REDcLcLExampleModule);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::ExampleModule*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::ExampleModule*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::ExampleModule*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr ExampleModule::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ExampleModule::Class_Name()
{
   return "RED::ExampleModule";
}

//______________________________________________________________________________
const char *ExampleModule::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ExampleModule*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ExampleModule::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::ExampleModule*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ExampleModule::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ExampleModule*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ExampleModule::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::ExampleModule*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void ExampleModule::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::ExampleModule.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::ExampleModule::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::ExampleModule::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLExampleModule(void *p) {
      return  p ? new(p) ::RED::ExampleModule : new ::RED::ExampleModule;
   }
   static void *newArray_REDcLcLExampleModule(Long_t nElements, void *p) {
      return p ? new(p) ::RED::ExampleModule[nElements] : new ::RED::ExampleModule[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLExampleModule(void *p) {
      delete (static_cast<::RED::ExampleModule*>(p));
   }
   static void deleteArray_REDcLcLExampleModule(void *p) {
      delete [] (static_cast<::RED::ExampleModule*>(p));
   }
   static void destruct_REDcLcLExampleModule(void *p) {
      typedef ::RED::ExampleModule current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::ExampleModule

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_ExampleDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_ExampleDict) = RecordReadRules_ExampleDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_ExampleDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_ExampleDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/modules/Example/ExampleModule.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/modules/Example/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ExampleDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/Example/ExampleModule.hh")))  ExampleModule;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ExampleDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/modules/Example/ExampleModule.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::ExampleModule", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ExampleDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ExampleDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ExampleDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ExampleDict() {
  TriggerDictionaryInitialization_ExampleDict_Impl();
}
