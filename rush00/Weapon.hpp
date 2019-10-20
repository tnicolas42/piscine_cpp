#pragma once

#include <unistd.h>

class AEntity;

class Weapon {
    public:
        Weapon(AEntity *entity, int posX, int posY, int velX, int velY, uint64_t speedMs, uint64_t delayMs, bool moveVertical);
        Weapon(Weapon const &src);
        virtual ~Weapon();

        Weapon &operator=(Weapon const &rhs);
        void shot();
        bool canShot() const;  // return true if the player can shot

        void setDelayMs(uint64_t delay);
        // getter
        AEntity *getEntity() const;
        int getPosX() const;
        int getPosY() const;
        int getVelX() const;
        int getVelY() const;
        uint64_t getDelayMs() const;
    protected:
    private:
        Weapon();
        AEntity *_entity;
        int _posX;  // relative pos X
        int _posY;  // relative pos Y
        int _velX;  // velocity X
        int _velY;  // velocity Y
        uint64_t _speedMs;  // speed of the bullet in ms
        uint64_t _delayMs;  // delay btw 2 shots in milliseconds
		bool		_vertical;
        uint64_t _lastShotTs;
};
