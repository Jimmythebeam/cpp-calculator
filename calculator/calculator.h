#pragma once

#include <string>
#include <optional>
#include "rational.h"
#include "pow.h"

using Error = std::string;
template <class Number>
class Calculator {

public:

    void Set(Number n){
        result_ = n;
    }

    Number GetNumber() const{
        return result_;
    }

    bool GetHasMem() const{
        return mem_.has_value();
    }

    void Save(){
         mem_ = result_;
    }

    void Load(){
        result_ = * mem_;
    }

    std::optional<Error> Add(Number n){
        result_ += n;
        return std::nullopt;
    }

    std::optional<Error> Sub(Number n){
        result_ -= n;
        return std::nullopt;
    }

    std::optional<Error> Div(Number n){
        if constexpr (
            std::is_integral_v<Number>      ||
            std::is_same_v<Number,Rational>) {
            if (n == 0) {
                return "Division by zero";
            }
        }
        result_ /= n;
        return std::nullopt;
    }

    std::optional<Error> Mul(Number n){
        result_ *= n;
        return std::nullopt;
    }

    std::optional<Error> Pow(Number n){
        if constexpr (
            std::is_integral_v<Number>) {
            if (n < 0) {
                return "Integer negative power";
            }
            if (result_ == 0 && n == 0) {
                return "Zero power to zero";
            }
            result_ = IntegerPow(result_,n);
            return std::nullopt;
        }
        if constexpr (
            std::is_same_v<Number, Rational>) {
            if (n.GetDenominator() != 1){
                return "Fractional power is not supported";
            }
            if (result_.GetNumerator() == 0 && n.GetNumerator() == 0) {
                return "Zero power to zero";
            }
            result_ = ::Pow(result_,n);
            return std::nullopt;
        }
        if constexpr (
            std::is_floating_point_v<Number>)  {
            result_ = std::pow(result_, n);
            return std::nullopt;
        }
    }

private:
    Number result_ {} ;
    std::optional<Number> mem_;
};
