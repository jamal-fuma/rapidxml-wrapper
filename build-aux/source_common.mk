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

COMPILE_FLAGS = $(INCLUDE_DIRS) $(SOURCE_DEFINES) $(WARNING_FLAGS)

LINKER_FLAGS= -lboost_iostreams -lboost_filesystem -lboost_system -rdynamic

LINKER_LIBS=


