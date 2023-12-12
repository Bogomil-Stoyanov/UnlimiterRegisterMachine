

#ifndef URM_SPARSEDARRAY_H
#define URM_SPARSEDARRAY_H

#include <unordered_map>

class SparsedArray {
    std::unordered_map<int, int> map;

    public:
    SparsedArray();
    ~SparsedArray();

    void set(int index, int value);
    int get(int index);
    void remove(int index);
    void removeAll();

    void print();
};

#endif //URM_SPARSEDARRAY_H
