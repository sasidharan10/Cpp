#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{
public:
    bool isValid(int i, int j, int row, int col)
    {
        if (i >= 0 && i < row && j >= 0 && j < col)
            return true;
        else
            return false;
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        // TC: O(n^2) * O(4 * alpha) * 2
        // SC: O(n^2)
        
        int n = grid.size();
        disjointSet ds(n * n);
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    int newRow = dRow[k] + row;
                    int newCol = dCol[k] + col;
                    if (isValid(newRow, newCol, n, n) && grid[newRow][newCol] == 1)
                    {
                        int node = row * n + col;
                        int adjNode = newRow * n + newCol;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int maxi = -1;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                unordered_set<int> component;
                for (int k = 0; k < 4; k++)
                {
                    int sz = 0;
                    int newRow = dRow[k] + row;
                    int newCol = dCol[k] + col;
                    if (isValid(newRow, newCol, n, n) && grid[newRow][newCol] == 1)
                    {
                        int adjNode = newRow * n + newCol;
                        component.insert(ds.findUParent(adjNode));
                    }
                    for (auto it : component)
                    {
                        sz += ds.size[it];
                    }
                    sz += 1; // counting the inverted cell also
                    maxi = max(maxi, sz);
                }
            }
        }
        // If every cell is 1, then  the above loop would not have executed, hence max size
        // is not updated

        if (maxi == -1)
            return n * n;
        else
            return maxi;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> grid{{1, 0}, {0, 1}};
    cout << "Result: " << s.largestIsland(grid) << endl;
    return 0;
}

/*

link: https://practice.geeksforgeeks.org/problems/maximum-connected-group/1

leetcode: https://leetcode.com/problems/making-a-large-island/

Youtube: https://www.youtube.com/watch?v=lgiz0Oup6gM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=52

algorithm:

*/


/*

827. Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

*/