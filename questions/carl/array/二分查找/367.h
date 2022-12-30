#pragma once

#include <vector>

using namespace std;

// TAG #数组 #二分查找

class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num == 1) return true;
    int lo = 0, hi = num;

    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (mid == num / mid) {
        if (num % mid == 0) return true;
        lo = mid + 1;
      } else if (mid > num / mid) {
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    return false;
  }
};