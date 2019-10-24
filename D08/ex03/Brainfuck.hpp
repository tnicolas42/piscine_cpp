#pragma once

#include <string>
#include <queue>
#include <map>

#define MAX_STR_SIZE 2000

class AInstruction;

class Brainfuck {
    public:
        Brainfuck();
        Brainfuck(Brainfuck const &src);
        virtual ~Brainfuck();

        Brainfuck &operator=(Brainfuck const &rhs);
        bool    compile(std::string srcCode);
        bool    decodePrgm();

        std::string const  &getData() const;
        std::string        &getData();
        uint64_t           getPtr() const;
        uint64_t           &getPtr();
        std::map<char, AInstruction*> const &getInstrList() const;
        std::vector<AInstruction*> const    &getProg() const;
        uint64_t           getProgPtr() const;
        uint64_t           &getProgPtr();
    protected:
    private:
        void    _init();

        std::string *_data;
        uint64_t    _ptr;

        std::map<char, AInstruction*>   _instrList;
        std::vector<AInstruction*>      _prog;
        uint64_t                        _progPtr;
};
