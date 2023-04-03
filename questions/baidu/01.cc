#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  unordered_map<char, int> um;
  string match = "Baidu";
  for (char c : match) {
    um[c]++;
  }

  for (int i = 0; i < t; i++) {
    string str;
    cin >> str;

    if (str.size() != 5) {
      cout << "No" << '\n';
      continue;
    }
    unordered_map<char, int> temp_um = um;

    bool find = true;
    for (char c : str) {
      if (temp_um.count(c) == 0) {
        find = false;
        break;
      }
      temp_um[c]--;
    }
    for (auto &item : temp_um) {
      if (item.second != 0) {
        find = false;
        break;
      }
    }
    cout << (find ? "Yes" : "No") << '\n';
  }
}