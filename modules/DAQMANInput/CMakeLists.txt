
# Define module
#project(DAQMANInput)

#
# build
include_directories(daqman)
ROOT_GENERATE_DICTIONARY(DAQMANInputDict *.hh LINKDEF modules/DAQMANInput/LinkDef.h OPTIONS -p)
ROOT_GENERATE_DICTIONARY(daqmanDict daqman/*.hh LINKDEF modules/DAQMANInput/daqman/daqmanLinkDef.h OPTIONS -p)

file(GLOB sources *.cc)
aux_source_directory(daqman daqman_sources)
add_library(moduleDAQMANInput SHARED ${sources} daqmanDict.cxx ${daqman_sources} DAQMANInputDict.cxx)
set_target_properties(moduleDAQMANInput PROPERTIES OUTPUT_NAME "DAQMANInput")
target_link_libraries(moduleDAQMANInput REDEvent REDProcessing
  ${ROOT_CORE_LIBS})
list(APPEND modlist moduleDAQMANInput)
set(modlist ${modlist} PARENT_SCOPE)

# install
install(TARGETS moduleDAQMANInput DESTINATION lib)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/DAQMANInputDict_rdict.pcm DESTINATION lib)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/daqmanDict_rdict.pcm DESTINATION lib)
endif()
