
#include "FileReader.h"
#include "../operations/Operation.h"
#include "../tokenizer/Tokenizer.h"


std::vector<Operation*> FileReader::read(const std::string &path) {

    std::ifstream file;
    file.open(path);

    std::vector<Operation*> operations;

    if (file.is_open()) {
        std::string line;
        std::string content;
        while (getline(file, line)) {
           operations.push_back(Tokenizer::tokenize(line));
        }
        file.close();
    } else {
        std::cout << "File not found." << std::endl;
    }

    return operations;
}
