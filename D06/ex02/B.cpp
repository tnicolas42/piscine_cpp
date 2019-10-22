#include "B.hpp"
#include <iostream>

B::B() {
    std::cout << "B created" << std::endl;
}

B::B(B const &src) {
    *this = src;
}

B::~B() {
}

B &B::operator=(B const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}
