#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class IncrData : public AInstruction {
    public:
        IncrData(Brainfuck *brfk);
        IncrData(IncrData const &src);
        virtual ~IncrData();

        IncrData &operator=(IncrData const &rhs);

        virtual bool exec();
    protected:
    private:
        IncrData();
};
