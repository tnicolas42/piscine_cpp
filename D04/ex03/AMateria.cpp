#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() :
_type("defaultType"),
_xp(0) {
}

AMateria::AMateria(std::string const &type) :
_type(type),
_xp(0) {
}

AMateria::AMateria(AMateria const &src) {
    *this = src;
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(AMateria const &rhs) {
    if (this != &rhs) {
        _type = rhs.getType();
        _xp = rhs.getXP();
    }
    return *this;
}

void AMateria::use(ICharacter &target) {
    (void)target;
    _xp += 10;
}

std::string const &AMateria::getType() const { return _type; }
unsigned int AMateria::getXP() const { return _xp; }