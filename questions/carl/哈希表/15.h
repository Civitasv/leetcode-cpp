#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0)
        return res;
      // a 去重
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int a = nums[i];
      int lo = i + 1, hi = nums.size() - 1;
      while (lo < hi) {
        int b = nums[lo];
        int c = nums[hi];

        if (b + c + a == 0) {
          res.push_back({a, b, c});
          // 去重
          while (lo < hi && nums[hi] == nums[hi - 1])
            hi--;
          while (lo < hi && nums[lo] == nums[lo + 1])
            lo++;

          lo++;
          hi--;
        } else if (b + c + a > 0) {
          hi--;
        } else {
          lo++;
        }
      }
    }

    return res;
  }
};
