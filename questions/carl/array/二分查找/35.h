#pragma once

#include <vector>

using namespace std;

// TAG #数组 #二分查找
// NOTE 二分查找要求数组是有序的，且数组中无重复元素

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        hi = mid - 1;
      else
        lo = mid + 1;
    }

    // 四种情况
    // a. 目标值在数组所有元素之前：[0, -1]
    // b. 目标值在数组所有元素之后：[nums.size(), nums.size()-1]
    // c. 目标值等于数组中的某一个元素：mid
    // d. 目标值在数组之中：[lo, hi]
    return hi + 1;
  }
};
