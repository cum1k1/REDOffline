#ifndef RED_ProcessingModuleFactory_hh
#define RED_ProcessingModuleFactory_hh

#include <string>
#include <map>
#include <vector>

namespace RED
{

  class Event;
  class ProcessingModule;
  class VProcessingModuleBuilder;

  class ProcessingModuleFactory
  {
  public:

    // This class is singleton
    static ProcessingModuleFactory& GetInstance();
    void Print( const char* option = "") const;

    void RegisterBuilder(VProcessingModuleBuilder* builder);
    void DeregisterBuilder(VProcessingModuleBuilder* builder);

    ProcessingModule* CreateModule(const std::string& class_, const std::string& name);
    void DestroyModule(ProcessingModule* mod);

  private:
    // singleton
    ProcessingModuleFactory() { ; }
    ProcessingModuleFactory(const ProcessingModuleFactory&) { ; }
    ~ProcessingModuleFactory();
    ProcessingModuleFactory& operator=(const ProcessingModuleFactory&);

    typedef std::vector< ProcessingModule* > ModuleVector;
    struct BuilderContainer {
      VProcessingModuleBuilder* fBuilder;
      bool fEnabled;
      ModuleVector fModules;
    };
    typedef std::map< std::string, BuilderContainer > ClassMap;

    ClassMap   fBuilders; // list of registered builders, class name is key

  };


  class VProcessingModuleBuilder {
    /* Utility class. 
       This provides the interface for ProcessingModuleFactory.
       The constructor/destructor perform automatic registration with the factory. */

  private:
    VProcessingModuleBuilder() { ; }
    template <typename T> friend class ProcessingModuleBuilder;

  public:
    virtual ~VProcessingModuleBuilder() { ; }

    virtual ProcessingModule* Create(const char*) = 0;
    virtual void Destroy(ProcessingModule*) = 0;
    virtual const char* GetClass() const = 0;

  };

  template <typename T>
  class ProcessingModuleBuilder: public VProcessingModuleBuilder
  {
    /* Template implementation of module builder. */
  public:
    ProcessingModuleBuilder() { 
      ProcessingModuleFactory::GetInstance().RegisterBuilder(this); }
    ~ProcessingModuleBuilder() {
      ProcessingModuleFactory::GetInstance().DeregisterBuilder(this); }

    ProcessingModule* Create(const char *name) { 
      T* o = new T(); o->SetName(name); return o; }
    void Destroy(ProcessingModule* m) { delete m; }
    const char* GetClass() const { return T::Class_Name(); }
  };

  // ClassDef can't be included into MODULE_DEFINE because rootcint looks 
  // for exactly it.
#define RED_PROCESSING_MODULE_DEFINE(Class) \

  // Just for symmetry we don't include ClassImp into MODULE_IMPLEMENT.
#define RED_PROCESSING_MODULE_IMPLEMENT(Class) \
  RED::ProcessingModuleBuilder< RED:: Class > gProcessingBuilder_##Class;

} // namespace

#endif /* RED_ProcessingModuleFactory_hh */
