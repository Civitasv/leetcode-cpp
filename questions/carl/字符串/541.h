#pragma once
#include <string>
using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    string res = s;
    bool swap = true;  // 1. 控制是否反转
    for (int i = 0; i < res.length(); i += k) {
      if (swap) {
        int size =
            min((int)res.length(), i + k);  // 2. 如果小于 k 个，则全部反转
        reverse(res.begin() + i, res.begin() + size);
        swap = false;
      } else {
        swap = true;
      }
    }
    return res;
  }
};
