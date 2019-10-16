#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() :
_name("defaultName"),
_hitPoint(100),
_maxHitPoint(100),
_energyPoint(50),
_maxEnergyPoint(50),
_level(1),
_meleeAtkdamage(20),
_rangedAtkdamage(15),
_armorAtkReduction(3) {
    srand(time(NULL));
    std::cout << "SC4V-TP new ScavTrap: " << _name << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) :
_name(name),
_hitPoint(100),
_maxHitPoint(100),
_energyPoint(50),
_maxEnergyPoint(50),
_level(1),
_meleeAtkdamage(20),
_rangedAtkdamage(15),
_armorAtkReduction(3) {
    srand(time(NULL));
    std::cout << "SC4V-TP new ScavTrap: " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "SC4V-TP " << _name << " die !" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _hitPoint = rhs.getHitPoint();
        _maxHitPoint = rhs.getMaxHitPoint();
        _energyPoint = rhs.getEnergyPoint();
        _maxEnergyPoint = rhs.getMaxEnergyPoint();
        _level = rhs.getLevel();
        _meleeAtkdamage = rhs.getMeleeAtkdamage();
        _rangedAtkdamage = rhs.getRangedAtkdamage();
        _armorAtkReduction = rhs.getArmorAtkReduction();
    }
    return *this;
}

void ScavTrap::rangedAttack(const std::string &target) {
    if (_energyPoint < RANGED_ATK_ENERGY) {
        std::cout << "SC4V-TP not enouth energy (" << _energyPoint << "). needed " << RANGED_ATK_ENERGY << std::endl;
        return;
    }
    _energyPoint -= RANGED_ATK_ENERGY;
    std::cout << "SC4V-TP " << _name << " attacks " << target << " at range, causing " <<
        _rangedAtkdamage << " points of damage" << std::endl;
}
void ScavTrap::meleeAttack(const std::string &target) {
    if (_energyPoint < MELEE_ATK_ENERGY) {
        std::cout << "SC4V-TP not enouth energy (" << _energyPoint << "). needed " << MELEE_ATK_ENERGY << std::endl;
        return;
    }
    _energyPoint -= MELEE_ATK_ENERGY;
    std::cout << "SC4V-TP " << _name << " attacks " << target << " in meleeAtk, causing " <<
        _meleeAtkdamage << " points of damage" << std::endl;
}
void ScavTrap::takedamage(uint32_t amount) {
    if ((int)amount < _armorAtkReduction)
        return;
    amount -= _armorAtkReduction;
    if (_hitPoint - (int)amount < 0) {
        amount = _hitPoint;
    }
    _hitPoint -= amount;
    std::cout << "SC4V-TP " << _name << " take " << amount << " points of damage. Now at " <<
        _hitPoint << std::endl;
}
void ScavTrap::beRepaired(uint32_t amount) {
    if (_hitPoint + (int)amount > _maxHitPoint) {
        amount = _maxHitPoint - _hitPoint;
    }
    _hitPoint += amount;
    std::cout << "SC4V-TP " << _name << " heath of " << amount << " lifepoint. Now at " <<
        _hitPoint << std::endl;
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

    std::cout << "SC4V-TP " << _name << " challenge: " << challengeNames[challengeId] << std::endl;
}

const std::string &ScavTrap::getName() const { return _name; }
int ScavTrap::getHitPoint() const { return _hitPoint; }
int ScavTrap::getMaxHitPoint() const { return _maxHitPoint; }
int ScavTrap::getEnergyPoint() const { return _energyPoint; }
int ScavTrap::getMaxEnergyPoint() const { return _maxEnergyPoint; }
int ScavTrap::getLevel() const { return _level; }
int ScavTrap::getMeleeAtkdamage() const { return _meleeAtkdamage; }
int ScavTrap::getRangedAtkdamage() const { return _rangedAtkdamage; }
int ScavTrap::getArmorAtkReduction() const { return _armorAtkReduction; }