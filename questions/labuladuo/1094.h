﻿#pragma once
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    if (trips.size() == 0)
      return true;

    // 构建差分数组
    vector<int> diff(10001, 0);
    for (auto &item : trips) {
      diff[item[1]] += item[0];
      diff[item[2]] -= item[0];
    }

    // 构建原始数组
    vector<int> passengers(10001, 0);
    for (int i = 0; i < 10001; i++) {
      if (i == 0)
        passengers[0] = diff[0];
      else
        passengers[i] = passengers[i - 1] + diff[i];

      if (passengers[i] > capacity)
        return false;
    }
    return true;
  }
};