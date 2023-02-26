#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> item;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());

    backTracking(res, item, nums, used);
    return res;
  }

  void backTracking(vector<vector<int>> &res, vector<int> &item,
                    vector<int> &nums, vector<bool> &used) {
    if (item.size() == nums.size()) {
      res.push_back(item);
      return;
    }

    bool tagged[21] = {false};
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1] && tagged[nums[i] + 10])
        continue;

      if (!used[i]) {
        used[i] = true;
        tagged[nums[i] + 10] = true;
        item.push_back(nums[i]);
        backTracking(res, item, nums, used);
        used[i] = false;
        item.pop_back();
      }
    }
  }
};
