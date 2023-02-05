#pragma once

#include <queue>
using namespace std;

class MyStack {
private:
  queue<int> q1;
  queue<int> q2;

public:
  MyStack() :q1(), q2() {

  }

  void push(int x) {
    // 1. q2 => q1
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
    // 2. push => q2
    q2.push(x);
    // 3. q1 => q2
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
  }

  int pop() {
    int data = q2.front();
    q2.pop();
    return data;
  }

  int top() {
    return q2.front();
  }

  bool empty() {
    return q2.empty();
  }
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/
