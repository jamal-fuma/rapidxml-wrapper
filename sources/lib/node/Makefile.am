# sources/lib/node/Makefile.am

include $(top_srcdir)/build-aux/source_common.mk

AM_LDFLAGS = $(LINKER_FLAGS)
AM_CPPFLAGS = $(COMPILE_FLAGS)

noinst_LTLIBRARIES = \
 libNode.la

#noinst_HEADERS =

libNode_la_SOURCES = \
 DOMTree.cpp \
 Element.cpp \
 QualifiedName.cpp \
 Util.cpp \
 XML.cpp

libNode_la_LIBADD = \
 $(LINKER_LIBS)

MAINTAINERCLEANFILES = \
 $(top_srcdir)/sources/lib/node/Makefile.in
