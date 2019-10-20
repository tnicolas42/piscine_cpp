#pragma once

#include "Screen.class.hpp"
#include "BulletsContainer.hpp"
#include "AEntity.hpp"
#include "Player.hpp"
#include "Texture.hpp"
#include "Defines.hpp"

class Enemy : public AEntity {
    public:
        Enemy(Screen *sc,
            BulletContainer *bullets,
            std::string type,
            int w,
            int h,
            int wp_x,
            int wp_y,
            uint64_t wp_speed_bullet,
            int wp_delay,
            uint64_t speed,
            std::string texture,
            uint8_t color,
            bool moveVertical=true,
			bool canBeWeaponized = true
        );
        Enemy(Enemy const &src);
        virtual ~Enemy();

        Enemy &operator=(Enemy const &rhs);
        virtual bool move(int x, int y);
        virtual bool update();

        void			enableWeapon(bool enable);
        bool			hasWeapon() const;
        uint64_t		getWeaponDelay() const;
		bool			isVertical() const;
    protected:
        Enemy();
        bool _hasWeapon;
        uint64_t _weaponDelay;
        bool _moveVertical;
        static size_t _lastSpawnPosX;
        static size_t _lastSpawnPosY;
    private:
};
