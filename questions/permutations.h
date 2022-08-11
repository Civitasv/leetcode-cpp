#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> curr;
    vector<bool> vi(nums.size(), false);

    helper(result, curr, vi, nums);

    return result;
  }

  void helper(vector<vector<int>> &result, vector<int> &curr, vector<bool> &vi,
              vector<int> &nums) {
    if (curr.size() == nums.size()) {
      result.push_back(curr);
    }

    for (int i = 0; i < nums.size(); i++) {
      if (vi[i]) continue;
      // choose
      curr.push_back(nums[i]);
      vi[i] = true;

      // explore
      helper(result, curr, vi, nums);

      // unchoose
      curr.pop_back();
      vi[i] = false;
    }
  }
};