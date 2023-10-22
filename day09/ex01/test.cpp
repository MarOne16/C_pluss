#include <iostream>
#include <string>
#include <vector>


int getValue(const std::string& s, size_t& index) {
    int result = 0;
    while (index < s.size() && isdigit(s[index])) {
        result = result * 10 + (s[index] - '0');
        index++;
    }
    return result;
}

int evaluate(const std::string& s, size_t& index) {
    std::vector<int> numbers;
    std::vector<char> ops;
    while (index < s.size() && s[index] != ')') {
        if (s[index] == ' ') {
            index++;
        } else if (isdigit(s[index])) {
            numbers.push_back(getValue(s, index));
        } else if (s[index] == '(') {
            index++; // skip '('
            numbers.push_back(evaluate(s, index));
        } else {
            ops.push_back(s[index]);
            index++;
        }
    }
    index++; // skip ')'
    int result = numbers[0];
    for (size_t i = 0; i < ops.size(); i++) {
        if (ops[i] == '+') {
            result += numbers[i+1];
        } else if (ops[i] == '-') {
            result -= numbers[i+1];
        } else if (ops[i] == '*') {
            result *= numbers[i+1];
        } else if (ops[i] == '/') {
            result /= numbers[i+1];
        }
    }
    return result;
}

int main() {
    std::string expression = "(1 + (2 * 3))";
    size_t index = 0;
    std::cout << expression << " = " << evaluate(expression, index) << std::endl;
    return 0;
}