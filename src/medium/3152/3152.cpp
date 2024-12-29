#include <vector>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

bool isSubArraySpecial(const std::vector<int> &nums, int begin, int end) {
  for (int i = begin; i <= end - 1; i++) {
    const bool lhs_even = nums[i] % 2 == 0;
    const bool rhs_even = nums[i + 1] % 2 == 0;

    if (lhs_even == rhs_even) {
      return false;
    }
  }
  return true;
}

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
  std::vector<bool> result;
  result.reserve(queries.size());

  for (const auto &query : queries) {
    const int begin = query[0];
    const int end = query[1];

    bool calculated = false;

    if (begin == end) {
      result.push_back(true);
      calculated = true;
      continue;
    }

    for (int q_i = 0; q_i < result.size(); q_i++) {
      const int old_begin = queries[q_i][0];
      const int old_end = queries[q_i][1];

      // [new] [old], [old] [new]
      if (begin > old_end || end < old_begin) {
        result.push_back(isSubArraySpecial(nums, begin, end));
        calculated = true;
        break;
      }
      // [ [old] ]
      else if (begin < old_begin && end > old_end) {
        const bool first_interval = isSubArraySpecial(nums, begin, old_begin);
        const bool middle_interval = result[q_i];
        const bool second_interval = isSubArraySpecial(nums, old_end, end);
        result.push_back(first_interval && middle_interval && second_interval);
        calculated = true;
        break;
      } else {
        continue;
      }
    }

    if (calculated) {
      continue;
    }

    result.push_back(isSubArraySpecial(nums, begin, end));
  }

  return result;
}

TEST(Test3152, Test1) {
  std::vector<int> nums = {3, 4, 1, 2, 6};
  std::vector<std::vector<int>> queries = {{0, 4}};

  ASSERT_THAT(isArraySpecial(nums, queries), testing::ElementsAre(false));
}

TEST(Test3152, Test2) {
  std::vector<int> nums = {4, 3, 1, 6};
  std::vector<std::vector<int>> queries = {{0, 2}, {2, 3}};

  ASSERT_THAT(isArraySpecial(nums, queries), testing::ElementsAre(false, true));
}

TEST(Test3152, Test3) {
  std::vector<int> nums = {5, 9, 3};
  std::vector<std::vector<int>> queries = {{0, 2}, {2, 2}, {1, 2}, {1, 1},
                                           {0, 2}, {0, 1}, {0, 1}, {1, 2}};
  ASSERT_THAT(
      isArraySpecial(nums, queries),
      testing::ElementsAre(
      false, true, false, true, false, false, false, false));
}

TEST(Test3152, Test4) {
  std::vector<int> nums = {3, 7, 3, 10, 5, 5};
  std::vector<std::vector<int>> queries = {{3, 4}, {1, 5}, {5, 5}, {0, 4},
                                           {1, 2}, {2, 3}, {5, 5}, {0, 1}};
  ASSERT_THAT(
      isArraySpecial(nums, queries),
      testing::ElementsAre(true, false, true, false, false, true, true, false));
}
