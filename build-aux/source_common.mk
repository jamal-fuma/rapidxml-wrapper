INCLUDE_DIRS= -I$(top_builddir) -I$(top_srcdir)/sources/include

SOURCE_DEFINES= -DPACKAGE_VERSION="\"${PACKAGE_VERSION}\"" \
		-D__STDC_LIMIT_MACROS=1 \
		-DBOOST_SPIRIT_USE_PHOENIX_V3=1 \
		-DBOOST_SPIRIT_DEBUG=1

WARNING_FLAGS= \
 -Wall\
 -Wextra\
 -pedantic\
 -Wunused-value\
 -Wcast-align\
 -Wno-unused-parameter\
 -Wunused-variable\
 -Winit-self\
 -Wfloat-equal\
 -Wno-undef\
 -Wno-shadow\
 -Wcast-qual\
 -Wwrite-strings

COMPILE_FLAGS = $(INCLUDE_DIRS) \
		$(BOOST_CPPFLAGS) \
		$(COVERAGE_CFLAGS) \
		$(SOURCE_DEFINES) $(WARNING_FLAGS)

LINKER_FLAGS= -rdynamic

LINKER_LIBS=

LINKER_LIBS		= $(BOOST_SYSTEM_LIB) -lboost_iostreams\
				  $(BOOST_PROGRAM_OPTIONS_LIB) \
				  $(BOOST_REGEX_LIB) \
				  $(BOOST_FILESYSTEM_LIB)
