#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist() :
AWeapon("Power Fist", 8, 50) {
}

PowerFist::PowerFist(PowerFist const &src) :
AWeapon(src) {
    *this = src;
}

PowerFist::~PowerFist() {
}

PowerFist &PowerFist::operator=(PowerFist const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void PowerFist::attack() const {
    std::cout << "* pschhh... SBAM! *" << std::endl;
}