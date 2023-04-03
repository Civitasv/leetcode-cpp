#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int weight(const string &str) {
  unordered_set<char> us;
  for (char c : str) {
    us.insert(c);
  }
  return us.size();
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    int n = x + y + z + 2;
    string result = "";
    // 权值为 3:
    for (int i = 0; i < z; i++) {
      if (i == 0)
        result += "mhy";
      else {
        if (i % 3 == 0)
          result += 'm';
        else if (i % 3 == 1)
          result += 'h';
        else
          result += 'y';
      }
    }

    // 权值为 2:
    if (result.size() == 0) {
      for (int i = 0; i < y; i++) {
        if (i % 2 == 0)
          result += "yy";
        else
          result += "hh";
      }
    } else {
      result += result[result.size() - 1];
      y--;
      for (int i = 0; i < y; i++) {
        if (i % 2 == 0)
          result += "yy";
        else
          result += "hh";
      }
    }
    // 权值为 1:
    if (z == 0 && y == 0) {
      for (int i = 0; i < x; i++) {
        if (i == 0)
          result += "yyy";
        else
          result += "y";
      }
    } else if (z != 0 && y != 0) {
      result += result[result.size() - 1];
      x -= 2;
      for (int i = 0; i < x; i++) {
        if (i == 0)
          result += "yyy";
        else
          result += "y";
      }
    } else {
      result += result[result.size() - 1];
      x--;
      for (int i = 0; i < x; i++) {
        if (i == 0)
          result += "yyy";
        else
          result += "y";
      }
    }

    cout << (result.size() == n ? result : "-1") << '\n';
  }
}