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
        if (this->_value.length() == 1 && !isdigit(this->_value[0]))
            throw ScalarConverte::ImpossibleExep();
        std::istringstream iss(this->_value);
        int i;
        if (!(iss >> i))
            throw ScalarConverte::ImpossibleExep();
        if (i < 0 || i > 127) {
            throw ScalarConverte::ImpossibleExep();
        }
        if (i < 32 || i == 127) {
            throw ScalarConverte::NonDisplayableExep();
        }
        std::cout << static_cast<char>(i) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverte::printInt() {
    std::cout << "int: ";
    try {
        std::istringstream iss(this->_value);
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
        std::istringstream iss(this->_value);
        double d;
        if (!(iss >> d))
            throw ScalarConverte::ImpossibleExep();
        float f = static_cast<float>(d);
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

