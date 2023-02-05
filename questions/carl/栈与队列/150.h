#pragma once
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string& token : tokens) {
      if (token == "+") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(a + b);
      }
      else if (token == "-") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(a - b);
      }
      else if (token == "*") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(a * b);
      }
      else if (token == "/") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(b / a);
      }
      else {
        st.push(stoi(token));
      }
    }

    return st.top();
  }
};