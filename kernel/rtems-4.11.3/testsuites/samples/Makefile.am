ACLOCAL_AMFLAGS = -I ../aclocal

_SUBDIRS = hello fileio
## capture ticker base_sp unlimited minimum fileio

if MPTESTS
## base_mp is a sample multiprocessing test
## _SUBDIRS += base_mp
endif

## _SUBDIRS += paranoia

## _SUBDIRS += nsecs

if CXXTESTS
## _SUBDIRS += iostream cdtest
endif

if NETTESTS
## loopback tests a network loopback interface
## _SUBDIRS += loopback
if HAS_SMP
else
## _SUBDIRS += pppd
endif
endif

include $(top_srcdir)/../automake/test-subdirs.am
include $(top_srcdir)/../automake/local.am
