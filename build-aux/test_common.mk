INCLUDE_DIRS	= -I$(top_builddir) \
				  -I$(top_srcdir)/sources/include \
				  -I$(top_srcdir)/tests/include

SOURCE_DEFINES= -DPACKAGE_VERSION="\"${PACKAGE_VERSION}\"" \
		-D__STDC_LIMIT_MACROS=1 \
		-DBOOST_SPIRIT_USE_PHOENIX_V3=1 \
		-DBOOST_SPIRIT_DEBUG=1 \
		-DBOOST_SIGNALS_NO_DEPRECATION_WARNING=1

TEST_DEFINES	= $(SOURCE_DEFINES) \
				  -DFIXTURES_DIR="\"${abs_top_srcdir}/tests/fixtures\"" \
				  -DBOOST_TEST_DYN_LINK="1"

LINKER_FLAGS	= $(BOOST_LDFLAGS) \
				  $(COVERAGE_LDFLAGS) \
				  -rdynamic

WARNING_FLAGS	= -Wall -Wextra -pedantic \
		  -Wunused-value \
		  -Wcast-align \
		  -Wno-unused-parameter \
		  -Wunused-variable \
		  -Winit-self \
		  -Wfloat-equal \
		  -Wno-undef \
		  -Wno-shadow \
		  -Wcast-qual \
		  -Wwrite-strings

COMPILE_FLAGS	= $(INCLUDE_DIRS) \
				  $(BOOST_CPPFLAGS) \
				  $(SOURCE_DEFINES) \
				  $(TEST_DEFINES) \
				  $(WARNING_FLAGS)

LINKER_LIBS		= $(BOOST_UNIT_TEST_FRAMEWORK_LIB) \
				  $(BOOST_SYSTEM_LIB) -lboost_iostreams\
				  $(BOOST_FILESYSTEM_LIB)
