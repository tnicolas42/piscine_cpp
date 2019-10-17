#include "Cure.hpp"
#include <iostream>

Cure::Cure() :
AMateria("cure") {
}

Cure::Cure(Cure const &src) :
AMateria(src) {
    *this = src;
}

Cure::~Cure() {
}

Cure &Cure::operator=(Cure const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

AMateria *Cure::clone() const {
    AMateria *cpy = new Cure();
    *cpy = *this;
    return cpy;
}

void Cure::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}