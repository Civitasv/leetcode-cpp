#pragma once
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  struct Compare {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
      return a.first < b.first;
    }
  };

public:
  vector<string> findRelativeRanks(vector<int> &score) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for (int i = 0; i < score.size(); i++) {
      pq.push({score[i], i});
    }

    vector<string> result(score.size());
    int index = 0;
    while (!pq.empty()) {
      auto item = pq.top();
      pq.pop();
      if (index == 0)
        result[item.second] = "Gold Medal";
      else if (index == 1)
        result[item.second] = "Silver Medal";
      else if (index == 2)
        result[item.second] = "Bronze Medal";
      else
        result[item.second] = to_string(index+1);
      index++;
    }

    return result;
  }
};