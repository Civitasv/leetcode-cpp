#pragma once
#include <exception>
#include <stdexcept>
#include <vector>

using namespace std;

class Heap {
private:
  vector<int> data;
  int size;

public:
  Heap() : data({0}), size(0) {}

  void Push(int val) {
    data.push_back(val);
    ShiftUp(data.size() - 1);
    size++;
  }

  int Pop() {
    if (size == 0) {
      throw overflow_error("Data size");
    }
    int res = data[1];
    swap(*(data.begin() + 1), *(data.end() - 1));
    data.erase(data.end() - 1);
    size--;
    ShiftDown(1);
    return res;
  }

  int Size() { return size; }

private:
  void ShiftDown(int index) {
    int temp = data[index];
    while ((index << 1) <= size) {
      // 左: 2*i 右:2*i+1
      int child = index << 1;
      if (child != size && data[child + 1] < data[child]) {
        // 使用右节点
        child++;
      }
      if (temp > data[child]) {
        data[index] = data[child];
        index = child;
      } else {
        break;
      }
    }
    data[index] = temp; // swap
  }

  void ShiftUp(int index) {
    int temp = data[index];

    while ((index >> 1) > 0) {
      if (temp < data[index >> 1]) {
        data[index] = data[index >> 1];
        index = index >> 1;
      } else
        break;
    }
    data[index] = temp;
  }
};