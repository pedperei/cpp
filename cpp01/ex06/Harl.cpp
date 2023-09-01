#include "Harl.hpp"

Harl::Harl()
{
    print_desc[0] = &Harl::debug;
    print_desc[1] = &Harl::info;
    print_desc[2] = &Harl::warning;
    print_desc[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
    std::string instructions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int lvl = 0;

    while (lvl < 5)
    {
        if(instructions[lvl] == level)
            break;
        lvl++;
    }
    
    switch (lvl)
    {
    case 0:
        (this->*print_desc[0])();
    case 1:
        (this->*print_desc[1])();
    case 2:
        (this->*print_desc[2])();
    case 3:
        (this->*print_desc[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

        break;
    }
}