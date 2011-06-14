noinst_PROGRAMS=lms5xx_simple_app
lms5xx_simple_app_SOURCES=main.cc
lms5xx_simple_app_LDADD=-lsicklms5xx $(PTHREAD_CFLAGS) $(PTHREAD_LIBS)
lms5xx_simple_app_LDFLAGS=-L$(top_srcdir)/c++/drivers/lms5xx/$(SICK_LMS_5XX_SRC_DIR)
AM_CPPFLAGS=-I$(top_srcdir)/c++/drivers/lms5xx -I$(top_srcdir)/c++/drivers/base/src $(PTHREAD_CFLAGS) $(PTHREAD_LIBS) $(all_includes)
