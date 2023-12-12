

#ifndef URM_ZEROINST_H
#define URM_ZEROINST_H


#include "../Operation.h"

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

private:
    int n;
};


#endif //URM_ZEROINST_H
