

#ifndef URM_ZEROCMD_H
#define URM_ZEROCMD_H

#include "../Operation.h"

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

private:
    int x, y;
};

#endif //URM_ZEROCMD_H
