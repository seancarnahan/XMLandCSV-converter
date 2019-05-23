#include "XMLReader.h"

CXMLReader::CXMLReader(std::ostream &ou) : output(ou)
{
    
}

CXMLReader::~CXMLReader()
{
    
}


bool CXMLReader::End()
{
    return ou.eof();
}

bool ReadEntity(const SXMLEntity &entity)
{
    
}
