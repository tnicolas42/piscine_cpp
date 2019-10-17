#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i=0; i < MAX_LEARN; i++) {
        _learned[i] = nullptr;
    }
}

MateriaSource::MateriaSource(MateriaSource const &src) {
    *this = src;
}

MateriaSource::~MateriaSource() {
    for (int i=0; i < MAX_LEARN; i++) {
        delete _learned[i];
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
    if (this != &rhs) {
        for (int i=0; i < MAX_LEARN; i++) {
            _learned[i] = rhs.getMateria(i);
        }
    }
    return *this;
}


void MateriaSource::learnMateria(AMateria *materia) {
    for (int i=0; i < MAX_LEARN; i++) {
        if (_learned[i] == nullptr) {
            _learned[i] = materia;
            return;
        }
    }
    std::cout << "not enouth place to learn some others Matreria" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i=0; i < MAX_LEARN; i++) {
        if (_learned[i]->getType() == type) {
            return _learned[i]->clone();
        }
    }
    return nullptr;
}

AMateria *MateriaSource::getMateria(int idx) const {
    if (idx < 0 || idx >= MAX_LEARN) {
        std::cout << "invalid index for createMateria" << std::endl;
        return nullptr;
    }
    if (_learned[idx] != nullptr) {
        return _learned[idx];
    }
    return nullptr;
}