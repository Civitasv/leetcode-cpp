#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool TheSame(long long n) {
  int i = n % 10;
  n /= 10;
  while (n) {
    if (n % 10 != i)
      return false;
    n /= 10;
  }
  return true;
}

int main() {
  string M;
  int N;
  char k; // 加减乘

  cin >> M;
  cin >> N;
  cin >> k;

  long long max_val = INT32_MIN;

  for (int i = 0; i < M.size(); i++) {
    for (int j = i + 2; j < i + 11 && j < M.size(); j++) {
      switch (k) {
      case '-': {
        long long a = stoll(M.substr(i, j - i + 1));
        int b = a - N;
        if (TheSame(b))
          max_val = max(max_val, a);
        break;
      }
      case '+': {
        long long a = stoll(M.substr(i, j - i + 1));
        int b = a + N;
        if (TheSame(a))
          max_val = max(max_val, a);
        break;
      }
      case '*': {
        long long a = stoll(M.substr(i, j - i + 1));
        int b = a * N;
        if (TheSame(a))
          max_val = max(max_val, a);
        break;
      }
      }
    }
  }

  cout << (max_val == INT32_MIN ? -1 : max_val) << endl;
}