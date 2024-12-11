#include "utils.hpp"

#include <iostream>
#include <string>

void printTestResult(const bool test_result) {
  static int test_number = 1;

  std::string result = "";
  if (test_result) {
    result = "OK";
  } else {
    result = "FAILED";
  }

  std::cout << "Test " << test_number << ": " << result << '\n';

  test_number++;
}
