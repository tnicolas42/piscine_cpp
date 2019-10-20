#include "Player.hpp"
#include "Weapon.hpp"

Player::Player() :
AEntity(nullptr, nullptr, "Player", 0, 0, PLAYER_W, PLAYER_H, PLAYER_SPEED_MS, PLAYER_TEXTURE, PLAYER_COLOR),
_fleet(nullptr) {
    std::cout << "DO NOT CALL DEFAULT CONSTRUCTOR FOR PLAYER" << std::endl;
}

Player::Player(Screen *sc, BulletContainer *bullets, EnemyFleet *fleet) :
AEntity(sc, bullets, "Player", 0, 0, PLAYER_W, PLAYER_H, PLAYER_SPEED_MS, PLAYER_TEXTURE, PLAYER_COLOR),
_fleet(fleet) {
    // set x and y pos at start
    _x = (_screen->getGameSizeX() - (PLAYER_W / 2)) / 2;
    _y = _screen->getGameSizeY() - PLAYER_H;
    // create the weapon
    _weapon = new Weapon(this, PLAYER_WP_X, PLAYER_WP_Y,
                         0, -1, PLAYER_WP_SPEED_BULLET_MS, PLAYER_WP_DELAY, true);
	this->getScreen()->setHP(PLAYER_HP);
}

Player::Player(Player const &src) :
AEntity(src) {
    *this = src;
}

Player::~Player() {
}

Player &Player::operator=(Player const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

bool Player::move(int x, int y) {
	bool	res;

    // check out of bound
    if (x < 0 && (int)_x < -x)
        return true;
    if (x > 0 && _x + x >= getScreen()->getGameSizeX())
        return true;
    if (y < 0 && (int)_y < -y)
        return true;
    if (y > 0 && _y + y >= getScreen()->getGameSizeY())
        return true;

	this->getScreen()->deleteElement(*this);
    res = baseMove(x, y);
	this->getScreen()->displayElement(*this);
	return (res);
}

bool Player::update() {
    // foreach enemy
    AScreenElement *enemy;
    for (int i=0; i < MAX_ELEMENT; i++) {
        enemy = _fleet->getElement(i);
        if (enemy != nullptr) {
            if (isColision(*enemy)) {
                // if colision with an enemy
				_fleet->delElement(i);
				return (this->getScreen()->decrementHP());  // enter in colision
            }
        }
    }
    // foreach bullets
    AScreenElement *bullet;
    int j = -1;
    while ((bullet = _bullets->getBullet(++j))) {
        if (isColision(*bullet)) {
            // if colision with a bullet
			_bullets->delBullet(j);
			return (this->getScreen()->decrementHP());  // enter in colision
        }
    }
	this->getScreen()->displayElement(*this);
    return true;
}
