#include "AWeapon.hpp"

AWeapon::AWeapon() :
_name("defaultName"),
_apcost(1),
_damage(1)  {
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) :
_name(name),
_apcost(apcost),
_damage(damage) {
}

AWeapon::AWeapon(AWeapon const &src) {
    *this = src;
}

AWeapon::~AWeapon() {
}

AWeapon &AWeapon::operator=(AWeapon const &rhs) {
    if (this != &rhs) {
        _name = getName();
        _apcost = getAPCost();
        _damage = getDamage();
    }
    return *this;
}


const std::string &AWeapon::getName() const { return _name; }
int AWeapon::getAPCost() const { return _apcost; }
int AWeapon::getDamage() const { return _damage; }