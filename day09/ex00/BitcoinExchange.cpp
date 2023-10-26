#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char **filename)
{
    lineData = 0;
    std::ifstream Data("data.csv");
    for (int i = 1; filename[i]; i++)
    {
        std::ifstream ifs(filename[i]);
        if (!ifs.is_open())
            throw std::invalid_argument("one of the files not found");
        Files.push_back(filename[i]);
    }
    if (!Data.is_open())
        throw std::invalid_argument("File not found");
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
    std::list<std::string> v = split(key, " ");
    if (v.size() > 2 || !isValidDate(v.front()))
    {
        std::cout << key << " => " << YELLOW" error in date\n"RESET;
        return;
    }
    std::list<std::string> v2 = split(value, " ");
    if (v2.size() >= 2 || !isNumber(v2.front(), 'f'))
    {
        std::cout << key << " => " << value << RED" error in value\n"RESET;
        return;
    }
    std::cout << key << " => " << value << " = " <<  GREEN << getValue(v.front(), v2.front()) << RESET  << std::endl;
}

void BitcoinExchange::parsLine(void)
{
    int i = 1;
    for (std::list<std::string>::iterator it = Files.begin(); it != Files.end(); it++)
    {
        std::ifstream ifs(*it);
        std::string line;
        while (std::getline(ifs, line))
        {
            lineIn++;
            if ((line.length() == 0 || !notIn(line, "data| value")))
                continue;
            size_t pos = line.find("|");
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1,line.length() - pos - 1);
            parsLine2(key, value);
        }
        std::cout << "File " << i << " done" << std::endl;
        i++;
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