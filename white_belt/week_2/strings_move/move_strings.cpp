#include <string>
#include <vector>

void MoveStrings(std::vector<std::string> &src, std::vector<std::string> &dst) {
  for (auto const &s : src)
    dst.push_back(s);
  src.clear();
}
