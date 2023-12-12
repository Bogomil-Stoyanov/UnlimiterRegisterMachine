

#ifndef URM_TOKENIZER_H
#define URM_TOKENIZER_H


#include <string>
#include "../operations/Operation.h"

class Tokenizer {

public:
    static Operation* tokenize(const std::string& line);
};


#endif //URM_TOKENIZER_H
