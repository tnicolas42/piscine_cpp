#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
Form("ShrubberyCreationForm", 145, 137),
_target("defaultTarget") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) :
Form("ShrubberyCreationForm", 145, 137),
_target(target) {
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
Form(src) {
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
    if (this != &rhs) {
        _target = rhs.getTarget();
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
    canExec(executor);  // throw error if can't execute

    std::ofstream fileOut(_target + "_shrubbery");
    if (fileOut.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
    }
    fileOut << "        ###" << std::endl;
    fileOut << "      #o###" << std::endl;
    fileOut << "    #####o###" << std::endl;
    fileOut << "   #o#\\#|#/###" << std::endl;
    fileOut << "    ###\\|/#o#" << std::endl;
    fileOut << "     # }|{  #" << std::endl;
    fileOut << "       }|{" << std::endl;
    if (fileOut.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
    }
    fileOut.close();
}

std::string const &ShrubberyCreationForm::getTarget() const { return _target; }