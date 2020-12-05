#include <iostream>
#include <numeric>
#include <ostream>
#include <sstream>

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
  friend std::ostream &operator<<(std::ostream &, const Rational &);
  friend std::istream &operator>>(std::istream &, Rational &);

  int numerator_;
  int denominator_;
};

std::ostream &operator<<(std::ostream &dst, const Rational &r) {
  dst << r.Numerator() << "/" << r.Denominator();
  return dst;
}

std::istream &operator>>(std::istream &src, Rational &r) {
  int numerator, denominator;
  char c;

  src >> numerator >> c >> denominator;
  if (src && c == '/')
    r = Rational(numerator, denominator);

  return src;
}

int main() {
  {
    ostringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4") {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
      return 1;
    }
  }

  {
    istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal) {
      cout << "5/7 is incorrectly read as " << r << endl;
      return 2;
    }
  }

  {
    istringstream input("");
    Rational r;
    bool correct = !(input >> r);
    if (!correct) {
      cout << "Read from empty stream works incorrectly" << endl;
      return 3;
    }
  }

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2
           << endl;
      return 4;
    }

    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " "
           << r2 << endl;
      return 5;
    }
  }

  {
    istringstream input1("1*2"), input2("1/"), input3("/4");
    Rational r1, r2, r3;
    input1 >> r1;
    input2 >> r2;
    input3 >> r3;
    bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
    if (!correct) {
      cout << "Reading of incorrectly formatted rationals shouldn't change "
              "arguments: "
           << r1 << " " << r2 << " " << r3 << endl;

      return 6;
    }
  }

  cout << "OK" << endl;
  return 0;
}
