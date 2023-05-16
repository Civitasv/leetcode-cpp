#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
class mycomp2 {
public:
  bool operator()(const int &i, const int &j) {
    return i < j; // 告诉他我是升序的
  }
};
int main() {
  vector<int> data{1, 2, 3, 5, 7};

  auto iter = lower_bound(data.begin(), data.end(), 3);
  cout << *iter << '\n';

  auto iter2 = upper_bound(data.begin(), data.end(), 3);
  cout << *iter2 << '\n';
  auto iter3 = upper_bound(data.begin(), data.end(), 3, mycomp2());
  cout << *iter3 << '\n';

  make_heap(data.begin(), data.end(), greater<>());

  for (int item : data)
    cout << item << ' ';
  cout << '\n';
  data.push_back(2);

  push_heap(data.begin(), data.end(), greater<>());
  for (int item : data)
    cout << item << ' ';
  cout << '\n';
  pop_heap(data.begin(), data.end(), greater<>());
  for (int item : data)
    cout << item << ' ';
  cout << '\n';
  nth_element(data.begin(), data.begin() + 2, data.end());
  for (int item : data)
    cout << item << ' ';
  cout << '\n';

  make_heap(data.begin(), data.end(), greater<>());
  sort_heap(data.begin(), data.end(), greater<>());
  for (int item : data)
    cout << item << ' ';
  cout << '\n';
  cout << "PARTIONS::: " << '\n';
  vector<int> val{2, 3, 1, 4, 5};
  auto iter4 = partition_point(val.begin(), val.end(), [&val](int item) {
    return item > *(val.begin());
  });
  for (int item : val)
    cout << item << ' ';
  cout << '\n';

  cout << *iter4;
  cout << '\n';
  cout << "PARTIONS END::: " << '\n';

  string a = "hello", b = "llo";
  auto iter5 = find_first_of(a.begin(), a.end(), b.begin(), b.end());
  cout << *iter5 << '\n';

  vector<int> set1{1, 2, 3, 4, 5};
  vector<int> set2{1, 2, 3};
  cout << "INCLUDE: "
       << includes(set1.begin(), set1.end(), set2.begin(), set2.end()) << '\n';
  struct Data {
    Data() { cout << "CONSTRUCTOR" << '\n'; }
    Data(const Data &data) { cout << "Copy construtor" << '\n'; }
    Data &operator=(const Data &data) {
      cout << "Copy assignment" << '\n';
      return *this;
    }
  };
  shared_ptr<Data> p(new Data);
  // shared_ptr<Data> p2 = make_shared<Data>();
  return 0;
}