#include "Ice.hpp"
#include <iostream>

Ice::Ice() :
AMateria("ice") {
}

Ice::Ice(Ice const &src) :
AMateria(src) {
    *this = src;
}

Ice::~Ice() {
}

Ice &Ice::operator=(Ice const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

AMateria *Ice::clone() const {
    AMateria *cpy = new Ice();
    *cpy = *this;
    return cpy;
}

void Ice::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}