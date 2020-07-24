#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
	std::string a, b, c;
	std::cin >> a >> b >> c;

	auto m = std::min(a, b);
	m = std::min(m, c);

	std::cout << m << std::endl;

	return 0;
}
