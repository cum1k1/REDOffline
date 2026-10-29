// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME FileDict
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
#include "/home/lev/Документы/REDOffline/REDFile/File.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void delete_REDcLcLFile(void *p);
   static void deleteArray_REDcLcLFile(void *p);
   static void destruct_REDcLcLFile(void *p);
   static void streamer_REDcLcLFile(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::File*)
   {
      ::RED::File *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::File >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::File", ::RED::File::Class_Version(), "REDFile/File.hh", 36,
                  typeid(::RED::File), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::File::Dictionary, isa_proxy, 16,
                  sizeof(::RED::File) );
      instance.SetDelete(&delete_REDcLcLFile);
      instance.SetDeleteArray(&deleteArray_REDcLcLFile);
      instance.SetDestructor(&destruct_REDcLcLFile);
      instance.SetStreamerFunc(&streamer_REDcLcLFile);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::File*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::File*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::File*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLInputFile(void *p = nullptr);
   static void *newArray_REDcLcLInputFile(Long_t size, void *p);
   static void delete_REDcLcLInputFile(void *p);
   static void deleteArray_REDcLcLInputFile(void *p);
   static void destruct_REDcLcLInputFile(void *p);
   static void streamer_REDcLcLInputFile(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::InputFile*)
   {
      ::RED::InputFile *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::InputFile >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::InputFile", ::RED::InputFile::Class_Version(), "REDFile/File.hh", 164,
                  typeid(::RED::InputFile), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::InputFile::Dictionary, isa_proxy, 16,
                  sizeof(::RED::InputFile) );
      instance.SetNew(&new_REDcLcLInputFile);
      instance.SetNewArray(&newArray_REDcLcLInputFile);
      instance.SetDelete(&delete_REDcLcLInputFile);
      instance.SetDeleteArray(&deleteArray_REDcLcLInputFile);
      instance.SetDestructor(&destruct_REDcLcLInputFile);
      instance.SetStreamerFunc(&streamer_REDcLcLInputFile);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::InputFile*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::InputFile*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::InputFile*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_REDcLcLOutputFile(void *p = nullptr);
   static void *newArray_REDcLcLOutputFile(Long_t size, void *p);
   static void delete_REDcLcLOutputFile(void *p);
   static void deleteArray_REDcLcLOutputFile(void *p);
   static void destruct_REDcLcLOutputFile(void *p);
   static void streamer_REDcLcLOutputFile(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RED::OutputFile*)
   {
      ::RED::OutputFile *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RED::OutputFile >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("RED::OutputFile", ::RED::OutputFile::Class_Version(), "REDFile/File.hh", 190,
                  typeid(::RED::OutputFile), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::RED::OutputFile::Dictionary, isa_proxy, 16,
                  sizeof(::RED::OutputFile) );
      instance.SetNew(&new_REDcLcLOutputFile);
      instance.SetNewArray(&newArray_REDcLcLOutputFile);
      instance.SetDelete(&delete_REDcLcLOutputFile);
      instance.SetDeleteArray(&deleteArray_REDcLcLOutputFile);
      instance.SetDestructor(&destruct_REDcLcLOutputFile);
      instance.SetStreamerFunc(&streamer_REDcLcLOutputFile);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RED::OutputFile*)
   {
      return GenerateInitInstanceLocal(static_cast<::RED::OutputFile*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::RED::OutputFile*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr File::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *File::Class_Name()
{
   return "RED::File";
}

//______________________________________________________________________________
const char *File::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::File*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int File::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::File*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *File::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::File*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *File::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::File*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr InputFile::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *InputFile::Class_Name()
{
   return "RED::InputFile";
}

//______________________________________________________________________________
const char *InputFile::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::InputFile*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int InputFile::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::InputFile*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *InputFile::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::InputFile*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *InputFile::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::InputFile*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
atomic_TClass_ptr OutputFile::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *OutputFile::Class_Name()
{
   return "RED::OutputFile";
}

//______________________________________________________________________________
const char *OutputFile::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputFile*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int OutputFile::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputFile*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *OutputFile::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputFile*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *OutputFile::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RED::OutputFile*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace RED
namespace RED {
//______________________________________________________________________________
void File::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::File.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::RED::File thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TNamed::Streamer(R__b);
      R__b >> fUseLegacyMode;
      R__b >> fFile;
      R__b >> fRunTree;
      R__b >> fEventTree;
      R__b >> fPulseTree;
      R__b >> fEvent;
      R__b >> fRun;
      R__b >> fPulses;
      R__b >> fClusters;
      R__b >> fRecordCounter;
      R__b >> fMaxNumOfChannels;
      R__b >> fMaxNumOfPulses;
      R__b >> fMaxNumOfClusters;
      R__b >> fInit;
      R__b >> fVerbose;
      { TString R__str; R__str.Streamer(R__b); fFileName = R__str.Data(); }
      fRunInfo.Streamer(R__b);
      fProcInfo.Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      TNamed::Streamer(R__b);
      R__b << fUseLegacyMode;
      R__b << fFile;
      R__b << fRunTree;
      R__b << fEventTree;
      R__b << fPulseTree;
      R__b << fEvent;
      R__b << fRun;
      R__b << fPulses;
      R__b << fClusters;
      R__b << fRecordCounter;
      R__b << fMaxNumOfChannels;
      R__b << fMaxNumOfPulses;
      R__b << fMaxNumOfClusters;
      R__b << fInit;
      R__b << fVerbose;
      { TString R__str = fFileName.c_str(); R__str.Streamer(R__b);}
      fRunInfo.Streamer(R__b);
      fProcInfo.Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace RED
namespace ROOT {
   // Wrapper around operator delete
   static void delete_REDcLcLFile(void *p) {
      delete (static_cast<::RED::File*>(p));
   }
   static void deleteArray_REDcLcLFile(void *p) {
      delete [] (static_cast<::RED::File*>(p));
   }
   static void destruct_REDcLcLFile(void *p) {
      typedef ::RED::File current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_REDcLcLFile(TBuffer &buf, void *obj) {
      ((::RED::File*)obj)->::RED::File::Streamer(buf);
   }
} // end of namespace ROOT for class ::RED::File

namespace RED {
//______________________________________________________________________________
void InputFile::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::InputFile.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::RED::InputFile thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      //This works around a msvc bug and should be harmless on other platforms
      typedef RED::File baseClass0;
      baseClass0::Streamer(R__b);
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      //This works around a msvc bug and should be harmless on other platforms
      typedef RED::File baseClass0;
      baseClass0::Streamer(R__b);
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLInputFile(void *p) {
      return  p ? new(p) ::RED::InputFile : new ::RED::InputFile;
   }
   static void *newArray_REDcLcLInputFile(Long_t nElements, void *p) {
      return p ? new(p) ::RED::InputFile[nElements] : new ::RED::InputFile[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLInputFile(void *p) {
      delete (static_cast<::RED::InputFile*>(p));
   }
   static void deleteArray_REDcLcLInputFile(void *p) {
      delete [] (static_cast<::RED::InputFile*>(p));
   }
   static void destruct_REDcLcLInputFile(void *p) {
      typedef ::RED::InputFile current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_REDcLcLInputFile(TBuffer &buf, void *obj) {
      ((::RED::InputFile*)obj)->::RED::InputFile::Streamer(buf);
   }
} // end of namespace ROOT for class ::RED::InputFile

namespace RED {
//______________________________________________________________________________
void OutputFile::Streamer(TBuffer &R__b)
{
   // Stream an object of class RED::OutputFile.

   //This works around a msvc bug and should be harmless on other platforms
   typedef ::RED::OutputFile thisClass;
   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      //This works around a msvc bug and should be harmless on other platforms
      typedef RED::File baseClass0;
      baseClass0::Streamer(R__b);
      R__b >> fRunInfoCached;
      R__b.CheckByteCount(R__s, R__c, thisClass::IsA());
   } else {
      R__c = R__b.WriteVersion(thisClass::IsA(), kTRUE);
      //This works around a msvc bug and should be harmless on other platforms
      typedef RED::File baseClass0;
      baseClass0::Streamer(R__b);
      R__b << fRunInfoCached;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

} // namespace RED
namespace ROOT {
   // Wrappers around operator new
   static void *new_REDcLcLOutputFile(void *p) {
      return  p ? new(p) ::RED::OutputFile : new ::RED::OutputFile;
   }
   static void *newArray_REDcLcLOutputFile(Long_t nElements, void *p) {
      return p ? new(p) ::RED::OutputFile[nElements] : new ::RED::OutputFile[nElements];
   }
   // Wrapper around operator delete
   static void delete_REDcLcLOutputFile(void *p) {
      delete (static_cast<::RED::OutputFile*>(p));
   }
   static void deleteArray_REDcLcLOutputFile(void *p) {
      delete [] (static_cast<::RED::OutputFile*>(p));
   }
   static void destruct_REDcLcLOutputFile(void *p) {
      typedef ::RED::OutputFile current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_REDcLcLOutputFile(TBuffer &buf, void *obj) {
      ((::RED::OutputFile*)obj)->::RED::OutputFile::Streamer(buf);
   }
} // end of namespace ROOT for class ::RED::OutputFile

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 458,
                  typeid(vector<vector<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<int> >","std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<int> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<int> >*>(nullptr))->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete (static_cast<vector<vector<int> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] (static_cast<vector<vector<int> >*>(p));
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 458,
                  typeid(vector<vector<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<vector<float> >","std::vector<std::vector<float, std::allocator<float> >, std::allocator<std::vector<float, std::allocator<float> > > >"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<vector<float> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<vector<float> >*>(nullptr))->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete (static_cast<vector<vector<float> >*>(p));
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] (static_cast<vector<vector<float> >*>(p));
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

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
                  &vectorlEintgR_Dictionary, isa_proxy, 4,
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
                  &vectorlEfloatgR_Dictionary, isa_proxy, 4,
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
   int RecordReadRules_FileDict() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_FileDict) = RecordReadRules_FileDict();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_FileDict));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_FileDict_Impl() {
    static const char* headers[] = {
"/home/lev/Документы/REDOffline/REDFile/File.hh",
nullptr
    };
    static const char* includePaths[] = {
"/home/lev/Документы/REDOffline",
"/usr/include/root",
"/home/lev/Документы/REDOffline/build/REDFile/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "FileDict dictionary forward declarations' payload"

#pragma diagnostic push
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace std{template <typename _Tp> class  __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDFile/File.hh")))  File;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDFile/File.hh")))  InputFile;}
namespace RED{class  __attribute__((annotate("$clingAutoload$/home/lev/Документы/REDOffline/REDFile/File.hh")))  OutputFile;}
#pragma diagnostic pop
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "FileDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/home/lev/Документы/REDOffline/REDFile/File.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"RED::File", payloadCode, "@",
"RED::InputFile", payloadCode, "@",
"RED::OutputFile", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("FileDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_FileDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_FileDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_FileDict() {
  TriggerDictionaryInitialization_FileDict_Impl();
}
