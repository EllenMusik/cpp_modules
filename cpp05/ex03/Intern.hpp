#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <stdlib.h>
#include <map>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        ~Intern();

        AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
