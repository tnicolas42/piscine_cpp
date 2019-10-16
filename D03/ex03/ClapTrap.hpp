#pragma once

#include <string>

#define RANGED_ATK_ENERGY 0
#define MELEE_ATK_ENERGY 0

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(const std::string &name, int hitPoint, int maxHitPoint,
            int energyPoint, int maxEnergyPoint, int level, int meleeAtkdamage,
            int rangedAtkdamage, int armorAtkReduction);
        ClapTrap(ClapTrap const &src);
        virtual ~ClapTrap();

        ClapTrap &operator=(ClapTrap const &rhs);

        bool atk(const std::string atkName, int damage, int energy, const std::string &target);
        void rangedAttack(const std::string &target);
        void meleeAttack(const std::string &target);
        void takedamage(uint32_t amount);
        void beRepaired(uint32_t amount);

        const std::string &getName() const;
        const std::string &getType() const;
        int getHitPoint() const;
        int getMaxHitPoint() const;
        int getEnergyPoint() const;
        int getMaxEnergyPoint() const;
        int getLevel() const;
        int getMeleeAtkdamage() const;
        int getRangedAtkdamage() const;
        int getArmorAtkReduction() const;
    protected:
        std::string _name;
        std::string _type;
        int _hitPoint;
        int _maxHitPoint;
        int _energyPoint;
        int _maxEnergyPoint;
        int _level;
        int _meleeAtkdamage;
        int _rangedAtkdamage;
        int _armorAtkReduction;
    private:
};