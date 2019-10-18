#pragma once

#include "Form.hpp"
#include <string>
#include <stdexcept>

class Intern {
    public:
        Intern();
        Intern(Intern const &src);
        virtual ~Intern();

        Intern &operator=(Intern const &rhs);
        Form *makeForm(std::string const &formName, std::string const &target) const;

        class InternException : public std::exception {};
        class InvalidFormNameException : public InternException {
            public:
                virtual const char *what() const throw() {
                    return "Invalid form name";
                }
        };
    protected:
    private:
};