#pragma once

#include "Screen.class.hpp"
#include "BulletsContainer.hpp"
#include "Texture.hpp"
#include "Enemy.hpp"

class EnemyBigMissile : public Enemy {
    public:
        EnemyBigMissile(Screen *sc, BulletContainer *bullets);
        EnemyBigMissile(EnemyBigMissile const &src);
        virtual ~EnemyBigMissile();

        EnemyBigMissile &operator=(EnemyBigMissile const &rhs);
    protected:
    private:
        EnemyBigMissile();
};
