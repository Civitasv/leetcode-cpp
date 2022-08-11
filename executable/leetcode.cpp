// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/reformat_the_string.h"

using namespace std;

int main() {
  Solution s;

  auto result = s.reformat("covid2019");
  std::cout << result;

  return 0;
}
