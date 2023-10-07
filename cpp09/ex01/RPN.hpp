#pragma once

#include <iostream>
#include <cstdlib>
#include <stack>
#include <limits>
#include <fstream>
#include <algorithm>
#include <exception>
#include <iomanip>
#include <sstream>

class RPN
{
private:
    std::stack<int> rpn_stack;
public:
    RPN();
    RPN(const RPN&);
    ~RPN();
    RPN& operator=(const RPN& rpn);
    int handle_operation(std::string token);
    int parse_input(std::string input);
};
