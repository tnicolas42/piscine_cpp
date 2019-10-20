#include "AEntity.hpp"
#include <chrono>

AEntity::AEntity() :
    _bullets(nullptr) {}

AEntity::AEntity(Screen *sc,
	BulletContainer *bullets,
	std::string type,
	int x,
	int y,
	int width,
	int height,
	uint64_t speed,
	std::string texture,
	uint8_t color) :
	AScreenRenderedElement(sc, x, y, width, height, texture, color),
    _bullets(bullets),
	_type(type),
	_speed(speed),
    _timeLastMove(0) {}

AEntity::AEntity(AEntity const &src) :
	AScreenRenderedElement(src.getScreen())
{
    *this = src;
}

AEntity::~AEntity() {
    delete _weapon;
}

AEntity &AEntity::operator=(AEntity const &rhs) {
    if (this != &rhs) {
        _bullets = rhs.getBullets();
        _weapon = rhs.getWeapon();
        this->setX(rhs.getX());
        this->setY(rhs.getY());
        this->setWidth(rhs.getWidth());
        this->setHeight(rhs.getHeight());
        _speed = rhs.getSpeed();
    }
    return *this;
}

bool AEntity::baseMove(int x, int y) {
    uint64_t curTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if (curTime - _timeLastMove >= _speed) {
        _timeLastMove = curTime;
    }
    else {
        return true;  // OK but don't move now
    }
    if ((int)_x + x < 0 || _x + x + _width > _screen->getGameSizeX())
        return false;
    if ((int)_y + y < 0 || _y + y + _height > _screen->getGameSizeY())
        return false;
    _x += x;
    _y += y;
    return true;
}


BulletContainer *AEntity::getBullets() const { return _bullets; }
Weapon *AEntity::getWeapon() const { return _weapon; }
std::string const &AEntity::getType() const { return _type; }
int AEntity::getSpeed() const { return _speed; }

std::ostream &operator<<(std::ostream &o, AEntity &other) {
    o << other.getType() << " at " << other.getX() << " " << other.getY() << std::endl;
    return o;
}
