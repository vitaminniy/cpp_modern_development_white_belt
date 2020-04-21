#include <iostream>
#include <map>
#include <vector>

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

	std::vector<std::string> result;
	for (int i = 0; i < npairs; i++) {
		std::string a = "", b = "";
		std::cin >> a >> b;

		std::map<char, int> a_chars = BuildCharCounters(a);
		std::map<char, int> b_chars = BuildCharCounters(b);

		if (a_chars == b_chars) {
			result.push_back("YES");
		} else {
			result.push_back("NO");
		}
	}

	for (const auto& i : result) {
		std::cout << i << std::endl;
	}
}
