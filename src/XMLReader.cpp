#include "XMLReader.h"

CXMLReader::CXMLReader(std::ostream &ou) : output(ou)
{
    
}

CXMLReader::~CXMLReader()
{
    XML_ParserFree(&Parser);
}


bool CXMLReader::End()
{
    return ou.eof();
}

bool ReadEntity(const SXMLEntity &entity)
{
    
}
