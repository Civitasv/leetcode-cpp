﻿#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i + 1 < s.size() && s[i] == s[i + 1]) {
      i++;
      count++;
    }
  }
  cout << count << '\n';
  return 0;
}