#pragma once

#include "AMateria.hpp"
#include <string>

class IMaterialSource {
    public:
        virtual ~IMaterialSource() {};
        virtual void learnMateria(AMateria *materia) = 0;
        virtual AMateria *createMateria(std::string const &type) = 0;
    protected:
    private:
};