#pragma once

#include <vector>

using namespace std;

// TAG #数组 #双指针 #排序

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size());
    int lo = 0, hi = 0, mid = 0, index = 0;

    while (mid < nums.size() && nums[mid] < 0) mid++;

    hi = mid, lo = mid - 1;

    while (lo >= 0 || hi < nums.size()) {
      if (lo < 0) {
        result[index++] = nums[hi] * nums[hi];
        hi++;
      } else if (hi >= nums.size()) {
        result[index++] = nums[lo] * nums[lo];
        lo--;
      } else if (nums[lo] * nums[lo] > nums[hi] * nums[hi]) {
        result[index++] = nums[hi] * nums[hi];
        hi++;
      } else {
        result[index++] = nums[lo] * nums[lo];
        lo--;
      }
    }
    return result;
  }
};