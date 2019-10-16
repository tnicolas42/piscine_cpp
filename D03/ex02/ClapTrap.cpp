#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
_name("defaultName"),
_type("CLAPTRAP"),
_hitPoint(100),
_maxHitPoint(100),
_energyPoint(100),
_maxEnergyPoint(100),
_level(1),
_meleeAtkdamage(30),
_rangedAtkdamage(20),
_armorAtkReduction(5) {
    srand(time(NULL));
    std::cout << "[CLAPTRAP][" << _type << "] new ClapTrap: " << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, int hitPoint, int maxHitPoint,
            int energyPoint, int maxEnergyPoint, int level, int meleeAtkdamage,
            int rangedAtkdamage, int armorAtkReduction) :
_name(name),
_type("CLAPTRAP"),
_hitPoint(hitPoint),
_maxHitPoint(maxHitPoint),
_energyPoint(energyPoint),
_maxEnergyPoint(maxEnergyPoint),
_level(level),
_meleeAtkdamage(meleeAtkdamage),
_rangedAtkdamage(rangedAtkdamage),
_armorAtkReduction(armorAtkReduction) {
    srand(time(NULL));
    std::cout << "[CLAPTRAP][" << _type << "] new ClapTrap: " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    _type = "CLAPTRAP";
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << "[CLAPTRAP][" << _type << "] " << _name << " die !" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
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

bool ClapTrap::atk(const std::string atkName, int damage, int energy, const std::string &target) {
    if (_energyPoint - energy < 0) {
        std::cout << "[CLAPTRAP][" << _type << "][" << _name << "][ERROR]: not enouth energy (" <<
            _energyPoint << "). needed " << energy << std::endl;
        return false;
    }
    _energyPoint -= energy;
    std::cout << "[CLAPTRAP][" << _type << "][" << _name << "] atk " << atkName << " on " <<
        target << " (" << damage << " damage)" << std::endl;
    return true;
}

void ClapTrap::rangedAttack(const std::string &target) {
    atk("rangedAttack", _rangedAtkdamage, RANGED_ATK_ENERGY, target);
}
void ClapTrap::meleeAttack(const std::string &target) {
    atk("meleeAttack", _meleeAtkdamage, MELEE_ATK_ENERGY, target);
}
void ClapTrap::takedamage(uint32_t amount) {
    if ((int)amount < _armorAtkReduction)
        return;
    amount -= _armorAtkReduction;
    if (_hitPoint - (int)amount < 0) {
        amount = _hitPoint;
    }
    _hitPoint -= amount;
    std::cout << "[CLAPTRAP][" << _type << "][" << _name << "] take " << amount << " points of damage. Now at " <<
        _hitPoint << "." << std::endl;
}
void ClapTrap::beRepaired(uint32_t amount) {
    if (_hitPoint + (int)amount > _maxHitPoint) {
        amount = _maxHitPoint - _hitPoint;
    }
    _hitPoint += amount;
    std::cout << "[CLAPTRAP][" << _type << "][" << _name << "] heath of " << amount << " lifepoint. Now at " <<
        _hitPoint << "." << std::endl;
}

const std::string &ClapTrap::getName() const { return _name; }
const std::string &ClapTrap::getType() const { return _type; }
int ClapTrap::getHitPoint() const { return _hitPoint; }
int ClapTrap::getMaxHitPoint() const { return _maxHitPoint; }
int ClapTrap::getEnergyPoint() const { return _energyPoint; }
int ClapTrap::getMaxEnergyPoint() const { return _maxEnergyPoint; }
int ClapTrap::getLevel() const { return _level; }
int ClapTrap::getMeleeAtkdamage() const { return _meleeAtkdamage; }
int ClapTrap::getRangedAtkdamage() const { return _rangedAtkdamage; }
int ClapTrap::getArmorAtkReduction() const { return _armorAtkReduction; }