

#ifndef URM_MOVEINST_H
#define URM_MOVEINST_H


#include "../Operation.h"

// Move Instruction - sets the value of register y to the value of register x
class MoveInst : public Operation{
public:
    explicit MoveInst(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Type getType() override {
        return Type::INSTRUCTION;
    };


    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void print() override {
        std::cout << "MOVE " << x <<" " << y << std::endl;
    }

    Name getName() override {
        return MOVE_INST;
    }

    void changeRange(int newRange){
        x += newRange+1;
        y += newRange+1;
    }

private:
    int x, y;
};


#endif //URM_MOVEINST_H
