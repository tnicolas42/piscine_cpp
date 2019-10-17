#pragma once

#include "ICharacter.hpp"
#include <string>

class AMateria {
    public:
        AMateria(std::string const &type);
        AMateria(AMateria const &src);
        virtual ~AMateria();

        AMateria &operator=(AMateria const &rhs);
        std::string const &getType() const;  // return materia type
        unsigned int getXP() const;  // return materia XP

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
    protected:
    private:
        AMateria();
        std::string _type;
        unsigned int _xp;
};