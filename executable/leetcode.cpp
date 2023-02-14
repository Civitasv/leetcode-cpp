// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/单调栈/739.h"

using namespace std;

int main() {
  Solution s;
  vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
  auto res = s.dailyTemperatures(temp);
  for (int item : res) {
    cout << item << ' ';
  }
}
