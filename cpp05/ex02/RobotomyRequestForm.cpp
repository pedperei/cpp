#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequest", 72, 45),target("."){}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequest", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm):AForm(robotomyRequestForm)
{
    *this = robotomyRequestForm;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm)
{
    if(this != &robotomyRequestForm)
    {
        AForm::operator=(robotomyRequestForm);
        this->target = robotomyRequestForm.target;
    }
    return *this;
}

std::string RobotomyRequestForm::getTarget()
{
    return (this->target);
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    std::cout << "RRRRRRRRRRRRRRRRRRR...";
    std::srand(clock());
    if (std::rand() <  RAND_MAX/2)
    {
        std::cout << this->target << " has been robotomized." << std::endl;
        return (true);
    }
    else
    {
        std::cout << this->target << ": robotomy failed." << std::endl;
        return (false);
    }
}
