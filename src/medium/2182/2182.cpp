#include <map>

#include <gtest/gtest.h>

using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
  auto comp = [](const char a, const char b) {
    if (a == b) {
      return false;
    }

    return !(a < b);
  };

  std::map<char, int, decltype(comp)> chars(comp);

  for (char c : s) {
    chars[c]++;
  }

  string result;
  result.reserve(s.size());

  int count = 0;
  auto chars_it = chars.begin();

  while (chars_it != chars.end()) {
    if (chars_it->second == 0) {
      chars.erase(chars_it);
      chars_it = chars.begin();
      count = 0;
      continue;
    }

    result += chars_it->first;
    chars_it->second--;
    count++;

    auto prev_it = std::prev(chars_it);

    // кончились буквы
    if (chars_it->second == 0) {
      chars.erase(chars_it);
      chars_it = chars.begin();
      count = 0;
      continue;
    }

    if (count == repeatLimit) {
      // кончилась возможность вставлять буквы, перейдем на следующую букву,
      // может вернемся потом

      if (chars_it == chars.begin()) {
        chars_it++;
      } else {
        chars_it = chars.begin();
      }
      count = 0;
      continue;
    }

    if (chars_it != chars.begin()) {
      // если у предыдущего не кончились буквы - возвращаемся
      chars_it = chars.begin();
      count = 0;
    }
  }

  std::cout << "Result " << result;

  return result;
}

TEST(Test2182, cczazcc) {
  EXPECT_EQ(repeatLimitedString("cczazcc", 3), "zzcccac");
}

TEST(Test2182, aababab) {
  EXPECT_EQ(repeatLimitedString("aababab", 2), "bbabaa");
}

TEST(Test2182, acccccc) {
  EXPECT_EQ(repeatLimitedString("acccccc", 3), "cccaccc");
}

TEST(Test2182, zzzzzzaaa) {
  EXPECT_EQ(repeatLimitedString("zzzzzzaaa", 1), "zazazaz");
}

TEST(Test2182, zaaaaaa) { EXPECT_EQ(repeatLimitedString("zaaaaaa", 1), "za"); }

TEST(Test2182, bbbbcccaaz) {
  EXPECT_EQ(repeatLimitedString("bbbbcccaaz", 3), "zcccbbbaba");
}

TEST(Test2182, aaaabbbccz) {
  EXPECT_EQ(repeatLimitedString("aaaabbbccz", 3), "zccbbbaaa");
}

TEST(Test2182, abcdef) {
  EXPECT_EQ(repeatLimitedString("abcdef", 1), "fedcba");
}

TEST(Test2182, abcdeffff) {
  EXPECT_EQ(repeatLimitedString("abcdeffff", 2), "ffeffdcba");
}

TEST(Test2182, longstring) {
  EXPECT_EQ(repeatLimitedString("xyutfpopdynbadwtvmxiemmusevduloxwvpk"
                                "jioizvanetecnuqbqqdtrwrkgt",
                                1),
            "zyxyxwxwvwvuvuvututstrtrtqpqpqponononmlmkmkjigifiededede"
            "dcbaba");
}
