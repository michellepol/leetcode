#include <vector>

#include <gtest/gtest.h>

using namespace std;

int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
  int result;

  std::vector<std::vector<int>> rows(matrix.size());

  for (int row = 0; row < matrix.size(); row++) {

    int sum = 0;

    std::vector<int> zero_flips;
    std::vector<int> one_flips;

    for (int col = 0; col < matrix[row].size(); col++) {
      sum += matrix[row][col];
    }
  }

  return result;
}

TEST(Test1072, Test1) {
  // 0 0 1
  // 1 1 0
  // 0 0 1
  vector<vector<int>> matrix{{0, 0, 1}, {1, 1, 0}, {0, 0, 1}};

  EXPECT_EQ(maxEqualRowsAfterFlips(matrix), 3);
}
