#include "AInstruction.hpp"

AInstruction::AInstruction(Brainfuck *brfk, char instr) : _brfk(brfk), _instr(instr) {}

AInstruction::AInstruction(AInstruction const &src) {
    *this = src;
}

AInstruction::~AInstruction() {}

AInstruction &AInstruction::operator=(AInstruction const &rhs) {
    if (this != &rhs) {
        _brfk = rhs.getBrfk();
        _instr = rhs.getInstr();
    }
    return *this;
}

Brainfuck   *AInstruction::getBrfk() const { return _brfk; }
char        AInstruction::getInstr() const { return _instr; }
