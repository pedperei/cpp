#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default"), grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
    *this = bureaucrat;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this != &bureaucrat)
    {
        this->name = bureaucrat.name;
        if (bureaucrat.grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else if (bureaucrat.grade < 1)
            throw Bureaucrat::GradeTooHighException();
        this->grade = bureaucrat.grade;
    }
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

bool Bureaucrat::incrementGrade()
{
    this->grade--;
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return true;
}

bool Bureaucrat::decrementGrade()
{
    this->grade++;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    return true;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(std::exception& exception)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << 
            " because " << exception.what() << "." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}