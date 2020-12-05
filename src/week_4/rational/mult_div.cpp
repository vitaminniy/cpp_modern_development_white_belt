#include <iostream>
#include <numeric>

using namespace std;

class Rational {
public:
  Rational() {
    numerator_ = 0;
    denominator_ = 1;
  }

  Rational(int numerator, int denominator) {
    if (numerator == 0) {
      numerator_ = 0;
      denominator_ = 1;
      return;
    }

    if (denominator < 0) {
      denominator *= -1;
      numerator *= -1;
    }

    const auto div = std::gcd(numerator, denominator);
    numerator_ = numerator / div;
    denominator_ = denominator / div;
  }

  int Numerator() const { return numerator_; }

  int Denominator() const { return denominator_; }

  bool operator==(const Rational &other) const {
    return other.denominator_ == denominator_ && other.numerator_ == numerator_;
  }

  Rational operator+(const Rational &other) const {
    if (denominator_ == other.denominator_) {
      return Rational(numerator_ + other.numerator_, denominator_);
    }

    const auto mult = std::lcm(denominator_, other.denominator_);
    const auto lhs = mult / denominator_;
    const auto rhs = mult / other.denominator_;

    return Rational((numerator_ * lhs) + (other.numerator_ * rhs), mult);
  }

  Rational operator-(const Rational &other) const {
    if (denominator_ == other.denominator_) {
      return Rational(numerator_ - other.numerator_, denominator_);
    }

    const auto mult = std::lcm(denominator_, other.denominator_);
    const auto lhs = mult / denominator_;
    const auto rhs = mult / other.denominator_;

    return Rational((numerator_ * lhs) - (other.numerator_ * rhs), mult);
  }

  Rational operator*(const Rational &other) const {
    return Rational(numerator_ * other.numerator_,
                    denominator_ * other.denominator_);
  }

  Rational operator/(const Rational &other) const {
    if (other.numerator_ == 0) {
      return Rational(0, 1);
    }

    return Rational(numerator_ * other.denominator_,
                    denominator_ * other.numerator_);
  }

private:
  int numerator_;
  int denominator_;
};

int main() {
  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal) {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 1;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    bool equal = c == Rational(2, 3);
    if (!equal) {
      cout << "5/4 / 15/8 != 2/3" << endl;
      return 2;
    }
  }

  cout << "OK" << endl;
  return 0;
}
