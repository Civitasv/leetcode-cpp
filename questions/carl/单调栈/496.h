#pragma once

#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    vector<int> nums2_res(nums2.size(), -1);
    vector<int> nums1_res(nums1.size(), 0);

    unordered_map<int, int> um;
    for (int i = 0; i < nums2.size(); i++) {
      um[nums2[i]] = i;
    }

    for (int i = 0; i < nums2.size(); i++) {
      while (!st.empty() && nums2[i] > nums2[st.top()]) {
        int index = st.top();
        st.pop();
        nums2_res[index] = nums2[i];
      }
      st.push(i);
    }

    for (int i = 0; i < nums1.size(); i++) {
      nums1_res[i] = nums2_res[um[nums1[i]]];
    }

    return nums1_res;
  }
};
