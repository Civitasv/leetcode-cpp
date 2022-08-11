#pragma once

#include <iostream>
#include <map>
using namespace std;

class Solution {
 public:
  bool equal(int a[], int b[], int size) {
    for (int i = 0; i < size; i++)
      if (a[i] != b[i]) return false;

    return true;
  }

  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    int alphabets[26] = {0}, alphabets2[26] = {0};
    for (int k = 0; k < s1.size(); k++) {
      alphabets[s1[k] - 'a']++;
      alphabets2[s2[k] - 'a']++;
    }
    int i = s1.size();
    while (i < s2.size()) {
      if (equal(alphabets, alphabets2, 26)) return true;

      // slide to right
      alphabets2[s2[i - s1.size()] - 'a']--;
      alphabets2[s2[i] - 'a']++;
      i++;
    }
    return equal(alphabets, alphabets2, 26);
  }
};
