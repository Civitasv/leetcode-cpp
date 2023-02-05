// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/carl/栈与队列/150.h"

using namespace std;

int main() {
  Solution s;
  vector<string> tokens = { "4", "13", "5", "/", "+" };
  cout << s.evalRPN(tokens);
}
