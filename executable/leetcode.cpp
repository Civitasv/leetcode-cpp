// leetcode-vs.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

#include "questions/offer_II/003.h"

using namespace std;

int main() {
  Solution s;

  auto result = s.countBits(5);
  for (auto& item : result) {
    std::cout << item << ' ';
  }

  return 0;
}
