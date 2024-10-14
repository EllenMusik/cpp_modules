#include "../RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &source)
{
    *this = source;
}

RPN &RPN::operator=(const RPN &source)
{
    if (this == &source)
        return *this;
    _stack = source._stack;
    return *this;
}

void RPN::calculate(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            std::cout << TEAL << "Pushing: " << TURQUOISE << str[i] - '0' << RST << std::endl;
            _stack.push(str[i] - '0');
        }
        else if (str[i] == '+' && _stack.size() > 1)
        {
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            std::cout << YELLOW << "Adding: " << PASTEL_YELLOW << b << " + " << a << RST << std::endl;
            _stack.push(b + a);
            std::cout << BLUE << "Pushing: " << PASTEL_BLUE << b + a << RST << std::endl;
        }
        else if (str[i] == '-' && _stack.size() > 1)
        {
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            std::cout << YELLOW << "Subtracting: " << PASTEL_YELLOW << b << " - " << a << RST << std::endl;
            _stack.push(b - a);
            std::cout << BLUE << "Pushing: " << PASTEL_BLUE << b - a << RST << std::endl;
        }
        else if (str[i] == '*' && _stack.size() > 1)
        {
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            std::cout << YELLOW << "Multiplying: " << PASTEL_YELLOW << b << " * " << a << RST << std::endl;
            _stack.push(b * a);
            std::cout << BLUE << "Pushing: " << PASTEL_BLUE << b * a << RST << std::endl;
        }
        else if (str[i] == '/' && _stack.size() > 1 && _stack.top() != 0)
        {
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            std::cout << YELLOW << "Dividing: " << PASTEL_YELLOW << b << " / " << a << RST << std::endl;
            _stack.push(b / a);
            std::cout << BLUE << "Pushing: " << PASTEL_BLUE << b / a << RST << std::endl;
        }
        else
        {
            std::cout << RED << "Error: Invalid character: " << PASTEL_RED << str[i] << RST << std::endl;
            return;
        }

        i++;
        if (str[i] == ' ')
        {
            while (str[i] == ' ')
                i++;
        }
        else if (str[i] == '\0')
            break;
        else
        {
            std::cout << RED << "Error: Invalid character: a Space is needed: " << PASTEL_RED << str[i] << RST << std::endl;
            return;
        }
    }
    if (_stack.size() != 1)
    {
        std::cout << RED << "Error: Invalid expression (amount)" << RST << std::endl;
        return;
    }
    std::cout << GREEN << "Result: " << PASTEL_GREEN << _stack.top() << RST << std::endl;
}