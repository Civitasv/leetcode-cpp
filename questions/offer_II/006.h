#pragma once

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int lo = 0, hi = numbers.size() - 1;
    while (lo < hi) {
      if (numbers[lo] + numbers[hi] == target)
        return {lo, hi};
      else if (numbers[lo] + numbers[hi] > target)
        hi--;
      else
        lo++;
    }
    return {-1, -1};
  }
};