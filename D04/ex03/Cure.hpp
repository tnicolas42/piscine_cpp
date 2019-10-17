#pragma once

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria {
    public:
        Cure();
        Cure(Cure const &src);
        virtual ~Cure();

        Cure &operator=(Cure const &rhs);

        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
    protected:
    private:
};