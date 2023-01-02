#pragma once

#include <vector>

using namespace std;

// TAG #数组 #双指针

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int lo = 0, hi = 0;

    while (hi < nums.size()) {
      if (nums[hi] != 0) {
        nums[lo++] = nums[hi];
      }

      hi++;
    }
    for (int i = lo; i < nums.size(); i++) nums[i] = 0;
  }
};