// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/堆/506.h"

using namespace std;

int main() {
  Solution s;
  vector<int> score = {5, 4, 3, 2, 1};
  auto res = s.findRelativeRanks(score);
  for (auto &item : res)
    cout << item << ' ';
}
