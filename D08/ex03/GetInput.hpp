#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class GetInput : public AInstruction {
    public:
        GetInput(Brainfuck *brfk);
        GetInput(GetInput const &src);
        virtual ~GetInput();

        GetInput &operator=(GetInput const &rhs);

        virtual bool exec();
    protected:
    private:
        GetInput();
};
