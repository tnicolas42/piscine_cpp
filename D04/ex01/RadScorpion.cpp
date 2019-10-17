#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion() :
Enemy(80, "RadScorpion") {
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src) :
Enemy(src) {
    *this = src;
}

RadScorpion::~RadScorpion() {
    std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion &RadScorpion::operator=(RadScorpion const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}