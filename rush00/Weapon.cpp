#include "Weapon.hpp"
#include "AEntity.hpp"

Weapon::Weapon() :
_entity(nullptr),
_posX(0),
_posY(0),
_velX(1),
_velY(1),
_speedMs(300),
_delayMs(300),
_vertical(false),
_lastShotTs(0) {
    std::cout << "INVALID CONSTRUCTOR FOR WEAPON" << std::endl;
}

Weapon::Weapon(AEntity *entity, int posX, int posY, int velX, int velY, uint64_t speedMs, uint64_t delayMs,
	bool moveVertical) :
_entity(entity),
_posX(posX),
_posY(posY),
_velX(velX),
_velY(velY),
_speedMs(speedMs),
_delayMs(delayMs),
_vertical(moveVertical),
_lastShotTs(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()) {
}

Weapon::Weapon(Weapon const &src) {
    *this = src;
}

Weapon::~Weapon() {
}

Weapon &Weapon::operator=(Weapon const &rhs) {
    if (this != &rhs) {
        _entity = rhs.getEntity();
        _posX = rhs.getPosX();
        _posY = rhs.getPosY();
        _velX = rhs.getVelX();
        _velY = rhs.getVelY();
        _delayMs = rhs.getDelayMs();
        _vertical = rhs._vertical;
        _lastShotTs = 0;
    }
    return *this;
}

void Weapon::shot() {
	Bullet *b;
    if (!canShot())
        return;
    _lastShotTs = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    int x = _entity->getX() + _posX;
    int y = _entity->getY() + _posY;
    b = _entity->getBullets()->newBullet(x, y, _velX, _velY, _speedMs);
	if (!this->_vertical)
	{
		b->setTexture("---");
		b->setWidth(3);
		b->setHeight(1);
	}
}

bool Weapon::canShot() const {
    uint64_t curTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if (curTime - _lastShotTs >= _delayMs)
        return true;
    return false;
}

void Weapon::setDelayMs(uint64_t delay) { _delayMs = delay; }

AEntity *Weapon::getEntity() const { return _entity; }
int Weapon::getPosX() const { return _posX; }
int Weapon::getPosY() const { return _posY; }
int Weapon::getVelX() const { return _velX; }
int Weapon::getVelY() const { return _velY; }
uint64_t Weapon::getDelayMs() const { return _delayMs; }
