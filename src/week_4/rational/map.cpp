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
    if (other.numerator_ == 0) {
      return Rational(0, 1);
    }

    return Rational(numerator_ * other.denominator_,
                    denominator_ * other.numerator_);
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
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}
