#pragma once

#include "AScreenElement.class.hpp"
#include "Screen.class.hpp"
#include "AContainer.class.hpp"
#include <chrono>

#define MAX_SPAWN_SPEED_MS 10  // max spawn speed in second (1 every MAX_SPAWN_SPEED millis)
#define WIN_POINT_DESTROY 150
#define LOOSE_POINT_SPACESHIP_OUT 50

class AFleet: public AContainer {
    public:
        AFleet(Screen *sc, float spawnSpeedMs, float increaseSpawnSpeedMs=0, int speedRandomPercent=0);
        AFleet(AFleet const &src);
        virtual ~AFleet();

        AFleet &operator=(AFleet const &rhs);
        virtual void update();
        virtual AScreenElement *newElement() const = 0;
        int64_t getSpawnSpeed() const;
        int64_t getIncreaseSpawnSpeed() const;
    protected:
    private:
        AFleet();
        int64_t _spawnSpeedMs;  // delay btw 2 spawn in milliseconds
        int64_t _increaseSpawnSpeedMs;  // increase _spawnSpeed on each loop
        int _speedRandomPercent;  // to have a random generation
        int64_t _timeLastSpawnMs;
};
