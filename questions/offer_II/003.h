#pragma once

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    // 如果正整数 i 是一个偶数，那么 i 相当于将 i/2
    // 左移一位的结果，因此偶数 i 和 i/2 的二进制形式 1 的个数是一样的 如果 i
    // 是奇数，那么 i 相当于将 i/2 左移一位之后再将最右边的位设为 1
    // 的结果，因此奇数 i 比 i/2 的二进制形式 1 的个数多 1 个
    // 可以利用这个规律有如下代码
    vector<int> result(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      result[i] = result[i >> 1] + (i & 1);
    }

    return result;
  }
};