#pragma once

#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int lo = 0, hi = 0;
    int product = 1, count = 0;
    while (hi < nums.size()) {
      product *= nums[hi];
      while (lo <= hi && product >= k) {
        product /= nums[lo++];
      }
      count += hi - lo + 1;
      hi++;
    }
    return count;
  }
};