TOPDIR = ../..

include $(TOPDIR)/Preamble.make

TESTS = fill_holes punch_holes verify_holes

CFLAGS = -O2 -Wall -g $(OCFS2_CFLAGS)

INCLUDES = -I$(TOPDIR)/programs/libocfs2test

LIBO2TEST = $(TOPDIR)/programs/libocfs2test/libocfs2test.a

SOURCES = fill_holes.c punch_holes.c verify_holes.c fill_holes.h reservations.h

SUBDIRS = fill_holes_data

DIST_FILES = $(SOURCES)

BIN_EXTRA = burn-in.sh old_burn-in.sh fill_verify_holes.sh

BIN_PROGRAMS = fill_holes punch_holes verify_holes 

fill_holes: fill_holes.o fill_holes.h
	$(LINK) $(OCFS2_LIBS) $(LIBO2TEST) -laio

punch_holes: punch_holes.o fill_holes.h
	$(LINK) $(OCFS2_LIBS) $(LIBO2TEST) -laio

verify_holes: verify_holes.o fill_holes.h
	$(LINK) $(OCFS2_LIBS)

include $(TOPDIR)/Postamble.make
