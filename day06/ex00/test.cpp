#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& input);
};

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

void ScalarConverter::convert(const std::string& input) {
    std::istringstream iss(input);
    char charValue;
    int intValue;
    float floatValue;
    double doubleValue;

    // Attempt to convert to char
    if (iss >> charValue) {
        if (isprint(charValue)) {
            std::cout << "char: '" << charValue << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    // Reset the stream state
    iss.clear();
    iss.seekg(0);

    // Attempt to convert to int
    if (iss >> intValue) {
        std::cout << "int: " << intValue << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

    // Reset the stream state
    iss.clear();
    iss.seekg(0);

    // Attempt to convert to float
    if (iss >> floatValue || (input.back() == 'f' && iss >> std::fixed >> floatValue)) {
        if (std::isnan(floatValue)) {
            std::cout << "float: nanf" << std::endl;
        } else if (std::isinf(floatValue)) {
            std::cout << "float: " << (floatValue < 0 ? "-inff" : "+inff") << std::endl;
        } else {
            std::cout << "float: " << std::setprecision(1) << std::fixed << floatValue << "f" << std::endl;
        }
    } else {
        std::cout << "float: impossible" << std::endl;
    }

    // Reset the stream state
    iss.clear();
    iss.seekg(0);

    // Attempt to convert to double
    if (iss >> std::fixed >> doubleValue) {
        if (std::isnan(doubleValue)) {
            std::cout << "double: nan" << std::endl;
        } else if (std::isinf(doubleValue)) {
            std::cout << "double: " << (doubleValue < 0 ? "-inf" : "+inf") << std::endl;
        } else {
            std::cout << "double: " << std::setprecision(1) << std::fixed << doubleValue << std::endl;
        }
    } else {
        std::cout << "double: impossible" << std::endl;
    }
}

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_literal>" << std::endl;
        return 1;
    }

    std::string input(argv[1]);
    ScalarConverter::convert(input);

    return 0;
}