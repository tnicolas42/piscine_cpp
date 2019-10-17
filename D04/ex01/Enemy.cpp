#include "Enemy.hpp"

Enemy::Enemy() :
_type("defaultType"),
_hp(1)  {
}

Enemy::Enemy(int hp, std::string const &type) :
_type(type),
_hp(hp) {
}

Enemy::Enemy(Enemy const &src) {
    *this = src;
}

Enemy::~Enemy() {
}

Enemy &Enemy::operator=(Enemy const &rhs) {
    if (this != &rhs) {
        _type = rhs.getType();
        _hp = rhs.getHP();
    }
    return *this;
}

void Enemy::takeDamage(int damage) {
    if (_hp - damage < 0) {
        damage = _hp;
    }
    _hp -= damage;
}

const std::string &Enemy::getType() const { return _type; }
int Enemy::getHP() const { return _hp; }