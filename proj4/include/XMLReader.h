
#ifndef XMLREADER_H
#define XMLREADER_H

#include "XMLEntity.h"
#include <istream>
#include <expat.h>

class CXMLReader{
    private:
    std::istream &input;
    XML_Parser parser;

    public:
        CXMLReader(std::istream &is);
        ~CXMLReader();

        bool End();
        bool ReadEntity(SXMLEntity &entity, bool skipcdata = false);
};

#endif
