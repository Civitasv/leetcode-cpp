#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

// TAG #数组 #哈希表 #滑动窗口

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int i = 0, j = 0, count = 0, type = 0;
    unordered_map<int, int> hash;

    while (j < fruits.size()) {
      int tp = fruits[j];
      if (hash.find(tp) != hash.end()) {
        if (hash[tp] == 0) {
          type++;
        }
        hash[tp]++;
      } else {
        hash[tp] = 1;
        type++;
      }

      while (type > 2) {
        int key = fruits[i++];
        hash[key]--;
        if (hash[key] == 0)
          type--;
      }
      count = max(count, j - i + 1);
      j++;
    }

    return count;
  }
};
