#include <exception>
#include <iostream>
#include <numeric>
#include <stdexcept>

class Rational {
public:
  inline Rational() {
    p = 0;
    q = 1;
  }

  Rational(int numerator, int denominator) {
    if (denominator == 0)
      throw std::invalid_argument("denominator can not be zero");

    if (numerator == 0) {
      p = 0;
      q = 1;
      return;
    }

    if (denominator < 0) {
      denominator *= -1;
      numerator *= -1;
    }

    const auto div = std::gcd(numerator, denominator);
    p = numerator / div;
    q = denominator / div;
  }

  inline int Numerator() const { return p; }
  inline int Denominator() const { return q; }

  inline bool operator==(const Rational &other) const {
    return other.q == q && other.p == p;
  }

  inline Rational operator*(const Rational &other) const {
    return Rational(p * other.p, q * other.q);
  }

  Rational operator+(const Rational &other) {
    if (q == other.q)
      return Rational(p + other.p, q);

    const auto lcm = std::lcm(q, other.q);
    return Rational((p * (lcm / q)) + (other.p * (lcm / other.q)), lcm);
  }

  Rational operator-(const Rational &other) {
    if (q == other.q)
      return Rational(p - other.p, q);

    const auto lcm = std::lcm(q, other.q);
    return Rational((p * (lcm / q)) - (other.p * (lcm / other.q)), lcm);
  }

  Rational operator/(const Rational &other) {
    if (other.p == 0)
      throw std::domain_error("divide by zero");

    return Rational(p * other.q, q * other.p);
  }

  bool operator<(const Rational &other) {
    if (q == other.q)
      return p < other.p;

    const auto lcm = std::lcm(q, other.q);
    return p * (lcm / q) < other.p * (lcm / other.q);
  }

private:
  friend std::ostream &operator<<(std::ostream &, const Rational &);
  friend std::istream &operator>>(std::istream &, Rational &);

  int p;
  int q;
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
  Rational r1, r2;
  char op;

  try {
    std::cin >> r1 >> op >> r2;
    switch (op) {
    case '+':
      std::cout << r1 + r2 << std::endl;
      break;
    case '-':
      std::cout << r1 - r2 << std::endl;
      break;
    case '*':
      std::cout << r1 * r2 << std::endl;
      break;
    case '/':
      std::cout << r1 / r2 << std::endl;
      break;
    }

  } catch (std::domain_error &) {
    std::cout << "Division by zero" << std::endl;
  } catch (std::invalid_argument &) {
    std::cout << "Invalid argument" << std::endl;
  }

  return 0;
}
