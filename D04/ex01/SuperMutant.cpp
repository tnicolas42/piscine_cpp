#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant() :
Enemy(170, "Super Mutant") {
    std::cout << "aaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) :
Enemy(src) {
    *this = src;
}

SuperMutant::~SuperMutant() {
    std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void SuperMutant::takeDamage(int damage) {
    if (damage > 3)
        damage -= 3;
    else
        return;
    if (_hp - damage < 0) {
        damage = _hp;
    }
    _hp -= damage;
}