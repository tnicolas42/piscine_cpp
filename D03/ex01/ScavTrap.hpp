#pragma once

#include <string>

#define RANGED_ATK_ENERGY 0
#define MELEE_ATK_ENERGY 0

class ScavTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(ScavTrap const &src);
        virtual ~ScavTrap();

        ScavTrap &operator=(ScavTrap const &rhs);

        void rangedAttack(const std::string &target);
        void meleeAttack(const std::string &target);
        void takedamage(uint32_t amount);
        void beRepaired(uint32_t amount);
        void challengeNewcomer();

        const std::string &getName() const;
        int getHitPoint() const;
        int getMaxHitPoint() const;
        int getEnergyPoint() const;
        int getMaxEnergyPoint() const;
        int getLevel() const;
        int getMeleeAtkdamage() const;
        int getRangedAtkdamage() const;
        int getArmorAtkReduction() const;
    protected:
    private:
        std::string _name;
        int _hitPoint;
        int _maxHitPoint;
        int _energyPoint;
        int _maxEnergyPoint;
        int _level;
        int _meleeAtkdamage;
        int _rangedAtkdamage;
        int _armorAtkReduction;
};