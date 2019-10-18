#include "RobotomyRequestForm.hpp"
#include <string>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() :
Form("RobotomyRequestForm", 72, 45),
_target("defaultTarget") {
    srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
Form("RobotomyRequestForm", 72, 45),
_target(target) {
    srand(time(NULL));
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
Form(src) {
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
    if (this != &rhs) {
        _target = rhs.getTarget();
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) {
    canExec(executor);  // throw error if can't execute
    std::cout << "* drilling noise *" << std::endl;
    if (rand() & 1) {
        std::cout << "[INFO]: " << _target << " as been robotomized successfully" << std::endl;
    }
    else {
        std::cout << "[INFO]: " << "failed to robotomisez " << _target << std::endl;
    }
}

std::string const &RobotomyRequestForm::getTarget() const { return _target; }