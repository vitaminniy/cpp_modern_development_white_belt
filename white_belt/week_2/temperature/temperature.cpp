#include <iostream>
#include <vector>

int count_average(const std::vector<int>& v) {
	int result = 0;
	
	for (const auto& i : v) {
		result += i;
	}

	result /= v.size();

	return result;
}

std::vector<int> get_above_average_indices(const std::vector<int>& v) {
	int avg = count_average(v);
	std::vector<int> result;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] > avg) {
			result.push_back(i);
		}
	}

	return result;
}

int main() {
	int n = 0;
	std::cin >> n;

	std::vector<int> tempByDays(n);
	for (int i = 0; i < n; i++) {
		std::cin >> tempByDays[i];
	}

	std::vector<int> above_avg_indieces = get_above_average_indices(tempByDays);

	std::cout << above_avg_indieces.size() << std::endl;
	for (const auto& i : above_avg_indieces) {
		std::cout << i << " ";
	}

	std::cout << std::endl;

	return 0;
}
