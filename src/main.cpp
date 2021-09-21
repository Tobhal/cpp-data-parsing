#include <iostream>

#include "yaml/yamlParser.h"

int main() {
    std::cout << "hello" << std::endl;

    YamlParser parser("src/yaml/test.yaml");

    std::cout << "world" << std::endl;

    return 0;
}