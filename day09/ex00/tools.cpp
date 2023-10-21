#include "BitcoinExchange.hpp"

int dateYearNow()
{
    time_t now = time(0);
    tm *local = localtime(&now);
    return local->tm_year + 1900;
}

bool isNumber(std::string str)
{
    std::istringstream ss(str);
    double num;
    ss >> num;
    if (num < 0)
        return false;
    return !ss.fail() && ss.eof();
}

bool notIn(std::string str, std::string s)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (s.find(str[i]) == std::string::npos)
            return true;
    }
    return false;
}

bool isValidDate(std::string date)
{
    if (date.length() != 10)
        return false;
    if (notIn(date, "0123456789- "))
        return false;
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (notIn(year, "0123456789") || notIn(month, "0123456789") || notIn(day, "0123456789"))
        return false;
    int y = atoi(year.c_str());
    int m = atoi(month.c_str());
    int d = atoi(day.c_str());
    if (y < 1970 || y > dateYearNow())
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31 || (m == 2 && d > 28) || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30))
        return false;
    return true;
}