#pragma once
#include <numeric>
#include <iostream>
#include <cstdint>

class Rational {

public:
    Rational () = default;

    Rational (int num){
        numerator_ = num;
        denominator_ = 1;
    }

    Rational(int num, int den):
        numerator_(num),
        denominator_(den){
        Reduction();
    }

    Rational (const Rational &other){
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
        Reduction();
    }

    int GetNumerator() const{
        return numerator_;
    }

    int GetDenominator() const{
        return denominator_;
    }

    Rational Inv() const{
        return Rational(GetDenominator(), GetNumerator());
    }

    inline Rational operator+(const Rational &other)const{
        int result_num = numerator_ * other.denominator_ + denominator_ * other.numerator_;
        int result_den = denominator_ * other.denominator_;
        return Rational(result_num, result_den);
    }

    inline Rational operator-(const Rational &other)const{
        int result_num = numerator_ * other.denominator_ - denominator_ * other.numerator_;
        int result_den = denominator_ * other.denominator_;
        return Rational(result_num, result_den);
    }

    inline Rational operator*(const Rational &other)const{
        int result_num = numerator_ * other.numerator_;
        int result_den = denominator_ * other.denominator_;
        return Rational(result_num, result_den);
    }

    inline Rational operator/(const Rational &other)const{
        int result_num = numerator_ * other.denominator_;
        int result_den = denominator_ * other.numerator_;
        return Rational(result_num, result_den);
    }

    inline Rational& operator+=(const Rational &other){
        numerator_ = numerator_ * other.denominator_ + denominator_ * other.numerator_;
        denominator_ = denominator_ * other.denominator_;
        Reduction();
        return *this;
    }

    inline Rational& operator-=(const Rational &other){
        numerator_ = numerator_ * other.denominator_ - denominator_ * other.numerator_;
        denominator_ = denominator_ * other.denominator_;
        Reduction();
        return *this;
    }

    inline Rational& operator*=(const Rational &other){
        numerator_ = numerator_ * other.numerator_;
        denominator_ = denominator_ * other.denominator_;
        Reduction();
        return *this;
    }

    inline Rational& operator/=(const Rational &other){
        numerator_ = numerator_ * other.denominator_;
        denominator_ = denominator_ * other.numerator_;
        Reduction();
        return *this;
    }

    inline Rational& operator=(const Rational &other){
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
        Reduction();
        return *this;
    }

    inline friend std::istream& operator>>(std::istream &is, Rational &rational){
        char temp;
        is >> rational.numerator_;
        is >> temp;
        if (is.fail()) {
            is.setstate(std::ios::failbit);
            return is;
        }
        else if (temp != '/') {
            is.unget();
            rational.denominator_ = 1;
            return is;
        }
        else
            is >> rational.denominator_;
        if (rational.denominator_ == 0)
            is.setstate(std::ios::failbit);
        return is;
    }

    inline friend std::ostream& operator<<(std::ostream &os, const Rational &rational){
        os << rational.numerator_;
        if (rational.denominator_ != 1){
            os << " / " << rational.denominator_;
        }
        return os;
    }

    inline auto operator<=>(const Rational &other)const {
        std::int64_t c1 = static_cast<int64_t>(numerator_) * other.denominator_;
        std::int64_t c2 = static_cast<int64_t>(denominator_) * other.numerator_;
        return (c1 <=> c2);
    }

    inline auto operator==(const Rational &other)const {
        std::int64_t c1 = static_cast<int64_t>(numerator_) * other.denominator_;
        std::int64_t c2 = static_cast<int64_t>(denominator_) * other.numerator_;
        return (c1 == c2);
    }

    Rational operator+()const{
        return *this;
    }

    Rational operator-()const{
        return Rational(-numerator_,denominator_);
    }


private:

    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

    int numerator_ = 0;
    int denominator_ = 1;
};
