#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreation", 145, 137), target("."){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreation", 145, 137), target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm):AForm(shrubberyCreationForm)
{
    *this = shrubberyCreationForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreationForm)
{
    if(this != &shrubberyCreationForm)
    {
        AForm::operator=(shrubberyCreationForm);
        this->target = shrubberyCreationForm.target;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget()
{
    return (this->target);
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream ofile;
    std::string tree = 
    "   a       a   \n"
    "  aaa     aaa  \n"
    " aaaaa   aaaaa \n"
    "aaaaaaa aaaaaaa\n"
    "   a       a   \n"
    "   a       a   \n"
    ;
    if (!this->getIsSigned())
        throw FormNotSignedException();
    else if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooLowException();
    ofile.open((this->target + "_shrubbery").c_str());
    if(!(ofile.is_open()))
        return (false);
    ofile << tree;
    ofile.close();
    return (true);
}

AForm* ShrubberyCreationForm::createNewForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}