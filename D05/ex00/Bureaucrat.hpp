#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

#define LOWER_GRADE 150
#define HIGHER_GRADE 1
#define GRADE_UP -1
#define IS_LOWER_GRADE(grade) (grade >= LOWER_GRADE)
#define IS_TOO_LOWER_GRADE(grade) (grade > LOWER_GRADE)
#define IS_HIGHER_GRADE(grade) (grade <= HIGHER_GRADE)
#define IS_TOO_HIGHER_GRADE(grade) (grade < HIGHER_GRADE)

class Bureaucrat {
    public:
        Bureaucrat(std::string const &name);
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &src);
        virtual ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &rhs);
        void upGrade();
        void downGrade();
        std::string const &getName() const;
        int getGrade() const;

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
        Bureaucrat();
        std::string const _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other);