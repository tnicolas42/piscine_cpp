#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
_name("defaultName"),
_grade(LOWER_GRADE) {
}

Bureaucrat::Bureaucrat(std::string const &name) :
_name(name),
_grade(LOWER_GRADE) {
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
    *this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
        _name = rhs.getName();
        _grade = rhs.getGrade();
    }
    return *this;
}

void Bureaucrat::upGrade() {
    if (IS_HIGHER_GRADE(_grade)) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade += GRADE_UP;
}
void Bureaucrat::downGrade() {
    if (IS_LOWER_GRADE(_grade)) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade -= GRADE_UP;
}

std::string const &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

std::ostream &operator<<(std::ostream &o, Bureaucrat const &other) {
    o << other.getName() << " bureaucrat grade " << other.getGrade();
    return o;
}