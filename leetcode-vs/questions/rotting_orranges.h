#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int four_directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> rot_oranges;
        // find all rot oranges
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    rot_oranges.push_back(vector<int>{i, j});
        }

        while (!rot_oranges.empty())
        {
            vector<vector<int>> new_rot_oranges;
            for (const auto &orange : rot_oranges)
            {
                int i = orange[0], j = orange[1];
                // four-direction
                for (const auto &direction : four_directions)
                {
                    int new_i = i + direction[0], new_j = j + direction[1];
                    if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n)
                    {
                        if (grid[new_i][new_j] == 1)
                        {
                            new_rot_oranges.push_back(vector<int>{new_i, new_j});
                            grid[new_i][new_j] = 2;
                        }
                    }
                }
            }
            if (new_rot_oranges.empty())
                break;
            count++;
            rot_oranges = new_rot_oranges;
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    return -1;

        return count;
    }
};

