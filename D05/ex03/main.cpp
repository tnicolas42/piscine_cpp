#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdexcept>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Bureaucrat president("president", 1);
    Intern intern;
    Form *shruberryForm = intern.makeForm("shrubbery creation", "target");
    Form *robotoForm = intern.makeForm("robotomy request", "target");
    Form *presForm = intern.makeForm("presidential pardon", "target");
    intern.makeForm("invalid form", "target");

    president.signForm(*presForm);
    president.executeForm(*presForm);

    delete shruberryForm;
    delete robotoForm;
    delete presForm;
    return 0;
}