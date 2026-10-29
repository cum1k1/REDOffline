
# Define module
#project(Inspector)

if (WITH_GUI)
#
# build
ROOT_GENERATE_DICTIONARY(InspectorDict *.hh LINKDEF modules/Inspector/LinkDef.h)
file(GLOB sources *.cc)
set(sources ${sources} InspectorDict.cxx)
add_library(moduleInspector SHARED ${sources})
set_target_properties(moduleInspector PROPERTIES OUTPUT_NAME "Inspector")
target_link_libraries(moduleInspector REDEvent REDProcessing ${ROOT_CORE_LIBS} ${ROOT_Hist_LIBRARY} ${ROOT_Graf_LIBRARY} ${ROOT_LIBRARY_DIR}/libGui.so)
list(APPEND modlist moduleInspector)
set(modlist ${modlist} PARENT_SCOPE)

# install
install(TARGETS moduleInspector DESTINATION lib)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/InspectorDict_rdict.pcm DESTINATION lib)
endif()

endif (WITH_GUI)
