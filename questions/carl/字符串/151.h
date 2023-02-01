#pragma once

#include <string>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    // 1. �Ƴ�����ո�
    int slow = 0, fast = 0;
    // 1.1 ǰ���ո�
    while (s.length() > 0 && fast < s.length() && s[fast] == ' ') fast++;

    // 1.2 �ַ����м�Ŀո�
    while (fast < s.length()) {
      if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
      } else {
        s[slow++] = s[fast];
      }
      fast++;
    }

    // 1.3 �󵼿ո�
    if (slow - 1 > 0 && s[slow - 1] == ' ') {
      s.resize(slow - 1);
    } else {
      s.resize(slow);
    }

    // 2. reverse �ַ���
    reverse(s.begin(), s.end());

    // 3. reverse ����
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
