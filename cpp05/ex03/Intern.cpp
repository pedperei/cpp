#include "Intern.hpp"

Intern::Intern()
{
    forms[0] = new ShrubberyCreationForm();
    forms[1] = new RobotomyRequestForm();
    forms[2] = new PresidentialPardonForm();
}

Intern::Intern(const Intern& intern)
{
    forms[0] = NULL;
    forms[1] = NULL;
    forms[2] = NULL;
    *this=intern;
}

Intern::~Intern()
{
    for (int i = 0; i < 3; i++)
        delete forms[i];
}

Intern& Intern::operator=(const Intern& intern)
{
    if (this != &intern)
    {
        *this->forms = *intern.forms;
    }
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string form_arr[3] = {"shrubbery creation",
                                "robotomy request",
                                "presidential pardon"};
    for (int i = 0; i < 3; i++)
    {
        if(form_arr[i] == name)
        {
            std::cout << "Intern creates " << this->forms[i]->getName() << std::endl;
            return (this->forms[i]->createNewForm(target));
        }
    }
    throw Intern::FormNotCreatedException();
    return (NULL);
}