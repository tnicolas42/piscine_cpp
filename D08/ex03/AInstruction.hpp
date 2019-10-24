#pragma once

#include "Brainfuck.hpp"

class AInstruction {
    public:
        AInstruction(Brainfuck *brfk, char instr);
        AInstruction(AInstruction const &src);
        virtual ~AInstruction();

        AInstruction &operator=(AInstruction const &rhs);

        virtual bool    exec() = 0;
        Brainfuck       *getBrfk() const;
        char            getInstr() const;
    protected:
        Brainfuck   *_brfk;
        char        _instr;
        char        _[7];  // for padding
    private:
        AInstruction();
};
