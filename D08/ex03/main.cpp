#include "Brainfuck.hpp"

#include "AInstruction.hpp"
#include "IncrPtr.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::string data = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

    Brainfuck brfk;

    (void)data;
    (void)brfk;
    return 0;
}
