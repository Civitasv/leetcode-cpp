#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    // backtracking
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;

    helper(candidates, result, 0, current, 0, target);
    return result;
  }
  void helper(vector<int> &candidates, vector<vector<int>> &result, int start,
              vector<int> &current, int val, int target) {
    if (val > target)
      return;
    if (val == target) {
      result.push_back(current);
      return;
    }

    for (int i = start; i < candidates.size(); i++) {
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      int candidate = candidates[i];
      // add
      current.push_back(candidate);
      val += candidate;

      helper(candidates, result, i + 1, current, val, target); // key

      // delete
      current.pop_back();
      val -= candidate;
    }
  }
};

int main() {
  Solution s;
  vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
  for (auto item : s.combinationSum2(candidates, 8)) {
    for (auto i : item)
      cout << i << " ";
    cout << endl;
  }
}
