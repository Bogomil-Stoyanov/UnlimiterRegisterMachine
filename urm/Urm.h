
#ifndef URM_URM_H
#define URM_URM_H

#include <iostream>
#include "sparsedarray/SparsedArray.h"
#include "operations/Operation.h"
#include "operations/commands/ZeroCmd.h"
#include <vector>
#include <map>


class Urm {
    //singleton class
    Urm() = default;
    ~Urm();

    public:
    static Urm* getInstance();
    void start();
    void clear();

private:
    SparsedArray memory;
    std::vector<Operation*> operations;
    std::map<int, int> instructions;  // maps the instruction number to the index of the operation in the vector

    int rangeTo = 0;

    void readOperation(Operation* operation);

    void zero(int n);
    void inc(int n);
    void move( int x, int y);

    void zeroCmd(int x, int y);
    void setCmd(int x, int y);
    void copyCmd(int x, int y, int z);
    void memCmd(int x, int y);
    void codeCmd();

    void run();

    void loadCmd(const std::string& path);
    void addCmd(const std::string& path);

    void applyInstruction(Operation* operation, int& line);

    void addSubprogram(std::vector<Operation*>& subprogram);

};

#endif //URM_URM_H