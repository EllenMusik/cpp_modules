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
#include "Header.hpp"

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();

    void readDatabase(const std::string &filename);
    void readInputFile(const std::string &filename);

    bool validateData(int amount);
    bool validateDate(const std::string &date);

    std::map<t_Date, float>::iterator findMatchingDate();

    void calculateAndPrint();


private:
    std::map<t_Date, float> _database;
    t_Date _currentInputDate;

    BitcoinExchange(const BitcoinExchange &source);
    BitcoinExchange &operator=(const BitcoinExchange &source);
};

#endif