CXX=g++

CURDIR =$(shell pwd)
BINDIR = ./bin
TESTBINDIR = ./testbin
LIBDIR = ./lib
OBJDIR = ./obj
INCLUDEDIR = ./include
SRCDIR = ./src
LIBCSVDIR = libcsv-3.0.3
LIBCSV_NAME = libcsv.a

INCLUDE = -I $(INCLUDEDIR)
CXXFLAGS = -std=c++14 $(INCLUDE)
TESTLDFLAGS = -L opt/local/lib -lgtest_main -lgtest

STRING_UTILS_OBJ = $(OBJDIR)/StringUtils.o
CSV_READER_OBJ = $(OBJDIR)/CSVReader.o
CSV_WRITER_OBJ = $(OBJDIR)/CSVWriter.o
CSV_TEST_OBJ = $(OBJDIR)/CSVTest.o
XML_READER_OBJ = $(OBJDIR)/XMLReader.o
XML_WRITER_OBJ = $(OBJDIR)/XMLWriter.o
XML_TEST_OBJ = $(OBJDIR)/XMLTest.o

CSV_TEST_NAME = CSVTest
XML_TEST_NAME = XMLTest

all: $(LIBDIR)/$(LIBCSV_NAME) directories runtest

runtest: $(TESTBINDIR)/$(CSV_TEST_NAME)
	$(TESTBINDIR)/$(CSV_TEST_NAME)

$(CSV_READER_OBJ): $(SRCDIR)/CSVReader.cpp $(INCLUDEDIR)/CSVReader.h
	$(CXX) $(SRCDIR)/CSVReader.cpp -c $(CXXFLAGS) -o $(CSV_READER_OBJ)

$(CSV_WRITER_OBJ): $(SRCDIR)/CSVWriter.cpp $(INCLUDEDIR)/CSVWriter.h
	$(CXX) $(SRCDIR)/CSVWriter.cpp -c $(CXXFLAGS) -o $(CSV_WRITER_OBJ)

$(CSV_TEST_OBJ): $(SRCDIR)/CSVTest.cpp $(INCLUDEDIR)/CSVReader.h $(INCLUDEDIR)/CSVWriter.h
	$(CXX) $(SRCDIR)/CSVTest.cpp -c $(CXXFLAGS) -o $(CSV_TEST_OBJ)

$(TESTBINDIR)/$(CSV_TEST_NAME): $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(CSV_TEST_OBJ) $(STRING_UTILS_OBJ) $(LIBDIR)/$(LIBCSV_NAME)
	$(CXX) $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(CSV_TEST_OBJ) $(LIBDIR)/$(LIBCSV_NAME) $(CXXFLAGS) $(TESTLDFLAGS) -o $(TESTBINDIR)/$(CSV_TEST_NAME)

$(LIBCSVDIR)/Makefile:
	cd $(LIBCSVDIR); ./configure --prefix=$(CURDIR); cd ..

$(LIBCSVDIR)/libcsv.la: $(LIBCSVDIR)/Makefile
	cd $(LIBCSVDIR); make; cd ..

$(LIBDIR)/$(LIBCSV_NAME): $(LIBCSVDIR)/libcsv.la
	cd $(LIBCSVDIR); make install; cd ..

directories: $(BINDIR) $(TESTBINDIR) $(OBJDIR)
clean:
	rm -f lib/*
	rm -f include/csv.h
	cd $(LIBCSVDIR); make clean; cd ..
	rm -f $(LIBCSVIDR)/Makefile
