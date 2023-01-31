// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/carl/哈希表/18.h"

using namespace std;

int main() {
  Solution s;
  vector<int> v = {1000000000, 1000000000, 1000000000, 1000000000};
  auto res = s.fourSum(v, 8);

  for (auto &item : res) {
    for (auto &i : item) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
