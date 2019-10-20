#pragma once

#include "Screen.class.hpp"
#include "BulletsContainer.hpp"
#include "AEntity.hpp"
#include "EnemyFleet.hpp"
#include "Colors.hpp"
#include "Texture.hpp"
#include "Defines.hpp"

class Player : public AEntity {
    public:
        Player(Screen *sc, BulletContainer *bullets, EnemyFleet *fleet);
        Player(Player const &src);
        virtual ~Player();

        Player &operator=(Player const &rhs);
        virtual bool move(int x, int y=0);
        virtual bool update();
    protected:
    private:
        Player();
        EnemyFleet *_fleet;
};
