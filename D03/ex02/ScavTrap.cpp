#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() :
ClapTrap("defaultName", 100, 100, 50, 50, 1, 20, 15, 3) {
    _type = "SCAVTRAP";
    std::cout << "[" << _type << "] new FragTrap: " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) :
ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3) {
    _type = "SCAVTRAP";
    std::cout << "[" << _type << "] new FragTrap: " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "[" << _type << "] " << _name << " die !" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

void ScavTrap::challengeNewcomer() {
    static std::string challengeNames[] = {
        "challenge01",
        "challenge02",
        "challenge03",
        "challenge04",
        "challenge05"
    };
    int challengeId = std::rand() % (sizeof(challengeNames) / sizeof(challengeNames[0]));

    std::cout << "[" << _type << "][" << _name << "] challenge: " << challengeNames[challengeId] << std::endl;
}