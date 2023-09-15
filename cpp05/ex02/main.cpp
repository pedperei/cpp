#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(void)
{
    {
        try
        {
            Bureaucrat ze = Bureaucrat("ze", 120);
            Bureaucrat wrongZe = Bureaucrat("ze", 220);
            Form form1 = Form("Form1", 123, 123);

            std::cout << form1;
            ze.signForm(form1);
            std::cout << form1;
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
            Bureaucrat ze = Bureaucrat("ze", 120);
            Form form1 = Form("Form1", 123, 123);

            std::cout << form1;
            ze.signForm(form1);
            std::cout << form1;
        }
        catch (std::exception& e)
        {
            std::cout << e.what();
        }
    }
    std::cout << std::endl;
    {
        Bureaucrat ze = Bureaucrat("ze", 120);
        Form form1 = Form("Form1", 10, 123);

        std::cout << form1;
        ze.signForm(form1);
        std::cout << form1;
    }
}