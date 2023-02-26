#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> divisibilityArray(string word, int m) {
    size_t n = word.length();
    size_t len = 0;
    int temp = m;
    while (temp != 0) {
      temp /= 10;
      len++;
    }

    vector<int> div(n, 0);

    long long mod = 0;
    for (int i = 0; i < n; i++) {
      mod = divisibility(word, i, m, len, mod);
      if (mod == 0)
        div[i] = 1;
      else
        div[i] = 0;
    }

    return div;
  }

  long long divisibility(const string &word, int index, int m, size_t len,
                         long long last_mod) {
    int n = word[index] - '0';
    return (n + last_mod * 10) % m;
  }
};
