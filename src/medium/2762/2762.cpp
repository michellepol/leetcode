#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

long long continuousSubarrays(vector<int> &nums) {
  long long result = 0;

  // every element is subarray of size 1
  result += nums.size();

  std::sort(nums.begin(), nums.end());

  int current_element = 0;

  int window_size = 2;
  while (window_size <= nums.size()) {
    int window_pos = 0;

    for (int window_pos = 0; (window_pos + window_size - 1) < nums.size();
         window_pos++) {
      const int window_end = window_pos + window_size - 1;

      int diff = abs(nums[window_pos] - nums[window_end]);

      if (diff <= 2) {
        result += 1;
      }
    }

    window_size++;
  }

  return result;
}

TEST(Test2762, Test1) {
  vector<int> nums = {5, 4, 2, 4};
  EXPECT_EQ(continuousSubarrays(nums), 8);
}

TEST(Test2762, Test2) {
  vector<int> nums = {1, 2, 3};
  EXPECT_EQ(continuousSubarrays(nums), 6);
}
