cmake_minimum_required(VERSION 2.8)

# Define project
#project(REDFile)

#
# build
ROOT_GENERATE_DICTIONARY(FileDict *.hh LINKDEF REDFile/FileLinkDef.h)
set(sources File.cc FileDict.cxx)
add_library(REDFile SHARED ${sources})
#set_target_properties(REDFile PROPERTIES VERSION "1")
target_link_libraries(REDFile REDEvent ${ROOT_CORE_LIBS} ${ROOT_RIO_LIBRARY} ${ROOT_Tree_LIBRARY})

# install
install(TARGETS REDFile DESTINATION lib)
file(GLOB headers *.hh)
install(FILES ${headers} DESTINATION include/REDFile)
if(NOT ROOT_VERSION VERSION_LESS 6)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/FileDict_rdict.pcm DESTINATION lib)
endif()
