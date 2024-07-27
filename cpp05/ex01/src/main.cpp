#include "../Bureaucrat.hpp"
#include "../Form.hpp"
#include "../colors.hpp"

int main() {
    Bureaucrat b1("Bureaucrat1", 5);
    Form f1("Form1", 4, 4);
    std::cout << PASTEL_PINK << b1 << RST << std::endl;
    std::cout << PASTEL_PINK << f1 << RST << std::endl;
    try {
        f1.beSigned(b1);
    }
    catch (std::exception &e) {
        std::cout << PASTEL_GREEN << e.what() << RST << std::endl;
    }
    b1.incrementGrade();
    std::cout << PINK << b1 << RST << std::endl;
    try {
        f1.beSigned(b1);
    }
    catch (std::exception &e) {
        std::cout << PASTEL_GREEN << e.what() << RST << std::endl;
    }

    Bureaucrat b2("Bureaucrat2", 150);
    Form f2("Form2", 149, 149);
    std::cout << PASTEL_PINK << b2 << RST << std::endl;
    std::cout << PASTEL_PINK << f2 << RST << std::endl;

    b2.signForm(f2);
    b2.incrementGrade();
    std::cout << PINK << b2 << RST << std::endl;
    b2.signForm(f2);

    return 0;
}