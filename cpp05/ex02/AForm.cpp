#include "AForm.hpp"

Form::Form():name("Default"),isSigned(false),gradeSign(150),gradeExecute(150){}

Form::Form(std::string name, int gradeSign, int gradeExecute):name(name),isSigned(false),gradeSign(gradeSign),gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& form):name(form.name), gradeSign(form.gradeSign), gradeExecute(form.gradeExecute)
{
    if (form.gradeSign < 1 || form.gradeExecute < 1)
            throw GradeTooHighException();
        else if (form.gradeSign > 150 || form.gradeExecute > 150)
            throw GradeTooLowException();
}

Form::~Form(){}

Form &Form::operator=(const Form& form)
{
    if(this != &form)
    {
        this->isSigned = form.isSigned;
    }
    return (*this);
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getGradeSigned() const
{
    return (this->gradeSign);
}

int Form::getGradeExecute() const
{
    return (this->gradeExecute);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGradeSigned())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Name: " << form.getName() << std::endl << 
        "isSigned: " << form.getIsSigned() << std::endl <<
        "GradeSign: " << form.getGradeSigned() << std::endl <<
        "GradeExecute: " << form.getGradeExecute() << std::endl;
    return out;
}