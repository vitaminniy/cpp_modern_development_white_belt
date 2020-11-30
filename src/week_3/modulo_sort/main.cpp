#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

bool less(int i, int j) { return (std::abs(i) < std::abs(j)); }

int main() {
  int n;
  std::cin >> n;

  if (n <= 0)
    return 0;

  std::vector<int> numbers;
  numbers.reserve(n);

  for (auto i = 0; i < n; i++) {
    int v;
    std::cin >> v;
    numbers.push_back(v);
  }

  std::sort(numbers.begin(), numbers.end(), less);
  for (auto it = numbers.begin(); it != numbers.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
  return 0;
}
