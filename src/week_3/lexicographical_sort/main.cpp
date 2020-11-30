#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::string> strings(n);
  for (auto i = 0; i < n; i++)
    std::cin >> strings[i];

  std::sort(strings.begin(), strings.end(),
            [](const std::string &i, const std::string &j) {
              const auto min = std::min(i.size(), j.size());
              for (auto k = 0; k < min; k++) {
                const auto ik = std::tolower(i[k]), jk = std::tolower(j[k]);
                if (ik != jk)
                  return ik < jk;
              }

              return i.size() < j.size();
            });

  for (auto it = strings.begin(); it != strings.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
