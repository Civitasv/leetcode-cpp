#pragma once

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string reformat(string s) {
    int numbers_size = 0, alphabets_size = 0;

    for (auto &item : s) {
      if (item >= '0' && item <= '9') {
        numbers_size++;
      } else {
        alphabets_size++;
      }
    }

    if (abs(alphabets_size - numbers_size) > 1) {
      return "";
    }

    // 双指针
    bool flag = numbers_size > alphabets_size;
    for (int i = 0, j = 1; i < s.size(); i += 2) { // i->存放出现次数多的
      if (isdigit(s[i]) != flag) { // 当前是出现次数较少的
        // 找到出现次数多的
        while (isdigit(s[j]) != flag) {
          j += 2;
        }
        swap(s[i], s[j]);
      }
    }
    return s;
  }
};
