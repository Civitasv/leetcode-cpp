#include <iostream>
#include <sstream>
#include <string>
using namespace std;

char prev3(char x) {
  if (x == 'a')
    return 'x';
  if (x == 'b')
    return 'y';
  if (x == 'c')
    return 'z';
  return x - 3;
}

int main() {
  int N;
  cin >> N;
  string ss;
  cin >> ss;

  stringstream result;

  for (char c : ss) {
    result << prev3(c);
  }

  cout << result.str();
}
