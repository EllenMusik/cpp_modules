#include "../BitcoinExchange.hpp"
#include "../colors.hpp"


BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

//BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
//{}
//
//BitcoinExchange::BitcoinExchange &operator=(const BitcoinExchange &source)
//{}

void BitcoinExchange::readDatabase(const std::string &filename)
{
    if (!filename.size())
        throw std::runtime_error("Error: invalid filename");
    std::ifstream inputFile;
    inputFile.open(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: could not open file");
    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        std::string date;
        float price;
        std::string temp;
        if (line.find(",") != std::string::npos)
            line.replace(line.find(","), 1, " ");
        std::stringstream stream(line);
        stream >> date >> price;
        //std::cout << LAVENDER << date << ", " << price << RST << std::endl;
        if (stream.fail()){
            std::cerr << RED << "Error: invalid input: " << line << RST << std::endl;
            continue;
        }
        database[date] = price;
    }
}

void BitcoinExchange::readInputFile(const std::string &filename)
{

    if (!filename.size())
        throw std::runtime_error("Error: invalid filename");
    std::ifstream inputFile;
    inputFile.open(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: could not open file");
    std::string line;
    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        std::string date;
        float price;
        std::string temp;
        std::stringstream stream(line);
        stream >> date >> temp >> price;
        std::cout << PINK << date << ", " << price << RST << std::endl;
        if (stream.fail() || temp != "|"){
            std::cerr << RED << "Error: invalid input: " << line << RST << std::endl;
            continue;
        }
        std::cout << CYAN << price << RST << std::endl;
        inputData.insert(std::pair<std::string, float>(date, price));
        for (std::map<std::string, float>::iterator it = inputData.begin(); it != inputData.end(); it++)
        {
            std::cout << GREEN << it->first << ", " << it->second << RST << std::endl;
        }
    }
}

void BitcoinExchange::validateData()
{
    for (std::map<std::string, float>::iterator it = inputData.begin(); it != inputData.end(); it++)
    {
        std::string date = it->first;
        std::cout << YELLOW2 << date << RST << std::endl;
        //std::string temp = date.substr(date.begin(), date.find("-") - date.begin());
        std::string temp = date.substr(0, date.find("-"));
        int year = atoi(temp.c_str());
        std::cout << year << std::endl;
        if (year > 0 && year < 2023)
            std::cout << "year valid" << std::endl;
        else
            std::cout << "year not valid" << std::endl;
    }
}

float BitcoinExchange::findMatchingDate()
{
    return 0;
}

void BitcoinExchange::calculateAndPrint()
{}
