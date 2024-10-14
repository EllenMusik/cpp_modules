#include "../PmergeMe.hpp"

bool is_all_num(char *str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        if (isdigit(str[i]) == false) {
            return false;
        }
    }
    return true;
}

bool hasDuplicates(const std::vector<int>& vec) {
    std::vector <int> seen;
    for (size_t i = 0; i < vec.size(); ++i){
        if (std::find(seen.begin(), seen.end(), vec[i]) != seen.end()) {
            return true;
        }
        seen.push_back(vec[i]);
    }
    return false;
}

bool PmergeMe::parsing(int argc, char **argv) {
    std::cout << LAVENDER << "\nBefore sorting:" << RST << std::endl;

    for (int i = 1; i < argc; ++i) {
        if (!is_all_num(argv[i])) {
            std::cerr << "Error: Argument " << i << "(" << argv[i] << ") is not a number" << std::endl;
            return false;
        }
        int num = atoi(argv[i]);
        std::cout << num << " ";
        _size++;
        _arrVec.push_back(num);
        _arrDeq.push_back(num);
        _compareVec.push_back(num);
    }
    std::cout << std::endl;
    if (hasDuplicates(_arrVec)) {
        std::cerr << RED << "Error: Duplicate numbers are not allowed" << RST << std::endl;
        return false;
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

    _jacobSeq = generateJacobsthal(22);
//    std::cout << _jacobSeq.size() << std::endl;
//    for (size_t i = 0; _jacobSeq.size() > i; ++i) {
//        std::cout << _jacobSeq[i] << ", ";
//    }

    clock_t start = clock();
    fordJohnsonSortVector(_arrVec);  // Vector sorting
    clock_t end = clock();

    _vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;  // Time calculation for Vector

    std::cout << PASTEL_BLUE << "After sorting Vector: " << RST << std::endl;
    for (size_t i = 0; i < _arrVec.size(); ++i) {
        std::cout << _arrVec[i] << " ";
    }
    std::cout << "\n" << std::endl;

    start = clock();
    fordJohnsonSortDeque(_arrDeq); // Deque sorting
    end = clock();

    _dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;  // Time calculation for Deque


    start = clock();
    std::sort(_compareVec.begin(), _compareVec.end());
    end = clock();
    _compareTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;  // Time calculation for std::sort
    std::cout << TURQUOISE << "After sorting Deque: " << RST << std::endl;
    for (size_t i = 0; i < _arrDeq.size(); ++i) {
        std::cout << _arrDeq[i] << " ";
    }
    std::cout << "\n" << std::endl;
}

void PmergeMe::printing() {
    std::cout << PINK << "Time to process a range of " << _size << " Elements with " << PASTEL_PINK << "std::vector: " << _vectorTime << "s" << RST << std::endl;
    std::cout << ORANGE << "Time to process a range of " << _size << " Elements with " << BRIGHT_ORANGE << "std::deque:  " << _dequeTime << "s" << RST << std::endl;
    std::cout << TEAL << "Time to process a range of " << _size << " Elements with " << PASTEL_BLUE << "std::sort:   " << _compareTime << "s" << RST << std::endl;
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

template <typename Container>
void binary_insert_numbers(Container &sorted, int num) {
    if (sorted.empty()) {
        sorted.push_back(num);
        return;
    }

    typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), num);
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

    // Step 2: sorting the higher number of each Pair into a sorted-pair vector
    std::vector<std::pair<int, int> > sorted_pairs;
    for (size_t i = 0; i < pairs.size(); ++i) {
        binary_insert_pairs(sorted_pairs, pairs[i]);
    }

    // pushing the (higher) numbers into a normal vector
    std::vector<int> sorted;
    sorted.push_back(sorted_pairs[0].second);
    for (size_t i = 0; i < sorted_pairs.size(); ++i) {
        sorted.push_back(sorted_pairs[i].first);
    }

    //inserting the lower number of each pair into the sorted (normal) vector, in the order of jacobsthal sequence
    size_t i;
    binary_insert_numbers(sorted, sorted_pairs[1].second);  //new: inserting the number at [1]
    for (i = 2; _jacobSeq[i] < _size / 2; ++i) {
        for (int f = _jacobSeq[i]; f > _jacobSeq[i - 1]; --f) {
            binary_insert_numbers(sorted, sorted_pairs[f].second);
        }
    }
    //inserting the rest above the jacobsthal sequence last fitting number
    for (i = _jacobSeq[i - 1] + 1; i < sorted_pairs.size(); ++i) {  //new: + 1 so no double numbers
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
    binary_insert_numbers(sorted, sorted_pairs[1].second);
    for (i = 2; _jacobSeq[i] < _size / 2; ++i) {
        for (int f = _jacobSeq[i]; f > _jacobSeq[i - 1]; --f) {
            binary_insert_numbers(sorted, sorted_pairs[f].second);
        }
    }
    //inserting the rest above the jacobsthal sequence last fitting number
    for (i = _jacobSeq[i - 1] + 1; i < sorted_pairs.size(); ++i) {
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
    _arrDeq = sorted;

}

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
