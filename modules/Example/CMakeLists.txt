
# Define module
#project(Example)

#
# build
ROOT_GENERATE_DICTIONARY(ExampleDict *.hh LINKDEF modules/Example/LinkDef.h)
file(GLOB sources *.cc)
set(sources ${sources} ExampleDict.cxx)
add_library(moduleExample SHARED ${sources})
set_target_properties(moduleExample PROPERTIES OUTPUT_NAME "Example")
target_link_libraries(moduleExample REDEvent REDProcessing ${ROOT_CORE_LIBS})
list(APPEND modlist moduleExample)
set(modlist ${modlist} PARENT_SCOPE)

# install
install(TARGETS moduleExample DESTINATION lib)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ExampleDict_rdict.pcm DESTINATION lib)
endif()
