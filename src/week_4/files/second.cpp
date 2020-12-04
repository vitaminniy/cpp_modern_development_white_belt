#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int main() {
  const std::string ifname = "input.txt";
  const std::string ofname = "output.txt";

  std::ifstream input(ifname);
  if (!input.is_open()) {
    std::cout << "could not open file " << ifname << std::endl;
    return 1;
  }

  std::ofstream output(ofname, std::fstream::out | std::fstream::trunc);
  if (!output.is_open()) {
    std::cout << "could not open output file " << ofname << std::endl;
    return 1;
  }

  for (std::string line; std::getline(input, line);) {
    output << line << std::endl;
  }

  input.close();
  output.close();

  return 0;
}
