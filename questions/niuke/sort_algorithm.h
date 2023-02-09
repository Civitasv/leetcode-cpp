#pragma once

#include <vector>

namespace {
inline void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
}; // namespace

// 选择排序
// 对于每一个索引，在该索引之后选择一个最小的值，然后与该索引交换
// 这样就能确保获得每一个最小的值
inline void select_sort(std::vector<int> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    int ele = arr[i];
    int min_index = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    swap(&arr[i], &arr[min_index]);
  }
}

// 插入排序
// 要求0-i必须是有序的，对于arr[i]，判断其在 0-i 内插入的索引即可
inline void insert_sort(std::vector<int> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    int a = arr[i];
    int j = i;
    while (j > 0 && arr[j - 1] > a) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = a;
  }
}

namespace {
void merge(std::vector<int> &arr, int lo, int mid, int hi);

inline void helper(std::vector<int> &arr, int lo, int hi) {
  if (lo >= hi)
    return;

  int mid = lo + ((hi - lo) >> 1);
  // left
  helper(arr, lo, mid);
  // right
  helper(arr, mid + 1, hi);
  merge(arr, lo, mid, hi);
}

inline void merge(std::vector<int> &arr, int lo, int mid, int hi) {
  static std::vector<int> aux(arr.size(), 0);
  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; k++) {
    aux[k] = arr[k];
  }
  for (int k = lo; k <= hi; k++) {
    if (i > mid)
      arr[k] = aux[j++];
    else if (j > hi)
      arr[k] = aux[i++];
    else if (aux[i] < aux[j])
      arr[k] = aux[i++];
    else
      arr[k] = aux[j++];
  }
}

inline int partition(std::vector<int> &arr, int lo, int hi) {
  int partition = arr[hi];
  int index = lo;
  for (int i = lo; i < hi; i++) {
    if (arr[i] < partition) {
      swap(&arr[i], &arr[index++]);
    }
  }
  swap(&arr[hi], &arr[index]);
  return index;
}
}; // namespace

// 归并排序
// 归并排序的重点是对数组的两部分分别排序，然后将结果归并
inline void merge_sort(std::vector<int> &arr) {
  helper(arr, 0, arr.size() - 1);
}

inline void quick_sort(std::vector<int> &arr, int lo, int hi) {
  if (lo >= hi)
    return;
  // 分治
  int index = partition(arr, lo, hi);
  quick_sort(arr, lo, index - 1);
  quick_sort(arr, index + 1, hi);
}