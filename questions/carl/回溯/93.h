#pragma once
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string str) {
    vector<string> result;
    backTrack(result, 0, 0, str);
    return result;
  }

  void backTrack(vector<string> &result, int start, int pointNum, string &str) {
    if (pointNum == 3) {
      if (isValid(str, start, str.size() - 1)) {
        result.push_back(str);
      }
      return;
    }
    for (int i = start; i < str.size(); i++) {
      if (isValid(str, start, i)) {
        str.insert(str.begin() + i + 1, '.');
        pointNum++;
        backTrack(result, i + 2, pointNum, str);
        pointNum--;
        str.erase(str.begin() + i + 1);
      }
    }
  }

  bool isValid(string &str, int start, int end) {
    if (start > end)
      return false;
    if (str[start] == '0' && start != end)
      return false;
    int num = 0;
    for (int i = start; i <= end; i++) {
      if (str[i] > '9' || str[i] < '0')
        return false;
      num = num * 10 + (str[i] - '0');
      if (num > 255)
        return false;
    }
    return true;
  }
};
