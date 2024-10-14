#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

#include <algorithm>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cstring>

#include "colors.hpp"

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe &source);
    PmergeMe &operator=(const PmergeMe &source);
    ~PmergeMe();

    bool parsing(int argc, char **argv);

    void fordJohnsonSortVector(std::vector<int>& arr);
    void fordJohnsonSortDeque(std::deque<int>& arr);

    void sorting();
    void printing();

private:
    std::vector<int> _arrVec;
    std::deque<int> _arrDeq;
    std::vector<int> _compareVec;

    std::vector<double> _jacobSeq;
    int _size;

    double _vectorTime;
    double _dequeTime;
};


#endif