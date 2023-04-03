#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>

using namespace std;

void dfs(const vector<char> &nodes, int &count, int index) {
  if (index >= nodes.size())
    return;

  char left = 2 * index < nodes.size() ? nodes[2 * index] : 0;
  char right = 2 * index + 1 < nodes.size() ? nodes[2 * index + 1] : 0;
  if (left != right) {
    count++;
  }

  dfs(nodes, count, index * 2);
  dfs(nodes, count, index * 2 + 1);
}

int main() {
  int n;
  cin >> n;
  int number = 1;
  for (int i = 0; i < n; i++)
    number *= 2;
  vector<char> nodes(number, '0');
  for (int i = 1; i < number; i++)
    cin >> nodes[i];

  // solve
  int count = 0;
  dfs(nodes, count, 1);
  int result = 1;
  for (int i = 0; i < count; i++) {
    result = (result * 2) % 1000000007;
  }
  cout << result;
}