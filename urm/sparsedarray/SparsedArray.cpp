#include "SparsedArray.h"
#include <iostream>

SparsedArray::SparsedArray() = default;

SparsedArray::~SparsedArray() = default;

void SparsedArray::set(int index, int value) {
    map[index] = value;
}

int SparsedArray::get(int index) {
    return map[index];
}

void SparsedArray::remove(int index) {
    map.erase(index);
}

void SparsedArray::print() {
    for (auto & it : map) {
        std::cout << it.first << " => " << it.second << '\n';
    }
}

void SparsedArray::removeAll() {
    map.clear();
}

