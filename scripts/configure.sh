#!/bin/sh

# workout the absolute path to the checkout directory
abspath()
{
    case "${1}" in
        [./]*)
            local ABSPATH="$(cd ${1%/*}; pwd)/${1##*/}"
            echo "${ABSPATH}"
            ;;
        *)
            echo "${PWD}/${1}"
            ;;
    esac
}

SCRIPT=$(abspath ${0})
SCRIPTPATH=`dirname ${SCRIPT}`
ROOTPATH=`dirname ${SCRIPTPATH}`
export PROJECT_ROOT=${ROOTPATH}
export PROJECT_NAME="rapidxml"
export PROJECT_USER="rapidxml"

#  CC          C compiler command
#  CFLAGS      C compiler flags
#  LDFLAGS     linker flags, e.g. -L<lib dir> if you have libraries in a nonstandard directory <lib dir>
#  LIBS        libraries to pass to the linker, e.g. -l<library>
#  CPPFLAGS    (Objective) C/C++ preprocessor flags, e.g. -I<include dir> if you have headers in a nonstandard directory <include dir>
#  CPP         C preprocessor
#  CXX         C++ compiler command
#  CXXFLAGS    C++ compiler flags
#  CXXCPP      C++ preprocessor

case "${1}" in
	"centos")
		PTHREAD_LIBS="-L/lib64 -lpthread" \
		${PROJECT_ROOT}/configure \
			--prefix="/home/${PROJECT_NAME}/software/${PROJECT_NAME}/" \
			--with-webtoolkit="/home/${PROJECT_NAME}/software/wt/current" \
			--enable-maintainer-mode \
			--enable-silent-rules \
			--with-boost="/home/${PROJECT_NAME}/software/wt/current" \
			--with-boost-libdir="/home/${PROJECT_NAME}/software/wt/current/lib" \
			--with-ccache=yes ;
		;;
	"bsd|linux")
		${PROJECT_ROOT}/configure \
			--prefix="/home/${PROJECT_NAME}/software/${PROJECT_NAME}/" \
			--with-webtoolkit="/home/${PROJECT_NAME}/software/wt/current" \
			--enable-maintainer-mode \
			--enable-silent-rules \
			--with-ccache=yes ;
		;;
	"profile")
		${PROJECT_ROOT}/configure \
			--prefix="/home/${PROJECT_NAME}/software/${PROJECT_NAME}/" \
			--with-webtoolkit="/home/${PROJECT_NAME}/software/wt/current" \
			--enable-maintainer-mode \
			--enable-silent-rules \
                	--enable-gcov;
		;;
	"osx")
		CTAGS=/usr/local/bin/ctags \
		CTAGSFLAGS="-R --tag-relative=yes --exclude=.git --exclude=build" \
		ASTYLE_TOOL=/usr/local/Cellar/astyle/2.04/bin/astyle \
		${PROJECT_ROOT}/configure \
			--prefix="/Users/${PROJECT_NAME}/software/${PROJECT_NAME}/" \
			--enable-maintainer-mode \
			--with-sqlite3=yes \
			--with-ccache=yes \
			--enable-debug \
			--enable-silent-rules ;
		;;
	*)
esac
