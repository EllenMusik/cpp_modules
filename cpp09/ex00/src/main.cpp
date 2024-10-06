#include "../BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./bitcoin [input file]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    try
    {
        exchange.readDatabase("data.csv");
        exchange.readInputFile(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

