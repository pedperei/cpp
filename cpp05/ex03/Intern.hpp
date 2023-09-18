#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
private:
    AForm* forms[3];
public:
    Intern();
    Intern(const Intern&);
    ~Intern();
    Intern& operator=(const Intern& intern);
    AForm* makeForm(std::string name, std::string target);
    class FormNotCreatedException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Form name doesn't exist");
        }
    };
};
