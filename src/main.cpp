#include <iostream>

#include "yaml/yamlParser.h"

int main() {
    YamlParser parser("src/yaml/test.yaml");
    parser.print();

    YamlParser::writeToFile(parser.result, "testFile.yaml");

    return 0;
}