#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();

    void readDatabase(const std::string &filename);
    void readInputFile(const std::string &filename);

    void validateData();

    float findMatchingDate();

    void calculateAndPrint();


private:
    std::map<std::string, float> database;
    std::map<std::string, float> inputData;

    BitcoinExchange(const BitcoinExchange &source);
    BitcoinExchange &operator=(const BitcoinExchange &source);
};

#endif