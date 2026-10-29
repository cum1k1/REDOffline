
# Define module
#project(REDDAQInput)

#
# build
ROOT_GENERATE_DICTIONARY(REDDAQInputDict *.hh LINKDEF modules/REDDAQInput/LinkDef.h OPTIONS -p)
file(GLOB sources *.cc)
set(sources ${sources} REDDAQInputDict.cxx)
add_library(moduleREDDAQInput SHARED ${sources})
set_target_properties(moduleREDDAQInput PROPERTIES OUTPUT_NAME "REDDAQInput")
target_link_libraries(moduleREDDAQInput REDEvent REDProcessing REDUtils ${ROOT_CORE_LIBS})
list(APPEND modlist moduleREDDAQInput)
set(modlist ${modlist} PARENT_SCOPE)

# install
install(TARGETS moduleREDDAQInput DESTINATION lib)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/REDDAQInputDict_rdict.pcm DESTINATION lib)
endif()
