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

private:
  int numerator_;
  int denominator_;
};

int main() {
  {
    Rational r1(4, 6);
    Rational r2(2, 3);
    bool equal = r1 == r2;
    if (!equal) {
      cout << "4/6 != 2/3" << endl;
      return 1;
    }
  }

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a + b;
    bool equal = c == Rational(2, 1);
    if (!equal) {
      cout << "2/3 + 4/3 != 2" << endl;
      return 2;
    }
  }

  {
    Rational a(5, 7);
    Rational b(2, 9);
    Rational c = a - b;
    bool equal = c == Rational(31, 63);
    if (!equal) {
      cout << "5/7 - 2/9 != 31/63" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}
