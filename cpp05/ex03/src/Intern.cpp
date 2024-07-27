#include "../Intern.hpp"

AForm *Intern::makeForm(const std::string &Name, const std::string &target) {
    std::string Names[3] = {
            "shrubbery creation",
            "robotomy request",
            "presidential pardon"
    };

    for (size_t i = 0; i < sizeof(Names) / sizeof(Names[0]); i++) {
        if (Name == Names[i]) {
            std::cout << "Intern creates " << Name << std::endl;
            switch (i) {
                case 0:
                    return (new ShrubberyCreationForm(target));
                case 1:
                    return (new RobotomyRequestForm(target));
                case 2:
                    return (new PresidentialPardonForm(target));
            }
        }
    }
    std::cout << "Intern cannot create " << Name << std::endl;
    return NULL;
}


Intern::Intern() {
}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern &Intern::operator=(const Intern &src) {
    (void)src;
    return *this;
}

Intern::~Intern() {
}
