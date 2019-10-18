#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() :
_intern(nullptr),
_signer(nullptr),
_executor(nullptr) {
}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor) :
_intern(intern),
_signer(signer),
_executor(executor) {
}

OfficeBlock::~OfficeBlock() {
}


void OfficeBlock::doBureaucracy(std::string const &formName, std::string const &target) {
    if (_intern == nullptr) throw OfficeBlock::NullInternException();
    if (_signer == nullptr) throw OfficeBlock::NullSignerException();
    if (_executor == nullptr) throw OfficeBlock::NullExecutorException();

    Form *form = _intern->makeForm(formName, target);
    _signer->signForm(*form);
    _executor->executeForm(*form);
    delete form;
}

void OfficeBlock::setIntern(Intern *intern) {
    _intern = intern;
}
void OfficeBlock::setSigner(Bureaucrat *signer) {
    _signer = signer;
}
void OfficeBlock::setExecutor(Bureaucrat *executor) {
    _executor = executor;
}