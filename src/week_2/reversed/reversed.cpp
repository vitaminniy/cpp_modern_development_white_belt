#include <vector>

std::vector<int> Reversed(const std::vector<int>& v) {
	std::vector<int> result(v.size());

	int i = 0, j = v.size() - 1;
	for (; j >= 0; j--) {
		result[i] = v[j];
		i++;
	}

	return result;
}

