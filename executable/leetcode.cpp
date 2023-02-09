// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/竞赛/331//2559.h"

using namespace std;

int main() {
  vector<int> nums{3, 2, 1, 5, 6, 4};
  Solution s;
  vector<string> data = {"aba", "bcb", "ece", "aa", "e"};
  vector<vector<int>> queries = {{0, 2}, {1, 4}, {1, 1}};
  auto res = s.vowelStrings(data, queries);
  for (auto &item : res)
    cout << item << ' ';
}
