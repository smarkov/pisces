# Makefile generated by imake - do not edit!
# $XConsortium: imake.c,v 1.37 88/10/08 20:08:30 jim Exp $
#
# The cpp used on this machine replaces all newlines and multiple tabs and
# spaces in a macro expansion with a single space.  Imake tries to compensate
# for this, but is not always successful.
#

###########################################################################
# Fri Jul 28 16:32:04 PDT 1989 (dredge--stanford)
# "Imake.tmpl": Imake template file for Stanford CAD tools
#
# Do not change the body of the imake template file.  Server-specific
# parameters may be set in the appropriate .def file; site-specific
# parameters (but shared by all servers) may be set in site.def.  If you
# make any changes, you'll need to rebuild the makefiles using
# "make Makefile; make Makefiles" (at least) in the top level directory.
#
# If you absolutely can't get imake to work, you'll need to set the
# variables at the top of each Makefile as well as the dependencies at the
# bottom ("make depend" will do this automatically).
#

###########################################################################
# platform-specific configuration parameters - edit Sun.def to change

          SHELL = /bin/sh
             CC = cc
            F77 = f77
           VF77 = $(F77)
            VCC = $(CC)
         RATFOR = ratfor
       CMINUS_C = -c
       FMINUS_C = -c
      VCMINUS_C = -c
      VFMINUS_C = -c
            CPP = /lib/cpp
        INSTALL = install -c -m
             RM = rm -f
          RMDIR = rm -rf
          MKDIR = mkdir
          CHMOD = chmod
             MV = mv
             CP = cp
             LN = ln -s
         RANLIB = ranlib
RANLIBINSTFLAGS = -t
             AR = ar clq
           LINT = lint
       LINTOPTS = -axz
           MAKE = make
          NROFF = nroff
       MANFLAGS = -man
     NROFF_FILT = | colcrt -

###########################################################################
# site-specific configuration parameters - edit site.def to change

# site.def: Thu Sep  7 11:15:10 PDT 1989 (dredge--stanford)

###########################################################################
# definitions common to all Makefiles - do not edit

        SYSTYPE = -DBSD
    SYSINCLUDES = -I"/tmp/icl"/include
        DESTDIR = "/tmp/icl"
         BINDIR = "/tmp/icl"/bin
         INCDIR = "/tmp/icl"/include
         LIBDIR = "/tmp/icl"/lib
         MANDIR = "/tmp/icl"/man
         MANEXT = l

     PLOTCAPDIR = "/tmp/icl"/lib
        PLOTCAP = "/tmp/icl"/lib/plotcap

    PLOTCAPLIBS = "/tmp/icl"/lib/libhigh2.a "/tmp/icl"/lib/libgplot.a
 F77PLOTCAPLIBS = "/tmp/icl"/lib/libgplotF77.a "/tmp/icl"/lib/libhigh2.a "/tmp/icl"/lib/libgplot.a
      GENII3LIB = "/tmp/icl"/lib/libgenii.a
     GENII3PROG = "/tmp/icl"/bin/genii3
       SPIFILIB = "/tmp/icl"/lib/libspifi0.a
         SYSF77 = "/tmp/icl"/lib/libsysf77.a
        F77LIBS = -lF77 -lI77 -lU77

      EDLINELIB = "/tmp/icl"/lib/libedline.a

     C_TOOLLIBS = $(SPIFILIB) $(PLOTCAPLIBS) $(EDLINELIB)
   F77_TOOLLIBS = $(GENII3LIB) $(SPIFILIB) $(F77PLOTCAPLIBS) $(SYSF77) $(EDLINELIB)
    VC_TOOLLIBS = $(C_TOOLLIBS)
  VF77_TOOLLIBS = $(F77_TOOLLIBS)

     PISCES_DIR = "/tmp/icl"/pisces
   SUPREM35_DIR = "/tmp/icl"/suprem35

   INSTBINFLAGS = 0755
   INSTLIBFLAGS = 0664
   INSTINCFLAGS = 0444
   INSTMANFLAGS = 0444
  INSTFILEFLAGS = 0444
   INSTDIRFLAGS = 0755
  COPYFILEFLAGS = 0644
   COPYBINFLAGS = 0755

    CDEBUGFLAGS =  -O
    FDEBUGFLAGS =  -O -u
   VCDEBUGFLAGS =  -O
   VFDEBUGFLAGS =  -O -u

        MAKEDEP = makedep
  MAKEDEP_FLAGS = -o Makefile.dep -N $(INCLUDES) $(SYSINCLUDES)
 MAKEDEP_OUTPUT =

CPPFLAGS= $(INCLUDES) $(DEFINES) $(SYSTYPE) $(SYSINCLUDES)
CFLAGS = $(CDEBUGFLAGS) $(CPPFLAGS)
FFLAGS = $(FDEBUGFLAGS) $(CPPFLAGS)
VCFLAGS = $(VCDEBUGFLAGS) $(CPPFLAGS)
VFFLAGS = $(VFDEBUGFLAGS) $(CPPFLAGS)
         RFLAGS = -6 -C
       CLDFLAGS = $(CDEBUGFLAGS)
       FLDFLAGS = $(FDEBUGFLAGS)
      VCLDFLAGS = $(VCDEBUGFLAGS)
      VFLDFLAGS = $(VFDEBUGFLAGS)

LINT = lint
LINTFLAGS = -hxanc $(INCLUDES) $(DEFINES) $(SYSTYPE) $(SYSINCLUDES)
LINTLIBFLAGS = $(INCLUDES) $(DEFINES) $(SYSTYPE) $(SYSINCLUDES) -v -C
LINTDIR = "/tmp/icl"/lib

        MATHLIB = -lm
        SYSLIBS =  -ltermcap $(MATHLIB)

      MACROFILE = Sun.def
         SYSDEF = -DSUN4
      SHELL_EXT = .sh

