#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> kv; // val-index
    for (int i = 0; i < nums.size(); i++) {
      if (kv.find(target - nums[i]) != kv.end()) {
        return {i, kv[target - nums[i]]};
      }
      kv[nums[i]] = i;
    }

    return {-1, -1};
  }
};
