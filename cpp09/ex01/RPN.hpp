#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stdlib.h>

#include "colors.hpp"

class RPN
{
public:
    RPN();
    ~RPN();
    RPN(const RPN &source);
    RPN &operator=(const RPN &source);

    void calculate(char *str);

private:
    std::stack<int> _stack;
};



#endif