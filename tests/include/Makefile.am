# tests/include/Makefile.am

SUBDIRS = \
 .

noinst_HEADERS = \
 TestHelper.hpp

check_PROGRAMS = \
 test_node_type
 
include $(top_srcdir)/build-aux/test_common.mk

TESTS = \
 $(check_PROGRAMS)

AM_CPPFLAGS = $(COMPILE_FLAGS) -DBOOST_TEST_MODULE="NODE"
AM_LDFLAGS  = $(LINKER_FLAGS)

test_node_type_LDADD = \
		   $(top_builddir)/sources/lib/node/libNode.la \
		   $(LINKER_LIBS)

test_node_type_SOURCES = \
		   test_node_type.cpp

MAINTAINERCLEANFILES = \
 $(top_srcdir)/tests/include/Makefile.in
