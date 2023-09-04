#pragma once

#include <iostream>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void (Harl::*print_desc[4])();

    public:
    Harl();
    ~Harl();
    void complain(std::string level);
};
