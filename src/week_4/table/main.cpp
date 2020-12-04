#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
  std::ifstream input("input.txt");
  if (!input.is_open()) {
    std::cout << "could not open input file" << std::endl;
    return 1;
  }

  int rows, columns, n;
  input >> rows >> columns;
  input.ignore();

  for (auto i = 0; i < rows; i++) {
    for (auto j = 0; j < columns; j++) {
      input >> n;
      input.ignore();

      std::cout << std::setw(10) << n;
      if (j < columns - 1)
        std::cout << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
