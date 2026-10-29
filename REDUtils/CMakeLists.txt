cmake_minimum_required(VERSION 2.8)

# Define project
#project(REDUtils)

#
# build
#ROOT_GENERATE_DICTIONARY(FileDict *.hh LINKDEF REDFile/FileLinkDef.h)
file(GLOB sources *.cc)
add_library(REDUtils SHARED ${sources})
#set_target_properties(REDUtils PROPERTIES VERSION "1")
#target_link_libraries(REDFile REDEvent ${ROOT_Cint_LIBRARY} ${ROOT_Core_LIBRARY} ${ROOT_RIO_LIBRARY} ${ROOT_Tree_LIBRARY})

# install
install(TARGETS REDUtils DESTINATION lib)
file(GLOB headers *.hh *.h)
install(FILES ${headers} DESTINATION include/REDUtils)
