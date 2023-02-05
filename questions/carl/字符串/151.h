#pragma once

#include <string>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    // 1. 移除多余空格
    int slow = 0, fast = 0;
    // 1.1 前导空格
    while (s.length() > 0 && fast < s.length() && s[fast] == ' ') fast++;

    // 1.2 字符串中间的空格
    while (fast < s.length()) {
      if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
      } else {
        s[slow++] = s[fast];
      }
      fast++;
    }

    // 1.3 后导空格
    if (slow - 1 > 0 && s[slow - 1] == ' ') {
      s.resize(slow - 1);
    } else {
      s.resize(slow);
    }

    // 2. reverse 字符串
    reverse(s.begin(), s.end());

    // 3. reverse 单词
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        reverse(s.begin() + pos, s.begin() + i);
        pos = i + 1;
      }
    }
    reverse(s.begin() + pos, s.end());

    return s;
  }
};
