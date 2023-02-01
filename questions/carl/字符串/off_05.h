#pragma once

#include <string>
using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {
    int n = s.length();
    int new_size = n;
    for (char c : s) {
      if (c == ' ') new_size += 2;
    }

    s.resize(new_size);
    for (int i = n - 1, j = new_size - 1; i >= 0 && j >= 0; i--, j--) {
      if (s[i] == ' ') {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j -= 2;
      } else {
        s[j] = s[i];
      }
    }

    return s;
  }
};
