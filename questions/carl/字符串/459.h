#pragma once

#include <string>
using namespace std;

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    if (s.length() == 0) return false;
    // KMP Æ¥Åä
    // next Êý×é
    vector<int> next(s.length(), 0);
    get_next(next, s);
    // Æ¥Åä
    // abababab
    return next[s.length() - 1] != 0 &&
      (s.length() % (s.length() - next[s.length() - 1]) == 0);
  }

  void get_next(vector<int>& next, const string& s) {
    int j = 0;
    next[0] = j;

    for (int i = 1; i < s.length(); i++) {
      while (j > 0 && s[i] != s[j]) {
        j = next[j - 1];
      }

      if (s[i] == s[j]) {
        j++;
      }
      next[i] = j;
    }
  }
};
