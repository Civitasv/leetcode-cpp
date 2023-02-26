#pragma once
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> item;
    backTracking(res, item, nums, 0);
    return res;
  }

  void backTracking(vector<vector<int>> &res, vector<int> &item,
                    vector<int> &nums, int index) {
    res.push_back(item);

    for (int i = index; i < nums.size(); i++) {
      item.push_back(nums[i]);
      backTracking(res, item, nums, i + 1);
      item.pop_back();
    }
  }
};
