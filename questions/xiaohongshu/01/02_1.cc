#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

map<int, int> mp; // number -> index

int NotSuit(vector<int> &number) {
  int count = 0;
  for (auto &item : mp) {
    if (item.first != item.second) {
      count++;
    }
  }
  return count;
}

int Solve(vector<int> &number, int k) {
  for (int i = 0; i < number.size(); i++) {
    mp[number[i]] = i + 1;
  }
  int count = NotSuit(number);
  return count % k <= 1 ? count / k : count / k + 1;
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int n, k;
    cin >> n >> k;

    vector<int> number(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> number[i];
    }

    cout << Solve(number, k) << '\n';
  }
}
