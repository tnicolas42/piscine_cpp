#pragma once

#include <string>

class FragTrap {
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(FragTrap const &src);
        virtual ~FragTrap();

        FragTrap &operator=(FragTrap const &rhs);

        void rangedAttack(const std::string &target);
        void meleeAttack(const std::string &target);
        void takeDammage(uint32_t amount);
        void beRepaired(uint32_t amount);
        void vaulthunter_dot_exe(std::string const & target);

        const std::string &getName() const;
        int getHitPoint() const;
        int getMaxHitPoint() const;
        int getEnergyPoint() const;
        int getMaxEnergyPoint() const;
        int getLevel() const;
        int getMeleeAtkDammage() const;
        int getRangedAtkDammage() const;
        int getArmorAtkReduction() const;
    protected:
    private:
        std::string _name;
        int _hitPoint;
        int _maxHitPoint;
        int _energyPoint;
        int _maxEnergyPoint;
        int _level;
        int _meleeAtkDammage;
        int _rangedAtkDammage;
        int _armorAtkReduction;
};