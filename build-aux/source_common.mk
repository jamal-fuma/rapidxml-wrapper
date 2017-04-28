INCLUDE_DIRS= -I$(top_builddir) -I$(top_srcdir)/sources/include -I$(top_srcdir)/sources/include/3rd_party
include $(top_srcdir)/build-aux/data_common.mk
SOURCE_DEFINES= -DPACKAGE_VERSION="\"${PACKAGE_VERSION}\"" \
				  -DFUMA_CONFIG_DIR="\"${pkg_sysconf_dir}\"" \
				  -DFUMA_DATA_DIR="\"${pkg_data_dir}\"" \
				  -DFUMA_BUILD_LABEL="\"${FUMA_BUILD_LABEL}\"" \
				  -D__STDC_LIMIT_MACROS=1 \
			      -DBOOST_SPIRIT_USE_PHOENIX_V3=1 \
				  -DBOOST_SPIRIT_DEBUG=1

WARNING_FLAGS	= -Wall -Wextra  -W \
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
		  $(COVERAGE_CFLAGS) \
		  $(SOURCE_DEFINES) $(WARNING_FLAGS)


LINKER_FLAGS= -rdynamic $(BOOST_LDFLAGS) $(PTHREAD_CFLAGS) $(COVERAGE_LDFLAGS)

LINKER_LIBS			= $(BOOST_SYSTEM_LIB) $(BOOST_IOSTREAMS_LIB) \
		  $(BOOST_PROGRAM_OPTIONS_LIB) \
		  $(BOOST_REGEX_LIB) \
		  $(BOOST_FILESYSTEM_LIB) \
		  $(PTHREAD_LIBS)
