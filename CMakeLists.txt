cmake_minimum_required(VERSION 2.8)
message(STATUS "cmake version ${CMAKE_VERSION}")
# Enforce an out-of-source builds before anything else
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(STATUS "This software requires an out-of-source build.")
    message(STATUS "Please remove these files from ${CMAKE_BINARY_DIR} first:")
    message(STATUS "CMakeCache.txt")
    message(STATUS "CMakeFiles")
    message(STATUS "Once these files are removed, create a separate directory")
    message(STATUS "and run CMake from there")
    message(FATAL_ERROR "in-source build detected")
endif()

# Define project
project(REDOffline)
string(TOLOWER "${PROJECT_NAME}" ${PROJECT_NAME}_TOLOW)
set(${PROJECT_NAME}_VERSION_MAJOR 0)
set(${PROJECT_NAME}_VERSION_MINOR 2)
set(${PROJECT_NAME}_VERSION_PATCH 1)
set(${PROJECT_NAME}_VERSION 
  ${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH})
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# ... and configuration options
option(WITH_GUI   "Build GUI, requires graphical libraries." ON)
option(DEBUG      "Turn debug options on" OFF)

# Also https://cmake.org/Wiki/CMake:How_To_Write_Platform_Checks
# check headers
include(CheckTypeSize)
# also checks for sys/types.h, stdint.h, stddef.h
check_type_size(uint64_t  TYPE_UINT64T_SIZE)
check_type_size(off_t     TYPE_OFFT_SIZE)
#check_type_size(size_t    TYPE_SIZET_SIZE) - implied by C++
check_type_size(ptrdiff_t TYPE_PTRDIFFT_SIZE)
include(CheckIncludeFiles)
check_include_files(limits.h HAVE_LIMITS_H)
check_include_files(stdlib.h HAVE_STDLIB_H)
check_include_files(string.h HAVE_STRING_H)
#check_include_files(stdbool.h HAVE_STDBOOL_H) - implied by C++
check_include_files(unistd.h HAVE_UNISTD_H)
# const, inline ? - implied by C++
# check functions
include(CheckFunctionExists)
check_function_exists(memset HAVE_MEMSET)
check_function_exists(strtol HAVE_STRTOL)
check_function_exists(strerror HAVE_STRERROR)
check_function_exists(localtime_r HAVE_LOCALTIME_R)
set(CMAKE_REQUIRED_LIBRARIES m)
check_function_exists(floor HAVE_FLOOR)
check_function_exists(pow HAVE_POW)
check_function_exists(sqrt HAVE_SQRT)
set(CMAKE_REQUIRED_LIBRARIES)
# check libraries
# check packages
#include(RequiredPackages)
find_package(UnixCommands)
find_package(Git)
find_package(PythonLibs 2.7)
if(PYTHONLIBS_FOUND)
  find_package(PythonInterp ${PYTHONLIBS_VERSION_STRING})
endif()
find_package(ROOT 5.34 REQUIRED)
find_package(Lua 5.0)
find_program(BZIP2_EXECUTABLE bzip2)
find_program(ASTYLE_EXECUTABLE astyle)
find_program(CTAGS_EXECUTABLE ctags)

# now check version information
if(GIT_FOUND)

  # closest tag
  execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --abbrev=0 --tags
    OUTPUT_VARIABLE ${PROJECT_NAME}_GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  # it also codes the last package version on this branch
  string(REGEX REPLACE "^v" "" ${PROJECT_NAME}_GIT_VERSION "${${PROJECT_NAME}_GIT_TAG}")
  if("${${PROJECT_NAME}_VERSION_PATCH}" STREQUAL "dev")
    if (NOT ${${PROJECT_NAME}_VERSION} VERSION_GREATER "${${PROJECT_NAME}_GIT_VERSION}")
      message(WARNING "Project version mismatch: cmake=${${PROJECT_NAME}_VERSION} git=${${PROJECT_NAME}_GIT_VERSION}")
    endif()
  else()
    if (NOT ${${PROJECT_NAME}_VERSION} VERSION_EQUAL "${${PROJECT_NAME}_GIT_VERSION}")
      message(WARNING "Project version mismatch: cmake=${${PROJECT_NAME}_VERSION} git=${${PROJECT_NAME}_GIT_VERSION}")
    endif()
  endif()

  # compact form for easay understanding current position of HEAD
  execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --tags HEAD
    OUTPUT_VARIABLE ${PROJECT_NAME}_GIT_CID
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  # calculate number of commits from the beginning
  #  - something like SNV revision number
  execute_process(
    COMMAND ${GIT_EXECUTABLE} log --oneline HEAD
    OUTPUT_VARIABLE tmp)
  string(REGEX MATCHALL "[^\n]+\n" tmp "${tmp}")
  list(LENGTH tmp tmp)
  set(${PROJECT_NAME}_GIT_REV "r${tmp}")

  # Do we have any modifications since last commit
  execute_process(
    COMMAND ${GIT_EXECUTABLE} status --short --untracked-files=no
    OUTPUT_VARIABLE tmp)
  if(NOT "${tmp}" STREQUAL "")
    set(${PROJECT_NAME}_GIT_TAG "${${PROJECT_NAME}_GIT_TAG}-M")
    set(${PROJECT_NAME}_GIT_CID "${${PROJECT_NAME}_GIT_CID}-M")
  endif()

  unset(tmp)

