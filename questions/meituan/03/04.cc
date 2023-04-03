#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Tank { // 记录位置
  Tank(int i, int j, char direction, char tag)
      : i(i), j(j), direction(direction), tag(tag), count(0) {}
  int i;
  int j;
  char direction;
  char tag;
  int count;

  int size = 16;
  void up(vector<vector<char>> &situation) {
    if (i > 0 && situation[i - 1][j] == '0') {
      i--;
      count++;
      situation[i][j] = tag;
    }
    direction = 'U';
  }
  void down(vector<vector<char>> &situation) {
    if (i < size - 1 && situation[i + 1][j] == '0') {
      i++;
      count++;
      situation[i][j] = tag;
    }
    direction = 'D';
  }
  void left(vector<vector<char>> &situation) {
    if (j > 0 && situation[i][j - 1] == '0') {
      j--;
      count++;
      situation[i][j] = tag;
    }
    direction = 'L';
  }
  void right(vector<vector<char>> &situation) {
    if (j < size - 1 && situation[i][j + 1]) {
      j++;
      count++;
      situation[i][j] = tag;
    }
    direction = 'R';
  }

  void move(char move_direction, vector<vector<char>> &situation) {
    switch (move_direction) {
    case 'U':
      up(situation);
      break;
    case 'D':
      down(situation);
      break;
    case 'L':
      left(situation);
      break;
    case 'R':
      right(situation);
      break;
    }
  }
  bool fire(Tank &other_tank) {
    if (direction == 'U' && j == other_tank.j && i > other_tank.i) {
      return true;
    } else if (direction == 'D' && j == other_tank.j && i < other_tank.i) {
      return true;
    } else if (direction == 'L' && i == other_tank.i && j > other_tank.j) {
      return true;
    } else if (direction == 'R' && i == other_tank.i && j < other_tank.j) {
      return true;
    } else {
      return false;
    }
  }
  bool crash(Tank &other_tank) {
    return i == other_tank.i && j == other_tank.j;
  }
};

int main() {
  string dd; // 小 D 的指令
  string ww; // 小 W 的指令

  cin >> dd;
  cin >> ww;

  vector<vector<char>> situation(16, vector<char>(16, '0'));
  situation[0][0] = 'd';
  situation[15][15] = 'w';

  Tank d_tank(0, 0, 'r', 'd');
  Tank w_tank(15, 15, 'l', 'w');

  int length = 256;
  int count = 0;     // 多少个回合后结束
  char result = 'P'; // 游戏的结果

  bool find = false;
  for (int i = 0; i < length; i++) {
    char d = dd[i];
    char w = ww[i];
    bool success_d = false, success_w = false;
    if (d == 'F') {
      success_d = d_tank.fire(w_tank);
    }
    if (w == 'F') {
      success_w = w_tank.fire(d_tank);
    }
    d_tank.move(d, situation);
    w_tank.move(w, situation);

    if (success_d && success_w) {
      cout << i + 1 << '\n' << 'P' << '\n';
      find = true;
      break;
    } else if (success_d) {
      cout << i + 1 << '\n' << 'D' << '\n';
      find = true;
      break;
    } else if (success_w) {
      cout << i + 1 << '\n' << 'W' << '\n';
      find = true;
      break;
    }

    if (d_tank.crash(w_tank)) {
      cout << i + 1 << '\n' << 'P' << '\n';
      find = true;
      break;
    }
  }
  if (!find) {
    if (d_tank.count == w_tank.count) {
      cout << 256 << '\n' << 'P' << '\n';
    } else if (d_tank.count > w_tank.count) {
      cout << 256 << '\n' << 'D' << '\n';
    } else {
      cout << 256 << '\n' << 'W' << '\n';
    }
  }
}