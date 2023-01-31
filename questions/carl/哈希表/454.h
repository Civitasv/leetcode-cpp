#pragma once
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    int n = nums1.size();
    int count = 0;
    unordered_map<int, int> kv; // value, count
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int val = nums1[i] + nums2[j];
        if (kv.find(val) != kv.end())
          kv[val]++;
        else
          kv[val] = 1;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int val = nums3[i] + nums4[j];
        if (kv.find(-val) != kv.end()) {
          count += kv[-val];
        }
      }
    }

    return count;
  }
};
