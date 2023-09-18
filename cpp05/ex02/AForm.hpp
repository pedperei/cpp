#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int gradeSign;
    const int gradeExecute;
public:
    AForm();
    AForm(std::string name, int gradeSign, int gradeExecute);
    AForm(const AForm&);
    virtual ~AForm();
    AForm &operator=(const AForm& aform);
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeSigned() const;
    int getGradeExecute() const;
    void beSigned(Bureaucrat& bureaucrat);
    virtual bool execute(Bureaucrat const & executor) const = 0;

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
    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return ("Form is not signed");
        }
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& aform);

