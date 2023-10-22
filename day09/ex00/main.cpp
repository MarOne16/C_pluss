#include "BitcoinExchange.hpp"

// void printmap(std::map<std::string, std::string> &m)
// {
//     for (BitcoinExchange::iterator it = m.begin(); it != m.end(); it++)
//     {
//         std::cout << it->first << " => " << it->second << std::endl;
//     }
// }

BitcoinExchange::BitcoinExchange(std::string filename)
{
    lineData = 0;
    std::ifstream ifs(filename);
    std::ifstream Data("data.csv");
    if (!ifs.is_open() || !Data.is_open())
        throw std::invalid_argument("File not found");
    this->filename = filename;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::parsLine2(std::string &key, std::string &value)
{
    if(key.find("|") != std::string::npos || value.find("|") != std::string::npos)
    {
        std::cout << key << " => " << value << BLUE" error in input syntax\n"RESET;
        return;
    }
    std::vector<std::string> v = split(key, " ");
    if (v.size() > 2 || !isValidDate(v[0]))
    {
        std::cout << key << " => " << YELLOW" error in date\n"RESET;
        return;
    }
    std::vector<std::string> v2 = split(value, " ");
    if (v2.size() > 2 || !isNumber(v2[0], 'f'))
    {
        std::cout << key << " => " << value << RED" error in value\n"RESET;
        return;
    }
    std::cout << key << " => " << value << " = " <<  GREEN << getValue(v[0], v2[0]) << RESET  << std::endl;
}

void BitcoinExchange::parsLine(void)
{
    std::ifstream ifs(this->filename);
    std::string line;
    while (std::getline(ifs, line))
    {
        if ((line.length() == 0 || !notIn(line, "data| value")))
            continue;
        size_t pos = line.find("|");
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1,line.length() - pos - 1);
        parsLine2(key, value);
    }
}

void BitcoinExchange::parsData()
{
    std::string line;
    std::ifstream Data("data.csv");
    while (std::getline(Data, line))
    {
        lineData++;
        if (line.length() == 0 || line =="date,exchange_rate")
            continue;
        size_t pos = line.find(",");
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1,line.length() - pos - 1);
        if (key.length() == 0 || value.length() == 0 || isValidDate(key) == false || !isNumber(value, 'D'))
        {
            std::cout << "Error in line >" << lineData << "< of data.csv";
            throw std::invalid_argument("");
        }
        this->mydata[key] = sToFloat(value);
    }
}

float BitcoinExchange::getValue(std::string key, std::string value)
{
    iterator smalest_it = this->mydata.begin();
    for ( iterator it = this->mydata.begin(); it != this->mydata.end(); it++)
    {
        if (it->first == key)
            return (sToFloat(value) * it->second);
        else if (it->first < key && it->first > smalest_it->first)
            smalest_it = it;
    }
    return (smalest_it->second * sToFloat(value));
    
}

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2)
            throw std::invalid_argument("Wrong number of arguments");
        BitcoinExchange b(argv[1]);
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
