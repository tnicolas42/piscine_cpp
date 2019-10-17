#include "Character.hpp"
#include <iostream>

Character::Character() :
_name("defaultName"),
_ap(MAX_AP),
_weapon(nullptr) {
}

Character::Character(std::string const &name) :
_name(name),
_ap(MAX_AP),
_weapon(nullptr) {
}

Character::Character(Character const &src) {
    *this = src;
}

Character::~Character() {
}

Character &Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _ap = rhs.getAP();
        _weapon = rhs.getWeapon();
    }
    return *this;
}

void Character::recoverAP() {
    if (_ap + RECOVER_AP > MAX_AP)
        _ap = MAX_AP;
    else
        _ap += RECOVER_AP;
}
void Character::equip(AWeapon *weapon) {
    _weapon = weapon;
}
void Character::attack(Enemy *enemy) {
    if (_weapon == nullptr || enemy == nullptr) {
        return;
    }
    // AP
    if (_ap - _weapon->getAPCost() < 0) {
        std::cout << "Not enouth AP to attack" << std::endl;
        return;
    }
    if (enemy->getHP() <= 0) {
        std::cout << enemy->getType() << " already dead" << std::endl;
        return;
    }
    _ap -= _weapon->getAPCost();

    std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
    _weapon->attack();

    // enemy damage
    enemy->takeDamage(_weapon->getDamage());
    if (enemy->getHP() <= 0) {
        // delete enemy;  // -> to delete enemny without abort, we need a **enemy
    }

}

const std::string &Character::getName() const { return _name; }
int Character::getAP() const { return _ap; }
AWeapon *Character::getWeapon() const { return _weapon; }

std::ostream &operator<<(std::ostream &o, Character const &other) {
    if (other.getWeapon() == nullptr) {
        o << other.getName() << " has " << other.getAP() << " AP and is unarmed" << std::endl;
    }
    else {
        o << other.getName() << " has " << other.getAP() << " AP and wields a " << other.getWeapon()->getName() << std::endl;
    }
    return o;
}