#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixPVal(0) {
    #if VERBOSE
        std::cout << "Default constructor called" << std::endl;
    #endif
}

Fixed::Fixed(const int nb) : _fixPVal(0) {
    #if VERBOSE
        std::cout << "Integer constructor called" << std::endl;
    #endif
    _fixPVal = nb << _nbFractBits;
}

Fixed::Fixed(const float nb) : _fixPVal(0) {
    #if VERBOSE
        std::cout << "Float constructor called" << std::endl;
    #endif
    // nb * 2^_nbFractBits
    _fixPVal = roundf(nb * (2<<(_nbFractBits-1)));
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
        _fixPVal = rhs.getRawBits();
    return *this;
}

fix_int Fixed::getRawBits() const {
    return _fixPVal;
}

void Fixed::setRawBits(const fix_int raw) {
    _fixPVal = raw;
}

float Fixed::toFloat() const {
    return (float)_fixPVal / (1 << _nbFractBits);
}

int Fixed::toInt() const {
    return _fixPVal >> _nbFractBits;
}

std::ostream &operator<<(std::ostream &o, const Fixed &other) {
    o << other.toFloat();
    return o;
}

const uint32_t Fixed::_nbFractBits = FRACTIONAL_BITS;