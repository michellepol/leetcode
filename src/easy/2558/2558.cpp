#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

long long pickGifts(vector<int> &gifts, int k) {
  std::sort(gifts.begin(), gifts.end());

  for (int second = 0; second < k; second++) {
    const auto new_value = sqrt(gifts.back());
    gifts.pop_back();

    const auto sqrt_it = upper_bound(gifts.begin(), gifts.end(), new_value);
    gifts.emplace(sqrt_it, new_value);
  }

  return std::accumulate(gifts.begin(), gifts.end(), 0LL);
}

TEST(Test2558, Test1) {
  std::vector<int> gifts = {25, 64, 9, 4, 100};
  EXPECT_EQ(pickGifts(gifts, 4), 29LL);
}

TEST(Test2558, OnlyOneNumber) {
  std::vector<int> gifts = {1, 1, 1, 1};
  EXPECT_EQ(pickGifts(gifts, 1), 4LL);
}
