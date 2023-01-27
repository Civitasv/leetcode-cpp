#pragma once

#include <vector>

using namespace std;

// TAG #数组 #二分查找 #前缀和 #滑动窗口

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int len = nums.size() + 1, sum = 0;
    int i = 0, j = 0;

    while (j < nums.size()) {
      sum += nums[j];

      while (sum >= target) {
        len = min(len, j - i + 1);
        sum -= nums[i++];
      }
      j++;
    }
    return len == nums.size() + 1 ? 0 : len;
  }
};
