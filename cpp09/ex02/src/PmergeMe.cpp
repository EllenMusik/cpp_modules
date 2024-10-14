#include "../PmergeMe.hpp"

bool is_all_num(char *str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        if (isdigit(str[i]) == false) {
            return false;
        }
    }
    return true;
}

bool PmergeMe::parsing(int argc, char **argv) {
    std::cout << "Before sorting: ";

    for (int i = 1; i < argc; ++i) {
        if (!is_all_num(argv[i])) {
            std::cerr << "Error: Argument " << i << "(" << argv[i] << ") is not a number" << std::endl;
            return false;
        }
        int num = atoi(argv[i]);
        std::cout << num << ", ";
        _size++;
        _arrVec.push_back(num);
        _arrDeq.push_back(num);
    }
    std::cout << std::endl;
    return true;
}

std::vector<double> generateJacobsthal(int n) {
    std::vector<double> jacobsthal(n);
    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;

    for (int i = 2; i < n; ++i) {
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
    }

    return jacobsthal;
}

void PmergeMe::sorting() {

    std::cout << "jakobsthal sequenz: " << std::endl;
    _jacobSeq = generateJacobsthal(_arrVec.size() / 2);
    std::cout << _jacobSeq.size() << std::endl;
    for (size_t i = 0; _jacobSeq.size() > i; ++i) {
        std::cout << _jacobSeq[i] << ", ";
    }

    clock_t start = clock();
    fordJohnsonSortVector(_arrVec);  // Vector sorting
    clock_t end = clock();

    _vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;  // Time calculation for Vector
    std::cout << _vectorTime;

    std::cout << "After sorting Vector: " << std::endl;
    for (size_t i = 0; i < _arrVec.size(); ++i) {
        std::cout << _arrVec[i] << " ";
    }
    std::cout << std::endl;

    start = clock();
    fordJohnsonSortDeque(_arrDeq); // Deque sorting
    end = clock();

    _dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;  // Time calculation for Deque

    std::cout << "After sorting Deque: " << std::endl;
    for (size_t i = 0; i < _arrDeq.size(); ++i) {
        std::cout << _arrDeq[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printing() {
    std::cout << "Time to process a range of " << _size << " Elements with std::vector: " << _vectorTime << "s" << std::endl;
    std::cout << "Time to process a range of " << _size << " Elements with std::deque:  " << _dequeTime << "s" << std::endl;
}

template <typename Container>
void binary_insert_pairs(Container &sorted_pairs, typename Container::value_type pair) {
    if (sorted_pairs.empty()) {
        sorted_pairs.push_back(pair);
        return;
    }

    typename Container::iterator it = std::lower_bound(sorted_pairs.begin(), sorted_pairs.end(), pair);
    sorted_pairs.insert(it, pair);
}

//void binary_insert_pairs(std::vector<std::pair<int, int> > &sorted_pairs, std::pair<int, int> pair) {
//    if (sorted_pairs.empty()) {
//        sorted_pairs.push_back(pair);
//        return;
//    }
//
//    std::vector<std::pair<int, int> >::iterator it = std::lower_bound(sorted_pairs.begin(), sorted_pairs.end(), pair);
//    sorted_pairs.insert(it, pair);
//}
//
//void binary_insert_pairs_deque(std::deque<std::pair<int, int> > &sorted_pairs, std::pair<int, int> pair) {
//    if (sorted_pairs.empty()) {
//        sorted_pairs.push_back(pair);
//        return;
//    }
//    std::deque<std::pair<int, int> >::iterator it = std::lower_bound(sorted_pairs.begin(), sorted_pairs.end(), pair);
//    sorted_pairs.insert(it, pair);
//}

void binary_insert_numbers(std::vector<int> &sorted, int num) {
    if (sorted.empty()) {
        sorted.push_back(num);
        return;
    }

    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), num);
    sorted.insert(it, num);
}

void binary_insert_numbers_deque(std::deque<int> &sorted, int num) {
    if (sorted.empty()) {
        sorted.push_back(num);
        return;
    }

    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), num);
    sorted.insert(it, num);
}


