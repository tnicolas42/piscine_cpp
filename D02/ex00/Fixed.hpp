#pragma once

#include <cstdint>

#define VERBOSE true

typedef int32_t fix_int;

class Fixed {
    public:
        Fixed();
        Fixed(Fixed const &src);
        ~Fixed();

        Fixed &operator=(Fixed const &rhs);
        fix_int getRawBits() const;
        void setRawBits(const fix_int raw);
    protected:
    private:
        fix_int _fixPVal;
        static const uint32_t _nbFractBits;  // allways 8
};