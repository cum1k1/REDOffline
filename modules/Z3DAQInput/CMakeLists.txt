
# Define module
#project(Z3DAQInput)

find_package(ZLIB)
if(ZLIB_LIBRARY)
#
# build
include_directories(${ZLIB_INCLUDE_DIR})
ROOT_GENERATE_DICTIONARY(Z3DAQInputDict *.hh LINKDEF modules/Z3DAQInput/LinkDef.h OPTIONS -p)
file(GLOB sources *.cc)
set(sources ${sources} Z3DAQInputDict.cxx)
add_library(moduleZ3DAQInput SHARED ${sources})
set_target_properties(moduleZ3DAQInput PROPERTIES OUTPUT_NAME "Z3DAQInput")
target_link_libraries(moduleZ3DAQInput REDEvent REDProcessing REDUtils ${ROOT_CORE_LIBS} ${ZLIB_LIBRARY})
list(APPEND modlist moduleZ3DAQInput)
set(modlist ${modlist} PARENT_SCOPE)

# install
install(TARGETS moduleZ3DAQInput DESTINATION lib)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/Z3DAQInputDict_rdict.pcm DESTINATION lib)
endif()

endif(ZLIB_LIBRARY)
