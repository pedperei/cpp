#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeSign;
    const int gradeExecute;
public:
    Form();
    Form(std::string name, int gradeSign, int gradeExecute);
    Form(const Form&);
    ~Form();
    Form &operator=(const Form& form);
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeSigned() const;
    int getGradeExecute() const;
    void beSigned(Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade too high");
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Grade too low");
        }
    };
    class FormAlreadySignedException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Form is already signed");
        }
    };
};

std::ostream& operator<<(std::ostream& out, const Form& form);

