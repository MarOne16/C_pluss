#include "ScalarConverte.hpp"

const char *ScalarConverte::ImpossibleExep::what() const throw() {
    return "impossible";
}

ScalarConverte::ImpossibleExep::ImpossibleExep() {
}

ScalarConverte::ImpossibleExep::ImpossibleExep(ScalarConverte::ImpossibleExep const &src) {
    *this = src;
}

ScalarConverte::ImpossibleExep::~ImpossibleExep() throw() {
    return;
}

ScalarConverte::ImpossibleExep &ScalarConverte::ImpossibleExep::operator=(ScalarConverte::ImpossibleExep const &rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

const char *ScalarConverte::NonDisplayableExep::what() const throw() {
    return "Non displayable";
}

ScalarConverte::NonDisplayableExep::NonDisplayableExep() {
}

ScalarConverte::NonDisplayableExep::NonDisplayableExep(ScalarConverte::NonDisplayableExep const &src) {
    *this = src;
}

ScalarConverte::NonDisplayableExep::~NonDisplayableExep() throw() {
}

ScalarConverte::NonDisplayableExep &ScalarConverte::NonDisplayableExep::operator=(ScalarConverte::NonDisplayableExep const &rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

void ScalarConverte::parse()
{
    for (size_t i = 0; i < this->_value.length(); i++)
    {
        if (this->_value[i] == 'f' && i != this->_value.length() - 1)
            throw ScalarConverte::ImpossibleExep();
        else if (this->_value[i] == 'f' && i == this->_value.length() - 1)
            this->_value.erase(i, 1);
    }
}
