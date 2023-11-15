#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2)
    {
        return p1.first < p2.first;
    }
};
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        while (!pq.empty())
        {
            int d1 = pq.top().first;
            int r1 = pq.top().second.first;
            int c1 = pq.top().second.second;
            pq.pop();
            if (r1 == n - 1 && c1 == m - 1)
                return d1;
            for (int i = 0; i < 4; i++)
            {
                int newRow = r1 + dRow[i];
                int newCol = c1 + dCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m)
                {
                    int d2 = max(abs(heights[r1][c1] - heights[newRow][newCol]), d1);
                    if (d2 < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = d2;
                        pq.push({d2, {newRow, newCol}});
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
    // vector<vector<int>> nums{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    vector<vector<int>> nums{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    cout << "Path With Minimum Effort: " << s.minimumEffortPath(nums) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1

leetcode: https://leetcode.com/problems/path-with-minimum-effort/submissions/

Youtube: https://www.youtube.com/watch?v=0ytpZyiZFhA&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=39

algorithm:

*/