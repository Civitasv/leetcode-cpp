#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> distance(m, vector<int>(n, 20000));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    distance[i][j] = min(distance[i][j], cal_distance(mat, distance, i, j));
                }
                else
                {
                    distance[i][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (mat[i][j] == 1)
                {
                    distance[i][j] = min(distance[i][j], cal_distance(mat, distance, i, j));
                }
                else
                {
                    distance[i][j] = 0;
                }
            }
        }
        return distance;
    }

    int cal_distance(vector<vector<int>> &mat, vector<vector<int>> &distance, int i, int j)
    {
        int min_distance = INT_LEAST32_MAX, dist;

        if (i > 0 && distance[i - 1][j] != 20000)
        {
            min_distance = min(min_distance, mat[i - 1][j] == 0 ? 1 : distance[i - 1][j] + 1);
        }
        if (i < mat.size() - 1 && distance[i + 1][j] != 20000)
        {
            min_distance = min(min_distance, mat[i + 1][j] == 0 ? 1 : distance[i + 1][j] + 1);
        }
        if (j > 0 && distance[i][j - 1] != 20000)
        {
            min_distance = min(min_distance, mat[i][j - 1] == 0 ? 1 : distance[i][j - 1] + 1);
        }
        if (j < mat[0].size() - 1 && distance[i][j + 1] != 20000)
        {
            min_distance = min(min_distance, mat[i][j + 1] == 0 ? 1 : distance[i][j + 1] + 1);
        }
        return min_distance;
    }
};