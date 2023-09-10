#include <vector>
#include <queue>

using namespace std;

 struct Point {
  int x;
  int y;
  Point(int xx, int yy) : x(xx), y(yy) {}
 };

 class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param N int整型 节点总数
     * @param constraints Point类vector 约束边
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > grouping(int N, vector<Point>& constraints) {
        // write code here
        vector<vector<bool>> graph(N, vector<bool>(N, false));

        for (const Point& constraint : constraints) {
            graph[constraint.x - 1][constraint.y - 1] = true;
            graph[constraint.y - 1][constraint.x - 1] = true;
        }

        vector<int> group(N, -1); // 每个节点在的分组
        int curr_group = 0;
        for (int i = 0; i < N; i++) {
            if (group[i] == -1) {
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    if (group[node] == -1) {
                        group[node] = curr_group;
                        for (int j = 0; j < N; j++) { // 遍历其他节点
                            bool can = false;
                            for (int k = 0; k<q.size(); k++) {
                              
                            }
                            if (!graph[node][j] && group[j] == -1) {
                                q.push(j);
                            }
                        }
                    }
                }
                curr_group ++;
            }
        }

        vector<vector<int>> result(curr_group);
        for (int i = 0; i < N; i++) {
            result[group[i]].push_back(i + 1);
        }
        return result;
    }
};

int main() {
  Solution s;
  vector<Point> constraints = {{1,2}, {3,4}};
  s.grouping(4, constraints);
}