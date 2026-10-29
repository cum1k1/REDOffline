// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME REDDAQInputDict
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
#include "/home/lev/Документы/REDOffline/modules/REDDAQInput/DataFile.hh"
#include "/home/lev/Документы/REDOffline/modules/REDDAQInput/REDDAQInput.hh"
#include "/home/lev/Документы/REDOffline/modules/REDDAQInput/data_file_types.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_REDcLcLREDDAQInput(void *p = nullptr);
   static void *newArray_REDcLcLREDDAQInput(Long_t size, void *p);
   static void delete_REDcLcLREDDAQInput(void *p);
   static void deleteArray_REDcLcLREDDAQInput(void *p);
   static void destruct_REDcLcLREDDAQInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::REDDAQInput*)
   {
      ::RED::REDDAQInput *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::REDDAQInput >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::REDDAQInput", ::RED::REDDAQInput::Class_Version(), "modules/REDDAQInput/REDDAQInput.hh", 13,
                  typeid(::RED::REDDAQInput), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::REDDAQInput::Dictionary, isa_proxy, 4,
                  sizeof(::RED::REDDAQInput) );
      instance.SetNew(&new_REDcLcLREDDAQInput);
      instance.SetNewArray(&newArray_REDcLcLREDDAQInput);
      instance.SetDelete(&delete_REDcLcLREDDAQInput);
      instance.SetDeleteArray(&deleteArray_REDcLcLREDDAQInput);
      instance.SetDestructor(&destruct_REDcLcLREDDAQInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::REDDAQInput*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::REDDAQInput*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::REDDAQInput*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *REDcLcLREDDAQInputcLcLRunHint_Dictionary();
   static void REDcLcLREDDAQInputcLcLRunHint_TClassManip(TClass*);
   static void *new_REDcLcLREDDAQInputcLcLRunHint(void *p = nullptr);
   static void *newArray_REDcLcLREDDAQInputcLcLRunHint(Long_t size, void *p);
   static void delete_REDcLcLREDDAQInputcLcLRunHint(void *p);
   static void deleteArray_REDcLcLREDDAQInputcLcLRunHint(void *p);
   static void destruct_REDcLcLREDDAQInputcLcLRunHint(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::REDDAQInput::RunHint*)
   {
      ::RED::REDDAQInput::RunHint *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RED::REDDAQInput::RunHint));
      static ::ROOT::TGenericClassInfo 
         instance("RED::REDDAQInput::RunHint", "modules/REDDAQInput/REDDAQInput.hh", 17,
                  typeid(::RED::REDDAQInput::RunHint), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &REDcLcLREDDAQInputcLcLRunHint_Dictionary, isa_proxy, 4,
                  sizeof(::RED::REDDAQInput::RunHint) );
      instance.SetNew(&new_REDcLcLREDDAQInputcLcLRunHint);
      instance.SetNewArray(&newArray_REDcLcLREDDAQInputcLcLRunHint);
      instance.SetDelete(&delete_REDcLcLREDDAQInputcLcLRunHint);
      instance.SetDeleteArray(&deleteArray_REDcLcLREDDAQInputcLcLRunHint);
      instance.SetDestructor(&destruct_REDcLcLREDDAQInputcLcLRunHint);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::REDDAQInput::RunHint*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::REDDAQInput::RunHint*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::REDDAQInput::RunHint*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *REDcLcLREDDAQInputcLcLRunHint_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::RED::REDDAQInput::RunHint*>(nullptr))->GetClass();
      REDcLcLREDDAQInputcLcLRunHint_TClassManip(theClass);
   return theClass;
   }

   static void REDcLcLREDDAQInputcLcLRunHint_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr REDDAQInput::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *REDDAQInput::Class_Name()
{
   return "RED::REDDAQInput";
}

//______________________________________________________________________________
const char *REDDAQInput::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::REDDAQInput*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int REDDAQInput::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::REDDAQInput*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *REDDAQInput::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::REDDAQInput*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *REDDAQInput::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::REDDAQInput*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void REDDAQInput::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::REDDAQInput.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::REDDAQInput::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::REDDAQInput::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLREDDAQInput(void *p) {
      return  p ? new(p) ::RED::REDDAQInput : new ::RED::REDDAQInput;
   }
   static void *newArray_REDcLcLREDDAQInput(Long_t nElements, void *p) {
      return p ? new(p) ::RED::REDDAQInput[nElements] : new ::RED::REDDAQInput[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLREDDAQInput(void *p) {
      delete (static_cast<::RED::REDDAQInput*>(p));
   }
   static void deleteArray_REDcLcLREDDAQInput(void *p) {
      delete [] (static_cast<::RED::REDDAQInput*>(p));
   }
   static void destruct_REDcLcLREDDAQInput(void *p) {
      typedef ::RED::REDDAQInput current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::REDDAQInput

namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLREDDAQInputcLcLRunHint(void *p) {
      return  p ? new(p) ::RED::REDDAQInput::RunHint : new ::RED::REDDAQInput::RunHint;
   }
   static void *newArray_REDcLcLREDDAQInputcLcLRunHint(Long_t nElements, void *p) {
      return p ? new(p) ::RED::REDDAQInput::RunHint[nElements] : new ::RED::REDDAQInput::RunHint[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLREDDAQInputcLcLRunHint(void *p) {
      delete (static_cast<::RED::REDDAQInput::RunHint*>(p));
   }
   static void deleteArray_REDcLcLREDDAQInputcLcLRunHint(void *p) {
      delete [] (static_cast<::RED::REDDAQInput::RunHint*>(p));
   }
   static void destruct_REDcLcLREDDAQInputcLcLRunHint(void *p) {
      typedef ::RED::REDDAQInput::RunHint current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::REDDAQInput::RunHint

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_REDDAQInputDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_REDDAQInputDict) = RecordReadRules_REDDAQInputDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_REDDAQInputDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_REDDAQInputDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/modules/REDDAQInput/DataFile.hh",
"/home/lev/Документы/REDOffline/modules/REDDAQInput/REDDAQInput.hh",
"/home/lev/Документы/REDOffline/modules/REDDAQInput/data_file_types.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/modules/REDDAQInput/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "REDDAQInputDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/REDDAQInput/REDDAQInput.hh")))  REDDAQInput;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "REDDAQInputDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/modules/REDDAQInput/DataFile.hh"
#include "/home/lev/Документы/REDOffline/modules/REDDAQInput/REDDAQInput.hh"
#include "/home/lev/Документы/REDOffline/modules/REDDAQInput/data_file_types.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::REDDAQInput", payloadCode, "@",
"RED::REDDAQInput::RunHint", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("REDDAQInputDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_REDDAQInputDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_REDDAQInputDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_REDDAQInputDict() {
  TriggerDictionaryInitialization_REDDAQInputDict_Impl();
}
