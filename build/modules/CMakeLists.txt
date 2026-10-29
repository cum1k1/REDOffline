
# Define project
#project(modules)

# This and targets should be MODULEs
set(CMAKE_SHARED_LIBRARY_PREFIX module)
#
file(GLOB dirlist *)
foreach(file ${dirlist})
  if(IS_DIRECTORY ${file})
    add_subdirectory(${file})
  endif()
endforeach()
set(modlist ${modlist} PARENT_SCOPE)
