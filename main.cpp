#include <iostream>
#include "urm/sparsedarray/SparsedArray.h"
#include "urm/Urm.h"

int main() {

  /*  SparsedArray sparsedArray;
    sparsedArray.set(0, 1);
    sparsedArray.set(1, 2);
    sparsedArray.set(2, 3);

    std::cout<< sparsedArray.get(0) << std::endl;
    std::cout<< sparsedArray.get(4) << std::endl;

    sparsedArray.print();*/

    Urm::getInstance()->start();

    return 0;
}
