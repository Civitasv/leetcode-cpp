#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> curr;
        helper(result, curr, 0, n, k);
        return result;
    }

    void helper(vector<vector<int>> &result, vector<int> &curr, int start, int n, int k)
    {
        if (curr.size() == k)
        {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < n - (k - curr.size()) + 1; i++)
        {
            // choose
            curr.push_back(i + 1);
            // explore
            helper(result, curr, i + 1, n, k);
            // unchoose
            curr.pop_back();
        }
    }
};

int main()
{
    int n = 4, k = 2;
    Solution s;
    for (auto item : s.combine(n, k))
        for (auto i : item)
            cout << i << " ";
    cout << endl;
}