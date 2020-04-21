#include <iostream>
#include <map>

std::map<char, int> BuildCharCounters(const std::string& s) {
	std::map<char, int> result;
	for (int i = 0; i < s.size(); i++) {
		result[s[i]]++;
	}
	return result;
}

int main() {
	int npairs = 0;
	std::cin >> npairs;

	for (int i = 0; i < npairs; i++) {
		std::string a = "", b = "";
		std::cin >> a >> b;

		std::map<char, int> a_chars = BuildCharCounters(a);
		std::map<char, int> b_chars = BuildCharCounters(b);

		if (a_chars == b_chars) {
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
}
