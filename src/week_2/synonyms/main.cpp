#include <iostream>
#include <map>
#include <set>
#include <string>

const std::string OP_ADD = "ADD";
const std::string OP_COUNT = "COUNT";
const std::string OP_CHECK = "CHECK";

int main() {
  int noperations = 0;
  std::cin >> noperations;

  std::map<std::string, std::set<std::string>> synonyms;
  for (auto i = 0; i < noperations; ++i) {
    std::string op;
    std::cin >> op;

    if (op == OP_ADD) {
      std::string first, second;
      std::cin >> first >> second;

      synonyms[first].insert(second);
      synonyms[second].insert(first);

      continue;
    }

    if (op == OP_COUNT) {
      std::string word;
      std::cin >> word;

      int nsynonyms = 0;
      if (synonyms.count(word) != 0)
        nsynonyms = synonyms[word].size();

      std::cout << nsynonyms << std::endl;

      continue;
    }

    if (op == OP_CHECK) {
      bool are_synonyms = false;
      std::string first, second;
      std::cin >> first >> second;

      if (synonyms.count(first) != 0) {
        are_synonyms = (synonyms[first].count(second) != 0);
      }

      if (!are_synonyms && (synonyms.count(second) != 0)) {
        are_synonyms = (synonyms[second].count(first) != 0);
      }

      std::cout << (are_synonyms ? "YES" : "NO") << std::endl;

      continue;
    }
  }

  return 0;
}
