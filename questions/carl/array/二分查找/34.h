#pragma once

#include <vector>
#include <queue>
using namespace std;

// TAG #数组 #二分查找

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    // 寻找左边界
    int left_border = findLeftBorder(nums, target);
    // 寻找右边界
    int right_border = findRightBorder(nums, target);

    // 1. 如果target在数组的左边或右边
    if (left_border == -2 || right_border == -2) {
      return {-1, -1};
    }

    // 3. 如果target在数组范围内，且数组中存在target
    if (right_border - left_border > 1)
      return {left_border + 1, right_border - 1};
    // 2. 如果target在数组范围内，但数组中不存在target
    return {-1, -1};
  }

  int findLeftBorder(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    int left_border = -2;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] >= target) {
        hi = mid - 1;  // nums[hi]<target
        left_border = hi;
      } else {
        lo = mid + 1;
      }
    }

    return left_border;
  }

  int findRightBorder(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    int right_border = -2;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] > target) {
        hi = mid - 1;
      } else {  // nums[lo]>target
        lo = mid + 1;
        right_border = lo;
      }
    }

    return right_border;
  }
};
