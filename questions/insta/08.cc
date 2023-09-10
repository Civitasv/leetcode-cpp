#include <iostream>
#include <vector>
using namespace std;

int MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long result = 0;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    dp[i][i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (j >= 1) {
        dp[i][j] = dp[i][j - 1] + (j - i + 1) * a[j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      result = (result % MOD + dp[i][j] % MOD) % MOD;
    }
  }

  cout << result << endl;
}
// 64 位输出请用 printf("%lld")