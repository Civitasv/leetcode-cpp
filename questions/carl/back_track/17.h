#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits == "") return {""};

    vector<string> res;
    string item;
    unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    backTracking(res, item, map, 0, digits);
    return res;
  }

  void backTracking(vector<string>& res, string& item,
                    unordered_map<char, string>& map, int start,
                    string& digits) {
    if (item.size() + digits.size() - start < digits.size()) return;

    if (item.size() == digits.size()) {
      res.push_back(item);
      return;
    }
    for (int i = start; i < digits.size(); i++) {
      for (int j = 0; j < map[digits[i]].size(); j++) {
        item.push_back(map[digits[i]][j]);
        backTracking(res, item, map, i + 1, digits);
        item.pop_back();
      }
    }
  }
};