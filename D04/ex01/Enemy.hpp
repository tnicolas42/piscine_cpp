#pragma once

#include <string>

class Enemy {
    public:
        Enemy(int hp, std::string const &type);
        Enemy(Enemy const &src);
        virtual ~Enemy();

        Enemy &operator=(Enemy const &rhs);
        virtual void takeDamage(int damage);
        const std::string &getType() const;
        int getHP() const;
    protected:
        std::string _type;
        int _hp;
    private:
        Enemy();
};