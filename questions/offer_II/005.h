#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int length = words.size();
    vector<int> masks(length, 0);

    for (int i = 0; i < length; i++) {
      for (char c : words[i]) {
        masks[i] |= (1 << c - 'a');
      }
    }
    int max_prod = 0;
    for (int i = 0; i < length; i++) {
      for (int j = i + 1; j < length; j++) {
        if ((masks[i] & masks[j]) == 0) {
          max_prod = max(max_prod, (int)(words[i].size() * words[j].size()));
        }
      }
    }
    return max_prod;
  }
};