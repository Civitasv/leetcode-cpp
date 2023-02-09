#pragma once

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> pq;
    for (int num : nums) {
      pq.push(num);
    }
    for (int i = 0; i < k - 1; i++)
      pq.pop();

    return pq.top();
  }
};