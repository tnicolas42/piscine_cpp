#pragma once

#include "Screen.class.hpp"
#include "Bullet.hpp"
#include <ostream>

class BulletContainer {
    public:
        struct BulletLst {
            Bullet *bullet;
            BulletLst *next;

            BulletLst();
        };

        BulletContainer(Screen *sc);
        BulletContainer(BulletContainer const &src);
        virtual ~BulletContainer();

        BulletContainer &operator=(BulletContainer const &rhs);
        Bullet *newBullet(int x, int y, int velX, int velY, uint64_t speedMs);
        void delBullet(int idx);
        void update();
		Screen		*getScreen() const;
        BulletLst	*getBullets() const;
        Bullet		*getBullet(int idx) const;
    protected:
    private:
        BulletContainer();
        // move a bullet
        bool updateOne(Bullet &bullet);

        Screen		*_screen;
        BulletLst	*_bullets;
};
