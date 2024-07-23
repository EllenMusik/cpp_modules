#include "../Intern.hpp"

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    std::map<std::string, FormCreator>::iterator tmp = form_creators.find(name);
    if (tmp != form_creators.end())
    {
        std::cout << "Intern creates " << name << " form" << std::endl;
        return tmp->second(target);
    }
    std::cout << "Intern doesn't know how to create " << name << " form" << std::endl;
    return nullptr;
}

//AForm *Intern::makeForm(const std::string &name, const std::string &target) {
//if (name == "presidential pardon") {
//        std::cout << "Intern creates " << name << " form" << std::endl;
//        return new PresidentialPardonForm(target);
//    } else if (name == "robotomy request") {
//        std::cout << "Intern creates " << name << " form" << std::endl;
//        return new RobotomyRequestForm(target);
//    } else if (name == "shrubbery creation") {
//        std::cout << "Intern creates " << name << " form" << std::endl;
//        return new ShrubberyCreationForm(target);
//    }
//    return nullptr;
//}







Intern::Intern() {
    form_creators["presidential pardon"] = PresidentialPardonForm::create;
    form_creators["robotomy request"] = RobotomyRequestForm::create;
    form_creators["shrubbery creation"] = ShrubberyCreationForm::create;
}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}
