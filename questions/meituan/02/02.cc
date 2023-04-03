#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> scores(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> scores[i];
  }

  // Solve
  sort(scores.begin(), scores.end(), greater<int>());
  int score = scores[x - 1];
  if (score == 0) {
    int lo = 0, hi = x - 1;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (scores[mid] == 0) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << hi + 1 << '\n';
  } else {
    int count = x;
    int index = x;
    while (index < n && scores[index] == score) {
      count++;
      index++;
    }
    cout << count << '\n';
  }
  return 0;
}
// 64 位输出请用 printf("%lld")