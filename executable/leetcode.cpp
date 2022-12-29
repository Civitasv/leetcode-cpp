// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/offer_II/012.h"

using namespace std;

int main() {
  Solution s;

  vector<int> data = {2,1,-1};
  auto result = s.pivotIndex(data);
  cout << result;
  return 0;
}
