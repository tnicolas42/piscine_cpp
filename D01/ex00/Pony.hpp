#pragma once

#include <string>

class Pony {
    public:
        Pony();
        Pony(std::string name);
        ~Pony();

        std::string &getName();
        const std::string &getName() const;
    protected:
    private:
        std::string _name;
};