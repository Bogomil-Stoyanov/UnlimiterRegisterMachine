

#ifndef URM_SETCMD_H
#define URM_SETCMD_H

#include "../Operation.h"

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

private:
    int x, y;
};

#endif //URM_SETCMD_H
