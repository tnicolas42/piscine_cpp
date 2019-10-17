#pragma once

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <string>

typedef struct s_SMList {
    ISpaceMarine *marine;
    struct s_SMList *next;

    s_SMList() : marine(nullptr), next(nullptr) {}
} SMList;

class Squad : public ISquad {
    public:
        Squad();
        Squad(Squad const &src);
        virtual ~Squad();

        Squad &operator=(Squad const &rhs);

        virtual int getCount() const;
        virtual ISpaceMarine *getUnit(int unit) const;
        virtual int push(ISpaceMarine *spaceM);
        SMList *getSpaceMarineList() const;
    protected:
    private:
        SMList *_spaceMarineList;
};