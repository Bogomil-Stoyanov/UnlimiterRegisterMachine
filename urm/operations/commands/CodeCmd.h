

#ifndef URM_CODECMD_H
#define URM_CODECMD_H

#include "../Operation.h"

// Code command - prints the code of the program
class CodeCmd : public Operation {
public:
    CodeCmd() = default;

    Type getType() override {
        return COMMAND;
    }

    void print() override {

    }

    Name getName() override {
        return CODE_CMD;
    }
};

#endif //URM_CODECMD_H
