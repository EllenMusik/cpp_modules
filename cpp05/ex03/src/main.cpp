#include "../Bureaucrat.hpp"
#include "../AForm.hpp"
#include "../ShrubberyCreationForm.hpp"
#include "../PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../colors.hpp"
#include "../Intern.hpp"

int main() {
    Bureaucrat b("b", 1);
    Intern i;

    std::cout << LAVENDER << std::endl;
    AForm *f1 = i.makeForm("presidential pardon", "target");
    std::cout << RST << std::endl;

    b.signForm(*f1);
    b.executeForm(*f1);

    std::cout << LAVENDER << std::endl;
    AForm *f2 = i.makeForm("robotomy request", "target");
    std::cout << RST << std::endl;

    b.signForm(*f2);
    b.executeForm(*f2);

    std::cout << LAVENDER << std::endl;
    AForm *f3 = i.makeForm("shrubbery creation", "target");
    std::cout << RST << std::endl;

    b.signForm(*f3);
    b.executeForm(*f3);

    std::cout << RED << std::endl;
    AForm *f4 = i.makeForm("unknown", "target");
    std::cout << RST << std::endl;

    delete(f1);
    delete(f2);
    delete(f3);

    return 0;
}