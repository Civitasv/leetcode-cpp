#pragma once
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> item;
    backTracking(result, item, 1, n, k);
    return result;
  }

  void backTracking(vector<vector<int>>& result, vector<int>& item, int start,
                    int end, int k) {
    if (item.size() + end - start + 1 < k) return;
    if (item.size() == k) {
      result.push_back(item);
      return;
    }
    for (int i = start; i <= end; i++) {
      item.push_back(i);
      backTracking(result, item, i + 1, end, k);
      item.pop_back();
    }
  }
};