// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/carl/array/螺旋矩阵/59.h"

using namespace std;

int main() {
  Solution s;

  vector<vector<int>> data{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  auto result = s.generateMatrix(3);
  for (auto &item : result) {
    for (auto &i : item)
      cout << i << " ";
    cout << '\n';
  }
  return 0;
}
