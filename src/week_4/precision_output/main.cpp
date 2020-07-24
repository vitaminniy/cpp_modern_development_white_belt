#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main() {
	const int precision = 3;
	const std::string path = "input.txt";

	std::ifstream input(path);
	if (!input.is_open()) {
		std::cout << "file " << path << " not found" << std::endl;
		return 1;
	}

	std::cout << std::fixed << std::setprecision(precision);

	std::string line;
	while(std::getline(input, line)) {
		double d = std::stod(line);
		std::cout << d << std::endl;
	}

	return 0;
}
