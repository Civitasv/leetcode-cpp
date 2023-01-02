#pragma once

#include <vector>

using namespace std;

// TAG #数组 #双指针

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
      while (lo <= hi && nums[lo] != val) lo++;  // 左边等于val的
      while (lo <= hi && nums[hi] == val) hi--;  // 右边不等于val的
      if (lo < hi) {
        nums[lo++] = nums[hi--];  // 覆盖
      }
    }
    return lo;
  }
};