# Imake parameters
          IRULE = /tmp/release/utils/imakesrc
          IMAKE = /tmp/bin/imake
   ICONFIGFILES = Imakefile $(IRULE)/Imake.tmpl $(IRULE)/$(MACROFILE) \
			$(IRULE)/site.def $(IRULE)/Imake.rules

  IMAKE_DEFINES =
      IMAKE_CMD = $(IMAKE) -TImake.tmpl -I$(IRULE)/Defaults -I$(IRULE) \
			-s Makefile $(SYSDEF) $(IMAKE_DEFINES) \
			'-DImakeDefines=$(IMAKE_DEFINES)'

         RM_CMD = $(RM) *.CKP *.BAK *.bak *.o core ,* *~ *.a \
			.emacs_* tags make.log

# The user Imakefile could probably override this
     RELEASEDIR = release

# Some Makes are compiled with the .f and .r reverses
#  anyway, make sure that we get what we really want.

.SUFFIXES:

.SUFFIXES: .o .r .F .f .c

# Specific rules.

.c.o:
	$(CC) $(CMINUS_C) $(CFLAGS) $*.c

.f.o:
	$(F77) $(FMINUS_C) $(FFLAGS) $*.f

.r.o:
	$(RATFOR) $(RFLAGS) $*.r > $*.f
	$(F77) $(FMINUS_C) $(FFLAGS) $*.f

###########################################################################
# start of Imakefile

# -----------------------------------------------------------------------------
# Fri Aug  3 11:17:04 PDT 1990 (dredge--stanford)

# Probably NOT safe anymore.  Don't do it.  It is just plain big now.
#DEFINES= -DINTeger='integer*2'

PISCES_VERSION=	9009
RELEASE=	S.0523 SunOS 4.0

PISCES=pisces2
PISLIB=libpisc2.a
OPTLIB=libpisc2a.a

INCDIR=.

INCLUDES= -I$(INCDIR)
# =============================================================================

PISCES_DEST=$(PISCES_DIR)/$(PISCES_VERSION)

MAIN_SRC=pisc2.f
MAIN_OBJ= pisc2.o

# The full object list for Pisces.
PIS_OBJS= \
	acanal.o \
	breakdown.o \
	clock.o \
	disct.o \
	doping.o \
	erite.o \
	extract.o \
	filopncls.o \
	flowline.o \
	impact.o \
	incfil.o \
	interface.o \
	loadsol.o \
	machplot.o \
	mcintfc.o \
	md.o \
	meshgen.o \
	meshio.o \
	meshrect.o \
	method.o \
	misc.o \
	mobil.o \
	options.o \
	pcrchol.o \
	pisces.o \
	plotter.o \
	plotutil.o \
	plotvec.o \
	printer.o \
	regrid.o \
	s3read.o \
	s4read.o \
	setmat.o \
	smobl.o \
	smooth.o \
	solasmb1.o \
	solasmb2.o \
	solgummel.o \
	sollud.o \
	solnewton.o \
	solver.o \
	stats.o \
	symbol.o \
	trefld.o \
	trfldmob.o \
	usrmob1.o \
	volume.o \
	$(DUMPA_OBJ)

# The full source list for Pisces.
PIS_SRCS= \
	acanal.f \
	breakdown.f \
	clock.f \
	disct.f \
	doping.f \
	erite.f \
	extract.f \
	filopncls.f \
	flowline.f \
	impact.f \
	incfil.f \
	interface.f \
	loadsol.f \
	machplot.f \
	mcintfc.f \
	md.f \
	meshgen.f \
	meshio.f \
	meshrect.f \
	method.f \
	misc.f \
	mobil.f \
	options.f \
	pcrchol.f \
	pisces.f \
	plotter.f \
	plotutil.f \
	plotvec.f \
	printer.f \
	regrid.f \
	s3read.f \
	s4read.f \
	setmat.f \
	smobl.f \
	smooth.f \
	solasmb1.f \
	solasmb2.f \
	solgummel.f \
	sollud.f \
	solnewton.f \
	solver.f \
	stats.f \
	symbol.f \
	trefld.f \
	trfldmob.f \
	usrmob1.f \
	volume.f \
	$(DUMPA_SRC)

# Option (null) interface code.
OPT_OBJS=	mc.o
OPT_SRCS=	mc.f

VERS_OBJ= version.o
VERS_SRC= version.f

SOURCES=	$(MAIN_SRC) $(PIS_SRCS) $(OPT_SRCS)
OBJECTS=	$(MAIN_OBJ) $(PIS_OBJS) $(OPT_OBJS) $(VERS_OBJ)

HFILES= adjstk.h adjtmp.h bitmp.h blank.h difftmp.h doptmp.h emaco.h \
	eritco.h extrtmp.h flowtmp.h igitmp.h impact.h key.h logunt.h \
	monte.h mshtmp.h names.h ordtmp.h p2conf.h photo.h \
	plot.h plttmp.h rgdtmp.h rgrid.h setup.h smhtmp.h sol.h \
	soltmpg.h soltmpn.h stat.h symb.h symme.h \
	symtmp1.h symtmp3.h symtmp4.h trfldmob.h usrmob1.h

# =============================================================================

all:: $(PISCES) lib

# I. Make the program.

$(PISCES): $(MAIN_OBJ)  $(PISLIB) $(OPTLIB)
	$(RM) $@
	$(F77) -o $@ $(FLDFLAGS) $(MAIN_OBJ)  $(PISLIB) $(OPTLIB)  $(LIBS) $(F77_TOOLLIBS) $(SYSLIBS)
	@echo make $(PISCES) done.

clean::
	$(RM) $(PISCES)

# II. Make the library.
lib: $(PISLIB) $(OPTLIB)

$(PISLIB):  $(PIS_OBJS) $(VERS_OBJ)
	$(RM) $@
	$(AR) $(PISLIB)  $(PIS_OBJS) $(VERS_OBJ)
	$(RANLIB) $(RANLIBFLAGS) $(PISLIB)
	@echo make $(PISLIB) done.

