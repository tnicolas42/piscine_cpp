#pragma once

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form {
    public:
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
        virtual void execute(Bureaucrat const &executor);
        std::string const &getTarget() const;
    protected:
    private:
        PresidentialPardonForm();
        std::string _target;
};