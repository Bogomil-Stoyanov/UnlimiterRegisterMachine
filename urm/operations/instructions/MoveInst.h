

#ifndef URM_MOVEINST_H
#define URM_MOVEINST_H


#include "../Operation.h"

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
        std::cout << "MOVE " << x << y << std::endl;
    }

    Name getName() override {
        return MOVE_INST;
    }

private:
    int x, y;
};


#endif //URM_MOVEINST_H
