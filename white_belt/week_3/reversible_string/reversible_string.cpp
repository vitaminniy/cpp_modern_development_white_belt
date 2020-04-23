#include <algorithm>
#include <string>

class ReversibleString {
	public:
		ReversibleString() = default;
		ReversibleString(const std::string& s) {
			this->s = s;
		}

		void Reverse() {
			std::reverse(this->s.begin(), this->s.end());
		}

		std::string ToString() const {
			return this->s;
		}
	private:
		std::string s;
};
