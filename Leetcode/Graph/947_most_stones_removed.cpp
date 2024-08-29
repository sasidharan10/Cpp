#include <bits/stdc++.h>
using namespace std;
class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
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
    void dfs(int index, int n, vector<vector<int>> &stones, vector<bool> &visited)
    {
        visited[index] = true;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
                dfs(i, n, stones, visited);
        }
    }
    // Using DFS
    int removeStones2(vector<vector<int>> &stones)
    {
        // TC: O(n)
        // SC: O(n)

        int n = stones.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] != true)
            {
                dfs(i, n, stones, visited);
                groups++;
            }
        }
        return n - groups;
    }
    // Using Disjoint Set
    int removeStones(vector<vector<int>> &stones)
    {
        // TC: O(^2) + alpha(n)
        // SC: O(n)
        
        int n = stones.size();
        disjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    ds.unionBySize(i, j);
            }
        }
        int groups = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                groups++;
        }
        return n - groups;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> stones{{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << "Result: " << s.removeStones(stones) << endl;
    return 0;
}

/*

link: https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

leetcode: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

Youtube: https://www.youtube.com/watch?v=cmqIeBFx01w

Code link: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Most%20Stones%20Removed%20with%20Same%20Row%20or%20Column.cpp

algorithm:

- Using DFS:

- We just traverse to next cell, if it is from the same column or row. In this way, we will
  group all the cells, belonging to same row/column. From these groups, only 1 stone will
  be left, and all other stones will be removed.
- So the total number of stones removed will be = (n - total groups).
- Link: https://www.youtube.com/watch?v=ZsGTpXm966E
- Code: https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/BFS_DFS/Most%20Stones%20Removed%20with%20Same%20Row%20or%20Column.cpp

- Using Disjoint Set:

- 

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

/*
************* Java Code **************

    public static void dfs(int index, int n, int[][] stones, boolean[] visited) {
        visited[index] = true;
        for (int i = 0; i < n; i++) {
            if (visited[i] == false && stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])
                dfs(i, n, stones, visited);
        }
    }

    public static int removeStones(int[][] stones) {
        int n = stones.length;
        boolean[] visited = new boolean[n];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] != true) {
                dfs(i, n, stones, visited);
                cnt++;
            }
        }
        return n - cnt;
    }

    // Using Disjoint Set

    public static int removeStones(int[][] stones)
    {
        // TC: O(^2) + alpha(n)
        // SC: O(n)
        
        int n = stones.length;
        disjointSet ds = new disjointSet(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    ds.unionBySize(i, j);
            }
        }
        int groups = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                groups++;
        }
        return n - groups;
    }

*/