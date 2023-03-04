#pragma once
#include <string>
using namespace std;

class Solution {
public:
  string printBin(double num) {
    // 0.72
    string result = "0.";
    while (result.size() <= 32 && num != 0) {
      num *= 2;
      int x = num;
      result.push_back('0' + x);
      num -= x;
    }
    return result.size() <= 32 ? result : "ERROR";
  }
};