#include "Squad.hpp"

Squad::Squad() :
_spaceMarineList(nullptr) {
}

Squad::Squad(Squad const &src) {
    *this = src;
}

Squad::~Squad() {
    SMList *tmp = _spaceMarineList;
    SMList *last = nullptr;
    while (tmp) {
        last = tmp;
        tmp = tmp->next;
        delete last->marine;
        delete last;
    }
}

Squad &Squad::operator=(Squad const &rhs) {
    if (this != &rhs) {
        _spaceMarineList = rhs.getSpaceMarineList();
    }
    return *this;
}


int Squad::getCount() const {
    int count = 0;
    SMList *tmp = _spaceMarineList;
    while (tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
ISpaceMarine *Squad::getUnit(int unit) const {
    if (unit < 0 || unit >= getCount())
        return nullptr;
    SMList *tmp = _spaceMarineList;
    while (unit--)
        tmp = tmp->next;
    return tmp->marine;
}
int Squad::push(ISpaceMarine *spaceM) {
    SMList *tmp = _spaceMarineList;
    if (tmp == nullptr) {
        _spaceMarineList = new SMList();
        _spaceMarineList->marine = spaceM;
        return 1;
    }
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new SMList();
    tmp->next->marine = spaceM;
    return getCount();
}

SMList *Squad::getSpaceMarineList() const { return _spaceMarineList; }