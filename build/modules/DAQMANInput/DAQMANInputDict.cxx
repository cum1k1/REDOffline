// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DAQMANInputDict
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
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/DAQMANInput.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_REDcLcLDAQMANInput(void *p = nullptr);
   static void *newArray_REDcLcLDAQMANInput(Long_t size, void *p);
   static void delete_REDcLcLDAQMANInput(void *p);
   static void deleteArray_REDcLcLDAQMANInput(void *p);
   static void destruct_REDcLcLDAQMANInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::DAQMANInput*)
   {
      ::RED::DAQMANInput *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::DAQMANInput >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::DAQMANInput", ::RED::DAQMANInput::Class_Version(), "modules/DAQMANInput/DAQMANInput.hh", 14,
                  typeid(::RED::DAQMANInput), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::DAQMANInput::Dictionary, isa_proxy, 4,
                  sizeof(::RED::DAQMANInput) );
      instance.SetNew(&new_REDcLcLDAQMANInput);
      instance.SetNewArray(&newArray_REDcLcLDAQMANInput);
      instance.SetDelete(&delete_REDcLcLDAQMANInput);
      instance.SetDeleteArray(&deleteArray_REDcLcLDAQMANInput);
      instance.SetDestructor(&destruct_REDcLcLDAQMANInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::DAQMANInput*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::DAQMANInput*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::DAQMANInput*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr DAQMANInput::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *DAQMANInput::Class_Name()
{
   return "RED::DAQMANInput";
}

//______________________________________________________________________________
const char *DAQMANInput::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::DAQMANInput*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int DAQMANInput::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::DAQMANInput*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DAQMANInput::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::DAQMANInput*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DAQMANInput::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::DAQMANInput*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void DAQMANInput::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::DAQMANInput.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::DAQMANInput::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::DAQMANInput::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLDAQMANInput(void *p) {
      return  p ? new(p) ::RED::DAQMANInput : new ::RED::DAQMANInput;
   }
   static void *newArray_REDcLcLDAQMANInput(Long_t nElements, void *p) {
      return p ? new(p) ::RED::DAQMANInput[nElements] : new ::RED::DAQMANInput[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLDAQMANInput(void *p) {
      delete (static_cast<::RED::DAQMANInput*>(p));
   }
   static void deleteArray_REDcLcLDAQMANInput(void *p) {
      delete [] (static_cast<::RED::DAQMANInput*>(p));
   }
   static void destruct_REDcLcLDAQMANInput(void *p) {
      typedef ::RED::DAQMANInput current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::DAQMANInput

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_DAQMANInputDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_DAQMANInputDict) = RecordReadRules_DAQMANInputDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_DAQMANInputDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_DAQMANInputDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/modules/DAQMANInput/DAQMANInput.hh",
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
#line 1 "DAQMANInputDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/DAQMANInput/DAQMANInput.hh")))  DAQMANInput;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DAQMANInputDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/modules/DAQMANInput/DAQMANInput.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::DAQMANInput", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DAQMANInputDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DAQMANInputDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DAQMANInputDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DAQMANInputDict() {
  TriggerDictionaryInitialization_DAQMANInputDict_Impl();
}
