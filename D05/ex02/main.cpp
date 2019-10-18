#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Bureaucrat b("bob");
    Form form("formulaire1", 149, 148);

    std::cout << b << form;
    b.signForm(form);

    b.upGrade();
    std::cout << b << form;
    b.signForm(form);

    return 0;
}