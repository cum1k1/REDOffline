// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME CsIDAQInputDict
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
#include "/home/lev/Документы/REDOffline/modules/CsIDAQInput/CsIDAQInput.hh"
#include "/home/lev/Документы/REDOffline/modules/CsIDAQInput/TTemplWaveform.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_REDcLcLCsIDAQInput(void *p = nullptr);
   static void *newArray_REDcLcLCsIDAQInput(Long_t size, void *p);
   static void delete_REDcLcLCsIDAQInput(void *p);
   static void deleteArray_REDcLcLCsIDAQInput(void *p);
   static void destruct_REDcLcLCsIDAQInput(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::CsIDAQInput*)
   {
      ::RED::CsIDAQInput *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::CsIDAQInput >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::CsIDAQInput", ::RED::CsIDAQInput::Class_Version(), "modules/CsIDAQInput/CsIDAQInput.hh", 14,
                  typeid(::RED::CsIDAQInput), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::CsIDAQInput::Dictionary, isa_proxy, 4,
                  sizeof(::RED::CsIDAQInput) );
      instance.SetNew(&new_REDcLcLCsIDAQInput);
      instance.SetNewArray(&newArray_REDcLcLCsIDAQInput);
      instance.SetDelete(&delete_REDcLcLCsIDAQInput);
      instance.SetDeleteArray(&deleteArray_REDcLcLCsIDAQInput);
      instance.SetDestructor(&destruct_REDcLcLCsIDAQInput);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::CsIDAQInput*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::CsIDAQInput*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::CsIDAQInput*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEdoublegR_Dictionary();
   static void TTemplWaveformlEdoublegR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEdoublegR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEdoublegR(Long_t size, void *p);
   static void delete_TTemplWaveformlEdoublegR(void *p);
   static void deleteArray_TTemplWaveformlEdoublegR(void *p);
   static void destruct_TTemplWaveformlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<double>*)
   {
      ::TTemplWaveform<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<double> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<double>", ::TTemplWaveform<double>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<double>) );
      instance.SetNew(&new_TTemplWaveformlEdoublegR);
      instance.SetNewArray(&newArray_TTemplWaveformlEdoublegR);
      instance.SetDelete(&delete_TTemplWaveformlEdoublegR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEdoublegR);
      instance.SetDestructor(&destruct_TTemplWaveformlEdoublegR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("TTemplWaveform<double>","TTemplWaveform<Double_t>"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<double>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<double>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<double>*>(nullptr))->GetClass();
      TTemplWaveformlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEintgR_Dictionary();
   static void TTemplWaveformlEintgR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEintgR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEintgR(Long_t size, void *p);
   static void delete_TTemplWaveformlEintgR(void *p);
   static void deleteArray_TTemplWaveformlEintgR(void *p);
   static void destruct_TTemplWaveformlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<int>*)
   {
      ::TTemplWaveform<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<int> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<int>", ::TTemplWaveform<int>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEintgR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<int>) );
      instance.SetNew(&new_TTemplWaveformlEintgR);
      instance.SetNewArray(&newArray_TTemplWaveformlEintgR);
      instance.SetDelete(&delete_TTemplWaveformlEintgR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEintgR);
      instance.SetDestructor(&destruct_TTemplWaveformlEintgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("TTemplWaveform<int>","TTemplWaveform<Int_t>"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<int>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<int>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<int>*>(nullptr))->GetClass();
      TTemplWaveformlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEunsignedsPshortgR_Dictionary();
   static void TTemplWaveformlEunsignedsPshortgR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEunsignedsPshortgR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEunsignedsPshortgR(Long_t size, void *p);
   static void delete_TTemplWaveformlEunsignedsPshortgR(void *p);
   static void deleteArray_TTemplWaveformlEunsignedsPshortgR(void *p);
   static void destruct_TTemplWaveformlEunsignedsPshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<unsigned short>*)
   {
      ::TTemplWaveform<unsigned short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<unsigned short> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<unsigned short>", ::TTemplWaveform<unsigned short>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<unsigned short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEunsignedsPshortgR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<unsigned short>) );
      instance.SetNew(&new_TTemplWaveformlEunsignedsPshortgR);
      instance.SetNewArray(&newArray_TTemplWaveformlEunsignedsPshortgR);
      instance.SetDelete(&delete_TTemplWaveformlEunsignedsPshortgR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEunsignedsPshortgR);
      instance.SetDestructor(&destruct_TTemplWaveformlEunsignedsPshortgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("TTemplWaveform<unsigned short>","TTemplWaveform<UShort_t>"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<unsigned short>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<unsigned short>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<unsigned short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEunsignedsPshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<unsigned short>*>(nullptr))->GetClass();
      TTemplWaveformlEunsignedsPshortgR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEunsignedsPshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEshortgR_Dictionary();
   static void TTemplWaveformlEshortgR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEshortgR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEshortgR(Long_t size, void *p);
   static void delete_TTemplWaveformlEshortgR(void *p);
   static void deleteArray_TTemplWaveformlEshortgR(void *p);
   static void destruct_TTemplWaveformlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<short>*)
   {
      ::TTemplWaveform<short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<short> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<short>", ::TTemplWaveform<short>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEshortgR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<short>) );
      instance.SetNew(&new_TTemplWaveformlEshortgR);
      instance.SetNewArray(&newArray_TTemplWaveformlEshortgR);
      instance.SetDelete(&delete_TTemplWaveformlEshortgR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEshortgR);
      instance.SetDestructor(&destruct_TTemplWaveformlEshortgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("TTemplWaveform<short>","TTemplWaveform<Short_t>"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<short>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<short>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<short>*>(nullptr))->GetClass();
      TTemplWaveformlEshortgR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEfloatgR_Dictionary();
   static void TTemplWaveformlEfloatgR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEfloatgR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEfloatgR(Long_t size, void *p);
   static void delete_TTemplWaveformlEfloatgR(void *p);
   static void deleteArray_TTemplWaveformlEfloatgR(void *p);
   static void destruct_TTemplWaveformlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<float>*)
   {
      ::TTemplWaveform<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<float> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<float>", ::TTemplWaveform<float>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<float>) );
      instance.SetNew(&new_TTemplWaveformlEfloatgR);
      instance.SetNewArray(&newArray_TTemplWaveformlEfloatgR);
      instance.SetDelete(&delete_TTemplWaveformlEfloatgR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEfloatgR);
      instance.SetDestructor(&destruct_TTemplWaveformlEfloatgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("TTemplWaveform<float>","TTemplWaveform<Float_t>"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<float>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<float>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<float>*>(nullptr))->GetClass();
      TTemplWaveformlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEunsignedsPlonggR_Dictionary();
   static void TTemplWaveformlEunsignedsPlonggR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEunsignedsPlonggR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEunsignedsPlonggR(Long_t size, void *p);
   static void delete_TTemplWaveformlEunsignedsPlonggR(void *p);
   static void deleteArray_TTemplWaveformlEunsignedsPlonggR(void *p);
   static void destruct_TTemplWaveformlEunsignedsPlonggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<unsigned long>*)
   {
      ::TTemplWaveform<unsigned long> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<unsigned long> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<unsigned long>", ::TTemplWaveform<unsigned long>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<unsigned long>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEunsignedsPlonggR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<unsigned long>) );
      instance.SetNew(&new_TTemplWaveformlEunsignedsPlonggR);
      instance.SetNewArray(&newArray_TTemplWaveformlEunsignedsPlonggR);
      instance.SetDelete(&delete_TTemplWaveformlEunsignedsPlonggR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEunsignedsPlonggR);
      instance.SetDestructor(&destruct_TTemplWaveformlEunsignedsPlonggR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<unsigned long>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<unsigned long>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<unsigned long>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEunsignedsPlonggR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<unsigned long>*>(nullptr))->GetClass();
      TTemplWaveformlEunsignedsPlonggR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEunsignedsPlonggR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEchargR_Dictionary();
   static void TTemplWaveformlEchargR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEchargR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEchargR(Long_t size, void *p);
   static void delete_TTemplWaveformlEchargR(void *p);
   static void deleteArray_TTemplWaveformlEchargR(void *p);
   static void destruct_TTemplWaveformlEchargR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<char>*)
   {
      ::TTemplWaveform<char> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<char> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<char>", ::TTemplWaveform<char>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<char>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEchargR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<char>) );
      instance.SetNew(&new_TTemplWaveformlEchargR);
      instance.SetNewArray(&newArray_TTemplWaveformlEchargR);
      instance.SetDelete(&delete_TTemplWaveformlEchargR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEchargR);
      instance.SetDestructor(&destruct_TTemplWaveformlEchargR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("TTemplWaveform<char>","TTemplWaveform<Char_t>"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<char>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<char>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<char>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEchargR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<char>*>(nullptr))->GetClass();
      TTemplWaveformlEchargR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEchargR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEcomplexlEdoublegRsPgR_Dictionary();
   static void TTemplWaveformlEcomplexlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEcomplexlEdoublegRsPgR(Long_t size, void *p);
   static void delete_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p);
   static void deleteArray_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p);
   static void destruct_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<complex<double> >*)
   {
      ::TTemplWaveform<complex<double> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<complex<double> > >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<complex<double> >", ::TTemplWaveform<complex<double> >::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<complex<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEcomplexlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<complex<double> >) );
      instance.SetNew(&new_TTemplWaveformlEcomplexlEdoublegRsPgR);
      instance.SetNewArray(&newArray_TTemplWaveformlEcomplexlEdoublegRsPgR);
      instance.SetDelete(&delete_TTemplWaveformlEcomplexlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEcomplexlEdoublegRsPgR);
      instance.SetDestructor(&destruct_TTemplWaveformlEcomplexlEdoublegRsPgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("TTemplWaveform<complex<double> >","TTemplWaveform<std::complex<double> >"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<complex<double> >*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<complex<double> >*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<complex<double> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEcomplexlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<complex<double> >*>(nullptr))->GetClass();
      TTemplWaveformlEcomplexlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEcomplexlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TTemplWaveformlEunsignedsPintgR_Dictionary();
   static void TTemplWaveformlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_TTemplWaveformlEunsignedsPintgR(void *p = nullptr);
   static void *newArray_TTemplWaveformlEunsignedsPintgR(Long_t size, void *p);
   static void delete_TTemplWaveformlEunsignedsPintgR(void *p);
   static void deleteArray_TTemplWaveformlEunsignedsPintgR(void *p);
   static void destruct_TTemplWaveformlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TTemplWaveform<unsigned int>*)
   {
      ::TTemplWaveform<unsigned int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TTemplWaveform<unsigned int> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TTemplWaveform<unsigned int>", ::TTemplWaveform<unsigned int>::Class_Version(), "modules/CsIDAQInput/TTemplWaveform.hh", 20,
                  typeid(::TTemplWaveform<unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TTemplWaveformlEunsignedsPintgR_Dictionary, isa_proxy, 4,
                  sizeof(::TTemplWaveform<unsigned int>) );
      instance.SetNew(&new_TTemplWaveformlEunsignedsPintgR);
      instance.SetNewArray(&newArray_TTemplWaveformlEunsignedsPintgR);
      instance.SetDelete(&delete_TTemplWaveformlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_TTemplWaveformlEunsignedsPintgR);
      instance.SetDestructor(&destruct_TTemplWaveformlEunsignedsPintgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TTemplWaveform<unsigned int>*)
   {
      return GenerateInitInstanceLocal(static_cast<::TTemplWaveform<unsigned int>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<unsigned int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TTemplWaveformlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::TTemplWaveform<unsigned int>*>(nullptr))->GetClass();
      TTemplWaveformlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void TTemplWaveformlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr CsIDAQInput::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CsIDAQInput::Class_Name()
{
   return "RED::CsIDAQInput";
}

//______________________________________________________________________________
const char *CsIDAQInput::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::CsIDAQInput*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CsIDAQInput::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::CsIDAQInput*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CsIDAQInput::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::CsIDAQInput*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CsIDAQInput::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::CsIDAQInput*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<double>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<double>::Class_Name()
{
   return "TTemplWaveform<double>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<double>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<double>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<double>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<double>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<double>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<double>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<double>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<double>*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<int>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<int>::Class_Name()
{
   return "TTemplWaveform<int>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<int>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<int>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<int>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<int>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<int>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<int>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<int>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<int>*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<unsigned short>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<unsigned short>::Class_Name()
{
   return "TTemplWaveform<unsigned short>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<unsigned short>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned short>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<unsigned short>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned short>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<unsigned short>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned short>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<unsigned short>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned short>*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<short>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<short>::Class_Name()
{
   return "TTemplWaveform<short>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<short>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<short>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<short>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<short>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<short>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<short>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<short>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<short>*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<float>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<float>::Class_Name()
{
   return "TTemplWaveform<float>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<float>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<float>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<float>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<float>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<float>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<float>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<float>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<float>*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<unsigned long>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<unsigned long>::Class_Name()
{
   return "TTemplWaveform<unsigned long>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<unsigned long>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned long>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<unsigned long>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned long>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<unsigned long>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned long>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<unsigned long>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned long>*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<char>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<char>::Class_Name()
{
   return "TTemplWaveform<char>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<char>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<char>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<char>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<char>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<char>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<char>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<char>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<char>*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<complex<double> >::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<complex<double> >::Class_Name()
{
   return "TTemplWaveform<complex<double> >";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<complex<double> >::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<complex<double> >*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<complex<double> >::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<complex<double> >*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<complex<double> >::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<complex<double> >*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<complex<double> >::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<complex<double> >*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
template <> atomic_TClass_ptr TTemplWaveform<unsigned int>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *TTemplWaveform<unsigned int>::Class_Name()
{
   return "TTemplWaveform<unsigned int>";
}

//______________________________________________________________________________
template <> const char *TTemplWaveform<unsigned int>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned int>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int TTemplWaveform<unsigned int>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned int>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<unsigned int>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned int>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *TTemplWaveform<unsigned int>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TTemplWaveform<unsigned int>*)nullptr)->GetClass(); }
   return fgIsA;
}

namespace RED {
//______________________________________________________________________________
void CsIDAQInput::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::CsIDAQInput.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RED::CsIDAQInput::Class(),this);
   } else {
      R__b.WriteClassBuffer(RED::CsIDAQInput::Class(),this);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLCsIDAQInput(void *p) {
      return  p ? new(p) ::RED::CsIDAQInput : new ::RED::CsIDAQInput;
   }
   static void *newArray_REDcLcLCsIDAQInput(Long_t nElements, void *p) {
      return p ? new(p) ::RED::CsIDAQInput[nElements] : new ::RED::CsIDAQInput[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLCsIDAQInput(void *p) {
      delete (static_cast<::RED::CsIDAQInput*>(p));
   }
   static void deleteArray_REDcLcLCsIDAQInput(void *p) {
      delete [] (static_cast<::RED::CsIDAQInput*>(p));
   }
   static void destruct_REDcLcLCsIDAQInput(void *p) {
      typedef ::RED::CsIDAQInput current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::RED::CsIDAQInput

//______________________________________________________________________________
template <> void TTemplWaveform<double>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<double>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<double>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<double>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEdoublegR(void *p) {
      return  p ? new(p) ::TTemplWaveform<double> : new ::TTemplWaveform<double>;
   }
   static void *newArray_TTemplWaveformlEdoublegR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<double>[nElements] : new ::TTemplWaveform<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEdoublegR(void *p) {
      delete (static_cast<::TTemplWaveform<double>*>(p));
   }
   static void deleteArray_TTemplWaveformlEdoublegR(void *p) {
      delete [] (static_cast<::TTemplWaveform<double>*>(p));
   }
   static void destruct_TTemplWaveformlEdoublegR(void *p) {
      typedef ::TTemplWaveform<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<double>

//______________________________________________________________________________
template <> void TTemplWaveform<int>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<int>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<int>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<int>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEintgR(void *p) {
      return  p ? new(p) ::TTemplWaveform<int> : new ::TTemplWaveform<int>;
   }
   static void *newArray_TTemplWaveformlEintgR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<int>[nElements] : new ::TTemplWaveform<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEintgR(void *p) {
      delete (static_cast<::TTemplWaveform<int>*>(p));
   }
   static void deleteArray_TTemplWaveformlEintgR(void *p) {
      delete [] (static_cast<::TTemplWaveform<int>*>(p));
   }
   static void destruct_TTemplWaveformlEintgR(void *p) {
      typedef ::TTemplWaveform<int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<int>

//______________________________________________________________________________
template <> void TTemplWaveform<unsigned short>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<unsigned short>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<unsigned short>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<unsigned short>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEunsignedsPshortgR(void *p) {
      return  p ? new(p) ::TTemplWaveform<unsigned short> : new ::TTemplWaveform<unsigned short>;
   }
   static void *newArray_TTemplWaveformlEunsignedsPshortgR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<unsigned short>[nElements] : new ::TTemplWaveform<unsigned short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEunsignedsPshortgR(void *p) {
      delete (static_cast<::TTemplWaveform<unsigned short>*>(p));
   }
   static void deleteArray_TTemplWaveformlEunsignedsPshortgR(void *p) {
      delete [] (static_cast<::TTemplWaveform<unsigned short>*>(p));
   }
   static void destruct_TTemplWaveformlEunsignedsPshortgR(void *p) {
      typedef ::TTemplWaveform<unsigned short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<unsigned short>

//______________________________________________________________________________
template <> void TTemplWaveform<short>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<short>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<short>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<short>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEshortgR(void *p) {
      return  p ? new(p) ::TTemplWaveform<short> : new ::TTemplWaveform<short>;
   }
   static void *newArray_TTemplWaveformlEshortgR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<short>[nElements] : new ::TTemplWaveform<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEshortgR(void *p) {
      delete (static_cast<::TTemplWaveform<short>*>(p));
   }
   static void deleteArray_TTemplWaveformlEshortgR(void *p) {
      delete [] (static_cast<::TTemplWaveform<short>*>(p));
   }
   static void destruct_TTemplWaveformlEshortgR(void *p) {
      typedef ::TTemplWaveform<short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<short>

//______________________________________________________________________________
template <> void TTemplWaveform<float>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<float>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<float>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<float>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEfloatgR(void *p) {
      return  p ? new(p) ::TTemplWaveform<float> : new ::TTemplWaveform<float>;
   }
   static void *newArray_TTemplWaveformlEfloatgR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<float>[nElements] : new ::TTemplWaveform<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEfloatgR(void *p) {
      delete (static_cast<::TTemplWaveform<float>*>(p));
   }
   static void deleteArray_TTemplWaveformlEfloatgR(void *p) {
      delete [] (static_cast<::TTemplWaveform<float>*>(p));
   }
   static void destruct_TTemplWaveformlEfloatgR(void *p) {
      typedef ::TTemplWaveform<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<float>

//______________________________________________________________________________
template <> void TTemplWaveform<unsigned long>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<unsigned long>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<unsigned long>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<unsigned long>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEunsignedsPlonggR(void *p) {
      return  p ? new(p) ::TTemplWaveform<unsigned long> : new ::TTemplWaveform<unsigned long>;
   }
   static void *newArray_TTemplWaveformlEunsignedsPlonggR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<unsigned long>[nElements] : new ::TTemplWaveform<unsigned long>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEunsignedsPlonggR(void *p) {
      delete (static_cast<::TTemplWaveform<unsigned long>*>(p));
   }
   static void deleteArray_TTemplWaveformlEunsignedsPlonggR(void *p) {
      delete [] (static_cast<::TTemplWaveform<unsigned long>*>(p));
   }
   static void destruct_TTemplWaveformlEunsignedsPlonggR(void *p) {
      typedef ::TTemplWaveform<unsigned long> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<unsigned long>

//______________________________________________________________________________
template <> void TTemplWaveform<char>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<char>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<char>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<char>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEchargR(void *p) {
      return  p ? new(p) ::TTemplWaveform<char> : new ::TTemplWaveform<char>;
   }
   static void *newArray_TTemplWaveformlEchargR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<char>[nElements] : new ::TTemplWaveform<char>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEchargR(void *p) {
      delete (static_cast<::TTemplWaveform<char>*>(p));
   }
   static void deleteArray_TTemplWaveformlEchargR(void *p) {
      delete [] (static_cast<::TTemplWaveform<char>*>(p));
   }
   static void destruct_TTemplWaveformlEchargR(void *p) {
      typedef ::TTemplWaveform<char> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<char>

//______________________________________________________________________________
template <> void TTemplWaveform<complex<double> >::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<complex<double> >.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<complex<double> >::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<complex<double> >::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p) {
      return  p ? new(p) ::TTemplWaveform<complex<double> > : new ::TTemplWaveform<complex<double> >;
   }
   static void *newArray_TTemplWaveformlEcomplexlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<complex<double> >[nElements] : new ::TTemplWaveform<complex<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p) {
      delete (static_cast<::TTemplWaveform<complex<double> >*>(p));
   }
   static void deleteArray_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p) {
      delete [] (static_cast<::TTemplWaveform<complex<double> >*>(p));
   }
   static void destruct_TTemplWaveformlEcomplexlEdoublegRsPgR(void *p) {
      typedef ::TTemplWaveform<complex<double> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<complex<double> >

//______________________________________________________________________________
template <> void TTemplWaveform<unsigned int>::Streamer(TBuffer &R__b)
{
   // Stream an object of class TTemplWaveform<unsigned int>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TTemplWaveform<unsigned int>::Class(),this);
   } else {
      R__b.WriteClassBuffer(TTemplWaveform<unsigned int>::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TTemplWaveformlEunsignedsPintgR(void *p) {
      return  p ? new(p) ::TTemplWaveform<unsigned int> : new ::TTemplWaveform<unsigned int>;
   }
   static void *newArray_TTemplWaveformlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? new(p) ::TTemplWaveform<unsigned int>[nElements] : new ::TTemplWaveform<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_TTemplWaveformlEunsignedsPintgR(void *p) {
      delete (static_cast<::TTemplWaveform<unsigned int>*>(p));
   }
   static void deleteArray_TTemplWaveformlEunsignedsPintgR(void *p) {
      delete [] (static_cast<::TTemplWaveform<unsigned int>*>(p));
   }
   static void destruct_TTemplWaveformlEunsignedsPintgR(void *p) {
      typedef ::TTemplWaveform<unsigned int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::TTemplWaveform<unsigned int>

namespace ROOT {
   static TClass *vectorlEunsignedsPshortgR_Dictionary();
   static void vectorlEunsignedsPshortgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPshortgR(void *p = nullptr);
   static void *newArray_vectorlEunsignedsPshortgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPshortgR(void *p);
   static void deleteArray_vectorlEunsignedsPshortgR(void *p);
   static void destruct_vectorlEunsignedsPshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned short>*)
   {
      vector<unsigned short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned short>", -2, "vector", 458,
                  typeid(vector<unsigned short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned short>) );
      instance.SetNew(&new_vectorlEunsignedsPshortgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPshortgR);
      instance.SetDelete(&delete_vectorlEunsignedsPshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPshortgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned short> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<unsigned short>","std::vector<unsigned short, std::allocator<unsigned short> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<unsigned short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<unsigned short>*>(nullptr))->GetClass();
      vectorlEunsignedsPshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPshortgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned short> : new vector<unsigned short>;
   }
   static void *newArray_vectorlEunsignedsPshortgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned short>[nElements] : new vector<unsigned short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPshortgR(void *p) {
      delete (static_cast<vector<unsigned short>*>(p));
   }
   static void deleteArray_vectorlEunsignedsPshortgR(void *p) {
      delete [] (static_cast<vector<unsigned short>*>(p));
   }
   static void destruct_vectorlEunsignedsPshortgR(void *p) {
      typedef vector<unsigned short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned short>

namespace ROOT {
   static TClass *vectorlEunsignedsPlonggR_Dictionary();
   static void vectorlEunsignedsPlonggR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPlonggR(void *p = nullptr);
   static void *newArray_vectorlEunsignedsPlonggR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPlonggR(void *p);
   static void deleteArray_vectorlEunsignedsPlonggR(void *p);
   static void destruct_vectorlEunsignedsPlonggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned long>*)
   {
      vector<unsigned long> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned long>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned long>", -2, "vector", 458,
                  typeid(vector<unsigned long>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPlonggR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned long>) );
      instance.SetNew(&new_vectorlEunsignedsPlonggR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPlonggR);
      instance.SetDelete(&delete_vectorlEunsignedsPlonggR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPlonggR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPlonggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned long> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<unsigned long>","std::vector<unsigned long, std::allocator<unsigned long> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<unsigned long>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPlonggR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<unsigned long>*>(nullptr))->GetClass();
      vectorlEunsignedsPlonggR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPlonggR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPlonggR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned long> : new vector<unsigned long>;
   }
   static void *newArray_vectorlEunsignedsPlonggR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned long>[nElements] : new vector<unsigned long>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPlonggR(void *p) {
      delete (static_cast<vector<unsigned long>*>(p));
   }
   static void deleteArray_vectorlEunsignedsPlonggR(void *p) {
      delete [] (static_cast<vector<unsigned long>*>(p));
   }
   static void destruct_vectorlEunsignedsPlonggR(void *p) {
      typedef vector<unsigned long> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned long>

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = nullptr);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 458,
                  typeid(vector<unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<unsigned int>","std::vector<unsigned int, std::allocator<unsigned int> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<unsigned int>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<unsigned int>*>(nullptr))->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete (static_cast<vector<unsigned int>*>(p));
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] (static_cast<vector<unsigned int>*>(p));
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlEshortgR_Dictionary();
   static void vectorlEshortgR_TClassManip(TClass*);
   static void *new_vectorlEshortgR(void *p = nullptr);
   static void *newArray_vectorlEshortgR(Long_t size, void *p);
   static void delete_vectorlEshortgR(void *p);
   static void deleteArray_vectorlEshortgR(void *p);
   static void destruct_vectorlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<short>*)
   {
      vector<short> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<short>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<short>", -2, "vector", 458,
                  typeid(vector<short>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<short>) );
      instance.SetNew(&new_vectorlEshortgR);
      instance.SetNewArray(&newArray_vectorlEshortgR);
      instance.SetDelete(&delete_vectorlEshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEshortgR);
      instance.SetDestructor(&destruct_vectorlEshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<short> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<short>","std::vector<short, std::allocator<short> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<short>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<short>*>(nullptr))->GetClass();
      vectorlEshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEshortgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<short> : new vector<short>;
   }
   static void *newArray_vectorlEshortgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<short>[nElements] : new vector<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEshortgR(void *p) {
      delete (static_cast<vector<short>*>(p));
   }
   static void deleteArray_vectorlEshortgR(void *p) {
      delete [] (static_cast<vector<short>*>(p));
   }
   static void destruct_vectorlEshortgR(void *p) {
      typedef vector<short> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<short>

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
   static TClass *vectorlEcomplexlEdoublegRsPgR_Dictionary();
   static void vectorlEcomplexlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEcomplexlEdoublegRsPgR(void *p = nullptr);
   static void *newArray_vectorlEcomplexlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEcomplexlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEcomplexlEdoublegRsPgR(void *p);
   static void destruct_vectorlEcomplexlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<complex<double> >*)
   {
      vector<complex<double> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<complex<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<complex<double> >", -2, "vector", 458,
                  typeid(vector<complex<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEcomplexlEdoublegRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<complex<double> >) );
      instance.SetNew(&new_vectorlEcomplexlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEcomplexlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEcomplexlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEcomplexlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEcomplexlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<complex<double> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<complex<double> >","std::vector<std::complex<double>, std::allocator<std::complex<double> > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<complex<double> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEcomplexlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<complex<double> >*>(nullptr))->GetClass();
      vectorlEcomplexlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEcomplexlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEcomplexlEdoublegRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<complex<double> > : new vector<complex<double> >;
   }
   static void *newArray_vectorlEcomplexlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<complex<double> >[nElements] : new vector<complex<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEcomplexlEdoublegRsPgR(void *p) {
      delete (static_cast<vector<complex<double> >*>(p));
   }
   static void deleteArray_vectorlEcomplexlEdoublegRsPgR(void *p) {
      delete [] (static_cast<vector<complex<double> >*>(p));
   }
   static void destruct_vectorlEcomplexlEdoublegRsPgR(void *p) {
      typedef vector<complex<double> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<complex<double> >

namespace ROOT {
   static TClass *vectorlEchargR_Dictionary();
   static void vectorlEchargR_TClassManip(TClass*);
   static void *new_vectorlEchargR(void *p = nullptr);
   static void *newArray_vectorlEchargR(Long_t size, void *p);
   static void delete_vectorlEchargR(void *p);
   static void deleteArray_vectorlEchargR(void *p);
   static void destruct_vectorlEchargR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<char>*)
   {
      vector<char> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<char>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<char>", -2, "vector", 458,
                  typeid(vector<char>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEchargR_Dictionary, isa_proxy, 0,
                  sizeof(vector<char>) );
      instance.SetNew(&new_vectorlEchargR);
      instance.SetNewArray(&newArray_vectorlEchargR);
      instance.SetDelete(&delete_vectorlEchargR);
      instance.SetDeleteArray(&deleteArray_vectorlEchargR);
      instance.SetDestructor(&destruct_vectorlEchargR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<char> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<char>","std::vector<char, std::allocator<char> >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<char>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEchargR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<char>*>(nullptr))->GetClass();
      vectorlEchargR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEchargR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEchargR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<char> : new vector<char>;
   }
   static void *newArray_vectorlEchargR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<char>[nElements] : new vector<char>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEchargR(void *p) {
      delete (static_cast<vector<char>*>(p));
   }
   static void deleteArray_vectorlEchargR(void *p) {
      delete [] (static_cast<vector<char>*>(p));
   }
   static void destruct_vectorlEchargR(void *p) {
      typedef vector<char> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<char>

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_CsIDAQInputDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_CsIDAQInputDict) = RecordReadRules_CsIDAQInputDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_CsIDAQInputDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_CsIDAQInputDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/modules/CsIDAQInput/CsIDAQInput.hh",
"/home/lev/Документы/REDOffline/modules/CsIDAQInput/TTemplWaveform.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/modules/CsIDAQInput/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CsIDAQInputDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/CsIDAQInput/CsIDAQInput.hh")))  CsIDAQInput;}
template <typename _Tp> class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/CsIDAQInput/TTemplWaveform.hh")))  TTemplWaveform;

namespace std{template <typename _Tp> class  __attribute__((annotate("$clingAutoload$complex")))  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/modules/CsIDAQInput/TTemplWaveform.hh")))  complex;
}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CsIDAQInputDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/modules/CsIDAQInput/CsIDAQInput.hh"
#include "/home/lev/Документы/REDOffline/modules/CsIDAQInput/TTemplWaveform.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::CsIDAQInput", payloadCode, "@",
"TTemplWaveform<Char_t>", payloadCode, "@",
"TTemplWaveform<Double_t>", payloadCode, "@",
"TTemplWaveform<Float_t>", payloadCode, "@",
"TTemplWaveform<Int_t>", payloadCode, "@",
"TTemplWaveform<Short_t>", payloadCode, "@",
"TTemplWaveform<UShort_t>", payloadCode, "@",
"TTemplWaveform<char>", payloadCode, "@",
"TTemplWaveform<complex<double> >", payloadCode, "@",
"TTemplWaveform<double>", payloadCode, "@",
"TTemplWaveform<float>", payloadCode, "@",
"TTemplWaveform<int>", payloadCode, "@",
"TTemplWaveform<short>", payloadCode, "@",
"TTemplWaveform<unsigned int>", payloadCode, "@",
"TTemplWaveform<unsigned long>", payloadCode, "@",
"TTemplWaveform<unsigned short>", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CsIDAQInputDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CsIDAQInputDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CsIDAQInputDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CsIDAQInputDict() {
  TriggerDictionaryInitialization_CsIDAQInputDict_Impl();
}
