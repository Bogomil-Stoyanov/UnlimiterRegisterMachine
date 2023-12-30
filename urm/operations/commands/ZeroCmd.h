

#ifndef URM_ZEROCMD_H
#define URM_ZEROCMD_H

#include "../Operation.h"

// Zero command - sets the value to 0 of registers from x to y
class ZeroCmd : public Operation {
public:
    ZeroCmd(int x, int y) {
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
        std::cout << "/zero " << x << " " << y << std::endl;
    }

    Name getName() override {
        return ZERO_CMD;
    }

    void changeRange(int newX, int newY){
        x += newX;
        y += newY;
    }

private:
    int x, y;
};

#endif //URM_ZEROCMD_H
