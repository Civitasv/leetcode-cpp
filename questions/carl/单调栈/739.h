#pragma once

#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> answer(temperatures.size(), 0);
    stack<int> st;

    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int index = st.top();
        st.pop();
        answer[index] = i - index;
      }

      st.push(i);
    }

    return answer;
  }
};