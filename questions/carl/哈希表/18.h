#pragma once
#include <algorithm>
#include <cstdint>
#include <vector>
using namespace std;

// 双指针法要求必须是排序的数组，所以如果是求索引，就不行了
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > target && nums[i] > 0)
        break;
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] > target && nums[i] > 0)
          break;
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;
        int lo = j + 1, hi = nums.size() - 1;

        while (lo < hi) {
          if ((long)nums[lo] + nums[hi] + nums[i] + nums[j] == target) {
            res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
            while (lo < hi && nums[hi] == nums[hi - 1])
              hi--;
            while (lo < hi && nums[lo] == nums[lo + 1])
              lo++;
            hi--;
            lo++;
          } else if ((long)nums[lo] + nums[hi] + nums[i] + nums[j] > target) {
            hi--;
          } else {
            lo++;
          }
        }
      }
    }
    return res;
  }
};
