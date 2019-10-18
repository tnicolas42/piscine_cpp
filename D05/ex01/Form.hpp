#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Form {
    public:
        Form(std::string const &name, int const requiredGradeSign, int const requiredGradeExec);
        Form(Form const &src);
        virtual ~Form();

        Form &operator=(Form const &rhs);
        void beSigned(Bureaucrat const &b);
        // getter
        std::string const &getName() const;
        int getRequiredGradeToSign() const;
        int getRequiredGradeToExec() const;
        bool isSigned() const;

        // error definitions
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Grade too high";
                }
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return "Grade too low";
                }
        };
    protected:
    private:
        Form();
        std::string const _name;
        int const _requiredGradeSign;
        int const _requiredGradeExec;
        bool _isSigned;
};

std::ostream &operator<<(std::ostream &o, Form const &other);