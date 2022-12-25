#pragma once

#include <string>

using namespace std;
class Solution {
 public:
  string addBinary(string a, string b) {
    string result = "";
    int append = 0;
    int len_a = a.length();
    int len_b = b.length();
    for (int i = 0; i < max(len_a, len_b); i++) {
      int item_a = len_a - i - 1 >= 0 ? a[len_a - i - 1] - '0' : 0;
      int item_b = len_b - i - 1 >= 0 ? b[len_b - i - 1] - '0' : 0;
      int added = item_a + item_b + append;
      if (added == 2) {
        result.insert(result.begin(), '0');
        append = 1;
      } else if (added == 3) {
        result.insert(result.begin(), '1');
        append = 1;
      } else if (added == 1) {
        result.insert(result.begin(), '1');
        append = 0;
      } else if (added == 0) {
        result.insert(result.begin(), '0');
        append = 0;
      }
    }
    if (append == 1) {
      result.insert(result.begin(), '1');
    }
    return result;
  }
};