$(OPTLIB):  $(OPT_OBJS)
	$(RM) $@
	$(AR) $(OPTLIB)  $(OPT_OBJS)
	$(RANLIB) $(RANLIBFLAGS) $(OPTLIB)
	@echo make $(OPTLIB) done.

method.o: method.f
	csh -fc "limit stack 16meg; $(F77) -c $(FFLAGS) $<"

# =============================================================================
# Special rules for files that can be vectorized....

sollud.o:  sollud.f
	$(VF77) $(VFMINUS_C) $(VFFLAGS)   $*.f

# =============================================================================

install:: $(PISCES_DEST)/$(PISCES)
$(PISCES_DEST)/$(PISCES): $(PISCES)
	$(INSTALL) $(INSTBINFLAGS) $(PISCES) $(PISCES_DEST)/$(PISCES)

install:: $(PISCES_DEST)/$(PISLIB)
$(PISCES_DEST)/$(PISLIB): $(PISLIB)
	$(INSTALL) $(INSTLIBFLAGS) $(PISLIB) $(PISCES_DEST)/$(PISLIB)
	$(RANLIB) $(RANLIBINSTFLAGS) $(PISCES_DEST)/$(PISLIB)

install:: $(PISCES_DEST)/$(OPTLIB)
$(PISCES_DEST)/$(OPTLIB): $(OPTLIB)
	$(INSTALL) $(INSTLIBFLAGS) $(OPTLIB) $(PISCES_DEST)/$(OPTLIB)
	$(RANLIB) $(RANLIBINSTFLAGS) $(PISCES_DEST)/$(OPTLIB)

install:: $(BINDIR)/pisc2
$(BINDIR)/pisc2: pisc2
	$(INSTALL) $(INSTBINFLAGS) pisc2 $(BINDIR)/pisc2

# and the shell to run the program.

# replace pisc2 with pisc2.tmp, only if pisc2.tmp is different!
pisc2: pisc2.tmp Please
	@-if test ! -f pisc2 ; then \
	$(MV) pisc2.tmp pisc2 ; \
	echo Created pisc2 ; \
	else \
	if cmp -s pisc2.tmp pisc2 ; then echo pisc2 ok ; \
	else $(RM) pisc2 ; $(MV) pisc2.tmp pisc2 ; \
	echo Updated pisc2 ; \
	fi ; \
	fi
pisc2.tmp: pisc2.sh Makefile
	sed -e 's;^[ 	]*PISC2DIR=.*;PISC2DIR=$(PISCES_DIR)/$(PISCES_VERSION);' \
	    -e 's;^[ 	]*VERS=.*;VERS=$(PISCES_VERSION);' pisc2.sh > pisc2.tmp

install:: $(PISCES_DEST)/pisc.key
$(PISCES_DEST)/pisc.key: pisc.key
	$(INSTALL) $(INSTFILEFLAGS) pisc.key $(PISCES_DEST)/pisc.key

install:: $(PISCES_DEST)/pisc.uky
$(PISCES_DEST)/pisc.uky: pisc.uky
	$(INSTALL) $(INSTFILEFLAGS) pisc.uky $(PISCES_DEST)/pisc.uky

# make and install the binary keyfile.
pisc.uky:: pisc.key $(PISCES)
	$(RM) $@
	./$(PISCES) /dev/null
	mv PISC2UKY  pisc.uky
clean::
	$(RM) pisc.uky

###########################################################################
# Imake.tmpl common rules for all Makefiles - do not edit

emptyrule::

clean::
	$(RM_CMD)

Makefile:: $(ICONFIGFILES)
	-@if [ -f Makefile ] ; then \
	$(RM) Makefile.bak; $(CP) Makefile Makefile.bak;\
	fi
	$(IMAKE_CMD)

depend::
	$(MAKEDEP) $(MAKEDEP_FLAGS) $(SOURCES)

lint::
	$(LINT) $(LINTFLAGS) $(CSOURCES) $(LINTLIBS)

release::
	@echo "release done."

Makefiles::
	@echo "Makefiles done."
install::
	@echo "install done."
lintlibs::
	@echo "lintlibs done."

# Force any target -- make it depend on 'Please'
Please:

###########################################################################
# dependencies generated by makedepend

