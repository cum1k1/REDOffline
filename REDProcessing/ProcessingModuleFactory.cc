//
//
//
// NOT THREAD_SAFE
// Removal of both modules and builders doesn't care about external users.
// To handle this better we should return modules in smart_ptr or something.
// 

#include <iostream>
#include <TClass.h>

#include "REDProcessing/ProcessingModuleFactory.hh"
#include "REDProcessing/ProcessingModule.hh"

using namespace RED;

//______________________________________________________________________________
ProcessingModuleFactory& ProcessingModuleFactory::GetInstance()
{
  static ProcessingModuleFactory mgProcessingModuleFactory;
  return mgProcessingModuleFactory;
}

//______________________________________________________________________________
void ProcessingModuleFactory::RegisterBuilder(VProcessingModuleBuilder* builder)
{
  // Register a builder class.  Users will gnenerally never call
  // this function directly, but the function registers with the
  // factory a builder which is known by the class name. 

  if (builder==0) return;
  if (fBuilders.find(builder->GetClass())!=fBuilders.end()) {
    std::clog << "ProcessingModuleFactory: Trying to double register builder for class " << builder->GetClass() << std::endl;
    // we should actually throw an exception here
    return;
  }
  BuilderContainer c;
  c.fBuilder = builder, c.fEnabled = true;
  fBuilders[builder->GetClass()] = c;
}

//______________________________________________________________________________
void ProcessingModuleFactory::DeregisterBuilder(VProcessingModuleBuilder* builder)
{
  // For completeness, include the deregistration.  Again, this
  // will likely never be called directly, but this removes
  // a designated builder from the factory.

  if (builder==0) return;

  std::string className = builder->GetClass();
  ClassMap::iterator ibuilder = fBuilders.find(className);
  if (ibuilder == fBuilders.end()) {
    std::clog << "ProcessingModuleFactory: Trying deregister builder for unknown class " << className << std::endl;
    // we should actually throw an exception here
    return;
  }

  BuilderContainer &c = ibuilder->second;
  c.fEnabled = false;

  // Now let's remove all modules of this class
  // This is dangerous if modules are still in use
  for (ModuleVector::iterator imodule = c.fModules.begin(); 
       imodule!=c.fModules.end(); imodule++)
    c.fBuilder->Destroy(*imodule);
  c.fModules.clear();

  fBuilders.erase(ibuilder);
}

//______________________________________________________________________________
ProcessingModule* ProcessingModuleFactory::CreateModule(const std::string& className, const std::string& name)
{
  // Generate an processing module using the name of the class and with
  // name provided. All modules generated this way should be deleted
  // using DestroyModule().

  ClassMap::iterator ibuilder = fBuilders.find(className);
  if (ibuilder == fBuilders.end()) {
    std::clog << "ProcessingModuleFactory: Trying create unknown class " << className << std::endl;
    // we should actually throw an exception here
    return 0;
  }

  BuilderContainer &c = ibuilder->second;
  if (!c.fEnabled) {
    std::clog << "ProcessingModuleFactory: Trying create module of disabled class " << className << std::endl;
    // we should actually throw an exception here
    return 0;
  }

  // FIXME CanBeManifold()?

  // Let's check name. Look through _all_ modules.
  bool match = false;
  for (ClassMap::iterator ibuilder = fBuilders.begin(); 
       ibuilder != fBuilders.end(); ibuilder++) {
    BuilderContainer &c = ibuilder->second;
    for (ModuleVector::iterator imodule = c.fModules.begin(); 
	 imodule!=c.fModules.end(); imodule++)
      if ((*imodule)->GetName()==name)
	{ match = true; break; }
    if (match) break;
  }
  if (match) {
    std::clog << "ProcessingModuleFactory: Trying create module with existing name " << name << std::endl;
    // we should actually throw an exception here
    return 0;
  }

  ProcessingModule* module = c.fBuilder->Create(name.c_str());
  c.fModules.push_back(module);
  return module;
}

//______________________________________________________________________________
void ProcessingModuleFactory::DestroyModule(ProcessingModule* module)
{
  // Destroy processing module. This should be called to destroy any
  // module created using CreateModule().

  std::string className = module->IsA()->GetName();
  ClassMap::iterator ibuilder = fBuilders.find(className);
  if (ibuilder == fBuilders.end()) {
    std::clog << "ProcessingModuleFactory: Trying remove module of unknown class " << className << std::endl;
    // we should actually throw an exception here
    return;
  }

  BuilderContainer &c = ibuilder->second;
  ModuleVector::iterator imodule;
  for (imodule=c.fModules.begin(); imodule!=c.fModules.end(); imodule++)
    if (*imodule==module)
      break;
  if (imodule == c.fModules.end()) {
    std::clog << "ProcessingModuleFactory: Trying remove unknown module with name " << module->GetName() << std::endl;
    // we should actually throw an exception here
    return;
  }

  c.fModules.erase(imodule);
  c.fBuilder->Destroy(module);
  return;
}

//______________________________________________________________________________
ProcessingModuleFactory::~ProcessingModuleFactory()
{
  // should we remove only modules?
  while(!fBuilders.empty()) {
    DeregisterBuilder(fBuilders.begin()->second.fBuilder);
  }
}

//______________________________________________________________________________
void ProcessingModuleFactory::Print( const char* option) const
{
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::ostream &os = std::cout;
  os << "{\n"
     << "  .mgProcessingModuleFactory = " << (void*)&(GetInstance()) <<",\n"
     << "  .fBuilders[" << fBuilders.size() << "] = {\n";
  for (ClassMap::const_iterator ibuilder = fBuilders.begin(); 
       ibuilder != fBuilders.end(); ibuilder++) {
    const BuilderContainer &c = ibuilder->second;
    os << "    [" << ibuilder->first << "] = {\n";
    os << "      .fBuilder = " << (void*)c.fBuilder << "(" << c.fBuilder->GetClass() << "),\n"
       << "      .fEnabled = " << (c.fEnabled?"true":"false") << ",\n"
       << "      .fModules[" << c.fModules.size() << "] = { ";
    for (ModuleVector::const_iterator imodule = c.fModules.begin(); 
	 imodule!=c.fModules.end(); imodule++)
      os << (void*)*(imodule) << "(" << (*imodule)->GetName() << "), ";
    os << "},\n"
       << "    },\n";
  }
  os << "  },\n"
     << "}" << std::endl;
}
