#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <iostream>
#include <stdexcept>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    Intern idiotOne;
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 45);
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 72);
    OfficeBlock ob;

    ob.setIntern(&idiotOne);
    ob.setSigner(&bob);

    // error -> exectutor not set
    try {
        ob.doBureaucracy("robotomy request", "Bobby");
    }
    catch (Bureaucrat::BureaucratException &e) {
        std::cout << "[ERROR][BureaucratException]: " << e.what() << std::endl;
    }
    catch (Form::FormException &e) {
        std::cout << "[ERROR][FormException]: " << e.what() << std::endl;
    }
    catch (Intern::InternException &e) {
        std::cout << "[ERROR][InternException]: " << e.what() << std::endl;
    }
    catch (OfficeBlock::OfficeBlockException &e) {
        std::cout << "[ERROR][OfficeBlockException]: " << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "[ERROR][exception]: " << e.what() << std::endl;
    }

    ob.setExecutor(&hermes);

    std::cout << std::endl;
    // OK
    try {
        ob.doBureaucracy("robotomy request", "Bobby");
    }
    catch (Bureaucrat::BureaucratException &e) {
        std::cout << "[ERROR][BureaucratException]: " << e.what() << std::endl;
    }
    catch (Form::FormException &e) {
        std::cout << "[ERROR][FormException]: " << e.what() << std::endl;
    }
    catch (Intern::InternException &e) {
        std::cout << "[ERROR][InternException]: " << e.what() << std::endl;
    }
    catch (OfficeBlock::OfficeBlockException &e) {
        std::cout << "[ERROR][OfficeBlockException]: " << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "[ERROR][exception]: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    // error grade low
    try {
        ob.doBureaucracy("presidential pardon", "Hermes");
    }
    catch (Bureaucrat::BureaucratException &e) {
        std::cout << "[ERROR][BureaucratException]: " << e.what() << std::endl;
    }
    catch (Form::FormException &e) {
        std::cout << "[ERROR][FormException]: " << e.what() << std::endl;
    }
    catch (Intern::InternException &e) {
        std::cout << "[ERROR][InternException]: " << e.what() << std::endl;
    }
    catch (OfficeBlock::OfficeBlockException &e) {
        std::cout << "[ERROR][OfficeBlockException]: " << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "[ERROR][exception]: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    // error -> form name invalid
    try {
        ob.doBureaucracy("invalid form", "target");
    }
    catch (Bureaucrat::BureaucratException &e) {
        std::cout << "[ERROR][BureaucratException]: " << e.what() << std::endl;
    }
    catch (Form::FormException &e) {
        std::cout << "[ERROR][FormException]: " << e.what() << std::endl;
    }
    catch (Intern::InternException &e) {
        std::cout << "[ERROR][InternException]: " << e.what() << std::endl;
    }
    catch (OfficeBlock::OfficeBlockException &e) {
        std::cout << "[ERROR][OfficeBlockException]: " << e.what() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "[ERROR][exception]: " << e.what() << std::endl;
    }
    return 0;
}