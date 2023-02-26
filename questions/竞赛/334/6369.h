#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> leftRigthDifference(vector<int> &nums) {
    vector<int> answer(nums.size(), 0);
    vector<int> sum(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0)
        sum[i] = sum[i - 1] + nums[i];
      else
        sum[i] = nums[i];
    }
    for (int i = 0; i < nums.size(); i++) {
      answer[i] = abs(2 * sum[i] - nums[i] - sum[nums.size() - 1]);
    }

    return answer;
  }
};
