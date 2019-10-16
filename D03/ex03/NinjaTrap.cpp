#include "NinjaTrap.hpp"
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

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
    *this = src;
}

NinjaTrap::~NinjaTrap() {
    std::cout << "[" << _type << "] " << _name << " die !" << std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap) {
    int damage = 30;
    atk("ClapAttack", damage, 20, trap.getName());
    trap.takedamage(damage);
}
void NinjaTrap::ninjaShoebox(FragTrap &trap) {
    int damage = 30;
    atk("FragAttack", damage, 20, trap.getName());
    trap.takedamage(damage);
}
void NinjaTrap::ninjaShoebox(ScavTrap &trap) {
    int damage = 30;
    atk("ScavAttack", damage, 20, trap.getName());
    trap.takedamage(damage);
}
void NinjaTrap::ninjaShoebox(NinjaTrap &trap) {
    int damage = 30;
    atk("NinjaAttack", damage, 20, trap.getName());
    trap.takedamage(damage);
}