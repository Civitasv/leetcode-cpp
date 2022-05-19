#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1. Find the largest index k 
        // such that nums[k] < nums[k+1]
        int n = nums.size(), k, l;

        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1])
                break;
        }

        // if k does not exist, then reverse the whole array
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // else, find the largest l that satifies nums[l] > nums[k]
        for (l = n - 1; l > k; l--) {
            if (nums[l] > nums[k])
                break;
        }

        swap(nums[k], nums[l]);

        // then reverse nums[k+1, :]
        reverse(nums.begin() + k + 1, nums.end());
    }
};


