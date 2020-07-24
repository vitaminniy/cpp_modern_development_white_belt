#include <iostream>
#include <iterator>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	int n_occurrences = 0;
	const char target = 'f';
	for (auto i = 0; i < s.length(); ++i) {
		if (s[i] == target)
			++n_occurrences;

		if (n_occurrences >= 2) {
			std::cout << i << std::endl;
			return 0;
		}
	}

	int result = -2;
	if (n_occurrences == 1)
		result = -1;

	std::cout << result << std::endl;

	return 0;
}
