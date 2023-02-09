#pragma once

#include <string>
using std::string;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    // 1. 计算前缀表
    int m = needle.length();
    std::vector<int> next(m, 0);
    int j = 0;
    next[0] = j;
    // [0-j): 记录前缀
    for (int i = 1; i < needle.length(); i++) {
      while (j > 0 && needle[i] != needle[j]) {
        // 前缀没办法继续走了
        j = next[j - 1];
      }
      if (needle[i] == needle[j]) {
        j++;
      }
      next[i] = j;
    }

    // 2. 匹配
    j = 0;
    for (int i = 0; i < haystack.length(); i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == needle.length()) {
        return i - needle.length() + 1;
      }
    }

    return -1;
  }
};
