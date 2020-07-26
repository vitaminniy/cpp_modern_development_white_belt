#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::string OP_NEW_BUS = "NEW_BUS";
const std::string OP_BUSES_FOR_STOP = "BUSES_FOR_STOP";
const std::string OP_STOPS_FOR_BUS = "STOPS_FOR_BUS";
const std::string OP_ALL_BUSES = "ALL_BUSES";

int main() {
  int noperations = 0;
  std::cin >> noperations;

  std::map<std::string, std::vector<std::string>> buses;
  std::map<std::string, std::vector<std::string>> stops;
  for (auto i = 0; i < noperations; ++i) {
    std::string op;
    std::cin >> op;

    if (op == OP_NEW_BUS) {
      std::string bus;
      int nstops = 0;
      std::cin >> bus >> nstops;

      for (auto j = 0; j < nstops; ++j) {
        std::string stop;
        std::cin >> stop;

        buses[bus].push_back(stop);
        stops[stop].push_back(bus);
      }

      continue;
    }

    if (op == OP_BUSES_FOR_STOP) {
      std::string stop;
      std::cin >> stop;

      if (stops.count(stop) == 0) {
        std::cout << "No stop" << std::endl;
        continue;
      }

      for (auto b : stops[stop])
        std::cout << b << " ";
      std::cout << std::endl;

      continue;
    }

    if (op == OP_STOPS_FOR_BUS) {
      std::string bus;
      std::cin >> bus;

      if (buses.count(bus) == 0) {
        std::cout << "No bus" << std::endl;
        continue;
      }

      for (auto const &stop : buses[bus]) {
        auto interbuses = stops[stop];

        std::cout << "Stop " << stop << ": ";
        if (interbuses.size() == 1) {
          std::cout << "no interchange" << std::endl;
          continue;
        }

        for (auto const &b : interbuses) {
          if (b == bus)
            continue;

          std::cout << b << " ";
        }
        std::cout << std::endl;
      }

      continue;
    }

    if (op == OP_ALL_BUSES) {
      if (buses.size() == 0) {
        std::cout << "No buses" << std::endl;
        continue;
      }

      for (auto const &b : buses) {
        std::cout << "Bus " << b.first << ": ";
        for (auto const &stop : b.second)
          std::cout << stop << " ";
        std::cout << std::endl;
      }

      continue;
    }
  }

  return 0;
}
