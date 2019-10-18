#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

class RobotomyRequestForm : public Form {
    public:
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
        virtual void execute(Bureaucrat const &executor);
        std::string const &getTarget() const;
    protected:
    private:
        RobotomyRequestForm();
        std::string _target;
};