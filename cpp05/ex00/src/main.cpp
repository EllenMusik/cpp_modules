#include "../Bureaucrat.hpp"

int main() {
    Bureaucrat b("Bureaucrat", 150);
    std::cout << b.getName() << std::endl;
    std::cout << b.getGrade() << std::endl;
    b.incrementGrade();
    std::cout << b.getGrade() << std::endl;
    b.decrementGrade();
    std::cout << b.getGrade() << std::endl;
    try {
        b.decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}