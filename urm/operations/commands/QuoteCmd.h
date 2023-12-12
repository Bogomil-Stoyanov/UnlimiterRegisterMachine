

#ifndef URM_QUOTECMD_H
#define URM_QUOTECMD_H

#include "../Operation.h"
#include <string>
#include <utility>

class QuoteCmd : public Operation {
public:
    explicit QuoteCmd(Operation* operation) {
        this->operation = operation;
    }

    Type getType() override {
        return COMMAND;
    }

    Operation* getOperation() const {
        return operation;
    }

    ~QuoteCmd() override {
        delete operation;
    }

    void print() override {
        std::cout << "/quote ";
        operation->print();
    }

    Name getName() override {
        return QUOTE_CMD;
    }


private:
    Operation* operation;
};

#endif //URM_QUOTECMD_H
