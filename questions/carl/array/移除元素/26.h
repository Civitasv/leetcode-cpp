#pragma once

#include <vector>

using namespace std;

// TAG #数组 #双指针

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    // NOTE 升序排列
    int lo = 0, hi = 1;

    while (hi < nums.size()) {
      if (nums[hi] != nums[hi - 1]) {
        nums[++lo] = nums[hi];
      }
      hi++;
    }
    return lo + 1;
  }
};