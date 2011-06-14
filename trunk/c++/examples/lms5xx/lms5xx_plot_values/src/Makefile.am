if HAVE_GNUPLOT

noinst_PROGRAMS=lms5xx_plot_values
lms5xx_plot_values_SOURCES=main.cc gnuplot_i.cc gnuplot_i.hpp
lms5xx_plot_values_LDADD=-lsicklms5xx $(PTHREAD_CFLAGS) $(PTHREAD_LIBS)
lms5xx_plot_values_LDFLAGS=-L$(top_srcdir)/c++/drivers/lms5xx/$(SICK_LMS_5XX_SRC_DIR)
AM_CPPFLAGS=-I$(top_srcdir)/c++/drivers/lms5xx -I$(top_srcdir)/c++/drivers/base/src $(PTHREAD_CFLAGS) $(PTHREAD_LIBS) $(all_includes)

endif