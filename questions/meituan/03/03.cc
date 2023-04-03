#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n; // 流星的数量
  cin >> n;

  vector<int> attend_time(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> attend_time[i];
  }

  vector<int> leave_time(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> leave_time[i];
  }

  // 差分数组
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[attend_time[i]] += 1;
    mp[leave_time[i] + 1] -= 1;
  }

  int count = 0, max_count = 0;
  vector<pair<int, int>> p;
  for (auto &item : mp) {
    count += item.second;
    max_count = max(max_count, count);
    p.push_back({item.first, count});
  }
  int ans = 0;
  for (int i = 0; i < p.size(); i++) {
    if (p[i].second == max_count)
      ans += p[i + 1].first - p[i].first;
  }

  cout << max_count << ' ' << ans << '\n';
}