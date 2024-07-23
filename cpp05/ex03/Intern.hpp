#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <stdlib.h>
#include <map>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &name, const std::string &target);

    private:
        typedef AForm* (*FormCreator)(const std::string&);
        std::map<std::string, FormCreator> form_creators;
};

#endif
