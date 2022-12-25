#pragma once

class Solution {
 public:
  int divide(int a, int b) {
    // NOTE when a is INT_MIN, and b=1, then output INT_MIN
    // NOTE else if b=-1, then output INT_MAX
    int result = 0;
    if (a == INT_MIN) {
      if (b == 1) {
        return INT_MIN;
      }
      if (b == -1) {
        return INT_MAX;
      }
    }
    if (b == INT_MIN) {
      return a == INT_MIN ? 1 : 0;
    }
    if (a == INT_MIN) {
      a += abs(b);
      result += 1;
    }

    bool neg = (a < 0 && b > 0) || (a > 0 && b < 0);
    a = abs(a);
    b = abs(b);

    for (int i = 31; i >= 0; i--) {
      if (a >> i >= b) {
        a -= b << i;
        result += 1 << i;
      }
    }

    return neg ? -result : result;
  }
};