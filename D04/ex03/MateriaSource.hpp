#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

#define MAX_LEARN 4

class MateriaSource : public IMaterialSource {
    public:
        MateriaSource();
        MateriaSource(MateriaSource const &src);
        virtual ~MateriaSource();

        MateriaSource &operator=(MateriaSource const &rhs);
        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);
        AMateria *createMateria(int idx) const;
    protected:
    private:
        AMateria *_learned[MAX_LEARN];
};