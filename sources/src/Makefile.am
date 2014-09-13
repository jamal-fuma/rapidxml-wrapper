# sources/src/Makefile.am

include $(top_srcdir)/build-aux/source_common.mk

AM_LDFLAGS = $(LINKER_FLAGS)
AM_CPPFLAGS = $(COMPILE_FLAGS)

bin_PROGRAMS = rss_xml

rss_xml_SOURCES = \
 Main.cpp

rss_xml_LDADD = \
 $(LINKER_LIBS)

MAINTAINERCLEANFILES = \
 $(top_srcdir)/sources/src/Makefile.in
