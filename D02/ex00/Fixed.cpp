#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixPVal(0) {
    #if VERBOSE
        std::cout << "Default constructor called" << std::endl;
    #endif
}

Fixed::Fixed(Fixed const &src) {
    #if VERBOSE
        std::cout << "Copy constructor called" << std::endl;
    #endif
    *this = src;
}

Fixed::~Fixed() {
    #if VERBOSE
        std::cout << "Destructor called" << std::endl;
    #endif
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    #if VERBOSE
        std::cout << "Asignation operator called" << std::endl;
    #endif
    if (this != &rhs)
        _fixPVal = getRawBits();
    return *this;
}

fix_int Fixed::getRawBits() const {
    #if VERBOSE
        std::cout << __func__ << "() menber function called" << std::endl;
    #endif
    return _fixPVal;
}

void Fixed::setRawBits(const fix_int raw) {
    #if VERBOSE
        std::cout << __func__ << "() menber function called" << std::endl;
    #endif
    _fixPVal = raw;
}

const uint32_t Fixed::_nbFractBits = 8;