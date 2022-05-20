// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/merge_intervals.h"

using namespace std;

int main() {
  vector<vector<int>> intervals{{1, 4}, {0, 4}};
  Solution s;

  auto result = s.merge(intervals);

  int val;
  std::cin >> val;
  return 0;
}
