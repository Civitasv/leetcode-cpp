#pragma once

#include <cstdlib>
#include <ctime>
#include <queue>
#include <random>
#include <vector>

using namespace std;
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    srand(time(0));
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }

  int quickSelect(vector<int> &nums, int l, int r, int index) {
    int q = randomPartition(nums, l, r);
    if (q == index) {
      return nums[q];
    }
    return q < index ? quickSelect(nums, q + 1, r, index)
                     : quickSelect(nums, l, q - 1, index);
  }

  int randomPartition(vector<int> &a, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    swap(a[i], a[r]);
    return partition(a, l, r);
  }

  int partition(vector<int> &nums, int lo, int hi) {
    int temp = nums[hi];
    int index = lo;
    for (int i = lo; i < hi; i++) {
      if (nums[i] <= temp) {
        int a = nums[i];
        swap(nums[i], nums[index++]);
      }
    }
    swap(nums[hi], nums[index]);
    return index;
  }
};