#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void Solve(int M, int N, vector<int> &number, string &op, vector<int> &L,
           vector<int> &R, vector<int> &X) {
  unordered_map<int, vector<pair<char, int>>> mp;
  for (int i = 0; i < M; i++) {
    int l = L[i] - 1, r = R[i] - 1, x = X[i];

    switch (op[i]) {
    case '|':
    case '&':
      for (int j = l; j <= r; j++) {
        mp[j].push_back({op[i], X[i]});
      }
      break;
    case '=':
      for (int j = l; j <= r; j++) {
        mp[j].clear();
        mp[j].push_back({'=', X[i]});
      }
      break;
    }
  }
  for (auto &item : mp) {
    for (auto &op_item : item.second) {
      if (op_item.first == '|') {
        number[item.first] |= op_item.second;
      } else if (op_item.first == '&') {
        number[item.first] &= op_item.second;
      } else if (op_item.first == '=') {
        number[item.first] = op_item.second;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << number[i] << ' ';
  }
}

int main() {
  int N; // 数组长度
  cin >> N;
  vector<int> number(N, 0); // 数组元素
  for (int i = 0; i < N; i++)
    cin >> number[i];
  int M; // 操作次数
  cin >> M;
  vector<int> L(M, 0); // 左端点
  for (int i = 0; i < M; i++)
    cin >> L[i];
  vector<int> R(M, 0); // 右端点
  for (int i = 0; i < M; i++)
    cin >> R[i];
  string op; // 操作
  cin >> op;
  vector<int> X(M, 0); // 操作的参数
  for (int i = 0; i < M; i++)
    cin >> X[i];

  Solve(N, M, number, op, L, R, X);
}
