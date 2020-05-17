#include <iostream>
#include <vector>

int main() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v;

	while(n > 0) {
		v.push_back(n%2);
		n = n/2;
	}

	for(int i = v.size() - 1; i >= 0; --i) {
		std::cout << v[i];
	}
	std::cout << std::endl;

	return 0;
}
