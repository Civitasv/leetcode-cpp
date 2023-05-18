#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  stack<int> s;
  int n;
  string str;
  getline(cin, str);
  int sum = 0;

  int curr = 0, npos;

  while (true) {
    npos = str.find(' ', curr);

    if (npos != string::npos) {
      n = stoi(str.substr(curr, npos - curr + 1));
      curr = npos + 1;
    } else {
      n = stoi(str.substr(curr));
    }

    if (!s.empty() && n == s.top()) {
      sum -= s.top();
      s.pop();
      s.push(2 * n);
      sum += 2 * n;
    } else if (!s.empty() && n == sum) {
      sum = 0;
      while (!s.empty())
        s.pop();

      s.push(2 * n);
      sum += 2 * n;
    } else {
      s.push(n);
      sum += n;
    }
    if (npos == string::npos)
      break;
  }

  while (!s.empty()) {
    cout << s.top() << ' ';
    s.pop();
  }
}