#pragma once

#include <string>
using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int alphabets[26] = {0};

    for (char c : magazine) {
      alphabets[c - 'a']++;
    }

    for (char c : ransomNote) {
      if (alphabets[c - 'a'] <= 0)
        return false;
      alphabets[c - 'a']--;
    }

    return true;
  }
};
