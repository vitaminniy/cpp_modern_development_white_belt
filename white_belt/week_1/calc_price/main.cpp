#include <iostream>

int main() {
	float n;
	float a;
	float b;
	float x;
	float y;

	std::cin >> n >> a >> b >> x >> y;
	if (n > b) {
		std::cout << n - ((n * y)/100) << std::endl;
	} else if (n > a) {
		std::cout << n - ((n * x)/100) << std::endl;
	} else {
		std::cout << n << std::endl;
	}

	return 0;
}
