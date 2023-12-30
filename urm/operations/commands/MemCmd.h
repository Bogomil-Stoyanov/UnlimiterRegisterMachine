

#ifndef URM_MEMCMD_H
#define URM_MEMCMD_H

#include "../Operation.h"

// Memory command - prints the values of the registers from x to y
class MemCmd : public Operation {
public:
    MemCmd(int x, int y){
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
        std::cout << "/mem " << x << " "<< y << std::endl;
    }

    Name getName() override {
        return MEM_CMD;
    }

    void changeRange(int newN){
        x += newN+1;
        y += newN+1;
    }

private:
    int x, y;
};


#endif //URM_MEMCMD_H
