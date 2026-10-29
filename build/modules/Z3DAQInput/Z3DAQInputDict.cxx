// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME Z3DAQInputDict
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
#include "/home/lev/Документы/REDOffline/modules/Z3DAQInput/Z3DAQInput.hh"
#include "/home/lev/Документы/REDOffline/modules/Z3DAQInput/z3file.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_REDcLcLZ3DAQInput(void *p = nullptr);
   static void *newArray_REDcLcLZ3DAQInput(Long_t size, void *p);
   static void delete_REDcLcLZ3DAQInput(void *p);
   static void deleteArray_REDcLcLZ3DAQInput(void *p);
   static void destruct_REDcLcLZ3DAQInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::Z3DAQInput*)
   {
      ::RED::Z3DAQInput *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::Z3DAQInput >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::Z3DAQInput", ::RED::Z3DAQInput::Class_Version(), "modules/Z3DAQInput/Z3DAQInput.hh", 13,
                  typeid(::RED::Z3DAQInput), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::Z3DAQInput::Dictionary, isa_proxy, 4,
                  sizeof(::RED::Z3DAQInput) );
      instance.SetNew(&new_REDcLcLZ3DAQInput);
      instance.SetNewArray(&newArray_REDcLcLZ3DAQInput);
      instance.SetDelete(&delete_REDcLcLZ3DAQInput);
      instance.SetDeleteArray(&deleteArray_REDcLcLZ3DAQInput);
      instance.SetDestructor(&destruct_REDcLcLZ3DAQInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::Z3DAQInput*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::Z3DAQInput*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::Z3DAQInput*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr Z3DAQInput::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Z3DAQInput::Class_Name()
{
   return "RED::Z3DAQInput";
}

//______________________________________________________________________________
const char *Z3DAQInput::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Z3DAQInput*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Z3DAQInput::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Z3DAQInput*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Z3DAQInput::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Z3DAQInput*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Z3DAQInput::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Z3DAQInput*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void Z3DAQInput::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::Z3DAQInput.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::Z3DAQInput::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::Z3DAQInput::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLZ3DAQInput(void *p) {
      return  p ? new(p) ::RED::Z3DAQInput : new ::RED::Z3DAQInput;
   }
   static void *newArray_REDcLcLZ3DAQInput(Long_t nElements, void *p) {
      return p ? new(p) ::RED::Z3DAQInput[nElements] : new ::RED::Z3DAQInput[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLZ3DAQInput(void *p) {
      delete (static_cast<::RED::Z3DAQInput*>(p));
   }
   static void deleteArray_REDcLcLZ3DAQInput(void *p) {
      delete [] (static_cast<::RED::Z3DAQInput*>(p));
   }
   static void destruct_REDcLcLZ3DAQInput(void *p) {
      typedef ::RED::Z3DAQInput current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::Z3DAQInput

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_Z3DAQInputDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_Z3DAQInputDict) = RecordReadRules_Z3DAQInputDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_Z3DAQInputDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_Z3DAQInputDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/modules/Z3DAQInput/Z3DAQInput.hh",
"/home/lev/Документы/REDOffline/modules/Z3DAQInput/z3file.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/usr/include",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/modules/Z3DAQInput/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Z3DAQInputDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/Z3DAQInput/Z3DAQInput.hh")))  Z3DAQInput;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Z3DAQInputDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/modules/Z3DAQInput/Z3DAQInput.hh"
#include "/home/lev/Документы/REDOffline/modules/Z3DAQInput/z3file.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::Z3DAQInput", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Z3DAQInputDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Z3DAQInputDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Z3DAQInputDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Z3DAQInputDict() {
  TriggerDictionaryInitialization_Z3DAQInputDict_Impl();
}
