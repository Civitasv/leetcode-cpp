#pragma once
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class Solution {
  class MaxQueue {
  private:
    deque<int> dq;
  public:
    void pop(int value) {
      if (!dq.empty() && dq.front() == value) {
        dq.pop_front();
      }
    }

    void push(int value) {
      while (!dq.empty() && dq.back() < value) {
        dq.pop_back();
      }
      dq.push_back(value);
    }

    int max() {
      return dq.front();
    }
  };
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 单调队列，从小到大
    MaxQueue q;
    vector<int> res;
    for (int i = 0; i < min(k, (int)nums.size()); i++) {
      q.push(nums[i]);
    }
    res.push_back(q.max());
    for (int i = k; i < nums.size(); i++) {
      q.pop(nums[i - k]);
      q.push(nums[i]);
      res.push_back(q.max());
    }

    return res;
  }
};
