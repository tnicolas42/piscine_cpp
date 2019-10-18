#pragma once

#include "Form.hpp"
#include <string>

class Intern {
    public:
        Intern();
        Intern(Intern const &src);
        virtual ~Intern();

        Intern &operator=(Intern const &rhs);
        Form *makeForm(std::string const &formName, std::string const &target) const;
    protected:
    private:
};