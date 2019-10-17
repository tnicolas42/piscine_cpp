#pragma once

#include "AWeapon.hpp"
#include <string>

class PlasmaRifle : public AWeapon {
    public:
        PlasmaRifle();
        PlasmaRifle(PlasmaRifle const &src);
        virtual ~PlasmaRifle();

        PlasmaRifle &operator=(PlasmaRifle const &rhs);
        virtual void attack() const;
    protected:
    private:
};