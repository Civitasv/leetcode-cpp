#pragma once
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> st;

    for (char c : s) {
      if (!st.empty() && st.top() == c) {
        st.pop();
      }
      else st.push(c);
    }

    string res;
    res.resize(st.size());
    int index = st.size() - 1;
    while (!st.empty()) {
      char c = st.top();
      res[index--] = c;
      st.pop();
    }

    return res;
  }
};