#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T; // 关卡
  int N; // 敌人

  cin >> T >> N;
  if (T <= 0 || N < 0)
    return 0;

  vector<int> hp(N, 0);
  vector<int> result(T, 0);

  for (int i = 0; i < T; i++) {
    for (int j = 0; j < N; j++) {
      cin >> hp[j];
    }

    // solve
    // 贪心算法，先杀掉血量最低的
    int count = 0;
    sort(hp.begin(), hp.end());
    int index = 0;
    while (index < N) {
      if (index + 1 >= N) {
        count++;
        break;
      }
      int a = hp[index];
      int b = hp[index + 1];
      count += 1;
      hp[index]--;
      hp[index + 1]--;
      if (hp[index] == 0 && hp[index + 1] == 0)
        index += 2;
      else if (hp[index] == 0)
        index++;
    }
    result[i] = min(count, N);
  }

  for_each(result.begin(), result.end(),
           [](int item) { cout << item << '\n'; });

  return 0;
}