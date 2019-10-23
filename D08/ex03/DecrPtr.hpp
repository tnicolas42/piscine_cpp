#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class DecrPtr : public AInstruction {
    public:
        DecrPtr(Brainfuck *brfk);
        DecrPtr(DecrPtr const &src);
        virtual ~DecrPtr();

        DecrPtr &operator=(DecrPtr const &rhs);

        virtual void exec();
    protected:
    private:
        DecrPtr();
};
