#ifndef ENGINEPROTOTYPE_YAMLPARSER
#define ENGINEPROTOTYPE_YAMLPARSER

#include <string>
#include <vector>
#include <fstream>
#include <any>
#include <map>

#include <utility>
#include <array>

#include "../dataParser.h"

class YamlParser : public DataParser {
    public:
        explicit YamlParser(const std::string& fileName);
        ~YamlParser();

        static void writeToFile(DataType dataType, std::string fileName);

    private:
        const char mapChar = ':';       // With a space afther (": ")
        const char listSplitChar = ','; // With a space afther (", ")
        const char arrayChar = '-';     // With a space before (" -")
        const char commentChar = '#';   // With a space before (" #")

        const char multiLineIncludeChar = '|';
        const char multiLineFoldChar = '>';

        const std::string fileStart = "---";
        const std::string fileEnd = "...";

        std::vector<std::string> lines;

        DataType parsePropsFormLines(std::vector<std::string> lines);

        std::vector<std::string> readFile(const std::string& fileName);

        std::any parseValue(const std::string& value);
        std::map<std::string, std::any> parseInlineObject(std::string object);
        std::vector<std::any> parseInlineVector(std::string vector);
        static std::string parseMultilineString(std::vector<std::string> lines, bool includeNewLine);

        static std::string parseString(std::string value);

        static std::vector<std::string> getTabedString(std::vector<std::string> lines, int tabLevel, int startLine);

        static char getFirstChar(const std::string& line);
        static bool containsChar(const std::string& line, char containChar);
        
        // write to file
        static std::string buildPrint(const std::any& object, int tab);
        static std::string buildObjectPrint(std::map<std::string, std::any> object, int tab);
        static std::string buildVectorPrint(std::vector<std::any> vector, int tab);
        static std::string buildDataTypePrint(DataType DataType, int tab);
};

#endif