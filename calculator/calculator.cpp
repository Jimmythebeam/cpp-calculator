#include "calculator.h"
#include <cmath>

void Calculator::Set(Number n) {
    result_ = n;
}

Number Calculator::GetNumber() const {
    return result_;
}

void Calculator::Add(Number n) {
    result_ += n;
}

void Calculator::Sub(Number n) {
    result_ -= n;
}

void Calculator::Div(Number n) {
    result_ /= n;
}

void Calculator::Mul(Number n) {
    result_ *= n;
}

void Calculator::Pow(Number n) {
    result_ = std::pow(result_, n);
}

