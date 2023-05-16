#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Data {
  int money;
  int A;
  int B;
  int C;
};

int main() {
  int N;
  cin >> N;

  vector<string> votes;
  for (int i = 0; i < N; i++) {
    cin >> votes[i];
  }

  vector<vector<int>> activities(3, vector<int>(2, 0));
  for (int i = 0; i < 3; i++) {
    cin >> activities[i][0] >> activities[i][1];
  }

  // solve
  vector<vector<Data>> dp(N, vector<Data>(3, {0, 0, 0, 0}));
  for (char c : votes[0]) {
    if (c == 'A') {
      dp[0][0] = {activities[0][1], activities[0][0] - 1, activities[0][1],
                  activities[2][0]};
    } else if (c == 'B') {
      dp[0][1] = {activities[1][1], activities[1][0] - 1, activities[1][1],
                  activities[2][0]};
    } else if (c == 'C') {
      dp[0][2] = {activities[2][1], activities[2][0] - 1, activities[2][1],
                  activities[2][0]};
    }
  }

  for (int i = 1; i < N; i++) {
    bool find = false;
    for (char c : votes[i]) {
      // 判断还能不能选这个活动，如果三个活动都不能选，那么就不合理
    }
  }
}