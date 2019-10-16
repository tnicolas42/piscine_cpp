#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap() :
ClapTrap("defaultName", 100, 100, 120, 120, 1, 60, 20, 5),
FragTrap("defaultName"),
NinjaTrap("defaultName") {
    _type = "SUPERTRAP";
    std::cout << "[" << _type << "] new SuperTrap: " << _name << std::endl;
}

SuperTrap::SuperTrap(const std::string &name) :
ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5),
FragTrap(name),
NinjaTrap(name) {
    _type = "SUPERTRAP";
    std::cout << "[" << _type << "] new SuperTrap: " << _name << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src) :
ClapTrap(src),
FragTrap(src),
NinjaTrap(src) {
    _type = "SUPERTRAP";
    *this = src;
}

SuperTrap::~SuperTrap() {
    std::cout << "[" << _type << "] " << _name << " die !" << std::endl;
}

SuperTrap &SuperTrap::operator=(SuperTrap const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}
const std::string &SuperTrap::getType() const { return _type; }