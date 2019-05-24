#include "CSVReader.h"

CCSVReader::CCSVReader(std::istream &in) //input(in)
{
  //csv_init(&Parser, 0);
}

CCSVReader::~CCSVReader()
{
  //csv_free(&Parser);
}

// void CCSVReader::CallbackField(void *str, size_t len, void *data)
// {
//   //CCSVReader *Ptr = static_cast<CCSVReader>(data);
//   //Ptr -> RowBuffer.push_back(std::string((char *)str, len));
// }

// void CCSVReader::CallbackRow(int c, void *data)
// {
//   //CCSVReader *Ptr = static_cast<CCSVReader>(data);
// }

bool CCSVReader::End() const
{
  //return in.eof();
  return true;
}

bool CCSVReader::ReadRow(std::vector<std::string> &row)
{
    // std::stringstream inCopy = in;
    // inCopy.seekg(0, inCopy.end);
    // int nBytes = inCopy.tellg();
    // csv_parse(Parser, row, nBytes, CallbackField(), CallbackRow()/*c*/, in, in);
    // csv_fini(Parser, CallbackField(), CallbackRow(/*c*/, in), in);
  return true;
}
