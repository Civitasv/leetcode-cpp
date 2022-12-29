#pragma once

#include <vector>

using namespace std;

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int pre = 0, sum = 0, n = nums.size();
    for (int& num : nums) sum += num;

    for (int i = -1; i < n - 1; i++) {
      if (i != -1) pre += nums[i];

      if (pre == sum - nums[i + 1] - pre) {
        return i + 1;
      }
    }

    return -1;
  }
};