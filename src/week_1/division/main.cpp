#include <iostream>

int main() {
	int a;
	int b;

	std::cin >> a >> b;
	if (b == 0) {
		std::cout << "Impossible" << std::endl;
		return 0;
	}

	std::cout << a/b << std::endl;

	return 0;
}
