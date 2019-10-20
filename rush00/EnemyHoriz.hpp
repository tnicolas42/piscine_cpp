#pragma once

#include "Screen.class.hpp"
#include "BulletsContainer.hpp"
#include "Texture.hpp"
#include "Enemy.hpp"

class EnemyHoriz : public Enemy {
    public:
        EnemyHoriz(Screen *sc, BulletContainer *bullets);
        EnemyHoriz(EnemyHoriz const &src);
        virtual ~EnemyHoriz();

        EnemyHoriz &operator=(EnemyHoriz const &rhs);
    protected:
    private:
        EnemyHoriz();
};
