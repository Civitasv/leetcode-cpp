#pragma once
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> st;
    while (true) {
      int val = 0;
      while (n != 0) {
        val += ((n % 10) * (n % 10));
        n /= 10;
      }
      if (val == 1)
        return true;
      else if (st.find(val) != st.end())
        return false;
      n = val;
      st.insert(val);
    }
  }
};
