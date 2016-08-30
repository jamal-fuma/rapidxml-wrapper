# tests/src/Makefile.am

SUBDIRS = \
 .

check_PROGRAMS = \
    test_parser

include $(top_srcdir)/build-aux/test_common.mk

TESTS = \
 $(check_PROGRAMS)

AM_CPPFLAGS = $(COMPILE_FLAGS) -DBOOST_TEST_MODULE="NODE_PARSER"
AM_LDFLAGS  = $(LINKER_FLAGS)

test_parser_LDADD = \
		   $(top_builddir)/sources/lib/node/libNode.la \
		   $(LINKER_LIBS)

test_parser_SOURCES = test_parser.cpp

MAINTAINERCLEANFILES = \
 $(top_srcdir)/tests/src/Makefile.in
