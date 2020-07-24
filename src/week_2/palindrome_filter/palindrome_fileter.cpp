#include <vector>
#include <string>

bool is_palindrom(const std::string& s) {
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

std::vector<std::string> PalindromFilter(const std::vector<std::string>& words,
										 int min_length) {
	std::vector<std::string> result;
	for (const auto& w : words) {
		if (w.size() < min_length) {
			continue;
		}

		if (!is_palindrom(w)) {
			continue;
		}

		result.push_back(w);
	}

	return result;
}
