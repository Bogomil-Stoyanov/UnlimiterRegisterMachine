

#ifndef URM_INCINST_H
#define URM_INCINST_H


#include "../Operation.h"

// Increment Instruction - increments the current value of register n
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

    void changeRange(int newN){
        n += newN+1;
    }

private:
    int n;
};

#endif //URM_INCINST_H
