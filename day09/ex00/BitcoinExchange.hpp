#pragma once

//colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define BLUE   "\033[34m"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <limits.h>
#include <cstdlib>
#include <unordered_map>

class BitcoinExchange
{
    private:
    std::map<std::string, float> mydata;
    std::string filename;
    std::list<std::string> Files;
    std::string myLine;
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    public:
    size_t lineData;
    size_t lineIn;
    typedef std::map<std::string, float>::iterator iterator;
    BitcoinExchange(const char **filename);
    ~BitcoinExchange();
    void parsLine(void);
    void parsLine2(std::string &key , std::string &value);
    void parsData();
    float getValue(std::string key , std::string value);
};
//tools.cpp
bool notIn(std::string str, std::string s);
bool isNumber(std::string str, char type);
bool isValidDate(std::string date);
int dateYearNow();
std::list<std::string> split(const std::string& str, const std::string& delimiter);
float sToFloat(std::string str);