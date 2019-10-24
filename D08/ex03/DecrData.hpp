#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class DecrData : public AInstruction {
    public:
        DecrData(Brainfuck *brfk);
        DecrData(DecrData const &src);
        virtual ~DecrData();

        DecrData &operator=(DecrData const &rhs);

        virtual bool exec();
    protected:
    private:
        DecrData();
};
