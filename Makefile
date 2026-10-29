#
#
# GIT_REV = "git rev-list HEAD --count" # from commit number
# .gitconfig: show-rev-number = !sh -c 'git rev-list --reverse HEAD | awk \"{ if(NR == "$0") { print \\$2 }}\"'
#

.PHONY: all conf clean distclean offline test install
.PHONY: astyle release archive tar TAGS

all:

top_srcdir = .
ifneq ($(wildcard $(top_srcdir)/config.mk),)
  include $(top_srcdir)/config.mk
endif
# provide defaults for core things
CMAKE ?= cmake
MAKE  ?= make
GIT   ?= git
BZIP2 ?= bzip2
TAR   ?= tar

CXXFLAGS += -ggdb
LDLIBS += -lstdc++ $(ROOT_LIBS)

ifeq ($(wildcard depend),)
  ifeq ($(filter depend,$(MAKECMDGOALS)),)
    TMP := $(shell [ -e config.mk ] && $(MAKE) depend >&2)
  endif
endif
ifneq ($(wildcard depend),)
  include depend
endif

all: config.mk offline
#	cd build && make test

conf build/CMakeCache.txt:
	[ -d build ] || mkdir build
	cd build && $(CMAKE) -DDEBUG=OFF ..

config.h: build/CMakeCache.txt
	[ -e config.h ] || ln -s build/config.h ./
config.mk: build/CMakeCache.txt
	[ -e config.mk ] || ln -s build/config.mk ./

offline: config.h
	cd build && $(MAKE)
	[ -e offline ] || ln -s build/offline ./

build/REDEvent/libREDEvent.so:
	cd build && $(MAKE) REDEvent
build/REDProcessing/libREDProcessing.so:
	cd build && $(MAKE) REDProcessing
build/REDFile/libREDFile.so:
	cd build && $(MAKE) REDFile

depend: config.mk
	find $(top_srcdir) -name '*.cc' -and -not -regex '\./RED.*' -and -not -regex '\./\([0-9]\|build\|tmp\)/.*' -exec \
	  $(CPP) $(CPPFLAGS) -MM $(INCLUDE) '{}' ';' | \
	    sed 's/^\([^\/]*\)\.o: \(.*\)\/\1\.\(cc\|cxx\|c\|C\)/\2\/\1.o: \2\/\1.\3/' >depend

test:

clean:
	cd build && $(MAKE) clean
	rm -fv depend config.h config.mk offline t
	find $(top_srcdir) -name '*.o' -exec rm -v '{}' ';'

distclean: clean
	rm -Rf build
	find $(top_srcdir) -name '*~' -exec rm -v '{}' ';'

install: all
	cd build && make install

%Dict.cc: %.hh %LinkDef.h
	$(ROOTCINT) -f $@ -c -p $^
%Dict.cxx: %.h %LinkDef.h
	$(ROOTCINT) -f $@ -c -p $^
t: t.o tDict.o build/REDEvent/libREDEvent.so
t-file: t-file.o build/REDEvent/libREDEvent.so build/REDFile/libREDFile.so

astyle:
ifneq ($(ASTYLE),ASTYLE_EXECUTABLE-NOTFOUND)
	list='$(filter-out astyle,$(MAKECMDGOALS))'; \
	for file in $$list; do \
	  astyle --style=kr --indent=spaces=2 --indent-preprocessor --indent-namespaces \
	         --keep-one-line-blocks --keep-one-line-statements --preserve-date $$file; \
	done
# --min-conditional-indent=1 --pad-header --align-pointer=name
else
	@echo "Error: Program atyle not found. Target is impossible." && exit 1;
endif

ifneq ($(GIT),GIT_EXECUTABLE-NOTFOUND)
release:
	VERSION=`$(GIT) describe master`; \
	  $(GIT) archive master --prefix="$(PACKAGE_NAME)-$$VERSION/" --format=tar | $(BZIP2) >"$(PACKAGE_TARNAME)-$$VERSION.tar.bz2"
archive:
	$(GIT) archive HEAD --prefix="$(PACKAGE_NAME)/" --format=tar | $(BZIP2) >"$(PACKAGE_TARNAME)-$(shell git describe).tar.bz2"
TAGS:
  ifneq ($(CTAGS),CTAGS_EXECUTABLE-NOTFOUND)
	$(CTAGS) -e `$(GIT) ls-tree -r HEAD --name-only`
  else
	@echo "Error: Program ctags not found. Target is impossible." && exit 1;
  endif
endif

tar:
	$(TAR) -cjf "$(PACKAGE_TARNAME).tar.bz2" --exclude-vcs --exclude-backups --exclude=build --exclude=*.root --exclude=*.gz .
