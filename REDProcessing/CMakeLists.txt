cmake_minimum_required(VERSION 2.8)

# Define project
#project(REDProcessing)

#
# build
ROOT_GENERATE_DICTIONARY(ProcessingDict *.hh LINKDEF REDProcessing/ProcessingLinkDef.h OPTIONS -p)
file(GLOB sources *.cc)
set(sources ${sources} ProcessingDict.cxx)
add_library(REDProcessing SHARED ${sources})
target_link_libraries(REDProcessing REDEvent REDFile REDUtils ${ROOT_CORE_LIBS} ${ROOT_MathCore_LIBRARY} ${ROOT_Hist_LIBRARY})

# install
install(TARGETS REDProcessing DESTINATION lib)
file(GLOB headers *.hh)
install(FILES ${headers} DESTINATION include/REDProcessing)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/ProcessingDict_rdict.pcm DESTINATION lib)
endif()
