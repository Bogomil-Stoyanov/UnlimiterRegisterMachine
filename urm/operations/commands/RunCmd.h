

#ifndef URM_RUNCMD_H
#define URM_RUNCMD_H

#include "../Operation.h"

// Run command - runs the program
class RunCmd : public Operation {
public:
    RunCmd() = default;

    Type getType() override {
        return COMMAND;
    }

    void print() override {

    }

    Name getName() override {
        return RUN_CMD;
    }
};

#endif //URM_RUNCMD_H
