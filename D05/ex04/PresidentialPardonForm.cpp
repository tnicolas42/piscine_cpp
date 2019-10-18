#include "PresidentialPardonForm.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm() :
Form("PresidentialPardonForm", 25, 5),
_target("defaultTarget") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) :
Form("PresidentialPardonForm", 25, 5),
_target(target) {
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
Form(src) {
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
    if (this != &rhs) {
        _target = rhs.getTarget();
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) {
    canExec(executor);  // throw error if can't execute
    std::cout << "[INFO]: " << _target << " as been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string const &PresidentialPardonForm::getTarget() const { return _target; }