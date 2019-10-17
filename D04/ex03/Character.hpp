#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

#define INVENTORY_SZ 4

class Character : public ICharacter {
    public:
        Character(std::string const &name);
        Character(Character const &src);
        virtual ~Character();

        Character &operator=(Character const &rhs);
        std::string const &getName() const;
        AMateria *getInventory(int id) const;
        virtual void equip(AMateria *m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter &target);
    protected:
    private:
        Character();
        std::string _name;
        AMateria *_inventory[INVENTORY_SZ];
};