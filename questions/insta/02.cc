#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> result(m + 1, 0); // 包括小红的金额
  for (int i = 0; i < n; i++) {
    int k, c;
    cin >> k >> c;

    int per = ceil((c * 1.0) / k);

    vector<int> others(k - 1, 0);

    for (int j = 0; j < k - 1; j++) {
      cin >> others[j];
      result[others[j]] += per;
    }
  }

  for (int i = 1; i <= m; i++) {
    cout << result[i] << " ";
  }
}
// 64 位输出请用 printf("%lld")