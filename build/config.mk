# the configured options and settings for REDOffline

CC      = /usr/bin/cc
CFLAGS  = 
CPP     = $(CC) -E
CPPFLAGS+=  -std=c++17 -DHAVE_CONFIG_H -DHAVE_ROOT -DLINUX -I/home/lev/Документы/REDOffline -I/usr/include/root
CXX     = /usr/bin/c++
CXXCPP  = $(CXX) -E
CXXFLAGS+=  -Wall -Wno-unused-variable -Wno-unused-parameter -g -O0
LD      = /usr/bin/ld
LDFLAGS +=  -Wl,--enable-new-dtags 
LIBS    = 

CMAKE   = /usr/bin/cmake
GIT     = /usr/bin/git
TAR     = /usr/bin/tar
ifeq (FALSE,TRUE)
  HAVE_PYTHON = yes
  PYTHON         = 
  PYTHON_INCLUDE := $(addprefix -I,)
  PYTHON_LIBS    = PYTHON_LIBRARY-NOTFOUND
endif
ifeq (TRUE,TRUE)
  HAVE_ROOT = yes
  ROOT_CONFIG  = /usr/bin/root-config
  ROOT_INCDIR  = /usr/include/root
  ROOT_INCLUDE := $(addprefix -I,/usr/include/root)
  ROOT_LIBDIR  = /usr/lib64/root
  ROOT_LIBS    := $(subst ;, ,/usr/lib64/root/libCore.so;/usr/lib64/root/libRIO.so;/usr/lib64/root/libNet.so;/usr/lib64/root/libHist.so;/usr/lib64/root/libGraf.so;/usr/lib64/root/libGraf3d.so;/usr/lib64/root/libGpad.so;/usr/lib64/root/libTree.so;/usr/lib64/root/libRint.so;/usr/lib64/root/libPostscript.so;/usr/lib64/root/libMatrix.so;/usr/lib64/root/libPhysics.so;/usr/lib64/root/libMathCore.so;/usr/lib64/root/libThread.so)
  ROOFIT_LIBS  := $(addsuffix .so,$(addprefix $(ROOT_LIBDIR)/lib,RooFit RooFitCore Minuit Foam))
  ROOTEXEC     := $(shell /usr/bin/root-config --bindir)/root
  ROOTCINT     = /usr/bin/rootcint
endif
ifeq (FALSE,TRUE)
  HAVE_LUA = yes
  LUA_INCLUDE = -ILUA_INCLUDE_DIR-NOTFOUND
  LUA_LIBS    = LUA_LIBRARY-NOTFOUND
endif
BZIP2   = /usr/bin/bzip2
ASTYLE  = ASTYLE_EXECUTABLE-NOTFOUND
CTAGS   = /usr/bin/ctags

PACKAGE_NAME = REDOffline
PACKAGE_STRING = "REDOffline 0.2.1"
PACKAGE_TARNAME = redoffline
PACKAGE_VERSION = 0.2.1

PACKAGE_GIT_DIR = /home/lev/Документы/REDOffline/.git
PACKAGE_GIT_VERSION := $(shell $(GIT) --git-dir=$(PACKAGE_GIT_DIR) describe --tags HEAD)

