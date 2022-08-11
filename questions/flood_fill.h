#pragma once

#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    helper(image, sr, sc, newColor, image[sr][sc]);
    return image;
  }
  void helper(vector<vector<int>> &image, int sr, int sc, int newColor,
              int color) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
        image[sr][sc] == newColor || image[sr][sc] != color)
      return;
    image[sr][sc] = newColor;
    helper(image, sr, sc + 1, newColor, color);  // right
    helper(image, sr, sc - 1, newColor, color);  // left
    helper(image, sr + 1, sc, newColor, color);  // down
    helper(image, sr - 1, sc, newColor, color);  // up
  }
};
