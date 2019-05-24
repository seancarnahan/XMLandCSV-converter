#ifndef CSVREADER_H
#define CSVREADER_H

#include <istream>
#include <string>
#include <vector>
#include <csv.h>

class CCSVReader{
    protected:
    struct csv_parser parser;
    std::istream &input;
    std::vector<std::string> rowBuffer;
        
    public:
        CCSVReader(std::istream &in);
        ~CCSVReader();
    
        void CallbackField(void *str, size_t len, void *data);
        void CallbackRow(int c, void *data);
        bool End() const;
        bool ReadRow(std::vector< std::string > &row);
};

#endif
