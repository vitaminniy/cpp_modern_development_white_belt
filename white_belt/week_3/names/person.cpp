#include <map>
#include <string>

class Person {
public:
	void ChangeFirstName(int year, const std::string& first_name) {
		if (first_names.count(year) != 0)
			return;

		first_names[year] = first_name;
	}

	void ChangeLastName(int year, const std::string& last_name) {
		if (last_names.count(year) != 0)
			return;

		last_names[year] = last_name;
	}

	std::string GetFullName(int year) {
		auto first_name = get_first_name(year);
		auto last_name = get_last_name(year);

		if (first_name.empty() && last_name.empty())
			return "Incognito";

		if (first_name.empty())
			return last_name+" with unknown first name";

		if (last_name.empty())
			return first_name+" with unknown last name";

		return first_name+" "+last_name;
	}

private:
	std::map<int, std::string> first_names;
	std::map<int, std::string> last_names;

	std::string get_first_name(int year) {
		for (auto iter = first_names.rbegin(); iter != first_names.rend(); ++iter) {
			if (iter->first <= year)
				return iter->second;
		}
		return "";
	}

	std::string get_last_name(int year) {
		for (auto iter = last_names.rbegin(); iter != last_names.rend(); ++iter) {
			if (iter->first <= year)
				return iter->second;
		}
		return "";
	}
};

