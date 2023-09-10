#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  double P;

  vector<vector<double>> prices;
  cin >> N >> M >> P;
  for (int i = 0; i < M; i++) {
    vector<double> price(N, 0);
    for (int j = 0; j < N; j++) {
      cin >> price[j];
    }

    prices.push_back(price);
  }

  // Answer
  vector<vector<double>> dp(M, vector<double>(N, 0.0));
  for (int i = 0; i < N; i++) {
    dp[0][i] = 1.0;
  }

  for (int t = 1; t < M; t++) {
    for (int i = 0; i < N; i++) {
      double max_cash = dp[t - 1][i];
      for (int j = 0; j < N; j++) {
        if (j != i) {
          double another =
              dp[t - 1][j] * prices[t][i] * (1.0 - P) + dp[t - 1][i];
          max_cash = max(max_cash, another);
        }
      }

      dp[t][i] = max_cash;
    }
  }

  double max_cash = 0.0;
  for (int i = 0; i < N; i++) {
    max_cash = max(max_cash, dp[M - 1][i]);
  }

  printf("%.1f", max_cash);
}
// 64 位输出请用 printf("%lld")