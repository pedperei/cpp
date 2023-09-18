#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    {
        try
        {
            AForm *form1 = new ShrubberyCreationForm();
            AForm *form2 = new RobotomyRequestForm();
            AForm *form3 = new PresidentialPardonForm();
            Bureaucrat asd = Bureaucrat("asd", 30);
            Bureaucrat tmp = Bureaucrat("asd2", 2);
            Bureaucrat asd2 = tmp;
            asd.executeForm(*form1);
            asd.executeForm(*form2);
            asd.executeForm(*form3);
            asd.signForm(*form1);
            asd.signForm(*form2);
            asd.signForm(*form3);
            asd2.signForm(*form3);
            asd2.signForm(*form3);
            asd.executeForm(*form3);
            asd2.executeForm(*form3);
            asd2.signForm(*form2);
            asd.executeForm(*form2);
            asd2.executeForm(*form2);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}