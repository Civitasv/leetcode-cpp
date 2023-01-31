#pragma once

#include <string>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int alphabets[26] = {0};
    for (char c : s) {
      alphabets[c - 'a']++;
    }

    for (char c : t) {
      alphabets[c - 'a']--;
    }

    for (int a : alphabets) {
      if (a != 0)
        return false;
    }

    return true;
  }
};
