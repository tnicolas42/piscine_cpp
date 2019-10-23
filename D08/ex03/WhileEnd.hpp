#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class WhileEnd : public AInstruction {
    public:
        WhileEnd(Brainfuck *brfk);
        WhileEnd(WhileEnd const &src);
        virtual ~WhileEnd();

        WhileEnd &operator=(WhileEnd const &rhs);

        virtual void exec();
    protected:
    private:
        WhileEnd();
};
