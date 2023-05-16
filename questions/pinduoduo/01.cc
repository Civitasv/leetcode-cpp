#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string ss;
  cin >> ss;

  stringstream decode_str;
  int i = 0;
  while (i < ss.size()) {
    if (ss[i] >= '1' && ss[i] <= '9') {
      int j = i + 1;
      while (j < ss.size() && ss[j] >= '0' && ss[j] <= '9')
        j++;
      string count_str = ss.substr(i, j - i);
      char c = ss[j];
      int count = stoi(count_str);
      for (int k = 0; k < count; k++) {
        decode_str << c;
      }
      i = j + 1;
    } else {
      decode_str << ss[i];
      i++;
    }
  }
  cout << decode_str.str();
}