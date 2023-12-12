

#ifndef URM_COPYCMD_H
#define URM_COPYCMD_H

#include "../Operation.h"

class CopyCmd : public Operation {
public:
    CopyCmd(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
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

    int getZ() const {
        return z;
    }

    void print() override {
        std::cout << "/copy " << x << " "<< y << " "<< z << std::endl;
    }

    Name getName() override {
        return COPY_CMD;
    }

private:
    int x, y, z;
};


#endif //URM_COPYCMD_H
