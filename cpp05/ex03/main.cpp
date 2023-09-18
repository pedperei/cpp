#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    {
        try
        {
            Intern someRandomIntern;
            Bureaucrat ze = Bureaucrat("ze", 10);
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            ze.signForm(*rrf);
            rrf->execute(ze);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try
        {
            Intern someRandomIntern;
            Bureaucrat ze = Bureaucrat("ze", 10);
            AForm* rrf;
            rrf = someRandomIntern.makeForm("random form", "Bender");
            ze.signForm(*rrf);
            rrf->execute(ze);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}