#pragma once

#include "Brain.hpp"
#include <string>

class Human {
    public:
        Human();
        ~Human();

        Brain &getBrain();
        std::string identify() const;
    protected:
    private:
        Brain _brain;
};