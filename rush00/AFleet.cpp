#include "AFleet.hpp"
#include <iostream>
#include "Enemy.hpp"

AFleet::AFleet():
AContainer(),
_spawnSpeedMs(1000),
_increaseSpawnSpeedMs(0),
_timeLastSpawnMs(0) {
    for (size_t i = 0; i < this->getMaxElement(); i++) {
        this->setElement(i, nullptr);
    }
}

AFleet::AFleet(Screen *sc, float spawnSpeedMs, float increaseSpawnSpeedMs, int speedRandomPercent) :
AContainer(sc),
_spawnSpeedMs(spawnSpeedMs),
_increaseSpawnSpeedMs(increaseSpawnSpeedMs),
_speedRandomPercent(speedRandomPercent),
_timeLastSpawnMs(0) {
    for (size_t i = 0; i < this->getMaxElement(); i++) {
        this->setElement(i, nullptr);
    }
}

AFleet::AFleet(AFleet const &src) {
    *this = src;
}

AFleet::~AFleet() {
}

AFleet &AFleet::operator=(AFleet const &rhs) {
    if (this != &rhs) {
        _screen = rhs.getScreen();
        for (size_t i = 0; i < this->getMaxElement(); i++) {
            this->setElement(i, rhs.getElement(i));
        }
        _spawnSpeedMs = rhs.getSpawnSpeed();
        _increaseSpawnSpeedMs = rhs.getIncreaseSpawnSpeed();
    }
    return *this;
}

void AFleet::update() {
    for (size_t i = 0; i < this->getMaxElement(); i++) {
        if (this->getElement(i) == nullptr)
            continue;
		this->getScreen()->deleteElement(*this->getElement(i));
        if (this->getElement(i)->update() == false) {
			if ((((Enemy*)this->getElement(i))->isVertical()))
            	_screen->decrementScore(LOOSE_POINT_SPACESHIP_OUT);
            this->delElement(i);
        }
		else
			this->getScreen()->displayElement(*this->getElement(i));
    }
    std::chrono::milliseconds curTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    if (curTime.count() - _timeLastSpawnMs >= _spawnSpeedMs) {
        for (size_t i = 0; i < this->getMaxElement(); i++) {
            if (this->getElement(i) == nullptr) {
                this->setElement(i, newElement());
                break;
            }
        }
        _timeLastSpawnMs = curTime.count();
        if (_speedRandomPercent > 0) {
            int add = (rand() % (int)((_speedRandomPercent / 100.0f) * _spawnSpeedMs));
            add *= (rand() % 2 == 0) ? -1 : 1;
            _timeLastSpawnMs += add;
        }
        if (_spawnSpeedMs - _increaseSpawnSpeedMs >= MAX_SPAWN_SPEED_MS)
            _spawnSpeedMs -= _increaseSpawnSpeedMs;
    }
}

int64_t AFleet::getSpawnSpeed() const { return _spawnSpeedMs; }
int64_t AFleet::getIncreaseSpawnSpeed() const { return _increaseSpawnSpeedMs; }
