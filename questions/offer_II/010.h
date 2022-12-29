#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int hi = 0;
    int sum = 0, count = 0;
    unordered_map<int, int> mp;  // key: 和 value: 该和出现的次数
    mp[0] = 1;

    while (hi < nums.size()) {
      sum += nums[hi];
      if (mp.find(sum - k) != mp.end()) {
        count += mp[sum - k];
      }

      mp[sum]++;

      hi++;
    }
    return count;
  }
};