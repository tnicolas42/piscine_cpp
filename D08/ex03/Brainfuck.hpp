#pragma once

#include <string>

#define MAX_STR_SIZE 2000

class Brainfuck {
    public:
        Brainfuck();
        Brainfuck(Brainfuck const &src);
        virtual ~Brainfuck();

        Brainfuck &operator=(Brainfuck const &rhs);

        std::string const  &getData() const;
        std::string        &getData();
        std::string const  *getPtr() const;
        std::string        *getPtr();
    protected:
    private:
        std::string *_data;
        std::string *_ptr;
};
