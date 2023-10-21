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
    std::string date = key.substr(0, 10);
    if (value.length() > 4)
        value = "error: too large a number.";
    else if (isValidDate(date) == false)
        value = "error: date format";
    else if (!notIn(value, "0123456789.") || !isNumber(value))
        value = "error: value";
    // std::cout << key << " => " << value << std::endl;
        this->iLines.insert(std::pair<std::string, std::string>(key, value));
}

void BitcoinExchange::parsLine(std::string line, char d)
{
    if(d == '|')
    {
        size_t pos = line.find("|");
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1,line.length() - pos - 1);
        parsLine2(key, value);
    }
    else
    {
        size_t pos = line.find(",");
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1,line.length() - pos - 1);
        if (key.length() == 0 || value.length() == 0 || isValidDate(key) == false || !isNumber(value))
        {
            std::cout << "Error in line >" << lineData << "< of data.csv";
            throw std::invalid_argument("");
        }
        this->mydata.insert(std::pair<std::string, std::string>(key, value));
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
        parsLine(line, ',');
    }
    std::ifstream ifs(this->filename);
    while (std::getline(ifs, line))
    {
        
    }
}

float BitcoinExchange::getValue(std::string key, std::string value)
{
    int smalest = INT_MAX;
    int a = 0;
    int b = 0;
    float v = 0;
    iterator smalest_it = this->mydata.begin();
    for ( iterator it = this->mydata.begin(); it != this->mydata.end(); it++)
    {
        std::istringstream ss(it->first);
        std::istringstream ss2(key);
        ss >> a;
        ss2 >> b;
        if ((a - b) == 0)
        {
            v = std::stof(it->second) * std::stof(value);
            return  v;
        }
        if (abs(a - b) < smalest)
        {
            smalest = abs(a - b);
            smalest_it = it;
        }
    }
    v = std::stof(smalest_it->second) * std::stof(value);

    return v;
    
}



void BitcoinExchange::printData()
{
    for (iterator it2 = this->iLines.begin(); it2 != this->iLines.end(); it2++)
    {
        if (notIn(it2->second, "0123456789. "))
            std::cout << it2->first << " => " << it2->second << std::endl;
        else
            std::cout << it2->first << it2->second << " => " << std::fixed << std::setprecision(2) << getValue(it2->first, it2->second) << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2)
            throw std::invalid_argument("Wrong number of arguments");
        BitcoinExchange b(argv[1]);
        b.parsData();
        b.printData();
        // std::cout << b.lineIn << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
