// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/niuke/sort_algorithm.h"

using namespace std;

int main() {
  vector<int> nums{3, 2, 1, 5, 6, 4};
  // select_sort(nums);
  merge_sort(nums);

  for (int num : nums) {
    cout << num << ' ';
  }
}
