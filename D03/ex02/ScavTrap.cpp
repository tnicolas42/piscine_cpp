#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() :
ClapTrap("defaultName", 100, 100, 50, 50, 1, 20, 15, 3) {
    _type = "SCAVTRAP";
    std::cout << "[" << _type << "] new ScavTrap: " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) :
ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3) {
    _type = "SCAVTRAP";
    std::cout << "[" << _type << "] new ScavTrap: " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) :
ClapTrap(src) {
    _type = "SCAVTRAP";
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "[" << _type << "] " << _name << " die !" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void ScavTrap::challengeNewcomer() {
    static std::string challengeNames[] = {
        "You versus me! Me versus you! Either way!",
        "I will prove to you my robotic superiority!",
        "Dance battle! Or, you know... regular battle.",
        "Man versus machine! Very tiny streamlined machine!",
        "Care to have a friendly duel?"
    };
    int challengeId = std::rand() % (sizeof(challengeNames) / sizeof(challengeNames[0]));

    std::cout << "[" << _type << "][" << _name << "] challenge: " << challengeNames[challengeId] << std::endl;
}