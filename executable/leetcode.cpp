// leetcode-vs.cpp : Defines the entry point for the application.

#include <iostream>
#include <vector>

#include "questions/carl/back_track/17.h"

using namespace std;

int main() {
  Solution s;
  auto res = s.letterCombinations("23");
  for (auto& item : res) {
    cout << item << ' ';
  }
}
