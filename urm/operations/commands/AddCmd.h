

#ifndef URM_ADDCMD_H
#define URM_ADDCMD_H

#include "../Operation.h"
#include <string>
#include <utility>

// Add command - extends the existing program with the program from the given file
class AddCmd : public Operation {
public:
    explicit AddCmd(std::string filename) {
        this->filename = std::move(filename);
    }

    Type getType() override {
        return COMMAND;
    }

    Name getName() override {
        return ADD_CMD;
    }

    const std::string &getFilename() const {
        return filename;
    }

    void print() override {
        std::cout << "/add " << filename << std::endl;
    }

private:
    std::string filename;
};

#endif //URM_ADDCMD_H
