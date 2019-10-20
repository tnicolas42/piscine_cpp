#pragma once

#include "AScreenRenderedElement.class.hpp"
#include "Screen.class.hpp"
#include "Colors.hpp"

#define BULLET_TEXTURE "||"
#define BULLET_COLOR COLOR_RED_PAIR
class Bullet : public AScreenRenderedElement {
    public:
        Bullet(Screen *sc, int x, int y, int velX, int velY, uint64_t speedMs);
        Bullet(Bullet const &src);
        virtual ~Bullet();

        Bullet &operator=(Bullet const &rhs);
	    virtual bool update();  // return false is the object need to be removed

        int getVelX() const;
        int getVelY() const;
        uint64_t getSpeedMs() const;
    protected:
    private:
        Bullet();
        int _velX;
        int _velY;
        uint64_t _speedMs;
        uint64_t _timeLastMove;
};

std::ostream &operator<<(std::ostream &o, Bullet const &other);
