#include "../Bureaucrat.hpp"

int main() {
    Bureaucrat a("BureaucratA", 1);
    Bureaucrat b("BureaucratB", 150);
    Bureaucrat c(b);
    std::cout << c << std::endl;
    std::cout << b.getName() << std::endl;
    std::cout << b.getGrade() << "\n~~~~~~~~~~" << std::endl;

    try {
        b.incrementGrade();
        std::cout << b.getGrade() << std::endl;
        b.decrementGrade();
        std::cout << b.getGrade() << std::endl;
        b.decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "Try failed because: " << e.what() << std::endl;
    }
    std::cout << "--------\n" << b << "\n--------" << std::endl;

    std::cout << a.getName() << std::endl;
    std::cout << a.getGrade() << "\n~~~~~~~~~~" << std::endl;

    try {
        a.decrementGrade();
        std::cout << a.getGrade() << std::endl;
        a.incrementGrade();
        std::cout << a.getGrade() << std::endl;
        a.incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "Try failed because: " << e.what() << std::endl;
    }
    std::cout << "--------\n" << a <<  "\n--------" << std::endl;

    try {
        Bureaucrat c("BureaucratC", 159);
    }
    catch(const std::exception& e) {
        std::cerr << "can't initalise Bureucrat because: " << e.what() << '\n';
    }
    try {
        Bureaucrat d("BureaucratD", 0);
    }
    catch(const std::exception& e) {
        std::cerr << "can't initalise Bureucrat because: " << e.what() << '\n';
    }
    return 0;
}