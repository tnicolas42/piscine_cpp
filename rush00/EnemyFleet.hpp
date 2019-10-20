#pragma once

#include "AFleet.hpp"
#include "AScreenElement.class.hpp"
#include "Screen.class.hpp"
#include "BulletsContainer.hpp"

#define FLEET_SPAWN_SPEED_MS 1300
#define FLEET_SPAWN_SPEED_PERCENT 70  // 2 enemy can spawn at a random range
#define FLEET_INCREASE_SPAWN_SPEED_MS 10

class EnemyFleet : public AFleet {
    public:
        EnemyFleet(Screen *sc, BulletContainer *bullets);
        EnemyFleet(EnemyFleet const &src);
        virtual ~EnemyFleet();

        EnemyFleet &operator=(EnemyFleet const &rhs);
        BulletContainer *getBullets() const;
        virtual void update();
        virtual AScreenElement *newElement() const;
    protected:
    private:
        EnemyFleet();
        BulletContainer *_bullets;
};
