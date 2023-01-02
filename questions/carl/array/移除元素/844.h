#pragma once

#include <string>
using namespace std;

// TAG #数组 #双指针

class Solution {
 private:
  int help(string& s) {
    int lo = 0;
    for (int hi = 0; hi < s.size(); hi++) {
      if (s[hi] == '#') {
        lo = (lo == 0 ? 0 : lo - 1);
      } else {
        s[lo++] = s[hi];
      }
    }
    return lo;
  }

 public:
  bool backspaceCompare(string s, string t) {
    int a = help(s);
    int b = help(t);

    return a == b && s.substr(0, a) == t.substr(0, b);
  }
};
