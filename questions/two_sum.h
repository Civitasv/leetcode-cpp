#pragma once
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;

    map<int, int> data;  // value-index

    for (int i = 0; i < nums.size(); i++) {
      data[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
      int val = target - nums[i];
      if (data.find(val) != data.end() && data[val] != i) {
        res.push_back(i);
        res.push_back(data[val]);
        break;
      }
    }
    return res;
  }
};