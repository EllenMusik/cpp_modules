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

    AForm *f1 = i.makeForm("presidential pardon", "target");

    b.signForm(*f1);
    b.executeForm(*f1);


    AForm *f2 = i.makeForm("robotomy request", "target");
    b.signForm(*f2);
    b.executeForm(*f2);

    AForm *f3 = i.makeForm("shrubbery creation", "target");
    b.signForm(*f3);
    b.executeForm(*f3);

    AForm *f4 = i.makeForm("unknown", "target");

    return 0;
}