#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int x;
  cin >> x;

  stringstream ss;
  while (x > 0) {
    if (x > ss.str().size()) {
      ss << "r";
      x -= ss.str().size();
    } else
      break;
  }
  if (x == 0)
    cout << ss.str();
  else {
    string result = ss.str();
    int index = 0;
    while (x > 0) {
      if (index % 3 == 0)
        result += 'd';
      else if (index % 3 == 1)
        result += 'e';
      else
        result += 'r';
      index++;
      x--;
    }
    cout << result;
  }
}