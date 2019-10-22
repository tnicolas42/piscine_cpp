#include "C.hpp"
#include <iostream>

C::C() {
    std::cout << "C created" << std::endl;
}

C::C(C const &src) {
    *this = src;
}

C::~C() {
}

C &C::operator=(C const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}
