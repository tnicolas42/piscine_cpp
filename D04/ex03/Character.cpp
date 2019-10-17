#include "Character.hpp"
#include <iostream>

Character::Character() :
_name("defaultName") {
    for (int i=0; i < INVENTORY_SZ; i++) {
        _inventory[i] = nullptr;
    }
}

Character::Character(std::string const &name) :
_name(name) {
    for (int i=0; i < INVENTORY_SZ; i++) {
        _inventory[i] = nullptr;
    }
}

Character::Character(Character const &src) {
    *this = src;
}

Character::~Character() {
}

Character &Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        for (int i=0; i < INVENTORY_SZ; i++) {
            _inventory[i] = rhs.getInventory(i);
        }
    }
    return *this;
}

void Character::equip(AMateria *m) {
    for (int i=0; i < INVENTORY_SZ; i++) {
        if (_inventory[i] == nullptr) {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "inventory full" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= INVENTORY_SZ) {
        std::cout << "invalid index for unequip" << std::endl;
        return;
    }
    _inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= INVENTORY_SZ) {
        std::cout << "invalid index" << std::endl;
        return;
    }
    _inventory[idx]->use(target);
}

std::string const &Character::getName() const { return _name; }
AMateria *Character::getInventory(int i) const { return _inventory[i]; }