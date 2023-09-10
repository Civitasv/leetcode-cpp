#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  vector<int> a(n);

  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end(), greater<>());

  ll score = 0;
  vector<bool> chosen(n, false); // 记录哪些被选择了

  for (int i = 0; i < n; i++) {
    if (!chosen[i]) {
      for (int j = i + 1; j < n; j++) {
        if (!chosen[j] && abs(a[i] - a[j]) <= k) {
          score += static_cast<ll>(a[i] * a[j]);
          chosen[i] = true;
          chosen[j] = true;
          break;
        }
      }
    }
  }

  cout << score << endl;

  return 0;
}
// 64 位输出请用 printf("%lld")