#include "../Bureaucrat.hpp"
#include "../Form.hpp"

int main() {
    Bureaucrat b("Bureaucrat", 5);
    Form f("Form", 4, 4);
    std::cout << b << std::endl;
    std::cout << f << std::endl;
    try {
        f.beSigned(b);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    b.incrementGrade();
    //b.incrementGrade();
    try {
        f.beSigned(b);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}