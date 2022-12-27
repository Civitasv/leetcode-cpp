#pragma once

#include <climits>
#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int lo = 0, hi = 0;
    int sum = 0, min_len = INT32_MAX;
    while (hi < nums.size()) {
      sum += nums[hi++];
      if (sum >= target) {
        min_len = min(min_len, hi - lo);
        lo++;
        hi = lo;
        sum = 0;
      }
    }
    return min_len == INT32_MAX ? 0 : min_len;
  }
};
