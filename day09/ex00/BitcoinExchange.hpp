#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <limits.h>
#include <cstdlib>
#include <unordered_map>

class BitcoinExchange
{
    private:
    std::multimap<std::string, std::string> mydata;
    std::multimap<std::string, std::string> iLines;
    std::string filename;
    std::string myLine;
    public:
    size_t lineData;
    size_t lineIn;
    typedef std::multimap<std::string, std::string>::iterator iterator;
    BitcoinExchange(std::string filename);
    ~BitcoinExchange();
    void parsLine(std::string line, char d);
    void parsLine2(std::string &key , std::string &value);
    void parsData();
    void printData();
    float getValue(std::string key , std::string value);
};
bool notIn(std::string str, std::string s);
bool isNumber(std::string str);
bool isValidDate(std::string date);
int dateYearNow();