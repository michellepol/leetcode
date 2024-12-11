#include <iostream>
#include <vector>

using namespace std;

// 0 1
// 1 1

// 0 1
// 0 1

// чтобы выровнять эту строку, нужно переставить такие то столбцы
// чтобы эту такие-то
// чтобы эту такие-то
//
// пересечение флипа столбцов одинакого вида - дает максимальное количество
// строк

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

  // все значения в строке равны друг другу когда сумма значений строки или 0,
  // или длина строки
  //
  // мы можем прочитать сумму каждой строки и понимать какие строки между собой
  // неравны

  return result;
}

void printTestResult(std::string &&test_name, int left, int right) {

  if (left == right) {
    std::cout << test_name << " is OK";
  } else {
    std::cout << test_name << " is FAILED";
  }
}

int main() {
  // 0 0 1
  // 1 1 0
  // 0 0 1
  vector<vector<int>> test_1{{0, 0, 1}, {1, 1, 0}, {0, 0, 1}};

  // 0 0 0
  // 1 1 1
  // 0 0 0
  printTestResult("test_1", maxEqualRowsAfterFlips(test_1), 3);
}
