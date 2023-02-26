#pragma once
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<int> item;
    vector<vector<int>> res;

    backTracking(res, item, nums, 0);
    return res;
  }

  void backTracking(vector<vector<int>> &res, vector<int> &item,
                    vector<int> &nums, int index) {
    if (item.size() >= 2)
      res.push_back(item);

    unordered_set<int> uset;
    for (int i = index; i < nums.size(); i++) {
      if ((!item.empty() && nums[i] < item.back()) ||
          uset.find(nums[i]) != uset.end())
        continue;
      item.push_back(nums[i]);
      uset.insert(nums[i]);
      backTracking(res, item, nums, i + 1);
      item.pop_back();
    }
  }
};
