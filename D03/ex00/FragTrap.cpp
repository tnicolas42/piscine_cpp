#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() :
_name("defaultName"),
_hitPoint(100),
_maxHitPoint(100),
_energyPoint(100),
_maxEnergyPoint(100),
_level(1),
_meleeAtkDammage(20),
_rangedAtkDammage(20),
_armorAtkReduction(5) {
    std::cout << "new FragTrap: " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) :
_name(name),
_hitPoint(100),
_maxHitPoint(100),
_energyPoint(100),
_maxEnergyPoint(100),
_level(1),
_meleeAtkDammage(20),
_rangedAtkDammage(20),
_armorAtkReduction(5) {
    std::cout << "new FragTrap: " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) {
    *this = src;
}

FragTrap::~FragTrap() {
    std::cout << _name << " die !" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _hitPoint = rhs.getHitPoint();
        _maxHitPoint = rhs.getMaxHitPoint();
        _energyPoint = rhs.getEnergyPoint();
        _maxEnergyPoint = rhs.getMaxEnergyPoint();
        _level = rhs.getLevel();
        _meleeAtkDammage = rhs.getMeleeAtkDammage();
        _rangedAtkDammage = rhs.getRangedAtkDammage();
        _armorAtkReduction = rhs.getArmorAtkReduction();
    }
    return *this;
}

void FragTrap::rangedAttack(const std::string &target) {
    std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " <<
        _rangedAtkDammage << " points of damage !" << std::endl;
}
void FragTrap::meleeAttack(const std::string &target) {
    std::cout << "FR4G-TP " << _name << " attacks " << target << " in meleeAtk, causing " <<
        _meleeAtkDammage << " points of damage !" << std::endl;
}
void FragTrap::takeDammage(uint32_t amount) {
    amount -= _armorAtkReduction;
    std::cout << "FR4G-TP " << _name << " take " << amount << " points of damage !" << std::endl;
    _hitPoint -= amount;
    if (_hitPoint < 0) {
        _hitPoint = 0;
    }
}
void FragTrap::beRepaired(uint32_t amount) {
    std::cout << "FR4G-TP " << _name << " heath of " << amount << " lifepoint !" << std::endl;
    _hitPoint += amount;
    if (_hitPoint > _maxHitPoint) {
        _hitPoint = _maxHitPoint;
    }
}
void FragTrap::vaulthunter_dot_exe(std::string const & target) {
    static std::string[] atksName = {
        "attack1",
        "attack2",
        "attack3",
        "attack4",
        "attack5"
    }
    static int[] atksDammage = {15, 20, 25, 30, 35};
    if (_energyPoint < 25)
        return;
    _energyPoint -= 25;

    int atkId = std::rand() % (sizeof(atksName) / sizeof(atksName[0]));
}

const std::string &FragTrap::getName() const { return _name; }
int FragTrap::getHitPoint() const { return _hitPoint; }
int FragTrap::getMaxHitPoint() const { return _maxHitPoint; }
int FragTrap::getEnergyPoint() const { return _energyPoint; }
int FragTrap::getMaxEnergyPoint() const { return _maxEnergyPoint; }
int FragTrap::getLevel() const { return _level; }
int FragTrap::getMeleeAtkDammage() const { return _meleeAtkDammage; }
int FragTrap::getRangedAtkDammage() const { return _rangedAtkDammage; }
int FragTrap::getArmorAtkReduction() const { return _armorAtkReduction; }