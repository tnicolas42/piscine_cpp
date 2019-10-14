#pragma once

#include <string>

class Weapon {
    public:
        Weapon();
        Weapon(const std::string type);
        ~Weapon();

        void setType(const std::string type);
        const std::string &getType() const;
    protected:
    private:
        std::string _type;
};