# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.69])
AC_INIT([RapidXML], [0.0.1], [bugs@llist.com])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

# location of additional build machinary
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SRCDIR([scripts/configure.sh])

# enabling subdir-objects will require folding all makefiles into a single makefile to preserve full paths
# and keep the lcov support working
AM_INIT_AUTOMAKE([1.10 no-define foreign tar-pax subdir-objects])

# allow for silent builds in older version of automake 12.04 lts cough
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])

dnl disable unnecessary compiler checks
AC_DEFUN([AC_PROG_F77], [:])
AC_DEFUN([AC_PROG_FC], [:])
AC_DEFUN([AC_PROG_OBJC], [:])
AC_DEFUN([AC_PROG_OBJCCPP], [:])
AC_DEFUN([AC_LIBTOOL_F77], [:])

# Checks for programs.
FUMA_AX_STANDARD_PROGRAMS

# Checks for typedefs, structures, and compiler characteristics.
FUMA_AX_STANDARD_TYPES

# Checks for libraries.
FUMA_AX_CANONICAL_HOST

# support a non-optimised debug build
FUMA_AX_DEBUG

# check if we can format code nicely
FUMA_AX_ASTYLE([2.03])

# enable what ever the local equivilent of --std=c++11
AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])

# Checks for library functions.
AC_CONFIG_FILES([Makefile
		 doc/Makefile
		 sources/Makefile
		 sources/include/Makefile
		 sources/include/rapidxml/Makefile
		 sources/src/Makefile])

# I like maintainer mode
AM_MAINTAINER_MODE

AC_OUTPUT
