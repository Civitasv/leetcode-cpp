#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res;
    vector<int> item;
    vector<bool> used(candidates.size(), false);
    backTrakcing(res, item, candidates, used, 0, 0, target);
    return res;
  }

  void backTrakcing(vector<vector<int>> &res, vector<int> &item,
                    vector<int> &candidates, vector<bool> &used, int start,
                    int sum, int target) {
    if (sum > target)
      return;
    if (sum == target) {
      res.push_back(item);
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      // 选取元素时，要求同一个树层不能重复选取元素
      if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]) {
        continue;
      }
      used[i] = true;
      item.push_back(candidates[i]);
      sum += candidates[i];

      backTrakcing(res, item, candidates, used, i + 1, sum, target);

      item.pop_back();
      sum -= candidates[i];
      used[i] = false;
    }
  }
};