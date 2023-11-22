#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto &&it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        // a node to itself has 0 distance
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // FW algo
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int cityNo = -1;
        int cityCount = INT_MAX;
        int cnt;
        for (int city = 0; city < n; city++)
        {
            cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= cityCount)
            {
                cityCount = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int n = 4, m = 4;
    int distanceThreshold = 4;
    cout << "City With the Smallest Number of Neighbors at a Threshold Distance: ";
    cout << s.findCity(n, m, edges, distanceThreshold) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

leetcode: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

Youtube: https://www.youtube.com/watch?v=PwMVNSJ5SLI&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46

algorithm:

*/