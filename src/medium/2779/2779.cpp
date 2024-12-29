#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

int maximumBeauty(vector<int> &nums, int k) {
  std::sort(nums.begin(), nums.end());

  int max = 0;

  int window_size = 0;
  while (window_size != nums.size()) {
    for (int i = 0, j = i + window_size; j < nums.size(); j++, i++) {
      if (nums[j] - nums[i] <= 2 * k) {
        if ((j - i + 1) > max) {
          max = j - i + 1;
        }
      }
    }

    window_size++;
  }

  return max;
}

TEST(Test2779, Test1) {
  std::vector<int> nums = {4, 6, 1, 2};
  EXPECT_EQ(maximumBeauty(nums, 2), 3);
}

TEST(Test2779, Test2) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(maximumBeauty(nums, 10), 4);
}
