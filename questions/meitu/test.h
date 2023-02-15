#pragma once
#include <iostream>

inline int f() {
  int x = 5;
  int y = 4;
  int& const q = x;
  int* const q2 = &x;
  int* p = &x;

  *q2 = 20;
  q = 20;
  class Test {
   public:
     void Print() {

    }
  };
  std::cout << *q2;
  return 0;
}