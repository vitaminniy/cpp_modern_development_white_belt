#include <fstream>
#include <iostream>
#include <string>

int main() {
  const std::string fname = "input.txt";

  std::ifstream input(fname);
  if (!input.is_open()) {
    std::cout << "could not open file " << fname << std::endl;
    return 1;
  }

  for (std::string line; std::getline(input, line);) {
    std::cout << line << std::endl;
  }

  input.close();

  return 0;
}
