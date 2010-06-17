## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

plse_beleg_5docdir = ${prefix}/doc/plse_beleg_5
plse_beleg_5doc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(plse_beleg_5doc_DATA)

# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(plse_beleg_5docdir)
