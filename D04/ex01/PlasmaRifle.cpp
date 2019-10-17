#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle() :
AWeapon("Plasma Rifle", 5, 21) {
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) :
AWeapon(src) {
    *this = src;
}

PlasmaRifle::~PlasmaRifle() {
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void PlasmaRifle::attack() const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}