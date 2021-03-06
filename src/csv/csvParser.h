#ifndef ENGINEPROTOTYPE_CSVPARSER
#define ENGINEPROTOTYPE_CSVPARSER

#include <string>
#include <vector>
#include <map>
#include <any>

#include "../dataParser.h"

class CsvParser : public DataParser {
    public:
        explicit CsvParser(const std::string& fileName);
        // explicit CsvParser(const std::string& fileName, const char& delimeter);
        ~CsvParser();

        void print();

    private:
        char delimeter = ',';
        bool hasHeader = true;

        std::vector<std::string> lines;

        std::vector<std::string> readFile(const std::string& fileName);
        std::vector<int> getDelimeterIndex(const std::string line);

        DataType parseData();
};

#endif