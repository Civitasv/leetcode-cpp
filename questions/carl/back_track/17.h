#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0)
      return {};

    vector<string> res;
    string item;
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    backTracking(res, item, map, 0, digits);
    return res;
  }

  void backTracking(vector<string> &res, string &item,
                    unordered_map<char, string> &map, int index,
                    string &digits) {
    if (index == digits.size()) {
      res.push_back(item);
      return;
    }
    char digit = digits[index];
    for (int j = 0; j < map[digit].size(); j++) {
      item.push_back(map[digit][j]);
      backTracking(res, item, map, index + 1, digits);
      item.pop_back();
    }
  }
};