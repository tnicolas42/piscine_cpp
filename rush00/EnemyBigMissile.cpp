#include "EnemyBigMissile.hpp"
#include "Defines.hpp"
#include <stdlib.h>

EnemyBigMissile::EnemyBigMissile() :
Enemy() {
    std::cout << "DO NOT CALL DEFAULT CONSTRUCTOR FOR ENEMY_BM" << std::endl;
}

EnemyBigMissile::EnemyBigMissile(Screen *sc, BulletContainer *bullets) :
    Enemy(sc,
        bullets,
        "Enemy",
        ENEMY_BM_W,
        ENEMY_BM_H,
        ENEMY_BM_WP_X,
        ENEMY_BM_WP_Y,
        ENEMY_BM_WP_SPEED_BULLET_MS,
        ENEMY_BM_WP_DELAY,
        ENEMY_BM_SPEED_MS,
        ENEMY_BM_TEXTURE,
        ENEMY_BM_COLOR,
        ENEMY_BM_MOVE_VERTICAL,
		false
    ) {
}

EnemyBigMissile::EnemyBigMissile(EnemyBigMissile const &src) :
Enemy(src) {
    *this = src;
}

EnemyBigMissile::~EnemyBigMissile() {
}

EnemyBigMissile &EnemyBigMissile::operator=(EnemyBigMissile const &rhs) {
    if (this != &rhs) {
    }
    return *this;
}
