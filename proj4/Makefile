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

INCLUDE = -I $(INCLUDEDIR) -I ./googletest/googletest/include
CXXFLAGS = -std=c++14 $(INCLUDE)
TESTLDFLAGS = -L /opt/local/lib -L ./googletest/build/lib -lgtest_main -lgtest -lexpat
LDFLAGS = -lexpat -L /usr/local/lib -lcsv

STRING_UTILS_OBJ = $(OBJDIR)/StringUtils.o
CSV_READER_OBJ = $(OBJDIR)/CSVReader.o
CSV_WRITER_OBJ = $(OBJDIR)/CSVWriter.o
CSV_TEST_OBJ = $(OBJDIR)/CSVTest.o
XML_READER_OBJ = $(OBJDIR)/XMLReader.o
XML_WRITER_OBJ = $(OBJDIR)/XMLWriter.o
XML_TEST_OBJ = $(OBJDIR)/XMLTest.o
MAIN_OBJ = $(OBJDIR)/Main.o
STRING_UTILS_OBJ = $(OBJDIR)/StringUtils.o

CSV_TEST_NAME = CSVTest
XML_TEST_NAME = XMLTest
MAIN_NAME = Main

all: $(LIBDIR)/$(LIBCSV_NAME) directories runtest $(TESTBINDIR)/$(MAIN_NAME)

runtest: $(TESTBINDIR)/$(CSV_TEST_NAME) $(TESTBINDIR)/$(XML_TEST_NAME)
	$(TESTBINDIR)/$(CSV_TEST_NAME)
	$(TESTBINDIR)/$(XML_TEST_NAME)

directories:
	mkdir -p $(OBJDIR)
	mkdir -p $(TESTBINDIR)

$(CSV_READER_OBJ): $(SRCDIR)/CSVReader.cpp $(INCLUDEDIR)/CSVReader.h
	$(CXX) $(SRCDIR)/CSVReader.cpp -c $(CXXFLAGS) -o $(CSV_READER_OBJ)

$(CSV_WRITER_OBJ): $(SRCDIR)/CSVWriter.cpp $(INCLUDEDIR)/CSVWriter.h
	$(CXX) $(SRCDIR)/CSVWriter.cpp -c $(CXXFLAGS) -o $(CSV_WRITER_OBJ)

$(CSV_TEST_OBJ): $(SRCDIR)/CSVTest.cpp $(INCLUDEDIR)/CSVReader.h $(INCLUDEDIR)/CSVWriter.h
	$(CXX) $(SRCDIR)/CSVTest.cpp -c $(CXXFLAGS) -o $(CSV_TEST_OBJ)

$(TESTBINDIR)/$(CSV_TEST_NAME): $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(CSV_TEST_OBJ) $(LIBDIR)/$(LIBCSV_NAME) $(STRING_UTILS_OBJ)
	$(CXX) $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(CSV_TEST_OBJ) $(STRING_UTILS_OBJ) /usr/local/lib/$(LIBCSV_NAME) $(CXXFLAGS) $(TESTLDFLAGS) -o $(TESTBINDIR)/$(CSV_TEST_NAME)

$(XML_READER_OBJ): $(SRCDIR)/XMLReader.cpp $(INCLUDEDIR)/XMLReader.h
	$(CXX) $(SRCDIR)/XMLReader.cpp -c $(CXXFLAGS) -o $(XML_READER_OBJ)

$(XML_WRITER_OBJ): $(SRCDIR)/XMLWriter.cpp $(INCLUDEDIR)/XMLWriter.h
	$(CXX) $(SRCDIR)/XMLWriter.cpp -c $(CXXFLAGS) -o $(XML_WRITER_OBJ)

$(XML_TEST_OBJ): $(SRCDIR)/XMLTest.cpp $(INCLUDEDIR)/XMLReader.h $(INCLUDEDIR)/XMLWriter.h
	$(CXX) $(SRCDIR)/XMLTest.cpp -c $(CXXFLAGS) -o $(XML_TEST_OBJ)

$(TESTBINDIR)/$(XML_TEST_NAME): $(XML_READER_OBJ) $(XML_WRITER_OBJ) $(XML_TEST_OBJ)
	$(CXX) $(XML_READER_OBJ) $(XML_WRITER_OBJ) $(XML_TEST_OBJ) $(CXXFLAGS) $(TESTLDFLAGS) -o $(TESTBINDIR)/$(XML_TEST_NAME)

$(MAIN_OBJ): $(SRCDIR)/Main.cpp
	$(CXX) $(SRCDIR)/Main.cpp -c $(CXXFLAGS) -o $(MAIN_OBJ)

$(STRING_UTILS_OBJ): $(SRCDIR)/StringUtils.cpp $(INCLUDEDIR)/StringUtils.h
	$(CXX) $(SRCDIR)/StringUtils.cpp -c $(CXXFLAGS) -o $(STRING_UTILS_OBJ)

$(TESTBINDIR)/$(MAIN_NAME): $(MAIN_OBJ) $(XML_READER_OBJ) $(XML_WRITER_OBJ) $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(STRING_UTILS_OBJ) $(LIBDIR)/$(LIBCSV_NAME)
	$(CXX) $(MAIN_OBJ) $(XML_READER_OBJ) $(XML_WRITER_OBJ) $(CSV_READER_OBJ) $(CSV_WRITER_OBJ) $(STRING_UTILS_OBJ) $(CXXFLAGS) $(LDFLAGS) -o $(TESTBINDIR)/$(MAIN_NAME)

$(LIBCSVDIR)/Makefile:
	cd $(LIBCSVDIR); ./configure --prefix=$(CURDIR); cd ..

$(LIBCSVDIR)/libcsv.la: $(LIBCSVDIR)/Makefile
	cd $(LIBCSVDIR); make; cd ..

$(LIBDIR)/$(LIBCSV_NAME): $(LIBCSVDIR)/libcsv.la
	cd $(LIBCSVDIR); make install; cd ..

clean:
	rm -f $(LIBDIR)/*
	rm -f include/csv.h
	cd $(LIBCSVDIR); make clean; cd ..
	rm -f $(LIBCSVIDR)/Makefile
	rm -r $(OBJDIR)
	rm -r $(TESTBINDIR)
