#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  cin.get();

  struct Type {
    int N;
    int M;
    string desks;
    string lines;
  };
  vector<Type> vv(T);

  for (int i = 0; i < T; i++) {
    Type type;
    cin >> type.N;
    cin.get();
    cin >> type.desks; // 就餐情况
    cin.get();
    cin >> type.M;
    cin.get();
    cin >> type.lines; // 排队情况

    // solve
    // 对于男士，优先选择已经坐有一人的餐桌，其次选择空桌
    // 对于女士，有限选择空桌，其次选择已经坐有一人的餐桌
    int one = 0, zero = 0;
    for (char c : type.desks) {
      if (c == '0')
        zero++;
      else if (c == '1')
        one++;
    }

    int last_m = 0,
        last_f = 0; // last_m 记录最小的为1(then 0)的地方，last_f 记录最小的为0(then 1)的地方

    for (int j = 0; j < type.M; j++) {
      if (type.lines[j] == 'M') {
        for (int k = last_m; k < type.N; k++) {
          if (one == 0 && type.desks[k] == '0') {
            type.desks[k] = '1';
            cout << k + 1 << '\n';
            one++;
            zero--;
            last_m = k;
            break;
          } else if (one != 0 && type.desks[k] == '1') {
            type.desks[k] = '2';
            cout << k + 1 << '\n';
            one--;
            last_m = one == 0 ? last_f : k + 1;
            break;
          }
        }
      } else if (type.lines[j] == 'F') {
        for (int k = last_f; k < type.N; k++) {
          if (zero != 0 && type.desks[k] == '0') {
            type.desks[k] = '1';
            cout << k + 1 << '\n';
            one++;
            zero--;
            last_m = min(last_m, k);
            last_f = zero == 0 ? last_m : k + 1;
            break;
          } else if (zero == 0 && type.desks[k] == '1') {
            type.desks[k] = '2';
            cout << k + 1 << '\n';
            one--;
            last_f = k + 1;
            break;
          }
        }
      }
    }
  }
}