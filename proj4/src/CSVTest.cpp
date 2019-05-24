#include "CSVReader.h"
#include "CSVWriter.h"
#include <sstream>
#include <gtest/gtest.h>

TEST(CSVReader, BasicTest)
{
    std::stringstream input = " 1,2 ,  3         ,4,5\x0d\x0a";
    CCSVReader reader(input);
    std::vector<std::string> row;

    EXPECT_TRUE(reader.ReadRow(row));
    EXPECT_EQ(row.size(), 5);
    if(row.size() >= 5){
        EXPECT_EQ(row[0], "1");
        EXPECT_EQ(row[1], "2");
        EXPECT_EQ(row[2], "3");
        EXPECT_EQ(row[3], "4");
        EXPECT_EQ(row[4], "5");
    }
    EXPECT_FALSE(reader.ReadRow(row));
}

TEST(CSVWriter, BasicTest)
{
    std::stringstream output;
    CCSVWriter writer(output);
    std::vector<std::string> row{"1","2","3","4","5"};

    EXPECT_TRUE(writer.WriteRow(row));
    EXPECT_EQ(output.str(), "\"1\",\"2\",\"3\",\"4\",\"5\"\n");
}

//Aly = CSV ALL,XML reader
//Sean= main file, XML writer, XML TEsts
