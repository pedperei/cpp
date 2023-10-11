#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& rpn)
{
    *this = rpn;
}

RPN::~RPN(){}

RPN& RPN::operator=(const RPN& rpn)
{
    if (this != &rpn)
    {
        this->rpn_stack = rpn.rpn_stack;
    }
    return (*this);
}

int RPN::handle_operation(std::string token)
{
    if (this->rpn_stack.size() < 2)
        throw std::runtime_error("Error: Invalid operation");
    int result;
    int n1 = this->rpn_stack.top();
    this->rpn_stack.pop();
    int n2 = this->rpn_stack.top();
    this->rpn_stack.pop();

    if (token == "+")
        result = n2 + n1;
    if (token == "-")
        result = n2 - n1;
    if (token == "*")
        result = n2 * n1;
    if (token == "/")
    {
        if (n1 == 0)
            throw std::runtime_error("Error: Divison by zero");
        result = n2 / n1;
    }    
    this->rpn_stack.push(result);
    
    return (result);
}

int RPN::parse_input(std::string input)
{
    std::stringstream s_input(input);
    std::string token;

    while (s_input >> token)
    {
        if (std::isdigit(token[0]) && token.size() == 1)
            this->rpn_stack.push(std::atoi(token.c_str()));
        else if (std::isdigit(token[1]) && token.size() == 2 && (token[0] == '+' || token[0] == '-'))
            this->rpn_stack.push(std::atoi(token.c_str()));
        else if (token == "+" || token == "-" || token == "*" || token == "/")
            handle_operation(token);
        else
            throw std::runtime_error("Error: Invalid input " + token);
    }
    if (this->rpn_stack.size() != 1)
        throw std::runtime_error("Error: Invalid operation");
    return (this->rpn_stack.top());
}
