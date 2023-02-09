#pragma once

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isVowel(const string &word) {
    return (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' ||
            word[0] == 'o' || word[0] == 'u') &&
           (word[word.length() - 1] == 'a' || word[word.length() - 1] == 'e' ||
            word[word.length() - 1] == 'i' || word[word.length() - 1] == 'o' ||
            word[word.length() - 1] == 'u');
  }
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    vector<int> result;
    bool is_vowel[words.size()];
    for (int i = 0; i < words.size(); i++) {
      is_vowel[i] = isVowel(words[i]);
    }
    vector<int> pfx_sum(words.size() + 1, 0);
    for (int i = 0; i < words.size(); i++) {
      pfx_sum[i + 1] = is_vowel[i] + pfx_sum[i];
    }

    for (vector<int> &query : queries) {
      int l = query[0], r = query[1];
      int count = pfx_sum[r + 1] - pfx_sum[l];
      result.push_back(count);
    }
    return result;
  }
};