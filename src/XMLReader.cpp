#include "XMLReader.h"

CXMLReader::CXMLReader(std::istream &in) : input(in)
{
    XML_ParserCreate(NULL);
}

CXMLReader::~CXMLReader()
{
    XML_ParserFree(&parser);
}


bool CXMLReader::End()
{
    return input.eof();
}

bool CXMLReader::ReadEntity(const SXMLEntity &entity)
{
    
}
