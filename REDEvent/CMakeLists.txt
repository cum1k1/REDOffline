cmake_minimum_required(VERSION 2.8)

# Define project
#project(REDEvent)

#
# build
ROOT_GENERATE_DICTIONARY(EventDict *.hh LINKDEF REDEvent/EventLinkDef.h)
file(GLOB sources *.cc)
set(sources ${sources} EventDict.cxx)
add_library(REDEvent SHARED ${sources})
target_link_libraries(REDEvent ${ROOT_CORE_LIBS})

# install
install(TARGETS REDEvent DESTINATION lib)
file(GLOB headers *.hh)
install(FILES ${headers} DESTINATION include/REDEvent)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/EventDict_rdict.pcm DESTINATION lib)
endif()
