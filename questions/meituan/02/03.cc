#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;

    vector<int> food(N, 0);
    for (int i = 0; i < N; i++) {
      cin >> food[i];
    }

    int pre = food[0], curr;

    int result = INT32_MIN;
    for (int i = 1; i < 2 * N; i++) {
      int max_val = INT32_MIN;
      for (int j = 0; j < min(i, N); j++) {
        if (j == 0)
          curr = food[i % N];
        else
          curr = max(pre, 0) + food[i % N];
        max_val = max(max_val, curr);
        pre = curr;
      }
      result = max(result, max_val);
    }
    cout << result << '\n';
  }
}
// 64 位输出请用 printf("%lld")