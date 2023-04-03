#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void dfs(long &result, long item, const string &type, const vector<long> &a,
         int x, int index) {
  if (index == a.size()) {
    result = min(result, item);
    return;
  }
  if (index + 1 >= a.size()) {
    // 1. 使用重击
    item += a[index];
    dfs(result, item, type, a, x, index + 1);
    return;
  }
  if (type[index] == type[index + 1]) {
    // 1. 使用重击
    item += a[index];
    dfs(result, item, type, a, x, index + 1);
    return;
  }

  // 作选择
  // 1. 使用重击
  item += a[index];
  dfs(result, item, type, a, x, index + 1);
  item -= a[index];

  // 2. 使用高天之歌
  if (a[index] + a[index + 1] >= x) {
    item += x;
    dfs(result, item, type, a, x, index + 2);
    item -= x;
  }
}

int main() {
  int n;
  long x;
  cin >> n >> x;

  vector<long> a(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  string type;
  cin >> type;

  long mp = INT32_MAX;
  dfs(mp, 0, type, a, x, 0);
  cout << mp;
}