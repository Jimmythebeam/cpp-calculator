#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

bool ReadNumber(Number& result) {
    if (!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected";
        return 0;
    }
    return 1;
}

bool SaveLoad(const std::string& oper, Number& store, Number& result, bool& was_stored) {
    if (oper == "s") {
        store = result;
        was_stored = true;
        return 1;
    }
    else if (oper == "l") {
        if (!was_stored) {
            std::cerr << "Error: Memory is empty";
            return 0;
        }
        else result = store;
        return 1;
    }
    else return 1;
}

bool RunCalculatorCycle() {
    Number number;
    Number result = 0;
    Number store = 0;
	bool is_stored = false;
    std::string oper;
	std::vector<std::string> valid_token = { "+", "-", "*", "/", "**", "=", ":", "c", "s", "l", "q" };
    ReadNumber(number);
        result += number;
        while (std::cin >> oper) {  
			if (std::find(valid_token.begin(), valid_token.end(), oper) == valid_token.end()) {
                std::cerr << "Error: Unknown token " << oper;
                return 0;
            }
            else if (oper == "q") return 1;
            else if (oper == "=") std::cout << result << std::endl;
            else if (oper == "c") result = 0;
            else if (oper == "s" || oper == "l") {
                if (!SaveLoad(oper, store, result, is_stored)) return 0;
            }
            else {
                if (!ReadNumber(number)) return 0;
                else if (oper == "+") result += number;
                else if (oper == "-") result -= number;
                else if (oper == "*") result *= number;
                else if (oper == "/") result /= number;
                else if (oper == "**") result = std::pow(result, number);
                else if (oper == ":") result = number;             
            }
        }
        return 0;
}
