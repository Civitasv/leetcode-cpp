#pragma once

#include <vector>

using namespace std;

// TAG #数组 #双指针 #排序

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> res(nums.size());
    int lo = 0, hi = nums.size() - 1;
    int k = nums.size() - 1;
    while (lo <= hi) {
      if (lo >= nums.size()) {
        res[k--] = nums[hi] * nums[hi];
        hi--;
      } else if (hi < 0) {
        res[k--] = nums[lo] * nums[lo];
        lo++;
      } else {
        int a = nums[lo] * nums[lo];
        int b = nums[hi] * nums[hi];

        if (a < b) {
          res[k--] = b;
          hi--;
        } else {
          res[k--] = a;
          lo++;
        }
      }
    }

    return res;
  }
};
