#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // TC: O(V^3)
        // SC: O(V^2)

        int n = matrix.size();
        // changing unreachable cells to 1e9 to compute the paths
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;
                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        // Floyd Warshall algo
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // changing unreachable cells to -1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>> matrix{{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
    s.shortest_distance(matrix);
    cout << "Shortest path from very node to every node: " << endl;
    for (auto &&i : matrix)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

leetcode:

Youtube: https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42

algorithm:

*/