#pragma once

#include <cstdint>
#include <iostream>

typedef uint32_t fix_int;

#define VERBOSE false
#define FRACTIONAL_BITS 8  // floating part is in # bits

class Fixed {
    public:
        Fixed();
        Fixed(const int nb);
        Fixed(const float nb);
        Fixed(Fixed const &src);
        ~Fixed();

        /* operators */
        Fixed &operator=(Fixed const &rhs);
        // comparison operators
        bool operator>(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        // arithmetic operators
        Fixed operator+(const Fixed &other);
        Fixed operator-(const Fixed &other);
        Fixed operator*(const Fixed &other);
        Fixed operator/(const Fixed &other);
        Fixed operator++();  // prefix operator (++i)
        Fixed operator++(int);  // postfix operator (i++)
        Fixed operator--();  // prefix operator (--i)
        Fixed operator--(int);  // postfix operator (i--)

        fix_int getRawBits() const;
        fix_int &getRawBits();
        void setRawBits(const fix_int raw);
        float toFloat() const;
        int toInt() const;

        static Fixed &min(Fixed &n1, Fixed &n2);
        static const Fixed &min(const Fixed &n1, const Fixed &n2);
        static Fixed &max(Fixed &n1, Fixed &n2);
        static const Fixed &max(const Fixed &n1, const Fixed &n2);
    protected:
    private:
        fix_int _fixPVal;  // first INTEGER_BITS = int part, then FRACTIONAL_BITS for the floating part
        static const uint32_t _nbFractBits;  // allways 8
};

std::ostream &operator<<(std::ostream &o, const Fixed &other);