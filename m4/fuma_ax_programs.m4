dnl (c) FumaSoftware 2013
dnl
dnl Standard programs detection for autotools
dnl
dnl Copying and distribution of this file, with or without modification,
dnl are permitted in any medium without royalty provided the copyright
dnl notice and this notice are preserved.  This file is offered as-is,
dnl without any warranty.
dnl
dnl Standard Programs
dnl
AC_DEFUN([FUMA_AX_STANDARD_PROGRAMS],[
#---------------------------------------------------------------
# FUMA_AX_STANDARD_PROGRAMS start
#---------------------------------------------------------------
# Checks for programs
    AC_REQUIRE([AC_PROG_CXX])
    AC_REQUIRE([AC_PROG_CPP])
    AC_REQUIRE([AC_PROG_CC])
    AC_REQUIRE([AC_PROG_GREP])
    AC_REQUIRE([AC_PROG_SED])
    AC_REQUIRE([AC_PROG_AWK])
    AC_REQUIRE([AC_PROG_INSTALL])
    AC_REQUIRE([AC_PROG_LN_S])
    AC_REQUIRE([AC_PROG_MKDIR_P])
    AC_REQUIRE([AC_PROG_LIBTOOL])
    AC_REQUIRE([AC_MINGW32])

# Checks for programs.
    AC_PROG_CPP
    AC_PROG_CC
    AC_PROG_CXX
    AC_PROG_GREP
    AC_PROG_SED
    AC_PROG_AWK
    AC_PROG_INSTALL
    AC_PROG_LN_S

    dnl prefer gmake to bsd make
    AC_CHECK_PROGS([MAKE], [gmake make])
    AC_PROG_MKDIR_P
    AC_LIBTOOL_DLOPEN
    AC_PROG_LIBTOOL

    AC_MINGW32

#---------------------------------------------------------------
# FUMA_AX_STANDARD_PROGRAMS end
#---------------------------------------------------------------
        ])
