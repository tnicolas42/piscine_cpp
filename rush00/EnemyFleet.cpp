#include "EnemyFleet.hpp"
#include "EnemySmallMissile.hpp"
#include "EnemyBigMissile.hpp"
#include "EnemyHoriz.hpp"
#include <iostream>

EnemyFleet::EnemyFleet() :
AFleet(nullptr, FLEET_SPAWN_SPEED_MS, FLEET_INCREASE_SPAWN_SPEED_MS),
_bullets(nullptr) {
    std::cout << "DO NOT CALL DEFAULT CONSTRUCTOR FOR ENEMY_FLEET" << std::endl;
}

EnemyFleet::EnemyFleet(Screen *sc, BulletContainer *bullets) :
AFleet(sc, FLEET_SPAWN_SPEED_MS, FLEET_INCREASE_SPAWN_SPEED_MS, FLEET_SPAWN_SPEED_PERCENT),
_bullets(bullets) {
}

EnemyFleet::EnemyFleet(EnemyFleet const &src) :
AFleet(src) {
    *this = src;
}

EnemyFleet::~EnemyFleet() {
}

EnemyFleet &EnemyFleet::operator=(EnemyFleet const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

void EnemyFleet::update() {
    AFleet::update();  // call AFleet update()

    // foreach enemy
    AScreenElement *enemy;
    for (int i=0; i < MAX_ELEMENT; i++) {
        enemy = getElement(i);
        if (enemy != nullptr) {

            // foreach bullets
            AScreenElement *bullet;
            int j = -1;
            while ((bullet = _bullets->getBullet(++j))) {
                if (enemy->isColision(*bullet)) {
                    // if enemy is in colision with a bullet
                    _screen->incrementScore(WIN_POINT_DESTROY);
                    this->delElement(i);  // delete the enemy
                    _bullets->delBullet(j);
                    break ;
                }
            }
        }
    }
}

AScreenElement *EnemyFleet::newElement() const {
    Enemy *new_;
    int rand_percent = rand() % 100;
    if (rand_percent < 10) {
        new_ = new EnemyHoriz(getScreen(), _bullets);
    }
    else if (rand_percent < 30) {
        new_ = new EnemyBigMissile(getScreen(), _bullets);
    }
    else {
        new_ = new EnemySmallMissile(getScreen(), _bullets);
    }
    if (new_->hasWeapon()) {
        // disable weapon if there is another enemy in Y
        // foreach enemy
        AScreenElement *enemy;
        for (int i=0; i < MAX_ELEMENT; i++) {
            enemy = getElement(i);
            if (enemy != nullptr) {
                if (new_->getX() + new_->getWidth() >= enemy->getX()
                && enemy->getX() + enemy->getWidth() >= new_->getX()) {
                    new_->enableWeapon(false);  // disable weapon
                    break;
                }
            }
        }
    }
    if (new_->hasWeapon()) {
        new_->setColor(COLOR_ORANGE_PAIR);
    }
    return (AScreenElement*)new_;
}

BulletContainer *EnemyFleet::getBullets() const { return _bullets; }
