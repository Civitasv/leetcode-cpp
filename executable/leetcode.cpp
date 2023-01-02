// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/carl/array/移除元素/977.h"

using namespace std;

int main() {
  Solution s;

  vector<int> data = {-1};
  auto result = s.sortedSquares(data);
  for (auto& item : result) cout << item << " ";
  return 0;
}
