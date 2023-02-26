#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> item;
    vector<vector<int>> res;
    vector<bool> used(nums.size(), false);

    sort(nums.begin(), nums.end());
    backTracking(res, item, nums, used, 0);
    return res;
  }

  void backTracking(vector<vector<int>> &res, vector<int> &item,
                    vector<int> &nums, vector<bool> &used, int index) {
    res.push_back(item);

    for (int i = index; i < nums.size(); i++) {
      // 需要对同一树层元素进行过滤
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;
      item.push_back(nums[i]);
      used[i] = true;
      backTracking(res, item, nums, used, i + 1);
      item.pop_back();
      used[i] = false;
    }
  }
};
