#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int Solve(int n, vector<int> &grades) {
  sort(grades.begin(), grades.end());
  int count = 0;

  for (int i = 1; i <= n; i++) {
    count += abs(grades[i - 1] - i);
  }
  return count;
}

int main() {
  int n;
  cin >> n;

  vector<int> nums(n, 0);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << Solve(n, nums);
}