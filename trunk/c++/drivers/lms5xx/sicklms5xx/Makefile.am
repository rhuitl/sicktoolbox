lib_include_hh= SickLMS5xx.hh \
                SickLMS5xxMessage.hh \
                SickLMS5xxBufferMonitor.hh \
	        $(top_srcdir)/c++/drivers/base/src/SickLIDAR.hh \
	        $(top_srcdir)/c++/drivers/base/src/SickMessage.hh \
	        $(top_srcdir)/c++/drivers/base/src/SickBufferMonitor.hh \
	        $(top_srcdir)/c++/drivers/base/src/SickException.hh

hh_sources= $(lib_include_hh) \
	    $(top_srcdir)/c++/drivers/base/src/SickConfig.hh \
            SickLMS5xxUtility.hh 

cc_sources= SickLMS5xx.cc \
            SickLMS5xxMessage.cc \
            SickLMS5xxBufferMonitor.cc

library_includedir=$(includedir)/sicklms5xx/
library_include_HEADERS=$(lib_include_hh)

lib_LTLIBRARIES=libsicklms5xx.la
libsicklms5xx_la_SOURCES=$(hh_sources) $(cc_sources)
libsicklms5xx_la_LIBADD=-lpthread
AM_CPPFLAGS=-I$(top_srcdir)/c++/drivers/base/src