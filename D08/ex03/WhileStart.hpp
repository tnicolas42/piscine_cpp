#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class WhileStart : public AInstruction {
    public:
        WhileStart(Brainfuck *brfk);
        WhileStart(WhileStart const &src);
        virtual ~WhileStart();

        WhileStart &operator=(WhileStart const &rhs);

        virtual bool exec();
    protected:
    private:
        WhileStart();
};
