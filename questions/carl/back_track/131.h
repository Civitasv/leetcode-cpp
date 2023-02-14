#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    backTracking(res, path, s, 0);
    return res;
  }

  void backTracking(vector<vector<string>> &res, vector<string> &path,
                    string &s, int start) {
    if (start >= s.size()) {
      res.push_back(path);
      return;
    }

    for (int i = start; i < s.size(); i++) {
      if (isPalindrome(s, start, i)) {
        path.push_back(s.substr(start, i - start + 1));
        backTracking(res, path, s, i + 1);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string &s, int start, int end) {
    int lo = start, hi = end;
    while (lo <= hi) {
      if (s[lo] != s[hi])
        return false;
      lo++;
      hi--;
    }
    return true;
  }
};