#pragma once
#include <string>
using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    string res = s;
    bool swap = true;  // 1. �����Ƿ�ת
    for (int i = 0; i < res.length(); i += k) {
      if (swap) {
        int size =
            min((int)res.length(), i + k);  // 2. ���С�� k ������ȫ����ת
        reverse(res.begin() + i, res.begin() + size);
        swap = false;
      } else {
        swap = true;
      }
    }
    return res;
  }
};
