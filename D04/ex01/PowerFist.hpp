#pragma once

#include "AWeapon.hpp"
#include <string>

class PowerFist : public AWeapon {
    public:
        PowerFist();
        PowerFist(PowerFist const &src);
        virtual ~PowerFist();

        PowerFist &operator=(PowerFist const &rhs);
        virtual void attack() const;
    protected:
    private:
};