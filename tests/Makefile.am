# tests/Makefile.am

SUBDIRS = \
 include \
 lib \
 src \
 .
EXTRA_DIST = fixtures

# test executables to run as a suite
TESTS = \
	include/test_node_type$(EXEEXT) \
	lib/test_build$(EXEEXT) \
	lib/test_qualified_name$(EXEEXT) \
	src/test_parser$(EXEEXT) \
	src/test_build$(EXEEXT)

MAINTAINERCLEANFILES = \
 $(top_srcdir)/tests/Makefile.in
