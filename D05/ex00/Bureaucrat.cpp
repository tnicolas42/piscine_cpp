#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
_name("defaultName"),
_grade(LOWER_GRADE) {
}

Bureaucrat::Bureaucrat(std::string const &name) :
_name(name),
_grade(LOWER_GRADE) {
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) :
_name(name),
_grade(grade) {
    if (IS_TOO_HIGHER_GRADE(_grade))
        throw Bureaucrat::GradeTooHighException();
    if (IS_TOO_LOWER_GRADE(_grade))
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) :
_name(src.getName()) {
    *this = src;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    if (this != &rhs) {
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