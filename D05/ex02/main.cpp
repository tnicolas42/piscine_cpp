#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <stdexcept>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Bureaucrat bob("bob", 146);
    Bureaucrat zaz("zaz", 10);
    Bureaucrat president("president", 1);
    Form *shruberryForm = new ShrubberyCreationForm("home");
    Form *robotoForm = new RobotomyRequestForm("roboto");
    Form *presForm = new PresidentialPardonForm("victim");

    bob.signForm(*shruberryForm);
    std::cout << "upgrade bob" << std::endl;
    bob.upGrade();
    bob.signForm(*shruberryForm);
    bob.signForm(*robotoForm);
    zaz.signForm(*robotoForm);
    president.signForm(*presForm);

    std::cout << std::endl;

    bob.executeForm(*shruberryForm);
    std::cout << "upgrade bob" << std::endl;
    for (int i=0; i < 10; i++) {
        bob.upGrade();
    }
    bob.executeForm(*shruberryForm);
    zaz.executeForm(*presForm);
    president.executeForm(*robotoForm);
    president.executeForm(*presForm);

    delete shruberryForm;
    delete robotoForm;
    delete presForm;
    return 0;
}