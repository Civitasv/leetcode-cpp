// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/carl/array/长度最小的子数组/76.h"

using namespace std;

int main() {
  Solution s;

  vector<int> data = {1,2,3,2,2};
  auto result = s.minWindow("cabwefgewcwaefgcf", "cae");
  cout << result;
  return 0;
}
