
# Define module
#project(CsIDAQInput)

#
# build
ROOT_GENERATE_DICTIONARY(CsIDAQInputDict *.hh LINKDEF modules/CsIDAQInput/LinkDef.h OPTIONS -p)
file(GLOB sources *.cc)
set(sources ${sources} CsIDAQInputDict.cxx)
add_library(moduleCsIDAQInput SHARED ${sources})
set_target_properties(moduleCsIDAQInput PROPERTIES OUTPUT_NAME "CsIDAQInput")
target_link_libraries(moduleCsIDAQInput REDEvent REDProcessing ${ROOT_CORE_LIBS})
list(APPEND modlist moduleCsIDAQInput)
set(modlist ${modlist} PARENT_SCOPE)

# install
install(TARGETS moduleCsIDAQInput DESTINATION lib)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/CsIDAQInputDict_rdict.pcm DESTINATION lib)
endif()
