#pragma once

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <string>
#include <iostream>

#define MAX_AP 40
#define RECOVER_AP 10

class Character {
    public:
        Character(std::string const &name);
        Character(Character const &src);
        virtual ~Character();

        Character &operator=(Character const &rhs);
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(Enemy *enemy);
        const std::string &getName() const;
        int getAP() const;
        AWeapon *getWeapon() const;
    protected:
    private:
        Character();
        std::string _name;
        int _ap;
        AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &o, Character const &other);