#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int Solve(int n, int x, int y, vector<int> &grades) {
  if (n < 2 * x || n > 2 * y)
    return -1;

  sort(grades.begin(), grades.end());

  int m = grades[0] - 1;
  int upgrade = n, fail = 0;

  for (int i = 0; i < grades.size(); i++) {
    m = grades[i];
    upgrade--;
    fail++;

    if (upgrade >= x && upgrade <= y && fail >= x && fail <= y) {
      return m;
    }
  }
  return -1;
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  cin.get();

  vector<int> grades(n, 0);
  for (int i = 0; i < n; i++)
    cin >> grades[i];
  cout << Solve(n, x, y, grades);
}