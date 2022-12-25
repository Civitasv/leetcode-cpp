#pragma once

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  double trimMean(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int sum = 0;
    for (int i = n * 0.05; i < n * 0.95; i++) {
      sum += arr[i];
    }

    return sum / (0.9 * n);
  }
};