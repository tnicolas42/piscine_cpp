#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(const std::string name) :
_name(name),
_weapon() {}

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void HumanB::attack() const {
    std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}