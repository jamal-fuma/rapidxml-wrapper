# tests/lib/Makefile.am

SUBDIRS = \
 .

# build a unit test
check_PROGRAMS = \
 test_qualified_name \
 test_build

TESTS = \
 $(check_PROGRAMS)

# pull in common test flags
include $(top_srcdir)/build-aux/test_common.mk

# name our test suite adding any test specific flags
NODE_LIBS= $(top_builddir)/sources/lib/node/libNode.la $(LINKER_LIBS)
AM_CPPFLAGS = $(COMPILE_FLAGS) -DBOOST_TEST_MODULE="NODE"
AM_LDFLAGS  = $(LINKER_FLAGS)

test_qualified_name_LDADD   = $(NODE_LIBS)
test_qualified_name_SOURCES = test_qualified_name.cpp

test_build_SOURCES = test_build.cpp
test_build_LDADD   = $(NODE_LIBS)

MAINTAINERCLEANFILES = \
 $(top_srcdir)/tests/lib/Makefile.in
