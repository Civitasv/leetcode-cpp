#pragma once

#include <vector>

using namespace std;

// TAG #数组 #二分查找

class Solution {
 public:
  int mySqrt(int x) {
    int lo = 0, hi = x;

    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (mid != 0) {
        if (mid == x / mid)
          return mid;
        else if (mid > x / mid)
          hi = mid - 1;
        else
          lo = mid + 1;
      } else {
        if (x == 0)
          return mid;
        else if (x < 0)
          hi = mid - 1;
        else
          lo = mid + 1;
      }
    }
    return hi;
  }
};