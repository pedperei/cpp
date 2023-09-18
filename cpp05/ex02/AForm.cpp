#include "AForm.hpp"

AForm::AForm():name("Default"),isSigned(false),gradeSign(150),gradeExecute(150){}

AForm::AForm(std::string name, int gradeSign, int gradeExecute):name(name),isSigned(false),gradeSign(gradeSign),gradeExecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& aform):name(aform.name), gradeSign(aform.gradeSign), gradeExecute(aform.gradeExecute)
{
    if (aform.gradeSign < 1 || aform.gradeExecute < 1)
        throw GradeTooHighException();
    else if (aform.gradeSign > 150 || aform.gradeExecute > 150)
        throw GradeTooLowException();
    *this = aform;
}

AForm::~AForm(){}

AForm &AForm::operator=(const AForm& aform)
{
    if(this != &aform)
    {
        this->isSigned = aform.isSigned;
    }
    return (*this);
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeSigned() const
{
    return (this->gradeSign);
}

int AForm::getGradeExecute() const
{
    return (this->gradeExecute);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (this->getIsSigned())
        throw FormAlreadySignedException();
    else if (bureaucrat.getGrade() < this->getGradeSigned())
        this->isSigned = true;
    else
        throw GradeTooLowException();
}


std::ostream& operator<<(std::ostream& out, const AForm& aform)
{
    out << "Name: " << aform.getName() << std::endl << 
        "isSigned: " << aform.getIsSigned() << std::endl <<
        "GradeSign: " << aform.getGradeSigned() << std::endl <<
        "GradeExecute: " << aform.getGradeExecute() << std::endl;
    return out;
}