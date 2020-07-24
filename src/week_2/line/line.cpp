#include <iostream>
#include <string>
#include <vector>

enum operation { worry, quiet, come, worry_count };

operation resolve_operation(const std::string &op);

int main() {
  int noperations = 0;
  std::cin >> noperations;

  if (noperations == 0)
    return 0;

  std::vector<bool> line;

  for (auto i = 0; i < noperations; ++i) {
    std::string op;
    std::cin >> op;

    switch (resolve_operation(op)) {
    case worry: {
      int n = 0;
      std::cin >> n;

      if (line.size() > n)
        line[n] = true;

      break;
    }
    case quiet: {
      int n = 0;
      std::cin >> n;

      if (line.size() > n)
        line[n] = false;

      break;
    }
    case come: {
      int n = 0;
      std::cin >> n;
      if (n > 0) {
        for (auto j = 0; j < n; ++j)
          line.push_back(false);
      } else {
        for (auto j = 0; j < (-1 * n); ++j) {
          if (line.size() > 0)
            line.pop_back();
        }
      }
      break;
    }
    case worry_count: {
      int nworried = 0;
      for (auto j = 0; j < line.size(); ++j)
        if (line[j])
          nworried++;

      std::cout << nworried << std::endl;
      break;
    }
    }
  }

  return 0;
}

operation resolve_operation(const std::string &op) {
  if (op == "WORRY")
    return worry;

  if (op == "QUIET")
    return quiet;

  if (op == "COME")
    return come;

  return worry_count;
}
