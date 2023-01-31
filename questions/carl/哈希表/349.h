#pragma once

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> res_set;
    for (int num : nums2) {
      if (set1.find(num) != set1.end())
        res_set.insert(num);
    }

    return vector<int>(res_set.begin(), res_set.end());
  }
};
