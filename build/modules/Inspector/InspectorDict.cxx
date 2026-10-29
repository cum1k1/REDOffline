// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME InspectorDict
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
#include "/home/lev/Документы/REDOffline/modules/Inspector/Inspector.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_REDcLcLInspector(void *p = nullptr);
   static void *newArray_REDcLcLInspector(Long_t size, void *p);
   static void delete_REDcLcLInspector(void *p);
   static void deleteArray_REDcLcLInspector(void *p);
   static void destruct_REDcLcLInspector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::Inspector*)
   {
      ::RED::Inspector *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::Inspector >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::Inspector", ::RED::Inspector::Class_Version(), "modules/Inspector/Inspector.hh", 17,
                  typeid(::RED::Inspector), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::Inspector::Dictionary, isa_proxy, 4,
                  sizeof(::RED::Inspector) );
      instance.SetNew(&new_REDcLcLInspector);
      instance.SetNewArray(&newArray_REDcLcLInspector);
      instance.SetDelete(&delete_REDcLcLInspector);
      instance.SetDeleteArray(&deleteArray_REDcLcLInspector);
      instance.SetDestructor(&destruct_REDcLcLInspector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::Inspector*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::Inspector*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::Inspector*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr Inspector::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Inspector::Class_Name()
{
   return "RED::Inspector";
}

//______________________________________________________________________________
const char *Inspector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Inspector*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Inspector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::Inspector*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Inspector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Inspector*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Inspector::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::Inspector*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void Inspector::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::Inspector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::Inspector::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::Inspector::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLInspector(void *p) {
      return  p ? new(p) ::RED::Inspector : new ::RED::Inspector;
   }
   static void *newArray_REDcLcLInspector(Long_t nElements, void *p) {
      return p ? new(p) ::RED::Inspector[nElements] : new ::RED::Inspector[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLInspector(void *p) {
      delete (static_cast<::RED::Inspector*>(p));
   }
   static void deleteArray_REDcLcLInspector(void *p) {
      delete [] (static_cast<::RED::Inspector*>(p));
   }
   static void destruct_REDcLcLInspector(void *p) {
      typedef ::RED::Inspector current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::Inspector

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_InspectorDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_InspectorDict) = RecordReadRules_InspectorDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_InspectorDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_InspectorDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/modules/Inspector/Inspector.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/modules/Inspector/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "InspectorDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/Inspector/Inspector.hh")))  Inspector;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "InspectorDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/modules/Inspector/Inspector.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::Inspector", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("InspectorDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_InspectorDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_InspectorDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_InspectorDict() {
  TriggerDictionaryInitialization_InspectorDict_Impl();
}
