#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>

namespace {

constexpr const char kOpAddition = '+';
constexpr const char kOpSubstraction = '-';
constexpr const char kOpMultiplication = '*';
constexpr const char kOpDivision = '/';

enum class Op { Addition, Substraction, Multiplication, Division };

constexpr Op char_to_op(char c) {
  switch (c) {
  case kOpAddition:
    return Op::Addition;
  case kOpSubstraction:
    return Op::Substraction;
  case kOpMultiplication:
    return Op::Multiplication;
  case kOpDivision:
    return Op::Division;
  }

  throw std::invalid_argument("unknown operation");
}

struct function_part {
  // applies operation on value.
  constexpr double apply(double value) const;

  // inverts function_part.
  constexpr void invert();

  Op op;
  double v;
};

inline constexpr double function_part::apply(double value) const {
  switch (op) {
  case Op::Addition:
    return value + v;
  case Op::Substraction:
    return value - v;
  case Op::Multiplication:
    return value * v;
  case Op::Division:
    return value / v;
  }
}

inline constexpr void function_part::invert() {
  switch (op) {
  case Op::Addition:
    op = Op::Substraction;
    return;
  case Op::Substraction:
    op = Op::Addition;
    return;
  case Op::Multiplication:
    op = Op::Division;
    return;
  case Op::Division:
    op = Op::Multiplication;
    return;
  }
}
} // namespace

class Function {
public:
  Function() = default;

  void AddPart(char op, double value) {
    parts_.push_back({char_to_op(op), value});
  }

  double Apply(double value) const {
    for (const auto &p : parts_) {
      value = p.apply(value);
    }
    return value;
  }

  void Invert() {
    for (auto &p : parts_) {
      p.invert();
    }

    std::reverse(parts_.begin(), parts_.end());
  }

private:
  std::vector<function_part> parts_;
};
