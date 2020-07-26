#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
  int noperations = 0;
  std::cin >> noperations;

  int bus_number = 1;
  std::map<std::set<std::string>, int> bus_numbers;
  for (auto i = 0; i < noperations; ++i) {
    int nstops = 0;
    std::cin >> nstops;

    std::set<std::string> stops;
    for (auto j = 0; j < nstops; ++j) {
      std::string stop;
      std::cin >> stop;
      stops.insert(stop);
    }

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