pisc2.o: pisc2.f
acanal.o: acanal.f
acanal.o: ./p2conf.h
acanal.o: ./blank.h
acanal.o: ./setup.h
acanal.o: ./logunt.h
acanal.o: ./symme.h
acanal.o: ./emaco.h
acanal.o: ./soltmpn.h
acanal.o: ./p2conf.h
acanal.o: ./blank.h
acanal.o: ./setup.h
acanal.o: ./emaco.h
acanal.o: ./soltmpn.h
acanal.o: ./p2conf.h
acanal.o: ./blank.h
acanal.o: ./logunt.h
acanal.o: ./emaco.h
breakdown.o: breakdown.f
breakdown.o: ./p2conf.h
breakdown.o: ./blank.h
breakdown.o: ./setup.h
breakdown.o: ./logunt.h
breakdown.o: ./impact.h
breakdown.o: ./emaco.h
breakdown.o: ./adjtmp.h
breakdown.o: ./p2conf.h
breakdown.o: ./blank.h
breakdown.o: ./setup.h
breakdown.o: ./logunt.h
breakdown.o: ./impact.h
breakdown.o: ./emaco.h
breakdown.o: ./p2conf.h
breakdown.o: ./impact.h
breakdown.o: ./p2conf.h
breakdown.o: ./emaco.h
breakdown.o: ./p2conf.h
breakdown.o: ./emaco.h
clock.o: clock.f
clock.o: ./p2conf.h
clock.o: ./blank.h
disct.o: disct.f
disct.o: ./p2conf.h
disct.o: ./blank.h
disct.o: ./logunt.h
disct.o: ./emaco.h
doping.o: doping.f
doping.o: ./p2conf.h
doping.o: ./blank.h
doping.o: ./stat.h
doping.o: ./setup.h
doping.o: ./logunt.h
doping.o: ./adjtmp.h
doping.o: ./doptmp.h
doping.o: ./p2conf.h
doping.o: ./blank.h
doping.o: ./emaco.h
doping.o: ./adjtmp.h
doping.o: ./doptmp.h
doping.o: ./p2conf.h
doping.o: ./blank.h
doping.o: ./setup.h
doping.o: ./emaco.h
doping.o: ./p2conf.h
doping.o: ./blank.h
doping.o: ./logunt.h
doping.o: ./adjtmp.h
doping.o: ./doptmp.h
doping.o: ./p2conf.h
doping.o: ./blank.h
doping.o: ./emaco.h
doping.o: ./p2conf.h
doping.o: ./blank.h
doping.o: ./logunt.h
doping.o: ./adjtmp.h
doping.o: ./doptmp.h
doping.o: ./p2conf.h
doping.o: ./blank.h
doping.o: ./logunt.h
doping.o: ./adjtmp.h
doping.o: ./doptmp.h
doping.o: ./p2conf.h
doping.o: ./adjtmp.h
doping.o: ./doptmp.h
doping.o: ./p2conf.h
doping.o: ./blank.h
erite.o: erite.f
erite.o: ./p2conf.h
erite.o: ./logunt.h
erite.o: ./blank.h
erite.o: ./eritco.h
erite.o: ./p2conf.h
erite.o: ./eritco.h
erite.o: ./blank.h
extract.o: extract.f
extract.o: ./p2conf.h
extract.o: ./blank.h
extract.o: ./logunt.h
extract.o: ./setup.h
extract.o: ./extrtmp.h
extract.o: ./p2conf.h
extract.o: ./blank.h
extract.o: ./logunt.h
extract.o: ./setup.h
extract.o: ./stat.h
extract.o: ./extrtmp.h
extract.o: ./p2conf.h
extract.o: ./blank.h
extract.o: ./emaco.h
extract.o: ./extrtmp.h
extract.o: ./p2conf.h
extract.o: ./blank.h
extract.o: ./setup.h
extract.o: ./emaco.h
extract.o: ./extrtmp.h
extract.o: ./p2conf.h
extract.o: ./blank.h
extract.o: ./setup.h
extract.o: ./emaco.h
extract.o: ./extrtmp.h
extract.o: ./p2conf.h
extract.o: ./blank.h
extract.o: ./setup.h
extract.o: ./emaco.h
extract.o: ./extrtmp.h
filopncls.o: filopncls.f
flowline.o: flowline.f
flowline.o: ./p2conf.h
flowline.o: ./blank.h
flowline.o: ./sol.h
flowline.o: ./setup.h
flowline.o: ./logunt.h
flowline.o: ./emaco.h
flowline.o: ./adjtmp.h
flowline.o: ./flowtmp.h
flowline.o: ./p2conf.h
flowline.o: ./blank.h
flowline.o: ./emaco.h
flowline.o: ./adjtmp.h
flowline.o: ./flowtmp.h
flowline.o: ./p2conf.h
flowline.o: ./blank.h
flowline.o: ./sol.h
flowline.o: ./setup.h
flowline.o: ./logunt.h
flowline.o: ./emaco.h
flowline.o: ./adjtmp.h
flowline.o: ./flowtmp.h
flowline.o: ./p2conf.h
flowline.o: ./blank.h
flowline.o: ./sol.h
flowline.o: ./emaco.h
flowline.o: ./adjtmp.h
flowline.o: ./flowtmp.h
flowline.o: ./p2conf.h
flowline.o: ./blank.h
flowline.o: ./setup.h
flowline.o: ./sol.h
flowline.o: ./emaco.h
flowline.o: ./adjtmp.h
flowline.o: ./flowtmp.h
flowline.o: ./p2conf.h
flowline.o: ./blank.h
flowline.o: ./emaco.h
flowline.o: ./adjtmp.h
flowline.o: ./flowtmp.h
impact.o: impact.f
impact.o: ./p2conf.h
impact.o: ./impact.h
impact.o: ./p2conf.h
impact.o: ./impact.h
impact.o: ./p2conf.h
impact.o: ./impact.h
impact.o: ./monte.h
impact.o: ./p2conf.h
impact.o: ./blank.h
impact.o: ./impact.h
incfil.o: incfil.f
interface.o: interface.f
interface.o: ./p2conf.h
interface.o: ./blank.h
interface.o: ./setup.h
interface.o: ./p2conf.h
interface.o: ./blank.h
interface.o: ./setup.h
interface.o: ./emaco.h
interface.o: ./p2conf.h
interface.o: ./blank.h
interface.o: ./setup.h
interface.o: ./emaco.h
interface.o: ./adjtmp.h
interface.o: ./doptmp.h
loadsol.o: loadsol.f
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./setup.h
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./setup.h
loadsol.o: ./logunt.h
loadsol.o: ./sol.h
loadsol.o: ./emaco.h
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./setup.h
loadsol.o: ./sol.h
loadsol.o: ./logunt.h
loadsol.o: ./impact.h
loadsol.o: ./photo.h
loadsol.o: ./symme.h
loadsol.o: ./emaco.h
loadsol.o: ./adjtmp.h
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./setup.h
loadsol.o: ./sol.h
loadsol.o: ./logunt.h
loadsol.o: ./impact.h
loadsol.o: ./photo.h
loadsol.o: ./symme.h
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./setup.h
loadsol.o: ./sol.h
loadsol.o: ./logunt.h
loadsol.o: ./impact.h
loadsol.o: ./photo.h
loadsol.o: ./emaco.h
loadsol.o: ./adjtmp.h
loadsol.o: ./plttmp.h
loadsol.o: ./difftmp.h
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./setup.h
loadsol.o: ./sol.h
loadsol.o: ./logunt.h
loadsol.o: ./emaco.h
loadsol.o: ./adjtmp.h
loadsol.o: ./plttmp.h
loadsol.o: ./difftmp.h
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./emaco.h
loadsol.o: ./p2conf.h
loadsol.o: ./blank.h
loadsol.o: ./logunt.h
loadsol.o: ./setup.h
loadsol.o: ./names.h
loadsol.o: ./sol.h
loadsol.o: ./emaco.h
machplot.o: machplot.f
machplot.o: ./p2conf.h
machplot.o: ./plot.h
machplot.o: ./p2conf.h
machplot.o: ./plot.h
machplot.o: ./p2conf.h
machplot.o: ./plot.h
mcintfc.o: mcintfc.f
mcintfc.o: ./p2conf.h
mcintfc.o: ./blank.h
mcintfc.o: ./logunt.h
mcintfc.o: ./monte.h
mcintfc.o: ./emaco.h
mcintfc.o: ./p2conf.h
md.o: md.f
meshgen.o: meshgen.f
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./stat.h
meshgen.o: ./key.h
meshgen.o: ./logunt.h
meshgen.o: ./setup.h
meshgen.o: ./rgrid.h
meshgen.o: ./emaco.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./stat.h
meshgen.o: ./logunt.h
meshgen.o: ./symme.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./stat.h
meshgen.o: ./setup.h
meshgen.o: ./emaco.h
meshgen.o: ./adjtmp.h
meshgen.o: ./doptmp.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./logunt.h
meshgen.o: ./symme.h
meshgen.o: ./emaco.h
meshgen.o: ./adjtmp.h
meshgen.o: ./doptmp.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./setup.h
meshgen.o: ./emaco.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./emaco.h
meshgen.o: ./adjtmp.h
meshgen.o: ./doptmp.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./setup.h
meshgen.o: ./emaco.h
meshgen.o: ./adjtmp.h
meshgen.o: ./adjstk.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshgen.o: ./setup.h
meshgen.o: ./emaco.h
meshgen.o: ./adjtmp.h
meshgen.o: ./adjstk.h
meshgen.o: ./p2conf.h
meshgen.o: ./emaco.h
meshgen.o: ./p2conf.h
meshgen.o: ./setup.h
meshgen.o: ./emaco.h
meshgen.o: ./adjtmp.h
meshgen.o: ./p2conf.h
meshgen.o: ./blank.h
meshio.o: meshio.f
meshio.o: ./p2conf.h
meshio.o: ./blank.h
meshio.o: ./logunt.h
meshio.o: ./symb.h
meshio.o: ./setup.h
meshio.o: ./stat.h
meshio.o: ./emaco.h
meshio.o: ./p2conf.h
meshio.o: ./blank.h
meshio.o: ./setup.h
meshio.o: ./logunt.h
meshio.o: ./symb.h
meshio.o: ./stat.h
meshio.o: ./emaco.h
meshio.o: ./adjtmp.h
meshio.o: ./igitmp.h
meshio.o: ./p2conf.h
meshio.o: ./blank.h
meshio.o: ./adjtmp.h
meshio.o: ./igitmp.h
meshio.o: ./p2conf.h
meshio.o: ./emaco.h
meshio.o: ./adjtmp.h
meshio.o: ./igitmp.h
meshrect.o: meshrect.f
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./stat.h
meshrect.o: ./key.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./stat.h
meshrect.o: ./key.h
meshrect.o: ./symb.h
meshrect.o: ./emaco.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./key.h
meshrect.o: ./stat.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./stat.h
meshrect.o: ./emaco.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./emaco.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./key.h
meshrect.o: ./stat.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./setup.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./symb.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./emaco.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./emaco.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./p2conf.h
meshrect.o: ./emaco.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./stat.h
meshrect.o: ./symb.h
meshrect.o: ./emaco.h
meshrect.o: ./mshtmp.h
meshrect.o: ./p2conf.h
meshrect.o: ./blank.h
meshrect.o: ./stat.h
meshrect.o: ./setup.h
meshrect.o: ./mshtmp.h
method.o: method.f
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./stat.h
method.o: ./sol.h
method.o: ./setup.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./setup.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./setup.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./setup.h
method.o: ./sol.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./setup.h
method.o: ./sol.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./setup.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./p2conf.h
method.o: ./setup.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./setup.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./sol.h
method.o: ./setup.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./setup.h
method.o: ./emaco.h
method.o: ./p2conf.h
method.o: ./blank.h
method.o: ./setup.h
method.o: ./emaco.h
misc.o: misc.f
misc.o: ./p2conf.h
misc.o: ./blank.h
mobil.o: mobil.f
mobil.o: ./p2conf.h
mobil.o: ./p2conf.h
mobil.o: ./p2conf.h
mobil.o: ./p2conf.h
mobil.o: ./impact.h
mobil.o: ./p2conf.h
mobil.o: ./impact.h
mobil.o: ./emaco.h
mobil.o: ./p2conf.h
mobil.o: ./setup.h
options.o: options.f
options.o: ./p2conf.h
options.o: ./plot.h
options.o: ./blank.h
options.o: ./sol.h
options.o: ./logunt.h
options.o: ./p2conf.h
options.o: ./plot.h
pcrchol.o: pcrchol.f
pcrchol.o: ./p2conf.h
pcrchol.o: ./p2conf.h
pcrchol.o: ./p2conf.h
pcrchol.o: ./p2conf.h
pcrchol.o: ./sol.h
pcrchol.o: ./blank.h
pcrchol.o: ./logunt.h
pcrchol.o: ./setup.h
pcrchol.o: ./p2conf.h
pisces.o: pisces.f
pisces.o: ./p2conf.h
pisces.o: ./blank.h
pisces.o: ./names.h
pisces.o: ./stat.h
pisces.o: ./key.h
pisces.o: ./logunt.h
pisces.o: ./plot.h
pisces.o: ./setup.h
pisces.o: ./impact.h
pisces.o: ./p2conf.h
pisces.o: ./blank.h
pisces.o: ./stat.h
pisces.o: ./key.h
pisces.o: ./logunt.h
pisces.o: ./names.h
pisces.o: ./symb.h
pisces.o: ./setup.h
pisces.o: ./sol.h
pisces.o: ./plot.h
pisces.o: ./impact.h
pisces.o: ./symme.h
pisces.o: ./photo.h
pisces.o: ./trfldmob.h
plotter.o: plotter.f
plotter.o: ./p2conf.h
plotter.o: ./blank.h
plotter.o: ./plot.h
plotter.o: ./key.h
plotter.o: ./adjtmp.h
plotter.o: ./plttmp.h
plotter.o: ./p2conf.h
plotter.o: ./blank.h
plotter.o: ./plot.h
plotter.o: ./stat.h
plotter.o: ./setup.h
plotter.o: ./p2conf.h
plotter.o: ./blank.h
plotter.o: ./plot.h
plotter.o: ./emaco.h
plotter.o: ./p2conf.h
plotter.o: ./blank.h
plotter.o: ./plot.h
plotter.o: ./setup.h
plotter.o: ./logunt.h
plotter.o: ./adjtmp.h
plotter.o: ./p2conf.h
plotter.o: ./blank.h
plotter.o: ./plot.h
plotter.o: ./setup.h
plotter.o: ./emaco.h
plotter.o: ./p2conf.h
plotter.o: ./blank.h
plotter.o: ./plot.h
plotter.o: ./setup.h
plotter.o: ./emaco.h
plotter.o: ./p2conf.h
plotter.o: ./plot.h
plotter.o: ./stat.h
plotter.o: ./blank.h
plotter.o: ./setup.h
plotter.o: ./symme.h
plotter.o: ./p2conf.h
plotter.o: ./plot.h
plotter.o: ./logunt.h
plotter.o: ./adjtmp.h
plotter.o: ./plttmp.h
plotter.o: ./p2conf.h
plotter.o: ./blank.h
plotter.o: ./setup.h
plotter.o: ./emaco.h
plotter.o: ./adjtmp.h
plotter.o: ./plttmp.h
plotter.o: ./p2conf.h
plotter.o: ./emaco.h
plotter.o: ./adjtmp.h
plotter.o: ./plttmp.h
plotter.o: ./p2conf.h
plotter.o: ./adjtmp.h
plotter.o: ./plttmp.h
plotter.o: ./p2conf.h
plotter.o: ./logunt.h
plotter.o: ./blank.h
plotter.o: ./plot.h
plotter.o: ./adjtmp.h
plotter.o: ./plttmp.h
plotter.o: ./p2conf.h
plotter.o: ./p2conf.h
plotter.o: ./p2conf.h
plotter.o: ./p2conf.h
plotutil.o: plotutil.f
plotutil.o: ./p2conf.h
plotutil.o: ./blank.h
plotutil.o: ./emaco.h
plotutil.o: ./p2conf.h
plotutil.o: ./blank.h
plotutil.o: ./emaco.h
plotutil.o: ./p2conf.h
plotutil.o: ./blank.h
plotutil.o: ./plot.h
plotutil.o: ./p2conf.h
plotutil.o: ./emaco.h
plotutil.o: ./p2conf.h
plotutil.o: ./plot.h
plotutil.o: ./p2conf.h
plotutil.o: ./blank.h
plotutil.o: ./setup.h
plotutil.o: ./emaco.h
plotutil.o: ./adjtmp.h
plotutil.o: ./difftmp.h
plotutil.o: ./p2conf.h
plotutil.o: ./emaco.h
plotutil.o: ./p2conf.h
plotutil.o: ./plot.h
plotutil.o: ./p2conf.h
plotutil.o: ./adjtmp.h
plotutil.o: ./plttmp.h
plotutil.o: ./p2conf.h
plotutil.o: ./adjtmp.h
plotutil.o: ./plttmp.h
plotutil.o: ./p2conf.h
plotutil.o: ./blank.h
plotutil.o: ./plot.h
plotutil.o: ./emaco.h
plotutil.o: ./p2conf.h
plotutil.o: ./symme.h
plotvec.o: plotvec.f
plotvec.o: ./p2conf.h
plotvec.o: ./blank.h
plotvec.o: ./setup.h
plotvec.o: ./p2conf.h
plotvec.o: ./blank.h
plotvec.o: ./plot.h
plotvec.o: ./logunt.h
plotvec.o: ./emaco.h
plotvec.o: ./adjtmp.h
plotvec.o: ./plttmp.h
plotvec.o: ./p2conf.h
plotvec.o: ./setup.h
plotvec.o: ./sol.h
plotvec.o: ./plot.h
plotvec.o: ./impact.h
plotvec.o: ./symme.h
plotvec.o: ./emaco.h
plotvec.o: ./adjtmp.h
plotvec.o: ./difftmp.h
plotvec.o: ./p2conf.h
plotvec.o: ./p2conf.h
printer.o: printer.f
printer.o: ./p2conf.h
printer.o: ./blank.h
printer.o: ./p2conf.h
printer.o: ./blank.h
printer.o: ./logunt.h
printer.o: ./setup.h
printer.o: ./sol.h
printer.o: ./stat.h
printer.o: ./emaco.h
printer.o: ./adjtmp.h
printer.o: ./plttmp.h
printer.o: ./difftmp.h
printer.o: ./p2conf.h
printer.o: ./blank.h
printer.o: ./emaco.h
printer.o: ./p2conf.h
printer.o: ./blank.h
printer.o: ./stat.h
printer.o: ./setup.h
printer.o: ./plot.h
regrid.o: regrid.f
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./key.h
regrid.o: ./rgrid.h
regrid.o: ./logunt.h
regrid.o: ./setup.h
regrid.o: ./stat.h
regrid.o: ./emaco.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./setup.h
regrid.o: ./rgrid.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./rgrid.h
regrid.o: ./emaco.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./symb.h
regrid.o: ./logunt.h
regrid.o: ./rgrid.h
regrid.o: ./emaco.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./rgrid.h
regrid.o: ./emaco.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./symb.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./symb.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./setup.h
regrid.o: ./symb.h
regrid.o: ./emaco.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./rgrid.h
regrid.o: ./logunt.h
regrid.o: ./emaco.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./rgrid.h
regrid.o: ./emaco.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./blank.h
regrid.o: ./emaco.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./ordtmp.h
regrid.o: ./p2conf.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./p2conf.h
regrid.o: ./rgrid.h
regrid.o: ./emaco.h
regrid.o: ./adjtmp.h
regrid.o: ./rgdtmp.h
regrid.o: ./p2conf.h
regrid.o: ./emaco.h
s3read.o: s3read.f
s3read.o: ./p2conf.h
s3read.o: ./blank.h
s3read.o: ./logunt.h
s3read.o: ./adjtmp.h
s3read.o: ./doptmp.h
s4read.o: s4read.f
s4read.o: ./p2conf.h
s4read.o: ./blank.h
s4read.o: ./setup.h
s4read.o: ./logunt.h
s4read.o: ./symb.h
s4read.o: ./stat.h
s4read.o: ./emaco.h
s4read.o: ./adjtmp.h
s4read.o: ./igitmp.h
setmat.o: setmat.f
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./key.h
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./stat.h
setmat.o: ./emaco.h
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./stat.h
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./stat.h
setmat.o: ./impact.h
setmat.o: ./photo.h
setmat.o: ./trfldmob.h
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./stat.h
setmat.o: ./symme.h
setmat.o: ./emaco.h
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./impact.h
setmat.o: ./symme.h
setmat.o: ./photo.h
setmat.o: ./trfldmob.h
setmat.o: ./emaco.h
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./logunt.h
setmat.o: ./impact.h
setmat.o: ./photo.h
setmat.o: ./symme.h
setmat.o: ./trfldmob.h
setmat.o: ./p2conf.h
setmat.o: ./blank.h
setmat.o: ./setup.h
setmat.o: ./impact.h
setmat.o: ./trfldmob.h
setmat.o: ./emaco.h
smobl.o: smobl.f
smobl.o: ./p2conf.h
smobl.o: ./blank.h
smobl.o: ./setup.h
smobl.o: ./emaco.h
smooth.o: smooth.f
smooth.o: ./p2conf.h
smooth.o: ./adjtmp.h
smooth.o: ./smhtmp.h
smooth.o: ./p2conf.h
smooth.o: ./blank.h
smooth.o: ./setup.h
smooth.o: ./emaco.h
smooth.o: ./adjtmp.h
smooth.o: ./smhtmp.h
smooth.o: ./p2conf.h
smooth.o: ./blank.h
smooth.o: ./emaco.h
smooth.o: ./p2conf.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./adjtmp.h
smooth.o: ./smhtmp.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./p2conf.h
smooth.o: ./blank.h
smooth.o: ./emaco.h
smooth.o: ./adjtmp.h
smooth.o: ./smhtmp.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./adjtmp.h
smooth.o: ./smhtmp.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./adjtmp.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./adjtmp.h
smooth.o: ./p2conf.h
smooth.o: ./logunt.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./p2conf.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./adjtmp.h
smooth.o: ./p2conf.h
smooth.o: ./p2conf.h
smooth.o: ./emaco.h
smooth.o: ./p2conf.h
solasmb1.o: solasmb1.f
solasmb1.o: ./p2conf.h
solasmb1.o: ./blank.h
solasmb1.o: ./setup.h
solasmb1.o: ./sol.h
solasmb1.o: ./logunt.h
solasmb1.o: ./trfldmob.h
solasmb1.o: ./emaco.h
solasmb1.o: ./p2conf.h
solasmb1.o: ./blank.h
solasmb1.o: ./setup.h
solasmb1.o: ./sol.h
solasmb1.o: ./impact.h
solasmb1.o: ./symme.h
solasmb1.o: ./photo.h
solasmb1.o: ./emaco.h
solasmb1.o: ./p2conf.h
solasmb1.o: ./blank.h
solasmb1.o: ./setup.h
solasmb1.o: ./impact.h
solasmb1.o: ./emaco.h
solasmb1.o: ./p2conf.h
solasmb1.o: ./setup.h
solasmb1.o: ./impact.h
solasmb1.o: ./trfldmob.h
solasmb1.o: ./emaco.h
solasmb1.o: ./p2conf.h
solasmb1.o: ./blank.h
solasmb1.o: ./sol.h
solasmb1.o: ./setup.h
solasmb1.o: ./photo.h
solasmb1.o: ./emaco.h
solasmb1.o: ./p2conf.h
solasmb1.o: ./blank.h
solasmb1.o: ./setup.h
solasmb1.o: ./p2conf.h
solasmb1.o: ./blank.h
solasmb1.o: ./setup.h
solasmb1.o: ./emaco.h
solasmb1.o: ./p2conf.h
solasmb1.o: ./blank.h
solasmb1.o: ./setup.h
solasmb1.o: ./emaco.h
solasmb2.o: solasmb2.f
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./setup.h
solasmb2.o: ./sol.h
solasmb2.o: ./emaco.h
solasmb2.o: ./soltmpn.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./setup.h
solasmb2.o: ./emaco.h
solasmb2.o: ./soltmpg.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./symb.h
solasmb2.o: ./soltmpn.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./symb.h
solasmb2.o: ./soltmpg.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./sol.h
solasmb2.o: ./emaco.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./setup.h
solasmb2.o: ./sol.h
solasmb2.o: ./emaco.h
solasmb2.o: ./soltmpn.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./soltmpg.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./sol.h
solasmb2.o: ./emaco.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./setup.h
solasmb2.o: ./sol.h
solasmb2.o: ./emaco.h
solasmb2.o: ./p2conf.h
solasmb2.o: ./blank.h
solasmb2.o: ./setup.h
solasmb2.o: ./sol.h
solasmb2.o: ./emaco.h
solgummel.o: solgummel.f
solgummel.o: ./p2conf.h
solgummel.o: ./blank.h
solgummel.o: ./logunt.h
solgummel.o: ./sol.h
solgummel.o: ./setup.h
solgummel.o: ./emaco.h
solgummel.o: ./soltmpg.h
solgummel.o: ./p2conf.h
solgummel.o: ./blank.h
solgummel.o: ./sol.h
solgummel.o: ./emaco.h
solgummel.o: ./p2conf.h
solgummel.o: ./blank.h
solgummel.o: ./setup.h
solgummel.o: ./sol.h
solgummel.o: ./logunt.h
solgummel.o: ./emaco.h
solgummel.o: ./soltmpg.h
solgummel.o: ./p2conf.h
solgummel.o: ./blank.h
solgummel.o: ./sol.h
solgummel.o: ./emaco.h
solgummel.o: ./p2conf.h
solgummel.o: ./blank.h
solgummel.o: ./setup.h
solgummel.o: ./sol.h
solgummel.o: ./emaco.h
solgummel.o: ./p2conf.h
solgummel.o: ./sol.h
solgummel.o: ./logunt.h
sollud.o: sollud.f
sollud.o: ./p2conf.h
sollud.o: ./blank.h
sollud.o: ./p2conf.h
solnewton.o: solnewton.f
solnewton.o: ./p2conf.h
solnewton.o: ./blank.h
solnewton.o: ./logunt.h
solnewton.o: ./sol.h
solnewton.o: ./emaco.h
solnewton.o: ./soltmpn.h
solnewton.o: ./p2conf.h
solnewton.o: ./blank.h
solnewton.o: ./setup.h
solnewton.o: ./sol.h
solnewton.o: ./p2conf.h
solnewton.o: ./blank.h
solnewton.o: ./setup.h
solnewton.o: ./sol.h
solnewton.o: ./logunt.h
solnewton.o: ./emaco.h
solnewton.o: ./soltmpn.h
solnewton.o: ./p2conf.h
solnewton.o: ./setup.h
solnewton.o: ./p2conf.h
solnewton.o: ./sol.h
solnewton.o: ./setup.h
solnewton.o: ./p2conf.h
solnewton.o: ./blank.h
solnewton.o: ./sol.h
solnewton.o: ./setup.h
solnewton.o: ./logunt.h
solnewton.o: ./p2conf.h
solnewton.o: ./blank.h
solnewton.o: ./p2conf.h
solnewton.o: ./blank.h
solnewton.o: ./sol.h
solnewton.o: ./setup.h
solnewton.o: ./emaco.h
solnewton.o: ./soltmpn.h
solver.o: solver.f
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./sol.h
solver.o: ./stat.h
solver.o: ./trfldmob.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./setup.h
solver.o: ./logunt.h
solver.o: ./sol.h
solver.o: ./stat.h
solver.o: ./impact.h
solver.o: ./emaco.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./setup.h
solver.o: ./logunt.h
solver.o: ./sol.h
solver.o: ./stat.h
solver.o: ./emaco.h
solver.o: ./p2conf.h
solver.o: ./sol.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./setup.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./stat.h
solver.o: ./setup.h
solver.o: ./sol.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./setup.h
solver.o: ./sol.h
solver.o: ./logunt.h
solver.o: ./symme.h
solver.o: ./emaco.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./logunt.h
solver.o: ./setup.h
solver.o: ./sol.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./setup.h
solver.o: ./emaco.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./setup.h
solver.o: ./logunt.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./setup.h
solver.o: ./sol.h
solver.o: ./logunt.h
solver.o: ./emaco.h
solver.o: ./p2conf.h
solver.o: ./soltmpn.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./sol.h
solver.o: ./emaco.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./soltmpn.h
solver.o: ./p2conf.h
solver.o: ./blank.h
solver.o: ./sol.h
stats.o: stats.f
stats.o: ./p2conf.h
stats.o: ./blank.h
stats.o: ./p2conf.h
stats.o: ./blank.h
stats.o: ./p2conf.h
stats.o: ./blank.h
stats.o: ./p2conf.h
stats.o: ./p2conf.h
stats.o: ./p2conf.h
stats.o: ./p2conf.h
stats.o: ./p2conf.h
stats.o: ./blank.h
stats.o: ./p2conf.h
stats.o: ./blank.h
stats.o: ./p2conf.h
symbol.o: symbol.f
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./stat.h
symbol.o: ./symb.h
symbol.o: ./emaco.h
symbol.o: ./adjtmp.h
symbol.o: ./symtmp1.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./emaco.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./setup.h
symbol.o: ./symb.h
symbol.o: ./emaco.h
symbol.o: ./adjtmp.h
symbol.o: ./symtmp1.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./adjtmp.h
symbol.o: ./symtmp1.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./emaco.h
symbol.o: ./adjtmp.h
symbol.o: ./symtmp1.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./logunt.h
symbol.o: ./symb.h
symbol.o: ./emaco.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./symb.h
symbol.o: ./logunt.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./symb.h
symbol.o: ./emaco.h
symbol.o: ./adjtmp.h
symbol.o: ./symtmp1.h
symbol.o: ./p2conf.h
symbol.o: ./p2conf.h
symbol.o: ./p2conf.h
symbol.o: ./p2conf.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./p2conf.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./stat.h
symbol.o: ./symb.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./symb.h
symbol.o: ./emaco.h
symbol.o: ./symtmp3.h
symbol.o: ./p2conf.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./emaco.h
symbol.o: ./symtmp4.h
symbol.o: ./p2conf.h
symbol.o: ./blank.h
symbol.o: ./setup.h
symbol.o: ./emaco.h
symbol.o: ./p2conf.h
symbol.o: ./emaco.h
trefld.o: trefld.f
trefld.o: ./p2conf.h
trefld.o: ./blank.h
trefld.o: ./emaco.h
trefld.o: ./setup.h
trefld.o: ./trfldmob.h
trfldmob.o: trfldmob.f
trfldmob.o: ./p2conf.h
trfldmob.o: ./setup.h
trfldmob.o: ./trfldmob.h
trfldmob.o: ./emaco.h
usrmob1.o: usrmob1.f
usrmob1.o: ./usrmob1.h
usrmob1.o: ./usrmob1.h
volume.o: volume.f
volume.o: ./p2conf.h
volume.o: ./p2conf.h
mc.o: mc.f

