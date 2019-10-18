#include "Form.hpp"

Form::Form() :
_name("defaultName"),
_requiredGradeSign(LOWER_GRADE),
_requiredGradeExec(LOWER_GRADE),
_isSigned(false) {
}

Form::Form(std::string const &name, int const requiredGradeSign, int const requiredGradeExec) :
_name(name),
_requiredGradeSign(requiredGradeSign),
_requiredGradeExec(requiredGradeExec),
_isSigned(false) {
    if (IS_TOO_HIGHER_GRADE(_requiredGradeSign) || IS_TOO_HIGHER_GRADE(_requiredGradeExec))
        throw Form::GradeTooHighException();
    if (IS_TOO_LOWER_GRADE(_requiredGradeSign) || IS_TOO_LOWER_GRADE(_requiredGradeExec))
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src) :
_name(src.getName()),
_requiredGradeSign(src.getRequiredGradeToSign()),
_requiredGradeExec(src.getRequiredGradeToExec()) {
    *this = src;
}

Form::~Form() {
}

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs) {
        _isSigned = rhs.isSigned();
    }
    return *this;
}

void Form::beSigned(Bureaucrat const &b) {
    if (b.getGrade() <= _requiredGradeSign)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::string const &Form::getName() const { return _name; }
int Form::getRequiredGradeToSign() const { return _requiredGradeSign; }
int Form::getRequiredGradeToExec() const { return _requiredGradeExec; }
bool Form::isSigned() const { return _isSigned; }

std::ostream &operator<<(std::ostream &o, Form const &other) {
    o << "Form: " << other.getName() << " (required grade " << other.getRequiredGradeToSign() <<
        " to be signed and " << other.getRequiredGradeToExec() << " to exectute)" << std::endl;
    return o;
}