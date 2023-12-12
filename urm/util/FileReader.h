

#ifndef URM_FILEREADER_H
#define URM_FILEREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../operations/Operation.h"


class FileReader {

public:
    static std::vector<Operation*> read(const std::string& path);
};


#endif //URM_FILEREADER_H
