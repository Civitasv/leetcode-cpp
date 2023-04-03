#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int Compare(vector<int> &number, vector<int> &sorted) {
  int count = 0;
  for (int i = 0; i < number.size(); i++) {
    if (number[i] != sorted[i])
      count++;
  }
  return count;
}

int Solve(vector<int> &number, int k) {
  vector<int> sorted = number;
  sort(sorted.begin(), sorted.end());

  int count = Compare(number, sorted);
  return count % k <= 1 ? count / k : count / k + 1;
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int n, k;
    cin >> n >> k;

    vector<int> number(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> number[i];
    }

    cout << Solve(number, k) << '\n';
  }
}
