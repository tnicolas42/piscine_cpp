#include "Bullet.hpp"
#include <iostream>
#include <chrono>

Bullet::Bullet() :
	AScreenRenderedElement(nullptr, 0, 0),
	_velX(0),
	_velY(1),
	_speedMs(300),
	_timeLastMove(0)
	{
		this->setBold(true);
	    std::cout << "DO NOT CALL DEFAULT CONSTRUCTOR FOR BULLET" << std::endl;
	}

Bullet::Bullet(Screen *sc, int x, int y, int velX, int velY, uint64_t speedMs) :
	AScreenRenderedElement(sc, x, y, 1, 2, BULLET_TEXTURE, BULLET_COLOR),
	_velX(velX),
	_velY(velY),
	_speedMs(speedMs),
	_timeLastMove(0)
	{
		this->setBold(true);
	}

Bullet::Bullet(Bullet const &src) :
AScreenRenderedElement(src) {
    *this = src;
}

Bullet::~Bullet() {
    this->getScreen()->deleteElement(*this);
}

Bullet &Bullet::operator=(Bullet const &rhs) {
    if (this != &rhs) {
        _screen = rhs.getScreen();
        _velX = rhs.getVelX();
        _velY = rhs.getVelY();
        _speedMs = rhs.getSpeedMs();
        _timeLastMove = 0;
    }
    return *this;
}

bool Bullet::update() {
    uint64_t curTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if (curTime - _timeLastMove >= _speedMs) {
        _timeLastMove = curTime;
    }
    else {
        return true;  // OK but don't move now
    }
    if ((int)_x + _velX < 0 || _x + _velX + 1 > _screen->getGameSizeX())
        return false;
    if ((int)_y + _velY < 0 || _y + _velY + 1 > _screen->getGameSizeY())
        return false;
    _x += _velX;
    _y += _velY;
    return true;
}

int Bullet::getVelX() const { return _velX; }
int Bullet::getVelY() const { return _velY; }
uint64_t Bullet::getSpeedMs() const { return _speedMs; }


std::ostream &operator<<(std::ostream &o, Bullet const &other) {
    o << "[BULLET] x: " << other.getX() << ", y: " << other.getY() <<
        ". At velocity " << other.getVelX() << " " << other.getVelY() << std::endl;
    return o;
}
