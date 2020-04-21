#include <iostream>
#include <set>

int main() {
	int nstrings = 0;
	std::cin >> nstrings;

	std::set<std::string> strings;
	for (int i = 0; i < nstrings; i++) {
		std::string s;
		std::cin >> s;

		strings.insert(s);
	}

	std::cout << strings.size() << std::endl;
}
