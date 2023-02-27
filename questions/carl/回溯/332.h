#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, map<string, int>>
        um;  // k: 航班 [v: [k: 航班] [v: 飞往次数]]，
             // 此处选择 map 的原因是 map 是有序的，默认按照字典序排序
    for (auto& vec : tickets) {
      um[vec[0]][vec[1]]++;
    }
    vector<string> result{"JFK"};
    backTracking(result, um, tickets);
    return result;
  }

  bool backTracking(vector<string>& result,
                    unordered_map<string, map<string, int>>& um,
                    vector<vector<string>>& tickets) {
    if (result.size() == tickets.size() + 1) return true;

    map<string, int>& mp = um[*(result.end() - 1)];
    for (auto& item : mp) {
      if (item.second > 0) {
        result.push_back(item.first);
        item.second--;
        if (backTracking(result, um, tickets)) return true;
        result.pop_back();
        item.second++;
      }
    }
    return false;
  }
};