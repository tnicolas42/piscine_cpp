#include "EnemySmallMissile.hpp"
#include "Defines.hpp"
#include <stdlib.h>

EnemySmallMissile::EnemySmallMissile() :
Enemy() {
    std::cout << "DO NOT CALL DEFAULT CONSTRUCTOR FOR ENEMY_SM" << std::endl;
}

EnemySmallMissile::EnemySmallMissile(Screen *sc, BulletContainer *bullets) :
    Enemy(sc,
        bullets,
        "Enemy",
        ENEMY_SM_W,
        ENEMY_SM_H,
        ENEMY_SM_WP_X,
        ENEMY_SM_WP_Y,
        ENEMY_SM_WP_SPEED_BULLET_MS,
        ENEMY_SM_WP_DELAY,
        ENEMY_SM_SPEED_MS,
        ENEMY_SM_TEXTURE,
        ENEMY_SM_COLOR,
        ENEMY_SM_MOVE_VERTICAL
    ) {
}

EnemySmallMissile::EnemySmallMissile(EnemySmallMissile const &src) :
Enemy(src) {
    *this = src;
}

EnemySmallMissile::~EnemySmallMissile() {
}

EnemySmallMissile &EnemySmallMissile::operator=(EnemySmallMissile const &rhs) {
    if (this != &rhs) {
    }
    return *this;
}
