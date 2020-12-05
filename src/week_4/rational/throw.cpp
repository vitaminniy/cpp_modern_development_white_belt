#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include <vector>

using namespace std;

class Rational {
public:
  Rational() {
    numerator_ = 0;
    denominator_ = 1;
  }

  Rational(int numerator, int denominator) {
    if (denominator == 0)
      throw invalid_argument("denominator can not be zero");

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
    const int p = numerator_ * other.denominator_;
    const int q = denominator_ * other.numerator_;
    if (q == 0)
      throw domain_error("divide by zero");

    return Rational(p, q);
  }

  bool operator<(const Rational &other) const {
    if (numerator_ < 0 && other.numerator_ >= 0)
      return true;
    else if (numerator_ >= 0 && other.numerator_ < 0)
      return false;

    if (denominator_ == other.denominator_)
      return numerator_ < other.numerator_;

    const auto lcm = std::lcm(denominator_, other.denominator_);
    const auto lhs = lcm / denominator_;
    const auto rhs = lcm / other.denominator_;

    return (lhs * numerator_) < (rhs * other.numerator_);
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
  try {
    Rational r(1, 0);
    cout << "Doesn't throw in case of zero denominator" << endl;
    return 1;
  } catch (invalid_argument &) {
  }

  try {
    auto x = Rational(1, 2) / Rational(0, 1);
    cout << "Doesn't throw in case of division by zero" << endl;
    return 2;
  } catch (domain_error &) {
  }

  cout << "OK" << endl;
  return 0;
}
