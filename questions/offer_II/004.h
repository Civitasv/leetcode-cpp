#pragma once

#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i <= 31; i++) {
      int total = 0;
      for (int num : nums) {
        total += (num >> i) & 1;
      }
      if (total % 3 != 0) {
        ans |= (1 << i);
      }
    }
    return ans;
  }
};