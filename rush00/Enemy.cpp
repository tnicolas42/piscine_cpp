#include "Enemy.hpp"
#include <stdlib.h>

Enemy::Enemy() :
AEntity() {
    std::cout << "DO NOT CALL DEFAULT CONSTRUCTOR FOR ENEMY" << std::endl;
}

Enemy::Enemy(Screen *sc,
            BulletContainer *bullets,
            std::string type,
            int w,
            int h,
            int wp_x,
            int wp_y,
            uint64_t wp_speed_bullet,
            int wp_delay,
            uint64_t speed,
            std::string texture,
            uint8_t color,
            bool moveVertical,
			bool canBeWeaponized) :
    AEntity(sc,
        bullets,
        type,
        0, 0,
        w, h,
        speed,
        texture,
        color),
    _hasWeapon((rand() % 2 == 1) ? canBeWeaponized : false),
    _weaponDelay(wp_delay),
    _moveVertical(moveVertical) {
    // set x pos at start
    size_t pos = 0;
    for (int i=0; i < 100; i++) {  // max 100 try
        // if colision X with last -> retry another radom generation
        if (moveVertical) {
            pos = rand() % (_screen->getGameSizeX() - getWidth());
            if (pos + getWidth() + 1 >= Enemy::_lastSpawnPosX
            && Enemy::_lastSpawnPosX + getWidth() + 1 >= pos)
                continue;
            else
                break;
        }
        else {
            pos = rand() % (_screen->getGameSizeY() - getHeight());
            if (pos + getHeight() + 1 >= Enemy::_lastSpawnPosY
            && Enemy::_lastSpawnPosY + getHeight() + 1 >= pos)
                continue;
            else
                break;
        }
    }
    if (moveVertical) {
        _x = pos;
        Enemy::_lastSpawnPosX = _x;
    }
    else {
        _y = pos;
        Enemy::_lastSpawnPosY = _y;
    }
    // set speed
    _speed = (rand() % (int)((ENEMY_RANDOM_SPEED_PERCENT / 100.0f) * speed));
    _speed *= (rand() % 2 == 0) ? -1 : 1;
    _speed += speed;
    // create the weapon
    int wp_velX = 0;
    int wp_velY = 0;
    if (_moveVertical)
        wp_velY = 1;
    else
        wp_velX = 2;
    _weapon = new Weapon(this, wp_x, wp_y, wp_velX, wp_velY, wp_speed_bullet, wp_delay, this->_moveVertical);
}

Enemy::Enemy(Enemy const &src) :
AEntity(src) {
    *this = src;
}

Enemy::~Enemy() {
	this->getScreen()->deleteElement(*this);
}

Enemy &Enemy::operator=(Enemy const &rhs) {
    if (this != &rhs) {
        _hasWeapon = rhs.hasWeapon();
        _weaponDelay = rhs.getWeaponDelay();
    }
    return *this;
}

bool Enemy::move(int x, int y) {
    return baseMove(x, y);
}

bool Enemy::update() {
    if (_hasWeapon)
        if (_weapon->canShot()) {
            _weapon->shot();
            uint64_t newDelay = (rand() % (int)((ENEMY_WP_DELAY_RANDOM_PERCENT / 100.0f) * _weaponDelay));
            newDelay *= (rand() % 2 == 0) ? -1 : 1;
            newDelay += _weaponDelay;
            _weapon->setDelayMs(newDelay);
        }
    if (_moveVertical)
        return move(0, 1);
    return move(1, 0);
}

void Enemy::enableWeapon(bool enable) { _hasWeapon = enable; }
bool Enemy::hasWeapon() const { return _hasWeapon; }
uint64_t Enemy::getWeaponDelay() const { return _weaponDelay; }
bool	Enemy::isVertical() const { return this->_moveVertical; };

size_t Enemy::_lastSpawnPosX = 300;
size_t Enemy::_lastSpawnPosY = 300;
