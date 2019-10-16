#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() :
ClapTrap("defaultName", 100, 100, 100, 100, 1, 30, 20, 5) {
    _type = "FRAGTRAP";
    std::cout << "[" << _type << "] new FragTrap: " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) :
ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5) {
    _type = "FRAGTRAP";
    std::cout << "[" << _type << "] new FragTrap: " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) :
ClapTrap(src) {
    _type = "FRAGTRAP";
    *this = src;
}

FragTrap::~FragTrap() {
    std::cout << "[" << _type << "] " << _name << " die !" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}
void FragTrap::vaulthunter_dot_exe(std::string const & target) {
    static std::string atksName[] = {
        "Laser Inferno",
        "Gun Wizard",
        "Clap-in-the-Box",
        "Pirate Ship Mode",
        "Torgue Fiesta"
    };
    static int atksdamage[] = {15, 20, 25, 30, 35};
    static int atksEnergy[] = {25, 25, 25, 25, 25};
    int atkId = std::rand() % (sizeof(atksName) / sizeof(atksName[0]));

    atk(atksName[atkId], atksdamage[atkId], atksEnergy[atkId], target);
}
const std::string &FragTrap::getType() const { return _type; }