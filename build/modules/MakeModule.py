#!/usr/bin/env python2

import sys
import os
import re
from string import Template


def generate_cmake(modname, clsname):
  fname = "%s/CMakeLists.txt" % modname
  print "Creating " + fname
  with open(fname,"w") as fh:
    fh.write(Template("""
# Define module
#project(${modname})

#
# build
ROOT_GENERATE_DICTIONARY(${modname}Dict *.hh LINKDEF modules/${modname}/LinkDef.h)
file(GLOB sources *.cc)
set(sources $${sources} ${modname}Dict.cxx)
add_library(module${modname} SHARED $${sources})
set_target_properties(module${modname} PROPERTIES OUTPUT_NAME \"${modname}\")
target_link_libraries(module${modname} REDEvent REDProcessing $${ROOT_Cint_LIBRARY} $${ROOT_Core_LIBRARY})
list(APPEND modlist module${modname})
set(modlist $${modlist} PARENT_SCOPE)

# install
install(TARGETS module${modname} DESTINATION lib)

""").substitute({'modname':modname,'clsname':clsname}))
    fh.close()
  return

def generate_linkdef(modname, clsname):
  fname = "%s/LinkDef.h" % modname
  print "Creating " + fname
  with open(fname,"w") as fh:
    fh.write(Template("#pragma link C++ class RED::${clsname}+;\n").substitute({'modname':modname,'clsname':clsname}))
    fh.close()
  return

def generate_source(modname, clsname):
  fname = "%s/%s.hh" % (modname, clsname)
  print "Creating " + fname
  with open(fname,"w") as fh:
    fh.write(Template("""
#ifndef RED_${clsname}_hh
#define RED_${clsname}_hh

#include \"REDProcessing/ProcessingModule.hh\"

namespace RED
{

  class ${clsname} : public ProcessingModule
  {
  public:
    ${clsname}();
    ~${clsname}();

    EventStatus ProcessEvent(Event *);

    //
    void SetMode(int v) { fMode = v; }
    void SetNumChannels(int v) { fNumChannels = v; }
    void SetNumSamples(int v) { fNumSamples = v; }
    void SetSamplingPeriod(double v) { fPeriod = v; }

  private:
    int      fMode;
    int      fNumChannels;
    int      fNumSamples;
    double   fPeriod;

  public:
    // module defines
    RED_PROCESSING_MODULE_DEFINE(${clsname})
    ClassDef(${clsname},1)
  };

} // namespace

#endif /* RED_${clsname}_hh */
""").substitute({'modname':modname,'clsname':clsname}))
    fh.close()

  fname = "%s/%s.cc" % (modname, clsname)
  print "Creating " + fname
  with open(fname,"w") as fh:
    fh.write(Template("""
#include <iostream>

#include \"${clsname}.hh\"
#include \"REDEvent/Event.hh\"

using std::cout;
using std::endl;
using namespace RED;

RED_PROCESSING_MODULE_IMPLEMENT( ${clsname} )
ClassImp( ${clsname} )


${clsname}::${clsname}()
{
  fMode = 0;
  fNumChannels = 0;
  fNumSamples = 1;
  fPeriod = 1.;
}
${clsname}::~${clsname}()
{
  ;
}

ProcessingModule::EventStatus ${clsname}::ProcessEvent(Event *event)
{
  cout << __PRETTY_FUNCTION__ << endl;

  if (1) event->Print();

  return kOk;
}
""").substitute({'modname':modname,'clsname':clsname}))
    fh.close()
  return

if __name__ == '__main__':

  # Check arguments
  if len(sys.argv) < 2 or len(sys.argv) > 3:
    print "Usage: %s <module_name> [<class_name>]" % sys.argv[0]
    exit(1)
  modname = sys.argv[1]
  if not re.match("^[A-Z][A-Za-z0-9_.]*$",modname):
    print "Bad module name '%s'" % modname
    exit(1)
  clsname = sys.argv[2] if len(sys.argv) == 3 else modname
  if not re.match("^[A-Z]\w*$",clsname):
    print "Bad class name '%s'" % clsname
    exit(1)

  # Now generate
  print "Creating " + modname + "/"
  os.mkdir(modname)
  generate_cmake(modname,clsname)
  generate_linkdef(modname,clsname)
  generate_source(modname,clsname)

  exit(0)

