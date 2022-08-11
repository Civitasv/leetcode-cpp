#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> result;

    helper(result, "", 0, s);

    return result;
  }

  void helper(vector<string> &result, string curr, int start, string s) {
    for (int i = start; i < s.size(); i++) {
      // choose
      curr.push_back(s[i]);

      // explore
      helper(result, curr, i + 1, s);

      // unchoose
      curr.pop_back();
      if (isalpha(s[i]))
        curr.push_back(s[i] >= 'a' && s[i] <= 'z' ? toupper(s[i])
                                                  : tolower(s[i]));
    }

    if (curr.size() == s.size()) {
      result.push_back(curr);
    }
  }
};
