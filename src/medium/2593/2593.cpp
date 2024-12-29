#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

struct Element {
  int value;
  int index;
};

long long findScore(vector<int> &nums) {
  long long score = 0;

  std::vector<bool> marked_elements(nums.size(), false);

  // O(N)
  std::vector<Element> elements;
  elements.reserve(nums.size());

  for (int i = 0; i < nums.size(); i++) {
    elements.push_back(Element{.value = nums[i], .index = i});
  }

  // O(NlogN)
  std::sort(elements.begin(), elements.end(),
            [](const Element &lhs, const Element &rhs) {
              if (lhs.value == rhs.value) {
                return lhs.index < rhs.index;
              }

              return lhs.value < rhs.value;
            });

  int marked_elements_num = 0;
  int current_index = 0;

  while (marked_elements_num != nums.size()) {
    const bool marked = marked_elements[elements[current_index].index];
    if (marked) {
      current_index++;
      continue;
    }

    const auto &element = elements[current_index];

    score += element.value;

    marked_elements[element.index] = true;
    marked_elements_num++;

    if (element.index != 0) {
      if (marked_elements[element.index - 1] == false) {
        marked_elements[element.index - 1] = true;
        marked_elements_num++;
      }
    }

    if (element.index != nums.size() - 1) {
      if (marked_elements[element.index + 1] == false) {
        marked_elements[element.index + 1] = true;
        marked_elements_num++;
      }
    }
  }

  return score;
}

    TEST(Test2593, Test1) {
  std::vector<int> nums = {2, 1, 3, 4, 5, 2};
  EXPECT_EQ(findScore(nums),7);
    }

    TEST(Test2593, Test2) {
        std::vector<int>
  nums = {2, 3, 5, 1, 3, 2};
  EXPECT_EQ(findScore(nums),5);
}
