#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, source});
        dist[source.first][source.second] = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int d1 = q.front().first;
            pair<int, int> cur = q.front().second;
            q.pop();
            int r1 = cur.first;
            int c1 = cur.second;
            if (cur == destination)
                return dist[r1][c1];
            for (int i = 0; i < 4; i++)
            {
                int newRow = r1 + dRow[i];
                int newCol = c1 + dCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1)
                {
                    if (d1 + 1 < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = d1 + 1;
                        q.push({dist[newRow][newCol], {newRow, newCol}});
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
    vector<vector<int>> grid{{1, 1, 1, 1},
                             {1, 1, 0, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0},
                             {1, 0, 0, 1}};
    pair<int, int> source = {0, 1}, destination = {2, 2};
    cout << "Shortest distance from source to destination: " << s.shortestPath(grid, source, destination) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

leetcode: https://leetcode.com/problems/shortest-path-in-binary-matrix/

Youtube: https://www.youtube.com/watch?v=U5Mw4eyUmw4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=36

algorithm:

*/