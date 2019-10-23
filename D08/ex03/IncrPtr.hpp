#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class IncrPtr : public AInstruction {
    public:
        IncrPtr(Brainfuck *brfk);
        IncrPtr(IncrPtr const &src);
        virtual ~IncrPtr();

        IncrPtr &operator=(IncrPtr const &rhs);

        virtual void exec();
    protected:
    private:
        IncrPtr();
};
