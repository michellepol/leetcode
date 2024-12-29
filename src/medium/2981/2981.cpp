#include <string>
#include <unordered_map>

#include <gtest/gtest.h>

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

TEST(Test2981, aaabbccddbbbb) { EXPECT_EQ(maximumLength("aaabbccddbbbb"), 2); }

TEST(Test2981, aaaa) { EXPECT_EQ(maximumLength("aaaa"), 2); }

TEST(Test2981, abcdef) { EXPECT_EQ(maximumLength("abcdef"), -1); }

TEST(Test2981, abcaba) { EXPECT_EQ(maximumLength("abcaba"), 1); }

// граничные случаи

TEST(Test2981, aaa) { EXPECT_EQ(maximumLength("aaa"), 1); }

TEST(Test2981, aa) { EXPECT_EQ(maximumLength("aa"), -1); }

TEST(Test2981, a) { EXPECT_EQ(maximumLength("a"), -1); }

TEST(Test2981, EmptyString) { EXPECT_EQ(maximumLength(""), -1); }

TEST(Test2981, bbccbbccbbccbbccbbcc) {
  EXPECT_EQ(maximumLength("bbccbbccbbccbbccbbcc"), 2);
}

TEST(Test2981, ccccccccc) { EXPECT_EQ(maximumLength("ccccccccc"), 7); }
