#if !defined(SCALARCONVERTE_HPP)
#define SCALARCONVERTE_HPP

#include <exception>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>


class ScalarConverte
{
private:
    std::string _value;
public:
    ScalarConverte();
    ScalarConverte(std::string const& value);
    ScalarConverte(ScalarConverte const& src);
    ~ScalarConverte();
    ScalarConverte& operator=(ScalarConverte const& rhs);
    void parse();
    void printChar();
    void printInt();
    void printFloat();
    void printDouble();
    class ImpossibleExep : public std::exception
    {
    public:
        ImpossibleExep();
        ImpossibleExep(ImpossibleExep const& src);
        ~ImpossibleExep() throw();
        ImpossibleExep& operator=(ImpossibleExep const& rhs);
        const char* what() const throw();
    };
    class NonDisplayableExep : public std::exception
    {
    public:
        NonDisplayableExep();
        NonDisplayableExep(NonDisplayableExep const& src);
        ~NonDisplayableExep() throw();
        NonDisplayableExep& operator=(NonDisplayableExep const& rhs);
        const char* what() const throw();
    };

};


#endif // ScalarConverte_HPP
