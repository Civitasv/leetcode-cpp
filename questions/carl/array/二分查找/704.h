#pragma once

#include <vector>

using namespace std;

// TAG #数组 #二分查找

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;  // [lo, hi]

    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        hi = mid - 1;
      else
        lo = mid + 1;
    }

    return -1;
  }
};
