#include "bitvector.h"

int main() {
    BitVector obj(4,5);
    // obj.set(1, 666);
    // obj.set(0, 767);
    // obj.set(8, 1);
    // BitVector obj2(std::move(obj));
    BitVector obj2;
    obj = obj2;
    std::cout << obj<<std::endl;
    std::cout << obj2<<std::endl;

 
}