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

t_Date convertStringToDate(const std::string &date)
{
    t_Date date_struct;
    date_struct.year = atoi(date.substr(0, 4).c_str());
    date_struct.month = atoi(date.substr(5, 2).c_str());
    date_struct.day = atoi(date.substr(8, 2).c_str());
    return date_struct;
}

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
        t_Date date_struct = convertStringToDate(date);
        _database[date_struct] = price;
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
        std::string temp2;
        std::stringstream stream(line);
        if (stream.fail()){
            std::cerr << RED << "Error: stream failed: " << line << RST << std::endl;
            continue;
        }
        stream >> date >> temp >> price >> temp2;
        if (!temp2.empty() || temp2 != "" || temp != "|"){
            std::cerr << RED << "Error: invalid input: " << line << RST << std::endl;
            continue;
        }
        if (!validateDate(date))
            continue;
        if (!validateData(price))
            continue;
        std::map<t_Date, float>::iterator it = findMatchingDate();
        float result = it->second * price;
        std::cout << PASTEL_GREEN << date << BRIGHT_BLACK << " => " << PASTEL_YELLOW << price << BRIGHT_BLACK << " = " << BRIGHT_ORANGE << result << RST << std::endl;
    }
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::validateDate(const std::string &date)
{
    int year;
    int month;
    int day;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cout << RED << "Error: Wrong date format" << RST << std::endl;
        return false;
    }
    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(5, 2).c_str());
    day = atoi(date.substr(2).c_str());

    if (year < 0 || year > 3000 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    static const int daysInMonth[] = { 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (daysInMonth[month - 1] < day)
        return false;

    _currentInputDate.year = year;
    _currentInputDate.month = month;
    _currentInputDate.day = day;
    return true;
}

bool BitcoinExchange::validateData(int amount)
{
    if (amount < 0) {
        std::cout << RED << "Error: not a positive number: " << amount << RST << std::endl;
        return false;
    }
    return true;
}


bool check_if_date_is_bigger(t_Date data_date, t_Date current_date){
    if ( data_date.year > current_date.year)
        return true;
    if (data_date.year == current_date.year && data_date.month > current_date.month)
        return true;
     if (data_date.year == current_date.year && data_date.month == current_date.month && data_date.day > current_date.day)
        return true;
    return false;
}

//finds the first date that is bigger than the current date, returns the one before to go with the smallest closest one
std::map<t_Date, float>::iterator BitcoinExchange::findMatchingDate()
{
    std::map<t_Date, float>::iterator iterator = _database.begin();
    std::map<t_Date, float>::iterator temp = _database.begin();
    std::map<t_Date, float>::iterator end = _database.end();

    if (iterator == end)
        return end;
    while (iterator != end)
    {
        if (check_if_date_is_bigger(iterator->first, _currentInputDate)) {
            return temp;
        }
        temp = iterator;
        iterator++;
    }
    return temp;
}

void BitcoinExchange::calculateAndPrint()
{}
