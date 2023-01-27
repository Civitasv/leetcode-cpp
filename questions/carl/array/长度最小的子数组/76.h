#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// TAG #哈希表 #字符串 #滑动窗口

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> hs, ht;
    int i = 0, j = 0, count = 0;
    string result = "";

    for (char s : t) {
      ht[s]++;
    }

    while (j < s.length()) {
      char c = s[j];
      hs[c]++;

      if (hs[c] <= ht[c]) {
        // 说明新加入的这个是必要的
        count++;
      }
      while (hs[s[i]] > ht[s[i]]) {
        // 去除不必要的
        hs[s[i++]]--;
      }

      if (count == t.length()) {
        if (result.empty() || j - i + 1 < result.length()) {
          result = s.substr(i, j - i + 1);
        }
      }
      j++;
    }

    return result;
  }
};
