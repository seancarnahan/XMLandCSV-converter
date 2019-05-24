#include "XMLReader.h"

CXMLReader::CXMLReader(std::istream &in)// : output(ou)
{
    
}

CXMLReader::~CXMLReader()
{
    
}


bool CXMLReader::End()
{
  //return ou.eof();
  return true;
}
bool CXMLReader::ReadEntity(SXMLEntity &entity, bool skipcdata)
{
  return true;
}


