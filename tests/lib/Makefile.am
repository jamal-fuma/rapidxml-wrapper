# tests/lib/Makefile.am

SUBDIRS = \
 .

check_PROGRAMS = \
 test_qualified_name
 
TESTS = \
 $(check_PROGRAMS)

include $(top_srcdir)/build-aux/test_common.mk

AM_CPPFLAGS = $(COMPILE_FLAGS) -DBOOST_TEST_MODULE="NODE"
AM_LDFLAGS  = $(LINKER_FLAGS)

test_qualified_name_LDADD = \
		   $(top_builddir)/sources/lib/node/libNode.la \
		   $(LINKER_LIBS)

test_qualified_name_SOURCES = \
		   test_qualified_name.cpp

MAINTAINERCLEANFILES = \
 $(top_srcdir)/tests/lib/Makefile.in
