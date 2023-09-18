#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string, int grade);
        Bureaucrat(const Bureaucrat &);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &bureaucrat);
        std::string getName() const;
        int getGrade() const;
        bool incrementGrade();
        bool decrementGrade();
        void signForm(AForm& form);
        void executeForm(AForm const & form);

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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);


