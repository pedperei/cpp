#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardon", 25, 5), target("."){}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardon", 25, 5), target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm):AForm(presidentialPardonForm)
{
    *this = presidentialPardonForm;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm)
{
    if(this != &presidentialPardonForm)
    {
        AForm::operator=(presidentialPardonForm);
        this->target = presidentialPardonForm.target;
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget()
{
    return (this->target);
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    std::cout << executor.getName() << " has been pardoned by Zapod Beeblebrox." << std::endl;
    return (true);
}

AForm* PresidentialPardonForm::createNewForm(std::string target)
{
    return new PresidentialPardonForm(target);
}