#include "EnemyHoriz.hpp"
#include "Defines.hpp"
#include <stdlib.h>

EnemyHoriz::EnemyHoriz() :
Enemy() {
    std::cout << "DO NOT CALL DEFAULT CONSTRUCTOR FOR ENEMYHoriz" << std::endl;
}

EnemyHoriz::EnemyHoriz(Screen *sc, BulletContainer *bullets) :
    Enemy(sc,
        bullets,
        "Enemy",
        ENEMY_HORIZ_W,
        ENEMY_HORIZ_H,
        ENEMY_HORIZ_WP_X,
        ENEMY_HORIZ_WP_Y,
        ENEMY_HORIZ_WP_SPEED_BULLET_MS,
        ENEMY_HORIZ_WP_DELAY,
        ENEMY_HORIZ_SPEED_MS,
        ENEMY_HORIZ_TEXTURE,
        ENEMY_HORIZ_COLOR,
        ENEMY_HORIZ_MOVE_VERTICAL
    )
{}

EnemyHoriz::EnemyHoriz(EnemyHoriz const &src) :
Enemy(src) {
    *this = src;
}

EnemyHoriz::~EnemyHoriz() {
}

EnemyHoriz &EnemyHoriz::operator=(EnemyHoriz const &rhs) {
    if (this != &rhs) {
    }
    return *this;
}
