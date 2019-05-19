CURDIR =  $(shell pwd)
LIBDIR = ./lib
INCLUDEDIR = ./include
LIBCSV_NAME = libcsv.a
LIBCSVDIR = libcsv-3.0.3

all: $(LIBDIR)/$(LIBCSV_NAME)

$(LIBCSVDIR)/Makefile: $(LIBCSVDIR)/configure
  cd $(LIBCSVDIR);  ./configure —-prefix=$(CURDIR); cd ..
$(LIBCSVDIR)/libcsv.la: $(LIBCSVDIR)/Makefile
	cd $(LIBCSVDIR); make; cd ..

$(LIBDIR)/$(LIBCSV_NAME): $(LIBCSVDIR)/libcsv.la
	cd $(LIBCSVDIR); make install; cd ..
$clean:
	rm -f $(LIBDIR)/*
	rm -f $(INCLUDEDIR)/csv.h
	cd $(LIBCSVDIR); make clean; cd ..
	rm -f $(LIBCSVIDR)/Makefile
