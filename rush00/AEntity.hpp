#pragma once

#include "Screen.class.hpp"
#include "BulletsContainer.hpp"
#include "Weapon.hpp"
#include "AScreenRenderedElement.class.hpp"
#include <iostream>
#include <string>

class AEntity: public AScreenRenderedElement {
    public:
        AEntity(Screen *sc, BulletContainer *bullets, std::string type, int x, int y,
            int width, int height, uint64_t speed, std::string texture, uint8_t color);
        AEntity(AEntity const &src);
        virtual ~AEntity();

        AEntity &operator=(AEntity const &rhs);
        bool baseMove(int x, int y);  // return false with the entity is out of the screen
        virtual bool move(int x, int y) = 0;
        virtual bool update() = 0;

        // getter
        BulletContainer *getBullets() const;
        Weapon *getWeapon() const;
        std::string const &getType() const;
        int getSpeed() const;
    protected:
        AEntity();
        BulletContainer *_bullets;
        Weapon *_weapon;

        std::string _type;
        uint64_t _speed;

        uint64_t _timeLastMove;
    private:
};

std::ostream &operator<<(std::ostream &o, AEntity &other);
