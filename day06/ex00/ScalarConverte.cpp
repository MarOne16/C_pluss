#include "ScalarConverte.hpp"
#include <iomanip>
ScalarConverte::ScalarConverte() {
    return;
}

ScalarConverte::ScalarConverte(std::string const &value) : _value(value) {
    return;
}

ScalarConverte::ScalarConverte(ScalarConverte const &src) {
    *this = src;
    return;
}

ScalarConverte::~ScalarConverte()
{
    return;
}

ScalarConverte &ScalarConverte::operator=(ScalarConverte const &rhs) {
    if (this != &rhs) {
        this->_value = rhs._value;
    }
    return *this;
}

void ScalarConverte::printChar() {
    std::cout << "char: ";
    try {
        if (this->_value == "inf" || this->_value == "+inf"  || this->_value == "-inf")
            throw ScalarConverte::NonDisplayableExep();
        std::istringstream iss(this->_value);
        int i;
        if (!(iss >> i))
            throw ScalarConverte::ImpossibleExep();
        if (i < 0 || i > 127) {
            throw ScalarConverte::NonDisplayableExep();
        }
        if (i < 32 || i == 127) {
            throw ScalarConverte::NonDisplayableExep();
        }
        std::cout << "\'" << static_cast<char>(i) << "\'" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverte::printInt() {
    std::cout << "int: ";
    try {
        std::string tmp = this->_value;
        if (tmp == "inf" || tmp == "+inf")
            tmp = "2147483647";
        else if (tmp == "-inf")
            tmp = "-2147483648";
        std::istringstream iss(tmp);
        int i;
        if (!(iss >> i))
            throw ScalarConverte::ImpossibleExep();
        if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
            throw ScalarConverte::ImpossibleExep();
        }
        std::cout << i << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}


void ScalarConverte::printFloat() {
    std::cout << "float: ";
    try {
        this->parse();
        std::string tmp = this->_value;
        if (tmp == "in" || tmp == "+in")
        {
            std::cout << "inff" << std::endl;
            return;
        }
        else if (tmp == "-in")
        {
            std::cout << "-inff" << std::endl;
            return;
        }
        std::istringstream iss(tmp);
        float f;
        if (!(iss >> f))
            throw ScalarConverte::ImpossibleExep();
        std::cout << std::setprecision(1) << std::fixed << f << "f" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverte::printDouble()
{
    std::cout << "double: ";
    try {
        this->parse();
        std::string tmp = this->_value;
        if (tmp == "in" || tmp == "+in")
        {
            std::cout << "inf" << std::endl;
            return;
        }
        else if (tmp == "-in")
        {
            std::cout << "-inf" << std::endl;
            return;
        }
        std::istringstream iss(this->_value);
        double d;
        if (!(iss >> d))
            throw ScalarConverte::ImpossibleExep();
        std::cout << std::setprecision(1) << std::fixed << d << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

