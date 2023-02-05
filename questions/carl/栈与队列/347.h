#pragma once
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  struct comparison {
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
      return lhs.second > rhs.second;
    }
  };
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> map;

    for(int num: nums) {
      map[num] ++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> pq;

    for(auto it = map.begin(); it!=map.end();it++){
      pq.push(*it);
      if(pq.size() > k){
        pq.pop();
      }
    }
    vector<int> res(k);
    for(int i=k-1;i>=0;i--){
      res[i] = pq.top().first;
      pq.pop();
    }
    return res;
  }
};
