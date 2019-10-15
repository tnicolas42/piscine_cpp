#pragma once

#include <cstdint>
#include <iostream>

typedef uint32_t fix_int;

#define VERBOSE true
#define FRACTIONAL_BITS 8  // floating part is in # bits

class Fixed {
    public:
        Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(Fixed const &src);
        ~Fixed();

        Fixed &operator=(Fixed const &rhs);
        fix_int getRawBits() const;
        void setRawBits(const fix_int raw);
        float toFloat() const;
        int toInt() const;
    protected:
    private:
        fix_int _fixPVal;  // first INTEGER_BITS = int part, then FRACTIONAL_BITS for the floating part
        static const uint32_t _nbFractBits;  // allways 8
};

std::ostream &operator<<(std::ostream &o, const Fixed &other);