void PmergeMe::fordJohnsonSortVector(std::vector<int> &arr) {
    if (arr.size() <= 1) return;

    // Step 1: Initial Pairing
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]); // Swap if not in order
        pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // Step 2: sorting the higher number of each Pair into a pair vector
    std::vector<std::pair<int, int> > sorted_pairs;
    for (size_t i = 0; i < pairs.size(); ++i) {
        binary_insert_pairs(sorted_pairs, pairs[i]);
    }

    // pushing the numbers into a normal vector
    std::vector<int> sorted;
    sorted.push_back(sorted_pairs[0].second);
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        sorted.push_back(sorted_pairs[i].first);
    }

    //inserting the lower number of each pair into the sorted vector is the order of jacobsthal sequence
    size_t i;
    for (i = 2; _jacobSeq[i] < _size / 2; ++i) {
        for (int f = _jacobSeq[i]; f < _jacobSeq[i - 1]; --f) {
            binary_insert_numbers(sorted, sorted_pairs[f].second);
        }
    }
    //inserting the rest above the jacobsthal sequence last fitting number
    for (i = _jacobSeq[i - 1]; i < sorted_pairs.size(); ++i) {
        binary_insert_numbers(sorted, sorted_pairs[i].second);
    }

        //simple binary insert for the rest of the numbers
//    for (size_t i = 1; i < sorted_pairs.size(); ++i) {
//        binary_insert_numbers(sorted, sorted_pairs[i].second);
//    }

    if (arr.size() % 2 != 0) {
        binary_insert_numbers(sorted, arr[arr.size() - 1]);
    }
    // Copy back to original array
    _arrVec = sorted;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    // Step 1: Initial Pairing
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]); // Swap if not in order
        pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // Step 2: sorting the higher number of each Pair into a pair vector
    std::deque<std::pair<int, int> > sorted_pairs;
    for (size_t i = 0; i < pairs.size(); ++i) {
        binary_insert_pairs(sorted_pairs, pairs[i]);
    }

    // pushing the numbers into a normal vector
    std::deque<int> sorted;
    sorted.push_back(sorted_pairs[0].second);
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        sorted.push_back(sorted_pairs[i].first);
    }

    //inserting the lower number of each pair into the sorted vector is the order of jacobsthal sequence
    size_t i;
    for (i = 2; _jacobSeq[i] < _size / 2; ++i) {
        for (int f = _jacobSeq[i]; f < _jacobSeq[i - 1]; --f) {
            binary_insert_numbers_deque(sorted, sorted_pairs[f].second);
        }
    }
    //inserting the rest above the jacobsthal sequence last fitting number
    for (i = _jacobSeq[i - 1]; i < sorted_pairs.size(); ++i) {
        binary_insert_numbers_deque(sorted, sorted_pairs[i].second);
    }

    //simple binary insert for the rest of the numbers
//    for (size_t i = 1; i < sorted_pairs.size(); ++i) {
//        binary_insert_numbers(sorted, sorted_pairs[i].second);
//    }

    if (arr.size() % 2 != 0) {
        binary_insert_numbers_deque(sorted, arr[arr.size() - 1]);
    }
    // Copy back to original array
    _arrDeq = sorted;

}


//void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
//    if (arr.size() <= 1) return;
//
//    // Step 1: Initial Pairing
//    std::deque<int> pairs;
//    for (size_t i = 0; i < arr.size() - 1; i += 2) {
//        if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
//        pairs.push_back(arr[i]);
//        pairs.push_back(arr[i + 1]);
//    }
//    if (arr.size() % 2 != 0) {
//        pairs.push_back(arr.back());
//    }
//
//    // Step 2: Merging Pairs
//    std::deque<int> sorted;
//    for (size_t i = 0; i < pairs.size(); i += 2) {
//        sorted.push_back(pairs[i]);
//    }
//    for (size_t i = 1; i < pairs.size(); i += 2) {
//        sorted.push_back(pairs[i]);
//    }
//    std::sort(sorted.begin(), sorted.end());
//
//    // Step 3: Insertion Phase
//    for (size_t i = pairs.size(); i < arr.size(); ++i) {
//        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), arr[i]);
//        sorted.insert(pos, arr[i]);
//    }
//
//    // Copy back to original array
//    _arrDeq = sorted;
//}




PmergeMe::PmergeMe() : _size(0), _vectorTime(0), _dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &source) {
    *this = source;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source) {
    if (this == &source) return *this;

    _arrVec = source._arrVec;
    _arrDeq = source._arrDeq;
    _size = source._size;
    _vectorTime = source._vectorTime;
    _dequeTime = source._dequeTime;

    return *this;
}

PmergeMe::~PmergeMe() {}
