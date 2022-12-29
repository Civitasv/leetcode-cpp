#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int sum = 0, length = 0;
    unordered_map<int, int> mp;  // 和 -> 该和出现的索引
    mp[0] = -1;

    // 如果 nums[i]==0，那么sum+=-1，否则sum+=1，
    // 那么，就变成求和为 0 的最长子数组
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i] == 0 ? -1 : 1;

      if (mp.find(sum) != mp.end()) {
        length = max(i - mp[sum], length);
      } else
        mp[sum] = i;  // 前缀和相同时，只记录最小的下标
    }

    return length;
  }
};