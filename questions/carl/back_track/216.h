#pragma once
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> item;
    backTracking(res, item, 0, 1, 9, n, k);
    return res;
  }

  void backTracking(vector<vector<int>>& res, vector<int>& item, int sum,
                    int start, int end, int n, int k) {
    if (sum > n) return;
    if (item.size() + end - start + 1 < k) return;
    if (item.size() == k) {
      if (sum == n) res.push_back(item);
      return;
    }

    for (int i = start; i <= end; i++) {
      sum += i;
      item.push_back(i);
      backTracking(res, item, sum, i + 1, end, n, k);
      sum -= i;
      item.pop_back();
    }
  }
};