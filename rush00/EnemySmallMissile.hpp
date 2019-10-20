#pragma once

#include "Screen.class.hpp"
#include "BulletsContainer.hpp"
#include "Texture.hpp"
#include "Enemy.hpp"

class EnemySmallMissile : public Enemy {
    public:
        EnemySmallMissile(Screen *sc, BulletContainer *bullets);
        EnemySmallMissile(EnemySmallMissile const &src);
        virtual ~EnemySmallMissile();

        EnemySmallMissile &operator=(EnemySmallMissile const &rhs);
    protected:
    private:
        EnemySmallMissile();
};
