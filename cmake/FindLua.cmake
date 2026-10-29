# Locate Lua library
# This module defines
#  LUA_FOUND, if false, do not try to link to Lua
#  LUA_LIBRARIES
#  LUA_INCLUDE_DIR, where to find lua.h
#  LUA_VERSION_STRING, the version of Lua found (since CMake 2.8.8)
#
# Note that the expected include convention is
#  #include "lua.h"
# and not
#  #include <lua/lua.h>
# This is because, the lua location is not standardized and may exist
# in locations other than lua/

#=============================================================================
# Copyright 2007-2009 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

string(REPLACE "." "" Lua_FIND_VERSION_SOLID "${Lua_FIND_VERSION}")

find_path(LUA_INCLUDE_DIR lua.h
  HINTS
    ENV LUA_DIR
  PATH_SUFFIXES include/lua${Lua_FIND_VERSION_SOLID} include/lua${Lua_FIND_VERSION} include/lua-${Lua_FIND_VERSION} include/lua include
  PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /sw # Fink
  /opt/local # DarwinPorts
  /opt/csw # Blastwave
  /opt
)

find_library(LUA_LIBRARY
  NAMES lua${Lua_FIND_VERSION_SOLID} lua${Lua_FIND_VERSION} lua-${Lua_FIND_VERSION} lua
  HINTS
    ENV LUA_DIR
  PATH_SUFFIXES lib
  PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /sw
  /opt/local
  /opt/csw
  /opt
)

if(LUA_LIBRARY)
  # include the math library for Unix
  if(UNIX AND NOT APPLE AND NOT BEOS)
    find_library(LUA_MATH_LIBRARY m)
    set( LUA_LIBRARIES "${LUA_LIBRARY};${LUA_MATH_LIBRARY}" CACHE STRING "Lua Libraries")
  # For Windows and Mac, don't need to explicitly include the math library
  else()
    set( LUA_LIBRARIES "${LUA_LIBRARY}" CACHE STRING "Lua Libraries")
  endif()

  set(lua_TESTFILE ${CMAKE_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeTmp/src.cxx)
  file(WRITE ${lua_TESTFILE} "
#include <lua.hpp>
int main() {
  lua_State *lua = lua_open();
  luaL_openlibs(lua);
  luaL_dostring(lua,\"print(_VERSION);\");
  lua_close(lua);
  return 0;}
")
  try_run(lua_EXITCODE lua_COMPILED
    ${CMAKE_BINARY_DIR} ${lua_TESTFILE}
    COMPILE_DEFINITIONS -I${LUA_INCLUDE_DIR} 
    LINK_LIBRARIES ${LUA_LIBRARIES} 
    COMPILE_OUTPUT_VARIABLE lua_COMPILE_OUTPUT
    RUN_OUTPUT_VARIABLE lua_RUN_OUTPUT)
  file(REMOVE ${lua_TESTFILE})
  if(lua_COMPILED)
    if(lua_EXITCODE EQUAL 0)
      if(lua_RUN_OUTPUT MATCHES "^Lua [0-9]")
        string(STRIP "${lua_RUN_OUTPUT}" lua_RUN_OUTPUT)
        string(REPLACE "Lua " "" LUA_VERSION "${lua_RUN_OUTPUT}")
      endif()
    else()
      file(APPEND ${CMAKE_BIBARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
        "Determining the Lua library version failed with "
        "the following output from execution:\n${lua_RUN_OUTPUT}\n\n")
    endif()
  else()
    file(APPEND ${CMAKE_BIBARY_DIR}${CMAKE_FILES_DIRECTORY}/CMakeError.log
      "Determining the Lua library version failed with "
      "the following output from compiler:\n${lua_COMPILE_OUTPUT}\n\n")
  endif()
  unset(lua_COMPILE_OUTPUT)
  unset(lua_RUN_OUTPUT)
  unset(lua_COMPILED)
  unset(lua_EXITCODE)
endif()

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LUA_FOUND to TRUE if
# all listed variables are TRUE
find_package_handle_standard_args(Lua
                                  REQUIRED_VARS LUA_LIBRARY LUA_INCLUDE_DIR
                                  VERSION_VAR LUA_VERSION)

mark_as_advanced(LUA_VERSION LUA_INCLUDE_DIR LUA_LIBRARIES LUA_LIBRARY LUA_MATH_LIBRARY)

