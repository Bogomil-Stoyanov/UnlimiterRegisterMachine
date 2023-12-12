
#ifndef URM_OPERATION_H
#define URM_OPERATION_H

#include <iostream>

enum Type{
    INSTRUCTION,
    COMMAND,
    ERROR
};

enum Name{
    ADD_CMD,
    CODE_CMD,
    COMMENT_CMD,
    COPY_CMD,
    LOAD_CMD,
    MEM_CMD,
    QUOTE_CMD,
    RUN_CMD,
    SET_CMD,
    ZERO_CMD,

    INC_INST,
    JUMP_INST,
    MOVE_INST,
    ZERO_INST,

    ERROR_NAME
};

class Operation {

public:
    Operation() = default;
    virtual ~Operation() = default;

    virtual Type getType() = 0;
    virtual Name getName() = 0;

    virtual void print() = 0;

};


#endif //URM_OPERATION_H
