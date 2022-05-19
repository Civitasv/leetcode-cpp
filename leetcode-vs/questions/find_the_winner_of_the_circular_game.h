#include <iostream>
#include <vector>

class Solution {
public:
  int findTheWinner(int n, int k) {
    int count = 0, curr = 0;
    std::vector<bool> vi(n, false);
    while (count < n - 1) {
      // choose one to kick out
      int kick_index = curr - 1;
      int c = 0;
      while (c < k) {
        kick_index = the_next(n, kick_index);
        if (!vi[kick_index]) {
          c++;
        }
      }
      vi[kick_index] = true;
      curr = kick_index;
      count++;
    }
    for (int i = 0; i < n; i++)
      if (vi[i] == false)
        return i + 1;
    return -1;
  }

  int the_next(int n, int i) {
    if (i == n - 1) {
      return 0;
    }
    return i + 1;
  }
};

