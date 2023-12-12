

#ifndef URM_JUMPINST_H
#define URM_JUMPINST_H


#include "../Operation.h"

class JumpInst : public Operation{
public:
    explicit JumpInst(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    };

    Type getType() override {
        return Type::INSTRUCTION;
    };

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getZ() const {
        return z;
    }

    void print() override {
        std::cout << "JUMP ";
        if(x == y){
            std::cout<< z << std::endl;
        }else {
            std::cout << x << " " << y << " " << z << std::endl;
        }
    }

    Name getName() override {
        return JUMP_INST;
    }


private:
    int x, y, z;
};


#endif //URM_JUMPINST_H
