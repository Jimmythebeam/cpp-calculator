#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma once

using Number = double;

class Calculator {

public:
    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);

private:
    Number result_ = 0.0;
};

#endif // CALCULATOR_H
