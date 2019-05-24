#include "CSVReader.h"
#include "StringUtils.h"

CCSVWriter::CCSVWriter(std::ostream &ou) : output(ou)
{

}

CCSVWriter::~CCSVWriter()
{

}

bool CCSVWriter::WriteRow(const std::vector<std::string> &row)
{
    std::vector<std::string> outputRow;
    for(auto x: row){
        outputRow.push_back(std::string("\"") + StringUtils::Replace(x, "\"", "\"\"") + "\"");
    }
    output << StringUtils::Join(",", outputRow) << std::endl;
    return true;
}
