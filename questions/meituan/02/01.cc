#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> result;
  string line;
  getline(cin, line);
  while (!line.empty()) {
    int n, m, a, b;
    int pos = 0, pre = 0;
    pos = line.find(' ', pre);
    n = stoi(line.substr(pre, pos - pre));
    pre = pos + 1;
    pos = line.find(' ', pre);
    m = stoi(line.substr(pre, pos - pre));
    pre = pos + 1;
    pos = line.find(' ', pre);
    a = stoi(line.substr(pre, pos - pre));
    pre = pos + 1;
    pos = line.find(' ', pre);
    b = stoi(line.substr(pre, pos - pre));
    pre = pos + 1;

    vector<int> cakes(m, 0);
    for (int i = 0; i < m; i++)
      cin >> cakes[i];

    // Solve
    sort(cakes.begin(), cakes.end());

    int min_weight = cakes[0], max_weight = cakes[cakes.size() - 1];
    int aa = min(a, b), bb = max(a, b);
    if (min_weight == aa && max_weight == bb) {
      result.emplace_back("YES");
    } else if (min_weight == aa) {
      if (max_weight > bb)
        result.emplace_back("NO");
      else {
        result.emplace_back(m < n ? "YES" : "NO");
      }
    } else if (max_weight == bb) {
      if (min_weight < aa)
        result.emplace_back("NO");
      else {
        result.emplace_back(m < n ? "YES" : "NO");
      }
    } else if (min_weight == bb || max_weight == aa) {
      result.emplace_back(m < n ? "YES" : "NO");
    } else if (min_weight < aa || max_weight > bb) {
      result.emplace_back("NO");
    } else {
      result.emplace_back(m <= n - 2 ? "YES" : "NO");
    }

    getchar();
    // next case
    getline(cin, line);
  }

  for (auto &item : result) {
    cout << item << '\n';
  }
}
// 64 位输出请用 printf("%lld")