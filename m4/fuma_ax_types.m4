dnl (c) FumaSoftware 2013
dnl
dnl Standard types detection for autotools
dnl
dnl Copying and distribution of this file, with or without modification,
dnl are permitted in any medium without royalty provided the copyright
dnl notice and this notice are preserved.  This file is offered as-is,
dnl without any warranty.
dnl
dnl Standard Types
dnl
AC_DEFUN([FUMA_AX_STANDARD_TYPES],[
#---------------------------------------------------------------
# FUMA_AX_STANDARD_TYPES start
#---------------------------------------------------------------

    # Checks for typedefs, structures, and compiler characteristics.
        AC_TYPE_UINT8_T
        AC_TYPE_UINT16_T
        AC_TYPE_UINT32_T
        AC_TYPE_UINT64_T
        AC_TYPE_INT16_T
        AC_TYPE_INT32_T
        AC_TYPE_INT64_T
        AC_TYPE_INT8_T

        AC_TYPE_MODE_T
        AC_TYPE_OFF_T

        AC_TYPE_UID_T

        AC_TYPE_SIZE_T

        AC_TYPE_SSIZE_T

        AC_TYPE_LONG_LONG_INT
        AC_TYPE_UNSIGNED_LONG_LONG_INT

        AC_C_INLINE
        AC_C_CONST
#---------------------------------------------------------------
# FUMA_AX_STANDARD_TYPES end
#---------------------------------------------------------------
        ])
