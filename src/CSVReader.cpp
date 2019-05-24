#include "CSVReader.h"

CCSVReader::CCSVReader(std::istream &in) : input(in)
{
    csv_init(&parser, 0);
}

CCSVReader::~CCSVReader()
{
    csv_free(&parser);
}

void CCSVReader::CallbackField(void *str, size_t len, void *data)
{
    CCSVReader *Ptr = static_cast<CCSVReader*>(data);
    Ptr -> rowBuffer.push_back(std::string((char *)str, len));
}

void CCSVReader::CallbackRow(int c, void *data)
{
    CCSVReader *Ptr = static_cast<CCSVReader*>(data);
}

bool CCSVReader::End() const
{
    return input.eof();
}


bool CCSVReader::ReadRow(std::vector<std::string> &row)
{
    int c = 0;
    std::vector<std::string> buffer;
    csv_parse(parser, input, row.size(), CallbackField(input, row.size(), input), CallbackRow(c, parser), Ptr);
    csv_fini(parser, CallbackField(rowBuffer, row.size(), input), CallbackRow(c, parser), data);
}
