// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/offer_II/009.h"

using namespace std;

int main() {
  Solution s;

  vector<int> data = {10, 5, 2, 6};
  auto result = s.numSubarrayProductLessThanK(data, 100);
  cout << result;
  return 0;
}
