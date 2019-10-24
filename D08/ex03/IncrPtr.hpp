#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class IncrPtr : public AInstruction {
    public:
        IncrPtr(Brainfuck *brfk);
        IncrPtr(IncrPtr const &src);
        virtual ~IncrPtr();

        IncrPtr &operator=(IncrPtr const &rhs);

        virtual bool exec();
    protected:
    private:
        IncrPtr();
};
