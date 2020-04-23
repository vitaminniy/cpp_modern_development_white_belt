#include <algorithm>
#include <string>
#include <vector>

class SortedStrings {
	public:
		void AddString(const std::string& s) {
			strings.push_back(s);
			std::sort(strings.begin(), strings.end());
		}

		std::vector<std::string> GetSortedStrings() {
			return strings;
		}
	private:
		std::vector<std::string> strings;
};
