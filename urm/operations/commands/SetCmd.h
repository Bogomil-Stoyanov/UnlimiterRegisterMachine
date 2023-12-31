

#ifndef URM_SETCMD_H
#define URM_SETCMD_H

#include "../Operation.h"

// Set command - sets the value to y of register x
class SetCmd : public Operation {
public:
    SetCmd(int x, int y){
        this->x = x;
        this->y = y;
    }

    Type getType() override {
        return COMMAND;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void print() override {
        std::cout << "/set " << x << " " << y << std::endl;
    }

    Name getName() override {
        return SET_CMD;
    }

    void changeRange(int newN){
        x += newN+1;
    }

private:
    int x, y;
};

#endif //URM_SETCMD_H
