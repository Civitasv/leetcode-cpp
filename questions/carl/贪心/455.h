#pragma once

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    int index = 0;

    for (int i = 0; i < g.size(); i++) {
      while (index < s.size() && s[index] < g[i]) {
        index++;
      }
      if (index < s.size()) {
        index++;
        count++;
      } else
        break;
    }

    return count;
  }
};