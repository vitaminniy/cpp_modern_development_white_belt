#include <iostream>

bool IsPalindrom(std::string s) {
	if (s.empty()) {
		return true;
	}

	int i = 0;
	int j = s.size() - 1;
	for (; i < j; ) {
		if (s.at(i) != s.at(j)) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}
