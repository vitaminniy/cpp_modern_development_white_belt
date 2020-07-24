#include <algorithm>
#include <map>
#include <string>
#include <vector>

class Person {
public:
  Person(const std::string &first_name, const std::string &last_name,
         int year) {
    first_names[year] = first_name;
    last_names[year] = last_name;
  }

  void ChangeFirstName(int year, const std::string &first_name) {
    first_names[year] = first_name;
  }

  void ChangeLastName(int year, const std::string &last_name) {
    last_names[year] = last_name;
  }

  const std::string GetFullName(int year) const {
    auto first_name = get_first_name(year);
    auto last_name = get_last_name(year);

    if (first_name.empty() && last_name.empty())
      return "No person";

    if (first_name.empty())
      return last_name + " with unknown first name";

    if (last_name.empty())
      return first_name + " with unknown last name";

    return first_name + " " + last_name;
  }

  const std::string GetFullNameWithHistory(int year) const {
    auto first_name = get_full_first_name(year);
    auto last_name = get_full_last_name(year);

    if (first_name.empty() && last_name.empty())
      return "No person";

    if (first_name.empty()) {
      return last_name + " with unknown first name";
    }

    if (last_name.empty()) {
      return first_name + " with unknown last name";
    }

    return first_name + " " + last_name;
  }

private:
  std::map<int, std::string> first_names;
  std::map<int, std::string> last_names;

  const std::string get_first_name(int year) const {
    return find_by_year(year, first_names);
  }

  const std::string get_last_name(int year) const {
    return find_by_year(year, last_names);
  }

  const std::string get_full_first_name(int year) const {
    return history_name(year, first_names);
  }

  const std::string get_full_last_name(int year) const {
    return history_name(year, last_names);
  }

  const std::string
  find_by_year(int year, const std::map<int, std::string> &names) const {
    for (auto iter = names.rbegin(); iter != names.rend(); ++iter) {
      if (iter->first <= year)
        return iter->second;
    }
    return "";
  }

  const std::string
  history_name(int year, const std::map<int, std::string> &names) const {
    std::vector<std::string> found_names;

    for (auto iter = names.rbegin(); iter != names.rend(); ++iter) {
      if (iter->first > year)
        continue;

      found_names.push_back(iter->second);
    }

    if (found_names.size() == 0)
      return "";

    auto first = found_names[0];
    std::vector<std::string> history_names;
    for (auto i = 1; i < found_names.size(); i++) {
      if (found_names[i].compare(found_names[i - 1]) == 0)
        continue;

      history_names.push_back(found_names[i]);
    }

    std::string history;
    for (auto i = 0; i < history_names.size(); i++) {
      if (i > 0)
        history += ", ";

      history += history_names[i];
    }

    if (!history.empty())
      first += " (" + history + ")";

    return first;
  }
};
