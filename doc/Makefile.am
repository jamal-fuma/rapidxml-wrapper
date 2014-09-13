# doc/Makefile.am
docdir 		= $(datadir)/doc

# ship rapidxml license
doc_rapidxmldir = $(docdir)/rapidxml
doc_rapidxml_DATA = \
	$(top_srcdir)/doc/rapidxml/licence.txt \
	$(top_srcdir)/doc/rapidxml/manual.html \
	$(top_srcdir)/doc/wt/patches/rapidxml/002-utf8-validation-from-wt.patch

# ship boost license
doc_boostdir = $(docdir)/boost
doc_boost_DATA = \
	$(top_srcdir)/doc/boost/licence.txt

# ship wt license
doc_wtdir = $(docdir)/wt
doc_wt_DATA = \
	$(top_srcdir)/doc/wt/licence.txt

# remove the create
uninstall-hook:
	    if test -d $(DESTDIR)$(doc_boostdir); then rmdir $(DESTDIR)$(doc_boostdir); fi
	    if test -d $(DESTDIR)$(doc_rapidxmldir); then rmdir $(DESTDIR)$(doc_rapidxmldir); fi
	    if test -d $(DESTDIR)$(doc_wtdir); then rmdir $(DESTDIR)$(doc_wtdir); fi
	    if test -d $(DESTDIR)$(docdir); then rmdir $(DESTDIR)$(docdir); fi
	    if test -d $(DESTDIR)$(datadir); then rmdir $(DESTDIR)$(datadir); fi

MAINTAINERCLEANFILES = \
 $(top_srcdir)/doc/Makefile.in
