#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap() :
ClapTrap("defaultName", 60, 60, 120, 120, 1, 60, 5, 0) {
    _type = "NINJATRAP";
    std::cout << "[" << _type << "] new NinjaTrap: " << _name << std::endl;
}

NinjaTrap::NinjaTrap(const std::string &name) :
ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3) {
    _type = "NINJATRAP";
    std::cout << "[" << _type << "] new NinjaTrap: " << _name << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) :
ClapTrap(src) {
    _type = "NINJATRAP";
    *this = src;
}

NinjaTrap::~NinjaTrap() {
    std::cout << "[" << _type << "] " << _name << " die !" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap) {
    if (atk("ClapAttack", NINJASHOEBOX_DAMAGE, NINJASHOEBOX_ENERGY, trap.getName())) {
        trap.takedamage(NINJASHOEBOX_ENERGY);
    }
}
void NinjaTrap::ninjaShoebox(FragTrap &trap) {
    if (atk("FragAttack", NINJASHOEBOX_DAMAGE, NINJASHOEBOX_ENERGY, trap.getName())) {
        trap.takedamage(NINJASHOEBOX_ENERGY);
    }
}
void NinjaTrap::ninjaShoebox(ScavTrap &trap) {
    if (atk("ScavAttack", NINJASHOEBOX_DAMAGE, NINJASHOEBOX_ENERGY, trap.getName())) {
        trap.takedamage(NINJASHOEBOX_ENERGY);
    }
}
void NinjaTrap::ninjaShoebox(NinjaTrap &trap) {
    if (atk("NinjaAttack", NINJASHOEBOX_DAMAGE, NINJASHOEBOX_ENERGY, trap.getName())) {
        trap.takedamage(NINJASHOEBOX_ENERGY);
    }
}
void NinjaTrap::ninjaShoebox(SuperTrap &trap) {
    if (atk("NinjaAttack", NINJASHOEBOX_DAMAGE, NINJASHOEBOX_ENERGY, trap.getName())) {
        trap.takedamage(NINJASHOEBOX_ENERGY);
    }
}
const std::string &NinjaTrap::getType() const { return _type; }