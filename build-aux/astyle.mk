if HAVE_ASTYLE
astyle:
	[ -d $(abs_top_srcdir)/sources ] && $(ASTYLE) -n -R $(abs_top_srcdir)/sources/*.hpp
	[ -d $(abs_top_srcdir)/sources ] && $(ASTYLE) -n -R $(abs_top_srcdir)/sources/*.cpp
	[ -d $(abs_top_srcdir)/tests ] && $(ASTYLE) -n -R $(abs_top_srcdir)/tests/*.hpp
	[ -d $(abs_top_srcdir)/tests ] && $(ASTYLE) -n -R $(abs_top_srcdir)/tests/*.cpp
endif # HAVE_ASTYLE
