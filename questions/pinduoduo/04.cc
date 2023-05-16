#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// 87%
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> data(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> data[i];
  }
  double sum = 0;
  vector<int> a(N, 0);
  vector<int> b(N, 0);
  vector<int> sort_data(N, 0);
  int index = 0;
  for (int i = 0; i < N; i++) {
    sum += data[i];
    double divide = sum / (i + 1);
    a[i] = sum / (i + 1);
    a[i] += (divide - a[i] >= 0.5 ? 1 : 0);
    int j = index;
    sort_data[j] = data[i];
    while (j > 0) {
      if (sort_data[j] < sort_data[j - 1]) {
        swap(sort_data[j], sort_data[j - 1]);
        j--;
      } else
        break;
    }
    index++;
    if (index % 2 == 0) {
      int xx = sort_data[index / 2];
      int yy = sort_data[index / 2 - 1];
      double divide = (xx + yy) / 2.0;
      b[i] = (xx + yy) / 2;
      b[i] += (divide - b[i] >= 0.5 ? 1 : 0);
    } else {
      b[i] = sort_data[index / 2];
    }
  }

  for (int i = 0; i < N; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < N; i++) {
    cout << b[i] << ' ';
  }
}