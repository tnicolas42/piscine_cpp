#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() :
_name("defaultName"),
_hitPoint(100),
_maxHitPoint(100),
_energyPoint(100),
_maxEnergyPoint(100),
_level(1),
_meleeAtkdamage(20),
_rangedAtkdamage(20),
_armorAtkReduction(5) {
    std::cout << "FR4G-TP new FragTrap: " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) :
_name(name),
_hitPoint(100),
_maxHitPoint(100),
_energyPoint(100),
_maxEnergyPoint(100),
_level(1),
_meleeAtkdamage(20),
_rangedAtkdamage(20),
_armorAtkReduction(5) {
    std::cout << "FR4G-TP new FragTrap: " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) {
    *this = src;
}

FragTrap::~FragTrap() {
    std::cout << "FR4G-TP " << _name << " die !" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
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

void FragTrap::rangedAttack(const std::string &target) {
    if (_energyPoint < RANGED_ATK_ENERGY) {
        std::cout << "FR4G-TP not enouth energy (" << _energyPoint << "). needed " << RANGED_ATK_ENERGY << std::endl;
        return;
    }
    _energyPoint -= RANGED_ATK_ENERGY;
    std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " <<
        _rangedAtkdamage << " points of damage" << std::endl;
}
void FragTrap::meleeAttack(const std::string &target) {
    if (_energyPoint < MELEE_ATK_ENERGY) {
        std::cout << "FR4G-TP not enouth energy (" << _energyPoint << "). needed " << MELEE_ATK_ENERGY << std::endl;
        return;
    }
    _energyPoint -= MELEE_ATK_ENERGY;
    std::cout << "FR4G-TP " << _name << " attacks " << target << " in meleeAtk, causing " <<
        _meleeAtkdamage << " points of damage" << std::endl;
}
void FragTrap::takedamage(uint32_t amount) {
    if ((int)amount < _armorAtkReduction)
        return;
    amount -= _armorAtkReduction;
    if (_hitPoint - (int)amount < 0) {
        amount = _hitPoint;
    }
    _hitPoint -= amount;
    std::cout << "FR4G-TP " << _name << " take " << amount << " points of damage. Now at " <<
        _hitPoint << std::endl;
}
void FragTrap::beRepaired(uint32_t amount) {
    if (_hitPoint + (int)amount > _maxHitPoint) {
        amount = _maxHitPoint - _hitPoint;
    }
    _hitPoint += amount;
    std::cout << "FR4G-TP " << _name << " heath of " << amount << " lifepoint. Now at " <<
        _hitPoint << std::endl;
}
void FragTrap::vaulthunter_dot_exe(std::string const & target) {
    static std::string atksName[] = {
        "attack1",
        "attack2",
        "attack3",
        "attack4",
        "attack5"
    };
    static int atksdamage[] = {15, 20, 25, 30, 35};
    static int atksEnergy[] = {25, 25, 25, 25, 25};
    int atkId = std::rand() % (sizeof(atksName) / sizeof(atksName[0]));

    if (_energyPoint < atksEnergy[atkId]) {
        std::cout << "FR4G-TP not enouth energy (" << _energyPoint << "). needed " << atksEnergy[atkId] << std::endl;
        return;
    }
    _energyPoint -= atksEnergy[atkId];

    std::cout << "FR4G-TP " << _name << " attack " << atksName[atkId] << " on " <<
        target << " causing " << atksdamage[atkId] << " points of damage" << std::endl;
}

const std::string &FragTrap::getName() const { return _name; }
int FragTrap::getHitPoint() const { return _hitPoint; }
int FragTrap::getMaxHitPoint() const { return _maxHitPoint; }
int FragTrap::getEnergyPoint() const { return _energyPoint; }
int FragTrap::getMaxEnergyPoint() const { return _maxEnergyPoint; }
int FragTrap::getLevel() const { return _level; }
int FragTrap::getMeleeAtkdamage() const { return _meleeAtkdamage; }
int FragTrap::getRangedAtkdamage() const { return _rangedAtkdamage; }
int FragTrap::getArmorAtkReduction() const { return _armorAtkReduction; }