#include <string>
#include <unordered_map>

#include "../utils.hpp"

using namespace std;

int maximumLength(string s) {
  std::unordered_map<std::string, int> substrings;

  std::string current_substr = "";
  char current_char = ' ';
  for (const auto &c : s) {
    if (c != current_char) {
      current_substr = c;
      current_char = c;
    } else {
      current_substr += c;
    }

    for (int i = 1; i <= current_substr.size(); i++) {
      substrings[current_substr.substr(0, i)] += 1;
    }
  }

  int max_size = -1;
  for (const auto &[key, value] : substrings) {
    if (value < 3) {
      continue;
    }

    int key_size = key.size();
    if (key_size > max_size) {
      max_size = key_size;
    }
  }

  return max_size;
}

int main() {
  printTestResult(maximumLength("aaabbccddbbbb") == 2);

  printTestResult(maximumLength("aaaa") == 2);

  printTestResult(maximumLength("abcdef") == -1);

  printTestResult(maximumLength("abcaba") == 1);

  // граничные случаи

  printTestResult(maximumLength("aaa") == 1);

  printTestResult(maximumLength("aa") == -1);

  printTestResult(maximumLength("a") == -1);

  printTestResult(maximumLength("") == -1);

  printTestResult(maximumLength("bbccbbccbbccbbccbbcc") == 2);

  printTestResult(maximumLength("ccccccccc") == 7);
}
