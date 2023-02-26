#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> item;
    backTrakcing(res, item, candidates, 0, 0, target);
    return res;
  }

  void backTrakcing(vector<vector<int>> &res, vector<int> &item,
                    vector<int> &candidates, int start, int sum, int target) {
    if (sum > target)
      return;
    if (sum == target) {
      res.push_back(item);
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      item.push_back(candidates[i]);
      sum += candidates[i];

      backTrakcing(res, item, candidates, i, sum, target);

      item.pop_back();
      sum -= candidates[i];
    }
  }
};