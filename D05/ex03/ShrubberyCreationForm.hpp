#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

class ShrubberyCreationForm : public Form {
    public:
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
        virtual void execute(Bureaucrat const &executor);
        std::string const &getTarget() const;
    protected:
    private:
        ShrubberyCreationForm();
        std::string _target;
};