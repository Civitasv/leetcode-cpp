#pragma once

#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  int max(vector<int> &gifts) {
    int index = 0;
    int max = gifts[0];
    for (int i = 1; i < gifts.size(); i++) {
      if (gifts[i] > max) {
        max = gifts[i];
        index = i;
      }
    }
    return index;
  }

  long long pickGifts(vector<int> &gifts, int k) {
    for (int i = 0; i < k; i++) {
      int index = max(gifts);
      gifts[index] = sqrt(gifts[index]);
    }
    long long sum = 0;
    for (int gift : gifts)
      sum += gift;
    return sum;
  }
};