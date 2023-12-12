

#ifndef URM_INCINST_H
#define URM_INCINST_H


#include "../Operation.h"

class IncInst : public Operation{
public:
    explicit IncInst(int n) {
        this->n = n;
    }

    Type getType() override {
        return Type::INSTRUCTION;
    };

    int getN() const {
        return n;
    }

    void print() override {
        std::cout << "INC " << n << std::endl;
    }

    Name getName() override {
        return INC_INST;
    }

private:
    int n;
};

#endif //URM_INCINST_H
