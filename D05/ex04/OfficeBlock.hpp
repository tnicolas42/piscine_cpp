#pragma once

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

class OfficeBlock {
    public:
        OfficeBlock();
        OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
        virtual ~OfficeBlock();

        void doBureaucracy(std::string const &formName, std::string const &target);

        void setIntern(Intern *intern);
        void setSigner(Bureaucrat *signer);
        void setExecutor(Bureaucrat *executor);

        class OfficeBlockException : public std::exception {};
        class NullInternException : public OfficeBlockException {
            public:
                virtual const char *what() const throw() {
                    return "Intern is not set";
                }
        };
        class NullSignerException : public OfficeBlockException {
            public:
                virtual const char *what() const throw() {
                    return "Signer is not set";
                }
        };
        class NullExecutorException : public OfficeBlockException {
            public:
                virtual const char *what() const throw() {
                    return "Executor is not set";
                }
        };
    protected:
    private:
        Intern *_intern;
        Bureaucrat *_signer;
        Bureaucrat *_executor;
};