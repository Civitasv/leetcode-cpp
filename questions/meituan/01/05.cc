#include <iostream>
using namespace std;

int main() {
  // 10 = 2*5 = 1*10
  // 100 =
  int n;
  cin >> n;
  int count_five = 0, temp = 0;
  for (int i = 5; i <= n; i++) {
    int num = i;
    while (num % 5 == 0) {
      num /= 5;
      temp++;
    }
    count_five += temp;
  }
  cout << count_five;
}
// 64 位输出请用 printf("%lld")