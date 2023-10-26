#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    try
    {
        if (argc < 2)
            throw std::invalid_argument("Wrong number of arguments");
        BitcoinExchange b(argv);
        std::cout << MAGENTA "////////////////////////////////////////////////////////\n";
        std::cout <<  "////////////////// Bitcoin Exchange ////////////////////\n";
        std::cout <<  "// The value must be a positive and low than 1000-BTC //\n";
        std::cout <<  "// The date must be between 1970 and the current year //\n";
        std::cout <<  "////////////////////////////////////////////////////////\n"RESET;
        b.parsData();
        b.parsLine();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
