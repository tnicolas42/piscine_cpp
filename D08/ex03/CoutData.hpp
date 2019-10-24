#pragma once

#include "AInstruction.hpp"
#include "Brainfuck.hpp"

class CoutData : public AInstruction {
    public:
        CoutData(Brainfuck *brfk);
        CoutData(CoutData const &src);
        virtual ~CoutData();

        CoutData &operator=(CoutData const &rhs);

        virtual bool exec();
    protected:
    private:
        CoutData();
};