endif()

#
add_definitions(-DHAVE_CONFIG_H)
include_directories(${PROJECT_SOURCE_DIR})
add_definitions(-DHAVE_ROOT)
include_directories(${ROOT_INCLUDE_DIR})
if (ROOT_VERSION VERSION_LESS 6)
  set(ROOT_CORE_LIBS ${ROOT_Cint_LIBRARY} ${ROOT_Core_LIBRARY})
else()
  set(ROOT_CORE_LIBS ${ROOT_Core_LIBRARY})
endif()
if(LUA_FOUND)
  add_definitions(-DHAVE_LUA)
endif()
if(PYTHONLIBS_FOUND)
  add_definitions(-DHAVE_PYTHON)
endif()
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  add_definitions(-DLINUX)
  set(CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--enable-new-dtags")
endif()
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  # APPLE is in around
  add_definitions(-DDARWIN)
  set(CMAKE_INSTALL_RPATH "@loader_path/../lib")
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
  if(POLICY CMP0042)
    cmake_policy(SET CMP0042 NEW) # MACOSX_RPATH
  endif()
  execute_process(COMMAND hostname OUTPUT_VARIABLE tmp OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(ENV{HOSTNAME} ${tmp})
  unset(tmp)
endif()
if(WIN32)
  add_definitions(-DWIN32)
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unused-variable -Wno-unused-parameter -g -O0")
if(DEBUG)
  set(CMAKE_VERBOSE_MAKEFILE ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
endif()

# configure header file
string(TIMESTAMP CONFIG_DATE)
set(CONFIG_USER $ENV{USER})
configure_file("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_BINARY_DIR}/config.h")
set(flags)
#add_compile_options()
get_directory_property(opts COMPILE_OPTIONS)
foreach(opt ${opts})
  set(flags "${flags} ${opt}")
endforeach()
#add_definitions()
get_directory_property(opts COMPILE_DEFINITIONS)
foreach(opt ${opts})
  set(flags "${flags} -D${opt}")
endforeach()
#include_directories()
get_directory_property(opts INCLUDE_DIRECTORIES)
foreach(opt ${opts})
  set(flags "${flags} -I${opt}")
endforeach()
set(my_CPP_FLAGS ${flags})
set(flags)
#link_directories()
get_directory_property(opts LINK_DIRECTORIES)
foreach(opt ${opts})
  set(flags "${flags} -L${opt}")
endforeach()
set(my_LD_FLAGS ${flags})
unset(opt)
unset(opts)
unset(flags)
configure_file("${PROJECT_SOURCE_DIR}/config.mk.in" "${PROJECT_BINARY_DIR}/config.mk" @ONLY)
configure_file("${PROJECT_SOURCE_DIR}/redoffline-config.in" "${PROJECT_BINARY_DIR}/redoffline-config" @ONLY)

#
# build targets
set(subdirs REDEvent REDProcessing REDFile REDUtils modules)
set(modlist)
foreach(dir ${subdirs})
  add_subdirectory(${dir})
endforeach()

add_executable(offline offline.cc ${src_list})
target_link_libraries(offline REDEvent REDProcessing REDFile ${modlist})
target_include_directories(offline PUBLIC ${PROJECT_BINARY_DIR})
#set_target_properties(offline PROPERTIES INSTALL_RPATH ?)

#
# what to install
install(TARGETS offline DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION share/REDOffline)
install(FILES "${PROJECT_BINARY_DIR}/config.mk" DESTINATION share/REDOffline)
install(FILES "${PROJECT_SOURCE_DIR}/default.conf" DESTINATION share/REDOffline)
install(FILES "${PROJECT_SOURCE_DIR}/README" DESTINATION share/REDOffline)
install(FILES "${PROJECT_SOURCE_DIR}/ChangeLog" DESTINATION share/REDOffline)
install(PROGRAMS "${PROJECT_BINARY_DIR}/redoffline-config" DESTINATION bin)
# Also https://cmake.org/cmake/help/git-master/manual/cmake-packages.7.html#creating-packages
