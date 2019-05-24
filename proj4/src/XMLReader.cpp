#include "XMLReader.h"

CXMLReader::CXMLReader(std::istream &in) : input(in)
{
    XML_ParserCreate(NULL);
}

CXMLReader::~CXMLReader()
{
    XML_ParserFree(&parser);
}

void CXMLReader::StartElementHandler(void *data, const XML_Char *name, const XML_Char **atts)
{

}

void CXMLReader::EndElementHandler(void *data, const XML_Char *name)
{

}

void CXMLReader::CharacterHandler(

bool CXMLReader::End()
{
    return input.eof();
}

bool CXMLReader::ReadEntity(const SXMLEntity &entity)
//from github.com/libexpat/libexpat/blob/master/expat/examples/outline.c "xml_parse"
{
    char *entityBuffer;
    int len = (int)fread(entityBuffer, 0, input.end.tellg(), input);
    XML_SetElementHandler(parser, start, end);

    XML_SetCharacterHandler(parser, charhndl);

    if(XML_Parse(parser, entityBuffer, len, (int)input.eof()) == XML_STATUS_ERROR){
        cerr << "Parse error @ line: " << XML_GetCurrentLineNumber(parser); << "\n" << XML_ErrorString(XML_GetErrorCode(parser));
        return false;
    }

    else return true;
}
