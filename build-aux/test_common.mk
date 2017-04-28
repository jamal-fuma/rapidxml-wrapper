include $(top_srcdir)/build-aux/data_common.mk

INCLUDE_DIRS	= -I$(top_builddir) \
				  -I$(top_srcdir)/sources/include \
				  -I$(top_srcdir)/sources/include/3rd_party \
				  -I$(top_srcdir)/tests/include

SOURCE_DEFINES  = -DPACKAGE_VERSION="\"${PACKAGE_VERSION}\"" \
				  -DFUMA_CONFIG_DIR="\"${pkg_sysconf_dir}\"" \
				  -DFUMA_DATA_DIR="\"${pkg_data_dir}\"" \
				  -D__STDC_LIMIT_MACROS=1 \
				  -DFUMA_BUILD_LABEL="\"${FUMA_BUILD_LABEL}\""

TEST_DEFINES	= $(SOURCE_DEFINES) \
				  -DFIXTURES_DIR="\"${abs_top_srcdir}/tests/fixtures\"" \
				  -DFUMA_TEST_CONFIG_DIR="\"${abs_top_srcdir}/assets/config\"" \
				  -DFUMA_TEST_DATA_DIR="\"${abs_top_srcdir}/assets\"" \
				  -DBOOST_TEST_DYN_LINK="1"

LINKER_FLAGS	= $(BOOST_LDFLAGS) \
				  $(PTHREAD_CFLAGS) \
				  $(COVERAGE_LDFLAGS) \
				  -rdynamic

WARNING_FLAGS	= -Wall -Wextra \
		   -fno-omit-frame-pointer \
		   -pedantic -pedantic-errors \
		  -Wunused-value -Wunused -Wunused-parameter -Wunused-variable \
		  -Wunreachable-code \
		  -Wcast-align -Wcast-qual \
		  -Winit-self \
		  -Wfloat-equal \
		  -Wundef \
		  -Wredundant-decls \
		  -Wshadow -Wstack-protector \
		  -Wdisabled-optimization \
		  -Wmissing-field-initializers -Wmissing-format-attribute -Wformat-nonliteral -Wformat-security -Wformat-y2k \
		  -Wmissing-noreturn \
		  -Wimport  -Winit-self  -Winline \
		  -Wstrict-aliasing=2 \
		  -Wwrite-strings

if FREEBSD
WARNING_FLAGS +=  -ftemplate-backtrace-limit=0
endif

COMPILE_FLAGS	= $(INCLUDE_DIRS) \
				  $(BOOST_CPPFLAGS) \
				  $(PTHREAD_CFLAGS) \
				  $(SOURCE_DEFINES) \
				  $(TEST_DEFINES) \
				  $(WARNING_FLAGS)

LINKER_LIBS	= $(BOOST_UNIT_TEST_FRAMEWORK_LIB) \
		  $(BOOST_SYSTEM_LIB) $(BOOST_IOSTREAM_LIB) \
		  $(BOOST_FILESYSTEM_LIB) \
		  $(PTHREAD_LIBS)
