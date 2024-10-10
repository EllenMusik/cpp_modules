#include "../PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe [num1] [num2] [num3] ..." << std::endl;
        return 1;
    }

    PmergeMe pmm;

    if (!pmm.parsing(argc, argv)) {
        return 1;
    }

    pmm.sorting();
    pmm.printing();

    return 0;
}