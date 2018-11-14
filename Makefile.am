SUBDIRS = src man
EXTRA_DIST = VERSION PROJECTS BUGS

dist-hook:
	@set -e; \
	 for file in `cd $(top_srcdir); find . -type f -name distfiles`; do \
	    dir=`dirname $$file` ; $(mkinstalldirs) $(distdir)/$$dir ; \
	    for i in distfiles `cat $(top_srcdir)/$$file` ; do \
 	        ln $(top_srcdir)/$$dir/$$i $(distdir)/$$dir/$$i 2> /dev/null \
	        || cp -p $(top_srcdir)/$$dir/$$i $(distdir)/$$dir/$$i; \
	    done ; \
	done
	@set -e; \
	sed -e 	's/@pkg_version@/$(VERSION)/g' \
	    $(top_srcdir)/scripts/magic.spec.in \
	    > $(distdir)/scripts/magic.spec
