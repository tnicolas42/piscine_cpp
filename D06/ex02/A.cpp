#include "A.hpp"
#include <iostream>

A::A() {
    std::cout << "A created" << std::endl;
}

A::A(A const &src) {
    *this = src;
}

A::~A() {
}

A &A::operator=(A const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}
