#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  int noperations = 0;
  std::cin >> noperations;

  int bus_number = 1;
  std::map<std::vector<std::string>, int> bus_numbers;
  for (auto i = 0; i < noperations; ++i) {
    int nstops = 0;
    std::cin >> nstops;

    std::vector<std::string> stops(nstops);
    for (auto j = 0; j < nstops; ++j)
      std::cin >> stops[j];

    if (bus_numbers.count(stops) == 1) {
      std::cout << "Already exists for " << bus_numbers[stops] << std::endl;
      continue;
    }

    std::cout << "New bus " << bus_number << std::endl;
    bus_numbers[stops] = bus_number;
    bus_number++;
  }

  return 0;
}
