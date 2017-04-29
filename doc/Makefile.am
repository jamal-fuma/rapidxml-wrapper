# doc/Makefile.am
include $(top_srcdir)/build-aux/data_common.mk
docdir 	= $(datadir)/doc

EXTRA_DIST= boost rapidxml wt
# ship rapidxml license
doc_rapidxmldir = $(docdir)/rapidxml
doc_rapidxml_DATA = \
	rapidxml/licence.txt \
	rapidxml/manual.html

# ship boost license
doc_boostdir = $(docdir)/boost
doc_boost_DATA = \
	boost/licence.txt

# ship wt license
doc_wtdir = $(docdir)/wt
doc_wt_DATA = \
	wt/licence.txt
	wt/patches/rapidxml/002-utf8-validation-from-wt.patch \
	wt/patches/rapidxml/003-xhtml-entity-expansion-from-wt.patch

uninstall-hook:
	    if test -d $(DISTDIR)$(doc_boostdir); then $$(cd $(DISTDIR)$(doc_boostdir) && rm -f $(DISTDIR)$(doc_boost_DATA) && rmdir $(DISTDIR)$(doc_boostdir);); fi
	    if test -d $(DISTDIR)$(doc_rapidxmldir); then $$(cd $(DISTDIR)$(doc_rapidxmldir) && rm -f $(DISTDIR)$(doc_rapidxml_DATA) && rmdir $(DISTDIR)$(doc_rapidxmldir);); fi
	    if test -d $(DISTDIR)$(doc_wtdir); then $$(cd $(DISTDIR)$(doc_wtdir) && rm -f $(DISTDIR)$(doc_wt_DATA) && rmdir $(DISTDIR)$(doc_wtdir);); fi
	    if test -d $(DISTDIR)$(docdir); then rmdir $(DISTDIR)$(docdir); fi

MAINTAINERCLEANFILES = \
 $(top_srcdir)/doc/Makefile.in
