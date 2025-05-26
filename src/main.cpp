#include "TextQueryLib.h"
#include <iostream>
#include <fstream>

void TextQueryFromFileTest(std::ifstream &file) {
    std::cout << __func__ << std::endl;

    TextQuery text_query(file);
    
    while (true) {
        std::cout << "Enter word to query or q to quit: ";
        std::string word;
        if (!(std::cin >> word) || word == "q") break;
        print(std::cout, text_query.query(word)) << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (file.is_open()) {
            TextQueryFromFileTest(file);
        } else {
            std::cout << "Fail to open " << argv[1] << std::endl;
        }
    }

    return 0;
}