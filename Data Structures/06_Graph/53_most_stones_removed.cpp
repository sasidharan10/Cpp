#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (parent[node] == node)
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
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        int maxRow = 0, maxCol = 0;
        for (int i = 0; i < n; i++)
        {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }
        disjointSet ds(maxRow + maxCol + 1);
        for (int i = 0; i < n; i++)
        {
            int nodeRow = stones[i][0];
            int nodeCol = stones[i][1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
        }
        int totalNodes = maxRow + maxCol + 2;
        int cnt = 0;
        for (int i = 0; i < totalNodes; i++)
        {
            if (ds.parent[i] == i && ds.size[i] > 1)
                cnt++;
        }
        return n - cnt;
    }
};
int main()
{
    Solution s;
    int n = 6;
    vector<vector<int>> stones{{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << "Result: " << s.maxRemove(stones, n) << endl;
    return 0;
}

/*

link:

leetcode: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Youtube:

algorithm:

- We take the rows and columns as nodes.
- if a 2D array has 4 rows [0,1,2,3] and 5 columns [0,1,2,3,4] then we can
  represent the rows as itself, and columns will be represented as [4,5,7,8,9].
- And we will connect the col and row nodes of each element, since they are
  connected.
- Now the no of connected components - n will be the max no of stones we can remove.
- because each connected components are lying without any connection with other components.
- Now the nodes inside the components are lying in the same row or column. We can remove
  c - 1 nodes from them, as we can keep 1 node in a component. hence the ans = n - cnt.
- To get the components count, we find no of "ds.parent[i] == i" and
  also check for "ds.size[i] > 1", which means this component has more than 1 node i.e.,
  its not an empty row or column(stones present in that row or column).
  
*/

/*

947. Most Stones Removed with Same Row or Column

On a 2D plane, we place n stones at some integer coordinate points.
Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same
column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents
the location of the ith stone, return the largest possible number
of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column
with another stone still on the plane.

Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column
with another stone still on the plane.

Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

*/