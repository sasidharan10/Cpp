#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int sr = 0, sc = 0;
        int dr = n - 1, dc = m - 1;
        if (grid[sr][sc] == 1 || grid[dr][dc] == 1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {sr, sc}});
        dist[sr][sc] = 1;
        while (!q.empty())
        {
            int d1 = q.front().first;
            int r1 = q.front().second.first;
            int c1 = q.front().second.second;
            q.pop();
            if (dr == r1 && dc == c1)
                return dist[r1][c1];
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    int newRow = r1 + i;
                    int newCol = c1 + j;
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 0)
                    {
                        if (d1 + 1 < dist[newRow][newCol])
                        {
                            dist[newRow][newCol] = d1 + 1;
                            q.push({dist[newRow][newCol], {newRow, newCol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    cout << "Shortest Clear Path in Binary Matrix: " << s.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

leetcode: https://leetcode.com/problems/shortest-path-in-binary-matrix/

Youtube: https://www.youtube.com/watch?v=U5Mw4eyUmw4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=36

algorithm:

- Clear path = (0,0) to (n-1, n-1)
- BFS
*/