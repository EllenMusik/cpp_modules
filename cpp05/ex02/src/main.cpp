#include "../Bureaucrat.hpp"
#include "../AForm.hpp"
#include "../ShrubberyCreationForm.h"
#include "../PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm.hpp"
#include "../colors.hpp"

int main() {
    Bureaucrat president("Obama", 1);
    Bureaucrat worker("worker", 146);
    Bureaucrat boss("boss", 8);
    Bureaucrat Abteilungsleiter("Leiter", 72);
    ShrubberyCreationForm Shrubby("target");
    PresidentialPardonForm Pardon("Pardon");
    RobotomyRequestForm Robotomy("Robot");

    worker.signForm(Shrubby);

    worker.incrementGrade();
    worker.incrementGrade();
    worker.incrementGrade();

    worker.signForm(Shrubby);
    worker.executeForm(Shrubby);
    Abteilungsleiter.executeForm(Shrubby);
    Abteilungsleiter.executeForm(Shrubby);
    std::cout << "-------------------" << std::endl;
    try {
    Robotomy.beSigned(Abteilungsleiter);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    Abteilungsleiter.incrementGrade();
    Abteilungsleiter.signForm(Robotomy);
    Abteilungsleiter.executeForm(Robotomy);
    boss.executeForm(Robotomy);
    std::cout << "-------------------" << std::endl;
    boss.signForm(Pardon);

    president.signForm(Pardon);
    president.executeForm(Pardon);

    return 0;
}