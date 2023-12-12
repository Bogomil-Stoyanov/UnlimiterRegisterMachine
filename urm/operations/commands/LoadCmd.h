

#ifndef URM_LOADCMD_H
#define URM_LOADCMD_H

#include "../Operation.h"
#include <string>
#include <utility>

class LoadCmd : public Operation {
public:
    explicit LoadCmd(std::string filename) {
        this->filename = std::move(filename);
    }

    Type getType() override {
        return COMMAND;
    }

    const std::string &getFilename() const {
        return filename;
    }

    void print() override {
        std::cout << "/load " << filename << std::endl;
    }

    Name getName() override {
        return LOAD_CMD;
    }

private:
    std::string filename;
};

#endif //URM_LOADCMD_H
