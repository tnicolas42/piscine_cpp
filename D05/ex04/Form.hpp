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
        virtual void execute(Bureaucrat const &executor) = 0;
        // getter
        std::string const &getName() const;
        int getRequiredGradeToSign() const;
        int getRequiredGradeToExec() const;
        bool isSigned() const;

        // error definitions
        class FormException : public std::exception {};
        class GradeTooHighException : public FormException {
            public:
                virtual const char *what() const throw() {
                    return "Grade too high";
                }
        };
        class GradeTooLowException : public FormException {
            public:
                virtual const char *what() const throw() {
                    return "Grade too low";
                }
        };
        class FormNotSignedException : public FormException {
            public:
                virtual const char *what() const throw() {
                    return "The form is not signed";
                }
        };
    protected:
        void canExec(Bureaucrat const &executor) ;
    private:
        Form();
        std::string const _name;
        int const _requiredGradeSign;
        int const _requiredGradeExec;
        bool _isSigned;
};

std::ostream &operator<<(std::ostream &o, Form const &other);