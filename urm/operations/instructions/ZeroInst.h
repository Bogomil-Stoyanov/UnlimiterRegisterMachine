

#ifndef URM_ZEROINST_H
#define URM_ZEROINST_H


#include "../Operation.h"

// Zero Instruction - sets the value of register n to 0
class ZeroInst : public Operation{
public:
    explicit ZeroInst(int n){
        this->n = n;
    };

    Type getType() override {
        return Type::INSTRUCTION;
    };

    int getN() const {
        return n;
    }

    void print() override {
        std::cout << "ZERO " << n << std::endl;
    }

    Name getName() override {
        return ZERO_INST;
    }

    void changeRange(int newN){
        n += newN+1;
    }

private:
    int n;
};


#endif //URM_ZEROINST_H
