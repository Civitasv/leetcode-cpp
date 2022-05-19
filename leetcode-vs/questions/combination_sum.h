#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    // backtracking
    vector<vector<int>> result;
    vector<int> current;

    helper(candidates, result, 0, current, 0, target);
    return result;
  }
  void helper(vector<int> &candidates, vector<vector<int>> &result, int start,
              vector<int> &current, int val, int target) {
    if (val == target) {
      result.push_back(current);
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      int candidate = candidates[i];
      // add
      current.push_back(candidate);
      val += candidate;

      if (val <= target)
        helper(candidates, result, i, current, val, target); // key

      // delete
      current.pop_back();
      val -= candidate;
    }
  }
};

