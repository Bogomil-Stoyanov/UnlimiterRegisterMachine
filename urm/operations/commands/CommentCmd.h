

#ifndef URM_COMMENTCMD_H
#define URM_COMMENTCMD_H

#include "../Operation.h"
#include <string>
#include <utility>

// Comment command - adds a comment to the program
class CommentCmd : public Operation {
public:
    explicit CommentCmd(std::string comment) {
        this->comment = std::move(comment);
    }

    Type getType() override {
        return COMMAND;
    }

    const std::string &getComment() const {
        return comment;
    }

    void print() override {
        std::cout << "/comment " << comment << std::endl;
    }

    Name getName() override {
        return COMMENT_CMD;
    }

private:
    std::string comment;
};

#endif //URM_COMMENTCMD_H
