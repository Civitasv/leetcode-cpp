#pragma once

#include <iostream>
using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      ans += n & 1;
      n >>= 1;
    }
    return ans;
  }
};