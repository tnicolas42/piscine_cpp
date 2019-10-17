#pragma once

#include "Enemy.hpp"

class RadScorpion : public Enemy {
    public:
        RadScorpion();
        RadScorpion(RadScorpion const &src);
        virtual ~RadScorpion();

        RadScorpion &operator=(RadScorpion const &rhs);
    protected:
    private:
};