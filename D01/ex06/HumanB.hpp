#pragma once

#include "Weapon.hpp"
#include <string>

class HumanB {
    public:
        HumanB(const std::string name);
        ~HumanB();

        void setWeapon(Weapon &Weapon);
        void attack() const;
    protected:
    private:
        std::string _name;
        Weapon *_weapon;
};