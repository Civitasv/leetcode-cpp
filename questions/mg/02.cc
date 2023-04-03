#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  long x;
  cin >> n >> x;

  vector<long> a(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  string type;
  cin >> type;

  long mp = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      // 使用重击
      mp += a[i];
    } else {
      if (type[i] == type[i + 1]) {
        // 对 i 使用重击
        mp += a[i];
      } else {
        // 对 i 和 i + 1 使用高天之歌
        if (a[i] + a[i + 1] >= x) {
          if (i + 2 < n && type[i + 1] != type[i + 2] && a[i + 2] > a[i]) {
            mp += a[i];
          } else {
            mp += x;
            i++;
          }
        } else {
          mp += a[i];
        }
      }
    }
  }

  cout << mp;
}