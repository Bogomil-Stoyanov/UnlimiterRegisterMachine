

#ifndef URM_ERROR_H
#define URM_ERROR_H

#include <utility>

#include "Operation.h"

class Error : public Operation {
public:

    explicit Error(std::string message = "") {
        this->message = std::move(message);
    }

    Type getType() override {
        return Type::ERROR;
    }

    Name getName() override {
        return ERROR_NAME;
    }

    void print() override {
        if(message.empty()){
            std::cout << "An error occurred" << std::endl;
        }else{
            std::cout << "An error occurred: " << message << std::endl;
        }
    }

private:
    std::string message;
};
#endif //URM_ERROR_H
