#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
}

Intern::Intern(Intern const &src) {
    *this = src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &rhs) {
    if (this != &rhs) {
        ;
    }
    return *this;
}

Form *Intern::makeForm(std::string const &formName, std::string const &target) const {
    Form *form;
    if (formName == "shrubbery creation") {
        form = new ShrubberyCreationForm(target);
    }
    else if (formName == "robotomy request") {
        form = new RobotomyRequestForm(target);
    }
    else if (formName == "presidential pardon") {
        form = new PresidentialPardonForm(target);
    }
    else {
        throw Intern::InvalidFormNameException();
    }
    std::cout << "[INFO]: Intern create " << form->getName() << " need grade " <<
        form->getRequiredGradeToSign() << " to sign and " << form->getRequiredGradeToExec() <<
        " to execute" << std::endl;
    return form;
}